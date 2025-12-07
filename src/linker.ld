/*
 * -------------------------------------------------------------------------
 *                                 AlthenosOS
 *  (c) 2025-2026 littlefly365
 *  This project is under the GPL v3 license.
 *  You should receive the license with the source code. If not - check:
 *  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

SECTIONS
{
  . = 0x0100000;

  .text :
  {
    *(.multiboot)
    *(.text*)
    *(.rodata*)
  }

  .data :
  {
    start_ctors = .;
    KEEP(*( .init_array ));
    KEEP(*(SORT_BY_INIT_PRIORITY( .init_array.* )));
    end_ctors = .;

    *(.data*)
  }

  .bss :
  {
    *(.bss*)
    *(COMMON)
  }

  .initrd ALIGN(4096) :
  {
      initrd_start = .;
      KEEP(*(.initrd))
      initrd_end = .;
  }

  /DISCARD/ :
  {
    *(.fini_array*)
    *(.comment)
  }
}
