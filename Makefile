CC=gcc
AS=as
CFLAGS = -fno-stack-protector -m32 -nostdlib -fno-builtin -fno-exceptions -ffreestanding -fno-leading-underscore -Wall -Wextra -Wpedantic
ASFLAGS = --32
LDFLAGS = -melf_i386
VERSION=0.0.1
MAKEFLAGS= -j$(nproc)

SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
ISO_DIR=iso

# Fuentes
SRC_DRIVERS=$(wildcard $(SRC_DIR)/drivers/*.c)
SRC_SHELL=$(wildcard $(SRC_DIR)/shell/*.c)
SRC_KERNEL=$(wildcard $(SRC_DIR)/kernel/i386/*.c)
SRC_BOOT=$(wildcard $(SRC_DIR)/boot/*.s)

# Objetos
OBJ_DRIVERS=$(patsubst $(SRC_DIR)/drivers/%.c,$(BUILD_DIR)/drivers/%.o,$(SRC_DRIVERS))
OBJ_SHELL=$(patsubst $(SRC_DIR)/shell/%.c,$(BUILD_DIR)/shell/%.o,$(SRC_SHELL))
OBJ_KERNEL=$(patsubst $(SRC_DIR)/kernel/i386/%.c,$(BUILD_DIR)/kernel/%.o,$(SRC_KERNEL))
OBJ_BOOT=$(patsubst $(SRC_DIR)/boot/%.s,$(BUILD_DIR)/boot/%.o,$(SRC_BOOT))

all: bzImage iso

# Crear ISO
iso: bzImage
	mkdir -p $(ISO_DIR)/boot/grub
	cp bzImage $(ISO_DIR)/boot/bzImage
	echo 'set timeout=0'                      > $(ISO_DIR)/boot/grub/grub.cfg
	echo 'set default=0'                     >> $(ISO_DIR)/boot/grub/grub.cfg
	echo ''                                  >> $(ISO_DIR)/boot/grub/grub.cfg
	echo 'menuentry "Althenos-OS-$(VERSION)" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  multiboot /boot/bzImage'         >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '  boot'                             >> $(ISO_DIR)/boot/grub/grub.cfg
	echo '}'                                 >> $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue --output=AlthenosOS-$(VERSION).iso $(ISO_DIR)
	rm -rf $(ISO_DIR)

# Compilación de objetos
$(BUILD_DIR)/drivers/%.o: $(SRC_DIR)/drivers/%.c
	mkdir -p $(BUILD_DIR)/drivers
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/shell/%.o: $(SRC_DIR)/shell/%.c
	mkdir -p $(BUILD_DIR)/shell
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/kernel/%.o: $(SRC_DIR)/kernel/i386/%.c
	mkdir -p $(BUILD_DIR)/kernel
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/boot/%.o: $(SRC_DIR)/boot/%.s
	mkdir -p $(BUILD_DIR)/boot
	$(AS) $(ASFLAGS) -o $@ $<

# Enlazado
bzImage: $(OBJ_DRIVERS) $(OBJ_SHELL) $(OBJ_KERNEL) $(OBJ_BOOT) $(SRC_DIR)/linker.ld
	ld $(LDFLAGS) -T $(SRC_DIR)/linker.ld -o bzImage $(OBJ_DRIVERS) $(OBJ_SHELL) $(OBJ_KERNEL) $(OBJ_BOOT)

# Limpieza
clean:
	rm -rf AlthenosOS-$(VERSION).iso bzImage $(BUILD_DIR) $(ISO_DIR)

# Ejecutar en QEMU
run: all
	qemu-system-i386 -cdrom AlthenosOS-$(VERSION).iso --enable-kvm
