	.cpu cortex-a53
	.eabi_attribute 20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute 21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute 23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute 24, 1	@ Tag_ABI_align8_needed
	.eabi_attribute 25, 1	@ Tag_ABI_align8_preserved
	.eabi_attribute 26, 2	@ Tag_ABI_enum_size
	.eabi_attribute 30, 2	@ Tag_ABI_optimization_goals
	.eabi_attribute 34, 1	@ Tag_CPU_unaligned_access
	.eabi_attribute 18, 4	@ Tag_ABI_PCS_wchar_t
	.file	"bounds.c"
@ GNU C89 (Realtek ASDK-6.4.1 Build 2778) version 6.4.1 20180307 (arm-linux-gnueabi)
@	compiled by GNU C version 5.4.0, GMP version 4.3.2, MPFR version 2.4.2, MPC version 0.8.2, isl version none
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -nostdinc -I ./arch/arm/include
@ -I ./arch/arm/include/generated/uapi -I ./arch/arm/include/generated
@ -I ./include -I ./arch/arm/include/uapi -I ./include/uapi
@ -I ./include/generated/uapi -I arch/arm/mach-rtd16xx/include
@ -imultilib v8-a/simdv8/softfp
@ -iprefix /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831/bin/../lib/gcc/arm-linux-gnueabi/6.4.1/
@ -isysroot /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831//arm-linux-gnueabi
@ -mlittle-endian -D __KERNEL__ -D __LINUX_ARM_ARCH__=7 -U arm
@ -D CC_HAVE_ASM_GOTO -D KBUILD_BASENAME="bounds"
@ -D KBUILD_MODNAME="bounds"
@ -isystem /home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/phoenix/toolchain/asdk-6.4.1-a53-EL-4.9-g2.26-a32nut-180831/bin/../lib/gcc/arm-linux-gnueabi/6.4.1/include
@ -include ./include/linux/kconfig.h -MD kernel/.bounds.s.d kernel/bounds.c
@ -mfpu=neon-fp-armv8 -mfloat-abi=softfp -mtune=cortex-a53 -mlittle-endian
@ -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp
@ -marm -march=armv8-a -mfloat-abi=soft -mtls-dialect=gnu
@ -auxbase-strip kernel/bounds.s -g -O2 -Wall -Wundef -Wstrict-prototypes
@ -Wno-trigraphs -Werror=implicit-function-declaration -Wno-format-security
@ -Wno-frame-address -Wframe-larger-than=1024 -Wno-unused-but-set-variable
@ -Wunused-const-variable=0 -Wdeclaration-after-statement -Wno-pointer-sign
@ -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time
@ -Werror=incompatible-pointer-types -std=gnu90 -p -fno-strict-aliasing
@ -fno-common -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -funwind-tables
@ -fno-delete-null-pointer-checks -fstack-protector-strong
@ -fno-omit-frame-pointer -fno-optimize-sibling-calls
@ -fno-var-tracking-assignments -fno-strict-overflow
@ -fno-merge-all-constants -fmerge-constants -fstack-check=no
@ -fconserve-stack -fverbose-asm --param allow-store-data-races=0
@ options enabled:  -faggressive-loop-optimizations -falign-jumps
@ -falign-labels -falign-loops -fauto-inc-dec -fbranch-count-reg
@ -fcaller-saves -fchkp-check-incomplete-type -fchkp-check-read
@ -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
@ -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
@ -fchkp-use-static-const-bounds -fchkp-use-wrappers
@ -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
@ -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdevirtualize
@ -fdevirtualize-speculatively -fearly-inlining
@ -feliminate-unused-debug-types -fexpensive-optimizations
@ -fforward-propagate -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
@ -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
@ -fif-conversion -fif-conversion2 -findirect-inlining -finline
@ -finline-atomics -finline-functions-called-once -finline-small-functions
@ -fipa-cp -fipa-cp-alignment -fipa-icf -fipa-icf-functions
@ -fipa-icf-variables -fipa-profile -fipa-pure-const -fipa-reference
@ -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
@ -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
@ -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
@ -fmath-errno -fmerge-constants -fmerge-debug-strings
@ -fmove-loop-invariants -foptimize-strlen -fpartial-inlining -fpeephole
@ -fpeephole2 -fplt -fprefetch-loop-arrays -fprofile -freg-struct-return
@ -freorder-blocks -freorder-functions -frerun-cse-after-loop
@ -fsched-critical-path-heuristic -fsched-dep-count-heuristic
@ -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
@ -fsched-pressure -fsched-rank-heuristic -fsched-spec
@ -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-insns
@ -fschedule-insns2 -fsection-anchors -fsemantic-interposition
@ -fshow-column -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
@ -fssa-backprop -fssa-phiopt -fstack-protector-strong -fstdarg-opt
@ -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
@ -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
@ -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
@ -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
@ -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
@ -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
@ -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
@ -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
@ -ftree-vrp -funit-at-a-time -funwind-tables -fuse-tls -fuse-uls
@ -fvar-tracking -fverbose-asm -fzero-initialized-in-bss -mapcs-frame -marm
@ -mglibc -mlittle-endian -mpic-data-is-text-relative -munaligned-access
@ -mvectorize-with-neon-quad

	.text
