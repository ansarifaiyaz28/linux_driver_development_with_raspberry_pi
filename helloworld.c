/*
 * helloworld.c
 *
 *  Created on: Mar 11, 2020
 *      Author: Faiyaz Ansari
 */

#include <linux/module.h>

static int __init hello_init(void){
	pr_info("Hello World init\n");
	return 0;
}

static void __exit hello_exit(void){
	pr_info("Hello World exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

//MODULE_LICENSE("GPL");
MODULE_AUTHOR("Faiyaz Ansari <ansari.faiyaz28@gmail.com>");
MODULE_DESCRIPTION("This is a print out hello world module.");
