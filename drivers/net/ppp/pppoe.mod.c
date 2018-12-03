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
	{ 0x18cf4c14, __VMLINUX_SYMBOL_STR(seq_release_net) },
	{ 0x2ba6de6, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x53fe9898, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xee0ec1a9, __VMLINUX_SYMBOL_STR(sock_no_mmap) },
	{ 0x23c59087, __VMLINUX_SYMBOL_STR(sock_no_getsockopt) },
	{ 0x77da72ca, __VMLINUX_SYMBOL_STR(sock_no_setsockopt) },
	{ 0x687f42a5, __VMLINUX_SYMBOL_STR(sock_no_shutdown) },
	{ 0x6c6390e6, __VMLINUX_SYMBOL_STR(sock_no_listen) },
	{ 0x14ca634c, __VMLINUX_SYMBOL_STR(pppox_ioctl) },
	{ 0x4c682e00, __VMLINUX_SYMBOL_STR(datagram_poll) },
	{ 0x80974ee3, __VMLINUX_SYMBOL_STR(sock_no_accept) },
	{ 0x8ffb5999, __VMLINUX_SYMBOL_STR(sock_no_socketpair) },
	{ 0xd17a77c5, __VMLINUX_SYMBOL_STR(sock_no_bind) },
	{ 0xe0ff7a18, __VMLINUX_SYMBOL_STR(unregister_pppox_proto) },
	{ 0xa5792410, __VMLINUX_SYMBOL_STR(dev_remove_pack) },
	{ 0x9d0d6206, __VMLINUX_SYMBOL_STR(unregister_netdevice_notifier) },
	{ 0xdc086d9c, __VMLINUX_SYMBOL_STR(unregister_pernet_device) },
	{ 0x59d8fb5b, __VMLINUX_SYMBOL_STR(proto_unregister) },
	{ 0xd2da1048, __VMLINUX_SYMBOL_STR(register_netdevice_notifier) },
	{ 0xda534841, __VMLINUX_SYMBOL_STR(dev_add_pack) },
	{ 0xf73615ac, __VMLINUX_SYMBOL_STR(register_pppox_proto) },
	{ 0x50f09d55, __VMLINUX_SYMBOL_STR(proto_register) },
	{ 0x983e78ac, __VMLINUX_SYMBOL_STR(register_pernet_device) },
	{ 0xe352793e, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x4878a7f5, __VMLINUX_SYMBOL_STR(seq_puts) },
	{ 0xb0cda3ea, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x334f2d94, __VMLINUX_SYMBOL_STR(seq_open_net) },
	{ 0x71f78756, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x8f280cd7, __VMLINUX_SYMBOL_STR(skb_queue_purge) },
	{ 0x1d1d7076, __VMLINUX_SYMBOL_STR(ppp_register_net_channel) },
	{ 0x7e29aa57, __VMLINUX_SYMBOL_STR(dev_get_by_name) },
	{ 0xacf93a35, __VMLINUX_SYMBOL_STR(copy_from_iter) },
	{ 0x992d3709, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xfb78b078, __VMLINUX_SYMBOL_STR(sock_wmalloc) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x7b413e7a, __VMLINUX_SYMBOL_STR(skb_copy_datagram_iter) },
	{ 0x8097b07a, __VMLINUX_SYMBOL_STR(skb_recv_datagram) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x60554702, __VMLINUX_SYMBOL_STR(ppp_input) },
	{ 0x6b8e0888, __VMLINUX_SYMBOL_STR(sock_queue_rcv_skb) },
	{ 0xd4a3026d, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0x32af9d95, __VMLINUX_SYMBOL_STR(dev_queue_xmit) },
	{ 0x68510027, __VMLINUX_SYMBOL_STR(sock_init_data) },
	{ 0x4b8a201b, __VMLINUX_SYMBOL_STR(sk_alloc) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xb2090564, __VMLINUX_SYMBOL_STR(dev_get_by_name_rcu) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0xbc10dd97, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0x353e3fa5, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x46f140e, __VMLINUX_SYMBOL_STR(___pskb_trim) },
	{ 0x2d9599b9, __VMLINUX_SYMBOL_STR(__sk_receive_skb) },
	{ 0x7d6fef0e, __VMLINUX_SYMBOL_STR(skb_pull_rcsum) },
	{ 0xc41ac9b6, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x4c233a44, __VMLINUX_SYMBOL_STR(_raw_read_unlock_bh) },
	{ 0x4c5fc58c, __VMLINUX_SYMBOL_STR(_raw_read_lock_bh) },
	{ 0x5df57a3f, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x96193a6b, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x333ed2ce, __VMLINUX_SYMBOL_STR(skb_clone) },
	{ 0xc0056be5, __VMLINUX_SYMBOL_STR(_raw_write_unlock_bh) },
	{ 0x6ec9ccdb, __VMLINUX_SYMBOL_STR(_raw_write_lock_bh) },
	{ 0x2469810f, __VMLINUX_SYMBOL_STR(__rcu_read_unlock) },
	{ 0x8d522714, __VMLINUX_SYMBOL_STR(__rcu_read_lock) },
	{ 0x84c0e309, __VMLINUX_SYMBOL_STR(sk_free) },
	{ 0x166d3770, __VMLINUX_SYMBOL_STR(release_sock) },
	{ 0x2a60ad5, __VMLINUX_SYMBOL_STR(pppox_unbind_sock) },
	{ 0x374caf35, __VMLINUX_SYMBOL_STR(lock_sock_nested) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