.Ltext0:
	.align	2
	.global	foo
	.syntax unified
	.arm
	.fpu softvfp
	.type	foo, %function
foo:
	.fnstart
.LFB139:
	.file 1 "kernel/bounds.c"
	.loc 1 16 0
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	.movsp ip
	mov	ip, sp	@,
.LCFI0:
	push	{fp, ip, lr, pc}	@
	.pad #4
	.save {fp, ip, lr}
.LCFI1:
	.setfp fp, ip, #-4
	sub	fp, ip, #4	@,,
.LCFI2:
	push	{lr}
	bl	__gnu_mcount_nc
	.loc 1 16 0
	.loc 1 18 0
	.syntax divided
@ 18 "kernel/bounds.c" 1
	
.ascii "->NR_PAGEFLAGS #21 __NR_PAGEFLAGS"	@
@ 0 "" 2
	.loc 1 19 0
@ 19 "kernel/bounds.c" 1
	
.ascii "->MAX_NR_ZONES #4 __MAX_NR_ZONES"	@
@ 0 "" 2
	.loc 1 21 0
@ 21 "kernel/bounds.c" 1
	
.ascii "->NR_CPUS_BITS #2 ilog2(CONFIG_NR_CPUS)"	@
@ 0 "" 2
	.loc 1 23 0
@ 23 "kernel/bounds.c" 1
	
.ascii "->SPINLOCK_SIZE #4 sizeof(spinlock_t)"	@
@ 0 "" 2
	.arm
	.syntax unified
	ldmfd	sp, {fp, sp, pc}	@
.LFE139:
	.fnend
	.size	foo, .-foo
	.section	.debug_frame,"",%progbits
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x3
	.ascii	"\000"
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0xe
	.byte	0xc
	.uleb128 0xd
	.uleb128 0
	.align	2
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB139
	.4byte	.LFE139-.LFB139
	.byte	0x4
	.4byte	.LCFI0-.LFB139
	.byte	0xd
	.uleb128 0xc
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0x8b
	.uleb128 0x4
	.byte	0x8d
	.uleb128 0x3
	.byte	0x8e
	.uleb128 0x2
	.byte	0x4
	.4byte	.LCFI2-.LCFI1
	.byte	0xc
	.uleb128 0xb
	.uleb128 0x4
	.align	2
.LEFDE0:
	.text
