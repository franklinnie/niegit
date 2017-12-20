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
	{ 0x94dbdab4, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0x6af0e4a7, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0x591dceea, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x10496e6, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x927cd316, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xd44ea723, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "B07D55AF05972CE7B6FF2DE");
