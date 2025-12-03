#!/bin/bash
set -e

BLUE="\033[1;34m"
YELLOW="\033[1;33m"
GREEN="\033[1;32m"
RESET="\033[0m"

CC="clang"
AS="as"
LD="ld"
CFLAGS="-Wno-error -w -fno-stack-protector -m32 -nostdlib -fno-builtin -fno-exceptions -ffreestanding -Wall -Wextra -Wpedantic"
ASFLAGS="--32"
LDFLAGS="-melf_i386"
VERSION="0.0.1"

SRC_DIR="src"
BUILD_DIR="build"
INCLUDE="-Iinclude"

echo -e "${GREEN}==> Building AlthenosOS kernel${RESET}"

mkdir -p $BUILD_DIR/{kernel,drivers,shell,bin,boot}

# Compile all .c
for f in $(find src -name "*.c"); do
    out=$BUILD_DIR/$(echo "$f" | sed "s|src/||" | sed "s|.c$|.o|")
    echo -e "${BLUE}  CC      ${RESET}$out"
    mkdir -p "$(dirname "$out")"
    $CC $CFLAGS $INCLUDE -c "$f" -o "$out"
done

# Assemble all .s
for f in $(find src/boot -name "*.s"); do
    out=$BUILD_DIR/boot/$(basename "$f" .s).o
    echo -e "${YELLOW}  AS      ${RESET}$out"
    $AS $ASFLAGS -o "$out" "$f"
done

# Initrd (binary -> object)
if [ -f initrd.tar ]; then
    tar -cvf build/initrd.tar -C src/initrd . >/dev/null 2>&1
    echo -e "${YELLOW}  AS      ${RESET}build/initrd.o"
    ld -m elf_i386 -r -b binary build/initrd.tar -o build/initrd.o >/dev/null 2>&1
fi

# Link
echo -e "${GREEN}  LD      ${RESET}bzImage"
$LD $LDFLAGS -T src/linker.ld -o bzImage $(find build -name "*.o") >/dev/null 2>&1
