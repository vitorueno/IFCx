export PATH=$PATH:/usr/local/i386elfgcc/bin

sh "clean.sh"

as boot.S -o "boot.o"   
as kernel_entry.S -o kernel_entry.o --32 -march=i386

ld --Ttext 0x7c00 --oformat=binary boot.o -o boot.bin 

i386-elf-gcc -ffreestanding -m32 -g -c "kernel.cpp" -o "kernel.o"

i386-elf-ld -o "full_kernel.bin" -Ttext 0x1000 "kernel_entry.o" "kernel.o" --oformat binary

cat "boot.bin" "full_kernel.bin"  > "test.bin"      

qemu-system-x86_64 -drive format=raw,file="test.bin",index=0,if=floppy,  -m 128M

