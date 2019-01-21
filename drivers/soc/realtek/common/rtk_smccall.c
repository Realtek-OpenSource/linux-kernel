#include <linux/compiler.h>

notrace unsigned long rtk_smc(unsigned long cmd, unsigned long arg0, unsigned long arg1)
{
	unsigned long ret;

#if defined(CONFIG_CPU_V7)
	asm volatile(
		".arch_extension sec\n\t"
		"mov r0, %1\n\t"
		"mov r1, %2\n\t"
		"mov r2, %3\n\t"
		"isb\n\t"
		"smc #0\n\t"
		"isb\n\t"
		"mov %0, r0"
		: "=r"(ret)
		: "r"(cmd), "r"(arg0), "r" (arg1)
		: "cc", "r0", "r1", "r2");
#else
	asm volatile(
		"mov x0, %1\n\t"
		"mov x1, %2\n\t"
		"mov x2, %3\n\t"
		"isb\n\t"
		"smc #0\n\t"
		"isb\n\t"
		"mov %0, x0"
		: "=r"(ret)
		: "r"(cmd), "r"(arg0), "r" (arg1)
		: "cc", "x0", "x1", "x2");
#endif
	return ret;
}