.Letext0:
	.file 2 "./include/linux/types.h"
	.file 3 "./arch/arm/include/asm/hwcap.h"
	.file 4 "./include/linux/init.h"
	.file 5 "./include/linux/printk.h"
	.file 6 "./include/linux/kernel.h"
	.file 7 "./include/linux/page-flags.h"
	.file 8 "./include/linux/mmzone.h"
	.file 9 "./include/linux/lockdep.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x41a
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF99
	.byte	0x1
	.4byte	.LASF100
	.4byte	.LASF101
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF9
	.uleb128 0x4
	.4byte	0x6b
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF10
	.uleb128 0x5
	.byte	0x4
	.4byte	0x6b
	.uleb128 0x6
	.4byte	.LASF12
	.byte	0x2
	.byte	0x1d
	.4byte	0x8f
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	.LASF11
	.uleb128 0x7
	.byte	0x4
	.byte	0x2
	.byte	0xae
	.4byte	0xab
	.uleb128 0x8
	.4byte	.LASF102
	.byte	0x2
	.byte	0xaf
	.4byte	0x41
	.byte	0
	.byte	0
	.uleb128 0x6
	.4byte	.LASF13
	.byte	0x2
	.byte	0xb0
	.4byte	0x96
	.uleb128 0x9
	.4byte	.LASF14
	.byte	0x3
	.byte	0xd
	.4byte	0x48
	.uleb128 0x9
	.4byte	.LASF15
	.byte	0x3
	.byte	0xd
	.4byte	0x48
	.uleb128 0x6
	.4byte	.LASF16
	.byte	0x4
	.byte	0x73
	.4byte	0xd7
	.uleb128 0x5
	.byte	0x4
	.4byte	0xdd
	.uleb128 0xa
	.4byte	0x41
	.uleb128 0x5
	.byte	0x4
	.4byte	0xe8
	.uleb128 0xb
	.uleb128 0xc
	.4byte	0xcc
	.4byte	0xf4
	.uleb128 0xd
	.byte	0
	.uleb128 0x9
	.4byte	.LASF17
	.byte	0x4
	.byte	0x76
	.4byte	0xe9
	.uleb128 0x9
	.4byte	.LASF18
	.byte	0x4
	.byte	0x76
	.4byte	0xe9
	.uleb128 0x9
	.4byte	.LASF19
	.byte	0x4
	.byte	0x77
	.4byte	0xe9
	.uleb128 0x9
	.4byte	.LASF20
	.byte	0x4
	.byte	0x77
	.4byte	0xe9
	.uleb128 0xc
	.4byte	0x6b
	.4byte	0x12b
	.uleb128 0xd
	.byte	0
	.uleb128 0x9
	.4byte	.LASF21
	.byte	0x4
	.byte	0x7e
	.4byte	0x120
	.uleb128 0x9
	.4byte	.LASF22
	.byte	0x4
	.byte	0x7f
	.4byte	0x7e
	.uleb128 0x9
	.4byte	.LASF23
	.byte	0x4
	.byte	0x80
	.4byte	0x48
	.uleb128 0x9
	.4byte	.LASF24
	.byte	0x4
	.byte	0x89
	.4byte	0x84
	.uleb128 0x9
	.4byte	.LASF25
	.byte	0x4
	.byte	0x8f
	.4byte	0xe2
	.uleb128 0x9
	.4byte	.LASF26
	.byte	0x4
	.byte	0x91
	.4byte	0x84
	.uleb128 0xc
	.4byte	0x72
	.4byte	0x178
	.uleb128 0xd
	.byte	0
	.uleb128 0x4
	.4byte	0x16d
	.uleb128 0x9
	.4byte	.LASF27
	.byte	0x5
	.byte	0xa
	.4byte	0x178
	.uleb128 0x9
	.4byte	.LASF28
	.byte	0x5
	.byte	0xb
	.4byte	0x178
	.uleb128 0xc
	.4byte	0x41
	.4byte	0x19e
	.uleb128 0xd
	.byte	0
	.uleb128 0x9
	.4byte	.LASF29
	.byte	0x5
	.byte	0x2f
	.4byte	0x193
	.uleb128 0x9
	.4byte	.LASF30
	.byte	0x5
	.byte	0x43
	.4byte	0x120
	.uleb128 0x9
	.4byte	.LASF31
	.byte	0x5
	.byte	0xb4
	.4byte	0x41
	.uleb128 0x9
	.4byte	.LASF32
	.byte	0x5
	.byte	0xb5
	.4byte	0x41
	.uleb128 0x9
	.4byte	.LASF33
	.byte	0x5
	.byte	0xb6
	.4byte	0x41
	.uleb128 0xe
	.4byte	.LASF35
	.uleb128 0x4
	.4byte	0x1d5
	.uleb128 0xf
	.4byte	.LASF34
	.byte	0x5
	.2byte	0x1c2
	.4byte	0x1da
	.uleb128 0xe
	.4byte	.LASF36
	.uleb128 0xf
	.4byte	.LASF37
	.byte	0x6
	.2byte	0x104
	.4byte	0x1eb
	.uleb128 0x10
	.4byte	0x77
	.4byte	0x20b
	.uleb128 0x11
	.4byte	0x41
	.byte	0
	.uleb128 0xf
	.4byte	.LASF38
	.byte	0x6
	.2byte	0x105
	.4byte	0x217
	.uleb128 0x5
	.byte	0x4
	.4byte	0x1fc
	.uleb128 0xf
	.4byte	.LASF39
	.byte	0x6
	.2byte	0x1bd
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF40
	.byte	0x6
	.2byte	0x1be
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF41
	.byte	0x6
	.2byte	0x1bf
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF42
	.byte	0x6
	.2byte	0x1c0
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF43
	.byte	0x6
	.2byte	0x1c1
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF44
	.byte	0x6
	.2byte	0x1c2
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF45
	.byte	0x6
	.2byte	0x1c3
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF46
	.byte	0x6
	.2byte	0x1c4
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF47
	.byte	0x6
	.2byte	0x1c6
	.4byte	0x84
	.uleb128 0xf
	.4byte	.LASF48
	.byte	0x6
	.2byte	0x1cd
	.4byte	0xab
	.uleb128 0xf
	.4byte	.LASF49
	.byte	0x6
	.2byte	0x1e1
	.4byte	0x41
	.uleb128 0xf
	.4byte	.LASF50
	.byte	0x6
	.2byte	0x1e3
	.4byte	0x84
	.uleb128 0x12
	.4byte	.LASF59
	.byte	0x4
	.4byte	0x48
	.byte	0x6
	.2byte	0x1e6
	.4byte	0x2dd
	.uleb128 0x13
	.4byte	.LASF51
	.byte	0
	.uleb128 0x13
	.4byte	.LASF52
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF53
	.byte	0x2
	.uleb128 0x13
	.4byte	.LASF54
	.byte	0x3
	.uleb128 0x13
	.4byte	.LASF55
	.byte	0x4
	.byte	0
	.uleb128 0xf
	.4byte	.LASF56
	.byte	0x6
	.2byte	0x1ec
	.4byte	0x2ad
	.uleb128 0xf
	.4byte	.LASF57
	.byte	0x6
	.2byte	0x1ff
	.4byte	0x178
	.uleb128 0xf
	.4byte	.LASF58
	.byte	0x6
	.2byte	0x20a
	.4byte	0x178
	.uleb128 0x14
	.4byte	.LASF60
	.byte	0x4
	.4byte	0x48
	.byte	0x7
	.byte	0x4a
	.4byte	0x3c6
	.uleb128 0x13
	.4byte	.LASF61
	.byte	0
	.uleb128 0x13
	.4byte	.LASF62
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF63
	.byte	0x2
	.uleb128 0x13
	.4byte	.LASF64
	.byte	0x3
	.uleb128 0x13
	.4byte	.LASF65
	.byte	0x4
	.uleb128 0x13
	.4byte	.LASF66
	.byte	0x5
	.uleb128 0x13
	.4byte	.LASF67
	.byte	0x6
	.uleb128 0x13
	.4byte	.LASF68
	.byte	0x7
	.uleb128 0x13
	.4byte	.LASF69
	.byte	0x8
	.uleb128 0x13
	.4byte	.LASF70
	.byte	0x9
	.uleb128 0x13
	.4byte	.LASF71
	.byte	0xa
	.uleb128 0x13
	.4byte	.LASF72
	.byte	0xb
	.uleb128 0x13
	.4byte	.LASF73
	.byte	0xc
	.uleb128 0x13
	.4byte	.LASF74
	.byte	0xd
	.uleb128 0x13
	.4byte	.LASF75
	.byte	0xe
	.uleb128 0x13
	.4byte	.LASF76
	.byte	0xf
	.uleb128 0x13
	.4byte	.LASF77
	.byte	0x10
	.uleb128 0x13
	.4byte	.LASF78
	.byte	0x11
	.uleb128 0x13
	.4byte	.LASF79
	.byte	0x12
	.uleb128 0x13
	.4byte	.LASF80
	.byte	0x13
	.uleb128 0x13
	.4byte	.LASF81
	.byte	0x14
	.uleb128 0x13
	.4byte	.LASF82
	.byte	0x15
	.uleb128 0x13
	.4byte	.LASF83
	.byte	0x8
	.uleb128 0x13
	.4byte	.LASF84
	.byte	0xc
	.uleb128 0x13
	.4byte	.LASF85
	.byte	0x8
	.uleb128 0x13
	.4byte	.LASF86
	.byte	0x4
	.uleb128 0x13
	.4byte	.LASF87
	.byte	0x8
	.uleb128 0x13
	.4byte	.LASF88
	.byte	0xb
	.uleb128 0x13
	.4byte	.LASF89
	.byte	0xc
	.uleb128 0x13
	.4byte	.LASF90
	.byte	0x11
	.byte	0
	.uleb128 0x12
	.4byte	.LASF91
	.byte	0x4
	.4byte	0x48
	.byte	0x8
	.2byte	0x122
	.4byte	0x3f6
	.uleb128 0x13
	.4byte	.LASF92
	.byte	0
	.uleb128 0x13
	.4byte	.LASF93
	.byte	0x1
	.uleb128 0x13
	.4byte	.LASF94
	.byte	0x2
	.uleb128 0x13
	.4byte	.LASF95
	.byte	0x3
	.uleb128 0x13
	.4byte	.LASF96
	.byte	0x4
	.byte	0
	.uleb128 0x9
	.4byte	.LASF97
	.byte	0x9
	.byte	0x10
	.4byte	0x41
	.uleb128 0x9
	.4byte	.LASF98
	.byte	0x9
	.byte	0x11
	.4byte	0x41
	.uleb128 0x15
	.ascii	"foo\000"
	.byte	0x1
	.byte	0xf
	.4byte	.LFB139
	.4byte	.LFE139-.LFB139
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF83:
	.ascii	"PG_checked\000"
