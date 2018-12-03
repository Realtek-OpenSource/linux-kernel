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
	{ 0x2254b367, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x41b4b1d0, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x758cb867, __VMLINUX_SYMBOL_STR(gpiod_set_raw_value) },
	{ 0xa2e73a79, __VMLINUX_SYMBOL_STR(switch_set_state) },
	{ 0xedbad95, __VMLINUX_SYMBOL_STR(gpiod_get_raw_value) },
	{ 0x51894015, __VMLINUX_SYMBOL_STR(ion_free) },
	{ 0x4257f808, __VMLINUX_SYMBOL_STR(ion_unmap_kernel) },
	{ 0x65435e3, __VMLINUX_SYMBOL_STR(send_rpc_command) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xcd3ccbf6, __VMLINUX_SYMBOL_STR(ion_map_kernel) },
	{ 0x223f6761, __VMLINUX_SYMBOL_STR(ion_phys) },
	{ 0xaed88368, __VMLINUX_SYMBOL_STR(ion_alloc) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0xbc477a2, __VMLINUX_SYMBOL_STR(irq_set_irq_type) },
	{ 0xf5a2c9be, __VMLINUX_SYMBOL_STR(gpiod_to_irq) },
	{ 0x353238cd, __VMLINUX_SYMBOL_STR(gpiod_set_debounce) },
	{ 0xd6b788b4, __VMLINUX_SYMBOL_STR(gpio_to_desc) },
	{ 0x47229b5c, __VMLINUX_SYMBOL_STR(gpio_request) },
	{ 0x2fae74b, __VMLINUX_SYMBOL_STR(of_get_named_gpio_flags) },
	{ 0x4121167a, __VMLINUX_SYMBOL_STR(of_property_read_variable_u32_array) },
	{ 0x46ff87e, __VMLINUX_SYMBOL_STR(switch_dev_register) },
	{ 0x46d04789, __VMLINUX_SYMBOL_STR(ion_client_create) },
	{ 0xf131ab9e, __VMLINUX_SYMBOL_STR(rtk_phoenix_ion_device) },
	{ 0xa241bac7, __VMLINUX_SYMBOL_STR(get_rtd_chip_revision) },
	{ 0x8f678b07, __VMLINUX_SYMBOL_STR(__stack_chk_guard) },
	{ 0xf30efa2, __VMLINUX_SYMBOL_STR(switch_dev_unregister) },
	{ 0xfe990052, __VMLINUX_SYMBOL_STR(gpio_free) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0x3ce4ca6f, __VMLINUX_SYMBOL_STR(disable_irq) },
	{ 0xb2d48a2e, __VMLINUX_SYMBOL_STR(queue_work_on) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

