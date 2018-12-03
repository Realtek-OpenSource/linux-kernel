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
	{ 0x621f96c7, __VMLINUX_SYMBOL_STR(class_find_device) },
	{ 0x6903ad6, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x80d68d3e, __VMLINUX_SYMBOL_STR(fb_register_client) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xe93e49c3, __VMLINUX_SYMBOL_STR(devres_free) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
	{ 0x8e9b68fd, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x86fdb1a, __VMLINUX_SYMBOL_STR(blocking_notifier_chain_unregister) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x828e0fb8, __VMLINUX_SYMBOL_STR(devres_alloc_node) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x8a503a59, __VMLINUX_SYMBOL_STR(device_register) },
	{ 0xa87ec259, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x6f29956c, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x5b86419e, __VMLINUX_SYMBOL_STR(kobject_uevent_env) },
	{ 0xc43f4477, __VMLINUX_SYMBOL_STR(devres_release) },
	{ 0x7c7efd02, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x20369497, __VMLINUX_SYMBOL_STR(blocking_notifier_call_chain) },
	{ 0x996bdb64, __VMLINUX_SYMBOL_STR(_kstrtoul) },
	{ 0x37518deb, __VMLINUX_SYMBOL_STR(sysfs_notify) },
	{ 0xe5c69e23, __VMLINUX_SYMBOL_STR(blocking_notifier_chain_register) },
	{ 0x854a3999, __VMLINUX_SYMBOL_STR(devres_add) },
	{ 0x54e379d3, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xb67520f0, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xb12cbacb, __VMLINUX_SYMBOL_STR(fb_unregister_client) },
	{ 0x5157c455, __VMLINUX_SYMBOL_STR(device_unregister) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0x15551488, __VMLINUX_SYMBOL_STR(dev_set_name) },
	{ 0x893fb9d9, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x6ec89cff, __VMLINUX_SYMBOL_STR(__init_rwsem) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

