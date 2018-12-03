cmd_drivers/firmware/efi/libstub/lib-fdt_sw.o := ccache arm-linux-gnueabi-gcc -Wp,-MD,drivers/firmware/efi/libstub/.lib-fdt_sw.o.d  -nostdinc -isystem /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831/bin/../lib/gcc/arm-linux-gnueabi/6.4.1/include -I./arch/arm/include -I./arch/arm/include/generated/uapi -I./arch/arm/include/generated  -I./include -I./arch/arm/include/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-rtd16xx/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -fno-ipa-sra -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv8-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -O2 --param=allow-store-data-races=0 -DCC_HAVE_ASM_GOTO -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -g0 -fno-builtin -fpic -mno-single-pic-base -I./scripts/dtc/libfdt -DDISABLE_BRANCH_PROFILING -ffreestanding -fno-stack-protector     -DKBUILD_BASENAME='"lib_fdt_sw"'  -DKBUILD_MODNAME='"lib_fdt_sw"' -c -o drivers/firmware/efi/libstub/.tmp_lib-fdt_sw.o lib/fdt_sw.c

source_drivers/firmware/efi/libstub/lib-fdt_sw.o := lib/fdt_sw.c

deps_drivers/firmware/efi/libstub/lib-fdt_sw.o := \
  include/linux/libfdt_env.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/uapi/linux/types.h \
  arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  arch/arm/include/uapi/asm/posix_types.h \
  include/uapi/asm-generic/posix_types.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831/lib/gcc/arm-linux-gnueabi/6.4.1/include/stdarg.h \
  include/uapi/linux/string.h \
  arch/arm/include/asm/string.h \
  arch/arm/include/uapi/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/uapi/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  arch/arm/include/asm/swab.h \
  arch/arm/include/uapi/asm/swab.h \
  include/linux/byteorder/generic.h \
  lib/../scripts/dtc/libfdt/fdt_sw.c \
  lib/../scripts/dtc/libfdt/libfdt_env.h \
  scripts/dtc/libfdt/fdt.h \
  scripts/dtc/libfdt/libfdt.h \
  scripts/dtc/libfdt/libfdt_env.h \
  scripts/dtc/libfdt/fdt.h \
  lib/../scripts/dtc/libfdt/libfdt_internal.h \

drivers/firmware/efi/libstub/lib-fdt_sw.o: $(deps_drivers/firmware/efi/libstub/lib-fdt_sw.o)

$(deps_drivers/firmware/efi/libstub/lib-fdt_sw.o):