.LASF91:
	.ascii	"zone_type\000"
.LASF34:
	.ascii	"kmsg_fops\000"
.LASF58:
	.ascii	"hex_asc_upper\000"
.LASF27:
	.ascii	"linux_banner\000"
.LASF42:
	.ascii	"panic_on_unrecovered_nmi\000"
.LASF6:
	.ascii	"long long unsigned int\000"
.LASF55:
	.ascii	"SYSTEM_RESTART\000"
.LASF38:
	.ascii	"panic_blink\000"
.LASF53:
	.ascii	"SYSTEM_HALT\000"
.LASF82:
	.ascii	"__NR_PAGEFLAGS\000"
.LASF5:
	.ascii	"long long int\000"
.LASF0:
	.ascii	"signed char\000"
.LASF20:
	.ascii	"__security_initcall_end\000"
.LASF22:
	.ascii	"saved_command_line\000"
.LASF45:
	.ascii	"sysctl_panic_on_rcu_stall\000"
.LASF73:
	.ascii	"PG_private_2\000"
.LASF51:
	.ascii	"SYSTEM_BOOTING\000"
.LASF60:
	.ascii	"pageflags\000"
.LASF100:
	.ascii	"kernel/bounds.c\000"
.LASF10:
	.ascii	"long int\000"
