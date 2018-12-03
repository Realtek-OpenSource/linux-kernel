cmd_kernel/printk/built-in.o :=  ccache arm-linux-gnueabi-ld -EL    -r -o kernel/printk/built-in.o kernel/printk/printk.o kernel/printk/nmi.o 
