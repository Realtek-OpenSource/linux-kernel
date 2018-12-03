cmd_arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb := mkdir -p arch/arm/boot/dts/realtek/rtd16xx/ ; ccache arm-linux-gnueabi-gcc -E -Wp,-MD,arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.d.pre.tmp -nostdinc -I./arch/arm/boot/dts -I./arch/arm/boot/dts/include -I./drivers/of/testcase-data -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.dts.tmp arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dts ; /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/dtb_overlay_tool/dtc -O dtb -o arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb -b 0 -i arch/arm/boot/dts/realtek/rtd16xx/ -p 8192  -d arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.d.dtc.tmp arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.dts.tmp ; cat arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.d.pre.tmp arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.d.dtc.tmp > arch/arm/boot/dts/realtek/rtd16xx/.rtd-1619-mjolnir-2GB-avb.dtb.d

source_arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb := arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dts

deps_arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb := \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB.dts \
    $(wildcard include/config/cma/areas.h) \
  arch/arm/boot/dts/include/dt-bindings/soc/rtd16xx,memory.h \
    $(wildcard include/config/arch/rtd16xx.h) \
  arch/arm/boot/dts/include/dt-bindings/soc/../../soc/realtek/memory.h \
    $(wildcard include/config/cpu/v7.h) \
    $(wildcard include/config/arch/rtd139x.h) \
    $(wildcard include/config/rtk/vmx/ultra.h) \
    $(wildcard include/config/arch/rtd129x.h) \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx.dtsi \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/irq.h \
  arch/arm/boot/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  arch/arm/boot/dts/include/dt-bindings/clock/rtk,clock-rtd16xx.h \
  arch/arm/boot/dts/include/dt-bindings/reset/rtk,reset-rtd16xx.h \
  arch/arm/boot/dts/include/dt-bindings/power/rtk,power-rtd16xx.h \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-pcie.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-cpu-dvfs.dtsi \
  arch/arm/boot/dts/include/dt-bindings/regulator/gmt,g22xx.h \
  arch/arm/boot/dts/include/dt-bindings/regulator/anpec,apw8889.h \
  arch/arm/boot/dts/include/dt-bindings/thermal/thermal.h \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-gpu-dvfs.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-irda.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-sata.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-usb.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-avb.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-pinctrl.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-hdmirxEDID.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-sata.dtsi \
  arch/arm/boot/dts/realtek/rtd16xx/rtd-16xx-usb.dtsi \

arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb: $(deps_arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb)

$(deps_arch/arm/boot/dts/realtek/rtd16xx/rtd-1619-mjolnir-2GB-avb.dtb):
