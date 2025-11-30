#AlthenosOS

AlthenosOS is an experimental 32-bit operating system, based on Primus-OS, written from scratch in C and x86 Assembly, with an educational, modular, and extensible approach.
Its goal is to provide a foundation for experimenting with kernels, bootloaders, memory management, file systems, and low-level tools, gradually adopting a more UNIX and BSD-like style.

#Main Features

-Monolithic 32-bit x86 kernel, freestanding.

-Grub as bootloader compatible with BIOS and multiboot.

-Basic drivers: text VGA, PS/2 keyboard, PIT, PIC.

-Interrupt system (IDT + IRQ + exceptions).

-Basic memory manager (paging + dynamic heap).

Internal shell with essential commands and f-uture support for external UNIX-like commands.

-Modular architecture with restructured code for easy learning.

-User space organized according to FHS, with symbolic links for binaries and libraries.

I-nspired by mature systems: Maestro OS, Linux Kernel, and NetBSD.

#Dependencies

To compile AlthenosOS, you need:

nasm
xorriso
mtools
gcc (with -m32 support)
ld / binutils-i386

#Generating the ISO
make clean and make
(if you want you can change the options in the Makefile and build scripts for your preferences)

#Testing with QEMU

qemu-system-i386 -cdrom althenos-os.iso --enable-kvm or run the run.sh script


#Project Structure(in the future)

AlthenosOS/
├── boot/          # bootloader (ASM)
├── arch/x86/      # x86-specific code
├── kernel/        # kernel
├── drivers/       # VGA, keyboard, PIT, etc.
├── lib/           # C utilities
├── fs/            # VFS and future filesystem drivers
├── init/          # kernel initialization
├── scripts/       # auxiliary scripts
├── Makefile
└── README.md


#License, Style, and Fork Vision

For certain reasons, the project will temporarily be licensed under GPL v3, since the original project it is based on, Primus-OS, is under that license.

It is expected that, in the future, AlthenosOS could migrate to the BSD 3-clause license, but until the majority or all of the original code is rewritten, it will continue under GPL v3.

Creating this fork required significant personal effort to make the project functional:

Minor errors that caused compilation failures were fixed.

Large parts of the code were restructured to adapt the architecture and style to AlthenosOS.

Broken components like the clock, date, and datetime commands were corrected.


#UNIX-style Approach and Roadmap

AlthenosOS aims to adopt a more UNIX-like style, including:

UNIX-like commands (ls, cp, chmod, mkdir, etc.).

File and user permissions management.

Clear modular boot sequence:


BIOS → Bootloader → Kernel → Init → OS → User Space

FHS-like filesystem layout with symbolic links:


/bin     → /usr/bin
/sbin    → /usr/sbin
/lib     → /usr/lib
/usr/bin
/usr/sbin
/usr/lib

This structure separates essential binaries, libraries, and user tools, creating a coherent and expandable user space.


#Future Transition to 64-bit and UEFI

AlthenosOS is planned to transition to 64-bit, bringing:

UEFI support, with advantages over traditional BIOS.

Better memory addressing and larger user space support.

Compatibility with modern graphics modes beyond VGA.

#Inspiration and Reference

During development, AlthenosOS takes inspiration from mature projects:

[Maestro-OS](https://github.com/maestro-os/maestro)

[Linux Kernel](https://github.com/torvalds/linux)

[NetBSD](https://github.com/NetBSD/src)


#Planned Future Improvements

Remove GNU dependencies and migrate to BSD-style tools (bsdmake, NetBSD-like scripts).

Replace GNU toolchain with LLVM/Clang for kernel and utilities compilation.

Possible replacement of the current bootloader with a custom one or alternatives like Limine.

Continue rewriting code to achieve full independence from the original GPL base.

Implement a more complete shell with support for external UNIX-like commands.

Expand the user system, permissions, and user space for a more UNIX-like experience.

Implement multitasking, advanced VFS, directories, and node trees.

Expand math and linear algebra libraries.

Support simple games (tic-tac-toe, snake) and additional VGA graphics modes.


#TODO

Unit testing framework for internal modules.

Complete memory manager (advanced paging + dynamic heap).

Filesystem support (VFS, FAT12/FAT16, or EXT2).

Advanced shell with external command parsing.

Simple text editor.

Complete documentation of kernel and OS architecture.

Migration to 64-bit and UEFI.

Remove all GNU dependencies and fully adopt BSD-style build system.
