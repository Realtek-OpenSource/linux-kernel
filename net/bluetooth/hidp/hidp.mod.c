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
	{ 0x790d7d8c, __VMLINUX_SYMBOL_STR(skb_queue_head) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xc247d075, __VMLINUX_SYMBOL_STR(hid_add_device) },
	{ 0x6903ad6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x68510027, __VMLINUX_SYMBOL_STR(sock_init_data) },
	{ 0x4f6b37ad, __VMLINUX_SYMBOL_STR(hid_ignore) },
	{ 0xf1f8fbb8, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x7622f5c0, __VMLINUX_SYMBOL_STR(kernel_sendmsg) },
	{ 0x5a6e5404, __VMLINUX_SYMBOL_STR(sockfd_lookup) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xb8eec98b, __VMLINUX_SYMBOL_STR(del_timer) },
	{ 0x77da72ca, __VMLINUX_SYMBOL_STR(sock_no_setsockopt) },
	{ 0x238bb51c, __VMLINUX_SYMBOL_STR(hid_parse_report) },
	{ 0x23c59087, __VMLINUX_SYMBOL_STR(sock_no_getsockopt) },
	{ 0x4c86184b, __VMLINUX_SYMBOL_STR(remove_wait_queue) },
	{ 0x1829d188, __VMLINUX_SYMBOL_STR(wait_woken) },
	{ 0x2a3aa678, __VMLINUX_SYMBOL_STR(_test_and_clear_bit) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x37ab1ecc, __VMLINUX_SYMBOL_STR(sock_no_getname) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
	{ 0x8fdf772a, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0x8e9b68fd, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x3b817141, __VMLINUX_SYMBOL_STR(bt_sock_register) },
	{ 0xeb5ec64c, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xddd3f80c, __VMLINUX_SYMBOL_STR(sock_no_poll) },
	{ 0x526c3a6c, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xd59e7a95, __VMLINUX_SYMBOL_STR(hid_input_report) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0xd55a5183, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0x47022514, __VMLINUX_SYMBOL_STR(bt_err) },
	{ 0xd7442057, __VMLINUX_SYMBOL_STR(bt_info) },
	{ 0xc41ac9b6, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0xe4b83260, __VMLINUX_SYMBOL_STR(input_event) },
	{ 0x275ef902, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xee0ec1a9, __VMLINUX_SYMBOL_STR(sock_no_mmap) },
	{ 0x6c11856b, __VMLINUX_SYMBOL_STR(sock_no_recvmsg) },
	{ 0xd125aa75, __VMLINUX_SYMBOL_STR(bt_sock_unlink) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x8f280cd7, __VMLINUX_SYMBOL_STR(skb_queue_purge) },
	{ 0x8ffb5999, __VMLINUX_SYMBOL_STR(sock_no_socketpair) },
	{ 0xce144b18, __VMLINUX_SYMBOL_STR(l2cap_conn_put) },
	{ 0x4b8a201b, __VMLINUX_SYMBOL_STR(sk_alloc) },
	{ 0x1cfa1d6d, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0xa87ec259, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x5f0fe8fd, __VMLINUX_SYMBOL_STR(l2cap_is_socket) },
	{ 0xd17a77c5, __VMLINUX_SYMBOL_STR(sock_no_bind) },
	{ 0x71c90087, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x328a05f1, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x6c6390e6, __VMLINUX_SYMBOL_STR(sock_no_listen) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x6f29956c, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x80974ee3, __VMLINUX_SYMBOL_STR(sock_no_accept) },
	{ 0x84c0e309, __VMLINUX_SYMBOL_STR(sk_free) },
	{ 0xfa5bcf35, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x8fea24bd, __VMLINUX_SYMBOL_STR(bt_sock_unregister) },
	{ 0x13cfc419, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0xeea77a2f, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x67e0d5fa, __VMLINUX_SYMBOL_STR(init_net) },
	{ 0x5f8831a1, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0xba5db3fa, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x622598b1, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0x687f42a5, __VMLINUX_SYMBOL_STR(sock_no_shutdown) },
	{ 0x5ac5f4a8, __VMLINUX_SYMBOL_STR(bt_sock_link) },
	{ 0x230ea606, __VMLINUX_SYMBOL_STR(skb_queue_tail) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0xa6ffec60, __VMLINUX_SYMBOL_STR(woken_wake_function) },
	{ 0x50f09d55, __VMLINUX_SYMBOL_STR(proto_register) },
	{ 0x4def3418, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0x7c7efd02, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xadd723b4, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x5df57a3f, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x59d8fb5b, __VMLINUX_SYMBOL_STR(proto_unregister) },
	{ 0x93fbca0a, __VMLINUX_SYMBOL_STR(l2cap_register_user) },
	{ 0xa9475f6f, __VMLINUX_SYMBOL_STR(__module_put_and_exit) },
	{ 0x14d94a3, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x8738912b, __VMLINUX_SYMBOL_STR(hid_destroy_device) },
	{ 0x54e379d3, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x1a493344, __VMLINUX_SYMBOL_STR(hid_allocate_device) },
	{ 0x46f665a, __VMLINUX_SYMBOL_STR(l2cap_conn_get) },
	{ 0x40774687, __VMLINUX_SYMBOL_STR(get_device) },
	{ 0x3a51394b, __VMLINUX_SYMBOL_STR(__module_get) },
	{ 0xd85cd67e, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x344b7739, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x36f6b5c2, __VMLINUX_SYMBOL_STR(sock_no_connect) },
	{ 0xc0056be5, __VMLINUX_SYMBOL_STR(_raw_write_unlock_bh) },
	{ 0xc7bcbc8d, __VMLINUX_SYMBOL_STR(add_wait_queue) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x52967ca, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0xf8313c38, __VMLINUX_SYMBOL_STR(sock_no_sendmsg) },
	{ 0xd7d74a04, __VMLINUX_SYMBOL_STR(set_user_nice) },
	{ 0x6ec9ccdb, __VMLINUX_SYMBOL_STR(_raw_write_lock_bh) },
	{ 0x1cfb04fa, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x89e0337e, __VMLINUX_SYMBOL_STR(bt_procfs_init) },
	{ 0x8284a4c2, __VMLINUX_SYMBOL_STR(skb_dequeue) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0xe2e8065e, __VMLINUX_SYMBOL_STR(memdup_user) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0x992d3709, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x1aed3eb1, __VMLINUX_SYMBOL_STR(bt_procfs_cleanup) },
	{ 0x4dec6038, __VMLINUX_SYMBOL_STR(memscan) },
	{ 0x42e1af16, __VMLINUX_SYMBOL_STR(l2cap_unregister_user) },
	{ 0xfe0e5eab, __VMLINUX_SYMBOL_STR(input_allocate_device) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "BA4794B0CB6FB4ACAC6926C");
