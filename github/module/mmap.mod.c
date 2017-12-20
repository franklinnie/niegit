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

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xe00b4984, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x94dbdab4, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x34987a5f, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0xf82eacf7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xe2cb65c5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x6af0e4a7, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x80a158fb, __VMLINUX_SYMBOL_STR(vfs_read) },
	{        0, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0xe8a1b4ec, __VMLINUX_SYMBOL_STR(vfs_write) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xad8309e6, __VMLINUX_SYMBOL_STR(filp_open) },
	{ 0x7105e20d, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "93CFF5FB51737D162933CB7");
