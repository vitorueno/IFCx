# ================== VARIÁVEIS =====================

# Specify the path to the i386-elf-gcc binary
CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CROSS_LD = /usr/local/i386elfgcc/bin/i386-elf-ld

# Flags for assembling and kernel_entry.S
ASFLAGS = --32 -march=i386

# Flags for compiling kernel.c
CFLAGS = -ffreestanding -m32 -g

# Flags for linking the kernel
LDFLAGS = -Ttext 0x1000 --oformat binary

# List of object files to build
<<<<<<< HEAD:bootloader/Makefile
OBJS = kernel_entry.o kernel.o lib.o imprime.o 
=======
OBJS = kernel_entry.o kernel.o print.o lib.o io.o idt.o isr.o pic.o irq.o tty.o
>>>>>>> testes_idt-vitor(main):src/Makefile

BUILD_DIR = build/

FINAL_BINARY = os.bin

# ===============REGRA GERAL=================

# The default target builds everything
all: create_build_dir os.bin

create_build_dir:
	@echo "-> creating build directory: $(BUILD_DIR)"
	@mkdir -p $(BUILD_DIR)

# Rule to create the final binary image
os.bin: $(BUILD_DIR)boot.bin $(BUILD_DIR)full_kernel.bin
	@echo "-> generating final binary: $< => $@" 
	@cat $^ > $@

# ================= BOOT ==================== 
# Rule to assemble boot.S into boot.bin
$(BUILD_DIR)boot.bin: boot.o
	@echo "-> generating binary: $< => $@" 
	@ld --Ttext 0x7c00 --oformat=binary $(BUILD_DIR)$< -o $@

# Rule to build boot.o
boot.o: boot.S
	@echo "-> compiling: $< => $@" 
	@as $< -o $(BUILD_DIR)$@

# ================FULL KERNEL===============

# Rule to link the kernel
$(BUILD_DIR)full_kernel.bin: $(OBJS)
	@echo "-> linking: $< => $@" 
	@$(CROSS_LD) $(LDFLAGS) -o $@  $(addprefix $(BUILD_DIR)/, $(OBJS))

# Rule to build kernel_entry.o
kernel_entry.o: kernel_entry.S
	@echo "-> compiling: $< => $@" 
	@as $(ASFLAGS) $< -o $(BUILD_DIR)$@

# Rule to build kernel.o
kernel.o: kernel.c
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

imprime.o: imprime.c 
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

lib.o: lib.c 
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

io.o: io.c 
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

idt.o: idt.c 
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

isr.o: isr.c 
	@echo "-> compiling: $< => $@" 
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

pic.o: pic.c 
	@echo "-> compiling $< => $@"
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

irq.o: irq.c 
	@echo "-> compiling $< => $@"
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

tty.o: tty.c
	@echo "-> compiling $< => $@"
	@$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@

# Clean up generated files
clean:
	@echo "-> limpando os arquivos de build"
	@rm -rf $(BUILD_DIR)
	@rm -f *.o *.bin

# Rule to run the binary image in QEMU
run: 
	@echo "-> running $(FINAL_BINARY)" 
	@qemu-system-x86_64 -drive format=raw,file=$(FINAL_BINARY),index=0,if=floppy -m 128M