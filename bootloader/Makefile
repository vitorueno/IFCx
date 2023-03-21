# ================== VARIÁVEIS =====================

# Specify the path to the i386-elf-gcc binary
CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CROSS_LD = /usr/local/i386elfgcc/bin/i386-elf-ld

# Flags for assembling and kernel_entry.S
ASFLAGS = --32 -march=i386

# Flags for compiling kernel.cpp
CFLAGS = -ffreestanding -m32 -g

# Flags for linking the kernel
LDFLAGS = -Ttext 0x1000 --oformat binary

# List of object files to build
OBJS = kernel_entry.o kernel.o 

# ===============REGRA GERAL=================

# The default target builds everything
all: test.bin

# Rule to create the final binary image
test.bin: boot.bin full_kernel.bin
	cat $^ > $@

# ================= BOOT ==================== 
# Rule to assemble boot.S into boot.bin
boot.bin: boot.o
	ld --Ttext 0x7c00 --oformat=binary $< -o $@

# Rule to build boot.o
boot.o: boot.S
	as $< -o $@


# ================FULL KERNEL===============

# Rule to link the kernel
full_kernel.bin: $(OBJS)
	$(CROSS_LD) $(LDFLAGS) -o $@ $(OBJS)


# Rule to build kernel_entry.o
kernel_entry.o: kernel_entry.S
	as $(ASFLAGS) $< -o $@

# Rule to build kernel.o
kernel.o: kernel.cpp
	$(CC) $(CFLAGS) -c $< -o $@


# =========== COMANDOS =====================

# Clean up generated files
clean:
	rm -f $(OBJS) test.bin


# Rule to run the binary image in QEMU
run: test.bin
	qemu-system-x86_64 -drive format=raw,file=$<,index=0,if=floppy -m 128M