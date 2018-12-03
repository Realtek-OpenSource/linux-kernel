#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x88b338af, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa120d33c, __VMLINUX_SYMBOL_STR(tty_unregister_ldisc) },
	{ 0x9247cf41, __VMLINUX_SYMBOL_STR(tty_register_ldisc) },
	{ 0x526c3a6c, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x13cfc419, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x97d68d30, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x992d3709, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xffb8e290, __VMLINUX_SYMBOL_STR(tty_unthrottle) },
	{ 0x51d559d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x230ea606, __VMLINUX_SYMBOL_STR(skb_queue_tail) },
	{ 0xfa818705, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0xaf5f8109, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0x598542b2, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x4059792f, __VMLINUX_SYMBOL_STR(print_hex_dump) },
	{ 0x5fb9611e, __VMLINUX_SYMBOL_STR(ppp_register_channel) },
	{ 0x409873e3, __VMLINUX_SYMBOL_STR(tty_termios_baud_rate) },
	{ 0x275ef902, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x54e379d3, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x6903ad6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x60554702, __VMLINUX_SYMBOL_STR(ppp_input) },
	{ 0xa4b43504, __VMLINUX_SYMBOL_STR(ppp_input_error) },
	{ 0x8284a4c2, __VMLINUX_SYMBOL_STR(skb_dequeue) },
	{ 0x96193a6b, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x2a3aa678, __VMLINUX_SYMBOL_STR(_test_and_clear_bit) },
	{ 0xcff6b676, __VMLINUX_SYMBOL_STR(_raw_spin_trylock_bh) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0x1a1431fd, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irq) },
	{ 0x3507a132, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x353e3fa5, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x1fab5905, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x8f280cd7, __VMLINUX_SYMBOL_STR(skb_queue_purge) },
	{ 0xb98ce6a6, __VMLINUX_SYMBOL_STR(ppp_unregister_channel) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x740fd118, __VMLINUX_SYMBOL_STR(_raw_write_unlock_irq) },
	{ 0xb5c00014, __VMLINUX_SYMBOL_STR(_raw_write_lock_irq) },
	{ 0xc60c8184, __VMLINUX_SYMBOL_STR(ppp_output_wakeup) },
	{ 0xdd3916ac, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0x5df57a3f, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0xa1d55e90, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x2fa2bf38, __VMLINUX_SYMBOL_STR(ppp_channel_index) },
	{ 0xca4ab4ce, __VMLINUX_SYMBOL_STR(tty_mode_ioctl) },
	{ 0xb3d92e3e, __VMLINUX_SYMBOL_STR(n_tty_ioctl_helper) },
	{ 0xbc10dd97, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0x57f4127, __VMLINUX_SYMBOL_STR(ppp_unit_number) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0xd4669fad, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x4bc9fa80, __VMLINUX_SYMBOL_STR(_raw_read_unlock) },
	{ 0xb5198b77, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

