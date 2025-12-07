# -------------------------------------------------------------------------
#                                 AlthenosOS
#  (c) 2025-2026 littlefly365
#  This project is under the GPL v3 license.
#  You should receive the license with the source code. If not - check:
#  https://github.com/littlefly365/AlthenosOS/blob/main/LICENSE.md
# -------------------------------------------------------------------------

CONFIG_FILE = Makefile.config

include $(CONFIG_FILE)

all: dirs bzImage iso

iso: bzImage
	$(Q)mkdir -p $(ISO_DIR)/boot/grub
	$(Q)cp bzImage $(ISO_DIR)/boot/bzImage
	$(Q)echo 'set timeout=10'                      > $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo 'set default=0'                     >> $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo ''                                  >> $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo 'menuentry "Althenos-OS-$(VERSION)" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo '  multiboot /boot/bzImage'         >> $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo '  boot'                             >> $(ISO_DIR)/boot/grub/grub.cfg
	$(Q)echo '}'                                 >> $(ISO_DIR)/boot/grub/grub.cfg
	@printf "$(GREEN)  MKISO   $(RESET)AlthenosOS-$(VERSION).iso\n"
	$(Q)grub-mkrescue --output=AlthenosOS-$(VERSION).iso $(ISO_DIR) >/dev/null 2>&1
	$(Q)rm -rf $(ISO_DIR)

$(BUILD_DIR)/drivers/%.o: $(KERNEL_DIR)/drivers/%.c
	@$(cmd_cc)
	$(Q)$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/ksh/%.o: $(KERNEL_DIR)/ksh/%.c
	@$(cmd_cc)
	$(Q)$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/kernel/%.o: $(KERNEL_DIR)/arch/i386/%.c
	@$(cmd_cc)
	$(Q)$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/bin/%.o: $(KERNEL_DIR)/bin/%.c
	@$(cmd_cc)
	$(Q)$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/bin/%.o: $(KERNEL_DIR)/bin/%.cpp
	@$(cmd_cpp)
	$(Q)$(CPP) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/boot/%.o: $(KERNEL_DIR)/boot/%.s
	@$(cmd_as)
	$(Q)$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/initrd.tar: 
	$(Q)tar -cvf $(BUILD_DIR)/initrd.tar -C $(SRC_DIR)/initrd . >/dev/null 2>&1

$(OBJ_INITRD): $(BUILD_DIR)/initrd.tar
	@$(cmd_ld)
	$(Q) $(LD) $(LDFLAGS) -r -b binary $(SRC_INITRD) -o $(OBJ_INITRD)

bzImage: $(OBJ_DRIVERS) $(OBJ_SHELL) $(OBJ_KERNEL) $(OBJ_BOOT) $(OBJ_BIN) $(OBJ_BIN_CPP) $(OBJ_INITRD) $(SRC_DIR)/linker.ld
	@$(cmd_ld)
	$(Q)$(LD) $(LDFLAGS) -T $(SRC_DIR)/linker.ld -o bzImage \
		$(OBJ_DRIVERS) $(OBJ_SHELL) $(OBJ_KERNEL) $(OBJ_BOOT) $(OBJ_BIN) $(OBJ_BIN_CPP) $(OBJ_INITRD) >/dev/null 2>&1

dirs:
	$(Q)./scripts/directories.sh >/dev/null 2>&1
clean:
	@printf "$(YELLOW)  CLEAN   $(RESET)build/ iso/ bzImage\n"
	$(Q)rm -rf AlthenosOS-$(VERSION).iso bzImage initrd.tar $(BUILD_DIR) $(ISO_DIR)

run: 
	@printf "$(YELLOW)  RUN     $(RESET)QEMU\n"
	$(Q)qemu-system-i386 -cdrom AlthenosOS-$(VERSION).iso --enable-kvm >/dev/null 2>&1
