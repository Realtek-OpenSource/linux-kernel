cmd_lib/bitrev.o := ccache arm-linux-gnueabi-gcc -Wp,-MD,lib/.bitrev.o.d  -nostdinc -isystem /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831/bin/../lib/gcc/arm-linux-gnueabi/6.4.1/include -I./arch/arm/include -I./arch/arm/include/generated/uapi -I./arch/arm/include/generated  -I./include -I./arch/arm/include/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-rtd16xx/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv8-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types     -DKBUILD_BASENAME='"bitrev"'  -DKBUILD_MODNAME='"bitrev"' -c -o lib/.tmp_bitrev.o lib/bitrev.c

source_lib/bitrev.o := lib/bitrev.c

deps_lib/bitrev.o := \
    $(wildcard include/config/have/arch/bitreverse.h) \

lib/bitrev.o: $(deps_lib/bitrev.o)

$(deps_lib/bitrev.o):
