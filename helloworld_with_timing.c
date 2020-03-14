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

static struct timeval start_time;

static void say_hello(void){
	int i;
	for (i=1; i<=num; i++)
		pr_info("[%d%d] Hello!\n", i, num);
}

static int __init first_init(void){
	do_gettimeofday(&start_time);
	pr_info("Loading first!\n");
	say_hello();
	return 0;
}

static void __exit first_exit(void){
	struct timeval end_time;
	do_gettimeofday(&end_time);
	pr_info("Unoading module after %ld seconds\n", end_time.tv_sec - start_time.tv_sec);
}

module_init(first_init);
module_exit(first_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Faiyaz Ansari <ansari.faiyaz28@gmail.com>");
MODULE_DESCRIPTION("This is a module that will print the time since it waas loaded.");