.LASF44:
	.ascii	"panic_on_warn\000"
.LASF70:
	.ascii	"PG_arch_1\000"
.LASF48:
	.ascii	"panic_cpu\000"
.LASF28:
	.ascii	"linux_proc_banner\000"
.LASF47:
	.ascii	"crash_kexec_post_notifiers\000"
.LASF61:
	.ascii	"PG_locked\000"
.LASF66:
	.ascii	"PG_lru\000"
.LASF63:
	.ascii	"PG_referenced\000"
.LASF16:
	.ascii	"initcall_t\000"
.LASF35:
	.ascii	"file_operations\000"
.LASF90:
	.ascii	"PG_isolated\000"
.LASF4:
	.ascii	"unsigned int\000"
.LASF72:
	.ascii	"PG_private\000"
.LASF49:
	.ascii	"root_mountflags\000"
.LASF7:
	.ascii	"long unsigned int\000"
.LASF33:
	.ascii	"kptr_restrict\000"
.LASF36:
	.ascii	"atomic_notifier_head\000"
.LASF29:
	.ascii	"console_printk\000"
.LASF52:
	.ascii	"SYSTEM_RUNNING\000"
.LASF3:
	.ascii	"short unsigned int\000"
.LASF24:
	.ascii	"rodata_enabled\000"
.LASF12:
	.ascii	"bool\000"
.LASF86:
	.ascii	"PG_savepinned\000"
.LASF32:
	.ascii	"dmesg_restrict\000"
.LASF18:
	.ascii	"__con_initcall_end\000"
.LASF97:
	.ascii	"prove_locking\000"
.LASF78:
	.ascii	"PG_reclaim\000"
.LASF62:
	.ascii	"PG_error\000"
.LASF8:
	.ascii	"sizetype\000"
.LASF85:
	.ascii	"PG_pinned\000"
.LASF46:
	.ascii	"sysctl_panic_on_stackoverflow\000"
.LASF23:
	.ascii	"reset_devices\000"
.LASF56:
	.ascii	"system_state\000"
.LASF74:
	.ascii	"PG_writeback\000"
.LASF98:
	.ascii	"lock_stat\000"
.LASF81:
	.ascii	"PG_mlocked\000"
