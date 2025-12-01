CC=gcc
AS=as
GCCPARAMS = -fno-stack-protector -m32 -nostdlib -fno-builtin -fno-exceptions -ffreestanding -fno-leading-underscore -Wall -Wextra -Wpedantic
ASPARAMS = --32
LDPARAMS = -melf_i386
VERSION= 0.0.1

SRC_DIR=src/code
HDR_DIR=src/include/
OBJ_DIR=build
ISO_DIR=iso

SRC_FILES1=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES1=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES1))
SRC_FILES2=$(wildcard $(SRC_DIR)/*.s)
OBJ_FILES2=$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC_FILES2))

all: bzImage
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp    bzImage iso/boot/bzImage
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "Althenos-OS-$(VERSION)" {'            >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/bzImage'   >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=AlthenosOS-$(VERSION).iso iso
	rm -rf iso

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(GCCPARAMS) $^ -I$(HDR_DIR) -c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	$(AS) $(ASPARAMS) -o $@ $<

bzImage: $(SRC_DIR)/linker.ld $(OBJ_FILES1) $(OBJ_FILES2) # $(OBJ_FILES3)
	ld $(LDPARAMS) -T $< -o $@ $(OBJ_DIR)/*.o

clean:
	rm -rf AlthenosOS-$(VERSION).iso bzImage $(OBJ_DIR) iso
run:
	qemu-system-i386 -cdrom primus-os-$(VERSION).iso --enable-kvm
