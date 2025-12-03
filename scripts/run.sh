#!/bin/bash
set -e
echo -e "\033[1;32m==> Running QEMU\033[0m"
qemu-system-i386 -cdrom AlthenosOS-0.0.1.iso --enable-kvm