.LASF40:
	.ascii	"panic_timeout\000"
.LASF89:
	.ascii	"PG_double_map\000"
.LASF95:
	.ascii	"ZONE_MOVABLE\000"
.LASF19:
	.ascii	"__security_initcall_start\000"
.LASF101:
	.ascii	"/home1/Kay/SDK_release/1619/181123/trunk-9.0/trunk-"
	.ascii	"9.0_Mjolnir_181123_SQA_Dailybuild_AOSP/linux-kernel"
	.ascii	"\000"
.LASF37:
	.ascii	"panic_notifier_list\000"
.LASF77:
	.ascii	"PG_mappedtodisk\000"
.LASF15:
	.ascii	"elf_hwcap2\000"
.LASF93:
	.ascii	"ZONE_NORMAL\000"
.LASF64:
	.ascii	"PG_uptodate\000"
.LASF11:
	.ascii	"_Bool\000"
.LASF1:
	.ascii	"unsigned char\000"
.LASF59:
	.ascii	"system_states\000"
.LASF76:
	.ascii	"PG_swapcache\000"
.LASF26:
	.ascii	"initcall_debug\000"
.LASF2:
	.ascii	"short int\000"
.LASF102:
	.ascii	"counter\000"
.LASF68:
	.ascii	"PG_slab\000"
.LASF96:
	.ascii	"__MAX_NR_ZONES\000"
.LASF94:
	.ascii	"ZONE_HIGHMEM\000"
.LASF65:
	.ascii	"PG_dirty\000"
.LASF54:
	.ascii	"SYSTEM_POWER_OFF\000"
.LASF39:
	.ascii	"oops_in_progress\000"
.LASF9:
	.ascii	"char\000"
.LASF13:
	.ascii	"atomic_t\000"
.LASF75:
	.ascii	"PG_head\000"
.LASF88:
	.ascii	"PG_slob_free\000"
.LASF80:
	.ascii	"PG_unevictable\000"
.LASF41:
	.ascii	"panic_on_oops\000"
.LASF21:
	.ascii	"boot_command_line\000"
.LASF69:
	.ascii	"PG_owner_priv_1\000"
.LASF31:
	.ascii	"printk_delay_msec\000"
.LASF50:
	.ascii	"early_boot_irqs_disabled\000"
.LASF43:
	.ascii	"panic_on_io_nmi\000"
.LASF71:
	.ascii	"PG_reserved\000"
.LASF14:
	.ascii	"elf_hwcap\000"
.LASF67:
	.ascii	"PG_active\000"
.LASF57:
	.ascii	"hex_asc\000"
.LASF84:
	.ascii	"PG_fscache\000"
.LASF87:
	.ascii	"PG_foreign\000"
.LASF17:
	.ascii	"__con_initcall_start\000"
.LASF25:
	.ascii	"late_time_init\000"
.LASF79:
	.ascii	"PG_swapbacked\000"
.LASF99:
	.ascii	"GNU C89 6.4.1 20180307 -mlittle-endian -mfpu=neon-f"
	.ascii	"p-armv8 -mfloat-abi=softfp -mtune=cortex-a53 -mlitt"
	.ascii	"le-endian -mapcs -mno-sched-prolog -mabi=aapcs-linu"
	.ascii	"x -mno-thumb-interwork -mfpu=vfp -marm -march=armv8"
	.ascii	"-a -mfloat-abi=soft -mtls-dialect=gnu -g -O2 -std=g"
	.ascii	"nu90 -p -fno-strict-aliasing -fno-common -fno-PIE -"
	.ascii	"fno-dwarf2-cfi-asm -fno-ipa-sra -funwind-tables -fn"
	.ascii	"o-delete-null-pointer-checks -fstack-protector-stro"
	.ascii	"ng -fno-omit-frame-pointer -fno-optimize-sibling-ca"
	.ascii	"lls -fno-var-tracking-assignments -fno-strict-overf"
	.ascii	"low -fno-merge-all-constants -fmerge-constants -fst"
	.ascii	"ack-check=no -fconserve-stack --param allow-store-d"
	.ascii	"ata-races=0\000"
.LASF92:
	.ascii	"ZONE_DMA\000"
.LASF30:
	.ascii	"devkmsg_log_str\000"
	.ident	"GCC: (Realtek ASDK-6.4.1 Build 2778) 6.4.1 20180307"
	.section	.note.GNU-stack,"",%progbits
