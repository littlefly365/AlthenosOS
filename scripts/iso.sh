#!/bin/bash
set -e

GREEN="\033[1;32m"
RESET="\033[0m"
VERSION="0.0.1"

mkdir -p iso/boot/grub

cp bzImage iso/boot/bzImage

cat > iso/boot/grub/grub.cfg <<EOF
set timeout=0
set default=0

menuentry "Althenos-OS-$VERSION" {
    multiboot /boot/bzImage
    boot
}
EOF

echo -e "${GREEN}  ISO     ${RESET}AlthenosOS-$VERSION.iso"
grub-mkrescue --output=AlthenosOS-$VERSION.iso iso >/dev/null 2>&1

rm -rf iso
