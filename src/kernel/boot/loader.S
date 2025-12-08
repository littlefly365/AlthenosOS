# -------------------------------------------------------------------------
#                                 AlthenosOS
#  (c) 2025-202 littlefly365
#  This project is under the GPL v3 license.
#  You should receive the license with the source code. If not - check:
#  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
# -------------------------------------------------------------------------

.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM


.section .text
.extern main
.global loader


loader:
    mov $kernel_stack, %esp
    push %eax
    push %ebx
    call kmain


_stop:
    cli
    hlt
    jmp _stop


.section .bss
.space 2*1024*1024
kernel_stack:
