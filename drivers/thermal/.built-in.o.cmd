cmd_drivers/thermal/built-in.o :=  ccache arm-linux-gnueabi-ld -EL    -r -o drivers/thermal/built-in.o drivers/thermal/thermal_sys.o drivers/thermal/samsung/built-in.o drivers/thermal/realtek/built-in.o 