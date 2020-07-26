/*
 * 参考：drivers\net\cs89x0.c
 */
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/in.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/string.h>
#include <linux/init.h>
#include <linux/bitops.h>
#include <linux/delay.h>

#include <asm/system.h>
#include <asm/io.h>
#include <asm/irq.h>

static struct net_device * vnet_dev;

static int virt_net_init(void)
{
	/* 1. 分配一个net_dev */
	vnet_dev = alloc_netdev(0, "vnet%d", ether_setup);

	/* 2. 设置 */

	/* 3. 注册 */
	register_netdev(vnet_dev);

	/* 4. 硬件相关设置 */
	return 0;
}

static void virt_net_exit(void)
{
	unregister_netdev(vnet_dev);
	free_netdev(vnet_dev);
}

module_init(virt_net_init);
module_exit(virt_net_exit);

MODULE_AUTHOR("rogerg6@163.com");
MODULE_LICENSE("GPL");


