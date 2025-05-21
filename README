# SpinOS

**SpinOS** is an experimental **monolithic C++ kernel** based on the [MIT xv6 operating system](https://pdos.csail.mit.edu/6.828/2023/xv6.html). It is intended for research, education, and exploration into modernizing low-level OS code using C++ while maintaining a minimalist, UNIX-like architecture.

> ⚙️ Built on xv6. Reimagined in C++.

---

## 🚀 Project Goals

- ✨ Port core components of xv6 from C to C++
- 🧵 Maintain xv6’s simplicity while exploring C++ idioms
- 🧪 Serve as a testbed for experimental kernel development
- 📚 Provide a readable codebase for learning OS internals in C++

---

## 🔍 Key Features

- Based on [xv6-public](https://github.com/mit-pdos/xv6-public)
- Hybrid build system with C and C++ compilation
- Uses a monolithic kernel model (all code runs in kernel space)
- Compiles with `g++` in freestanding mode (no standard library)
- Runs in [QEMU](https://www.qemu.org/) and [Bochs](http://bochs.sourceforge.net/)

---

## 🧑‍💻 Building SpinOS

### Prerequisites

- GCC cross-compiler for `i386` (e.g., `i386-jos-elf-gcc`, `i386-jos-elf-g++`)
- `make`, `qemu`, `perl`

Install cross-tools on Ubuntu:
```bash
sudo apt install gcc-multilib qemu-system-x86 build-essential perl
````

### Build the kernel image

```bash
make clean
make
```

### Run it in QEMU

```bash
make qemu
```

---

## 🏗️ Code Layout

```
.
├── boot/           # Bootloader and startup assembly
├── kernel/         # C++ kernel source files
├── user/           # User-space applications
├── Makefile        # Cross-compilation makefile
├── fs.img          # User program disk image
└── README.md
```

---

## 🔧 Porting Notes

* Replaced many `.c` source files with `.cpp` equivalents
* Disabled C++ exceptions and RTTI (`-fno-exceptions -fno-rtti`)
* Avoids STL and dynamic memory allocation (except `kalloc`)
* Boot and linker code remain in C and assembly
* Added rules in the Makefile to compile `.cpp` files with `g++`

---

## 📜 License

SpinOS is a fork of xv6, which is licensed under the [MIT License](LICENSE). All original xv6 authors and copyright holders are acknowledged.

> You are free to use, modify, and distribute SpinOS under the same license terms.

---

## 🙏 Acknowledgments

* [xv6 by MIT](https://github.com/mit-pdos/xv6-public)
* The 6.828 Operating Systems Engineering course
* [OSDev.org](https://wiki.osdev.org/Main_Page) community

---

## 🧠 Future Plans

* Add more C++ features (RAII, templates in device drivers)
* Isolate subsystems with namespaces
* Improve testability with mock interfaces
* Explore user-space in C++

---

## ✉️ Contributing

This is an experimental project. Bug reports, suggestions, and discussions are welcome!

Feel free to fork, star ⭐, or reach out with ideas.
