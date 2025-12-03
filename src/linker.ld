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

  /* ----------------------------- */
  /* INITRD embebido en el kernel */
  /* ----------------------------- */
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
