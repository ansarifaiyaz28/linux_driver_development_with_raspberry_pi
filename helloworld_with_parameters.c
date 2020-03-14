/*
 * helloworld.c
 *
 *  Created on: Mar 14, 2020
 *      Author: Faiyaz Ansari
 */

#include <linux/module.h>

static int num = 5;
/*
 The definition of module parameters is done via the macro module_param().
 The perm argument specifies the permission
 of the corresponding file in sysfs
 module_param(name, type, perm)
 */
module_param(num, int, S_IRUGO);	//S_IRUGO: everyone can read the sysfs entry

static int __init hello_init(void){
	pr_info("parameter num = %d\n", num);
	return 0;
}

static void __exit hello_exit(void){
	pr_info("Hello World with parameter exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Faiyaz Ansari <ansari.faiyaz28@gmail.com>");
MODULE_DESCRIPTION("This is a module that accepts parameters.");
