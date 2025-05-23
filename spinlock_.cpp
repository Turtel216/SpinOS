#include "spinlock.hpp"

#include "defs.h"
#include "memlayout.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "types.h"
#include "x86.h"

inline Spinlock::Spinlock(const char *name)
    : locked(0), name(name), holder(nullptr) {
    for (int i = 0; i < 10; ++i)
        pcs[i] = 0;
}

inline void Spinlock::acquire() {
    pushcli();
    if (holding()) {
        panic((char *)"Spinlock::acquire: already held");
    }

    while (__sync_lock_test_and_set(&locked, 1) != 0)
        ;

    __sync_synchronize();

    holder = mycpu();
    getCallerPcs((void *)&name, pcs);
}

inline void Spinlock::release() {
    if (!holding()) {
        panic((char *)"Spinlock::release: not held");
    }

    pcs[0] = 0;
    holder = nullptr;
    __sync_synchronize();
    __asm__ __volatile__("movl $0, %0" : "+m"(locked) :);

    popcli();
}

inline bool Spinlock::holding() {
    pushcli();
    bool r = locked && holder == mycpu();
    popcli();
    return r;
}

inline void Spinlock::getCallerPcs(void *v, uint pcs[]) {
    uint *ebp = (uint *)v - 2;
    for (int i = 0; i < 10; ++i) {
        if (ebp == nullptr || ebp < (uint *)KERNBASE ||
            ebp == (uint *)0xffffffff)
            break;
        pcs[i] = ebp[1];
        ebp = (uint *)ebp[0];
    }
    for (int i = 0; i < 10; ++i)
        pcs[i] = 0;
}

inline void Spinlock::pushcli() {
    int eflags = readeflags();
    cli();
    if (mycpu()->ncli == 0)
        mycpu()->intena = eflags & FL_IF;
    mycpu()->ncli++;
}

inline void Spinlock::popcli() {
    if (readeflags() & FL_IF)
        panic((char *)"Spinlock::popcli - interruptible");
    if (--mycpu()->ncli < 0)
        panic((char *)"Spinlock::popcli");
    if (mycpu()->ncli == 0 && mycpu()->intena)
        sti();
}
