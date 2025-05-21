#pragma once

#include "types.h"

class Spinlock {
  public:
    Spinlock(const char *name);

    void acquire();
    void release();
    bool holding();

  private:
    volatile uint locked;
    const char *name;
    struct cpu *holder;
    uint pcs[10];

    void getCallerPcs(void *v, uint pcs[]);
    void pushcli();
    void popcli();
};
