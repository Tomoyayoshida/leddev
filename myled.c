/* SPDX-License-Identifier: GPL-3.0 */
/*
 *　Copyright (C) 2020 Ryuichi Ueda and Tomoya yoshida. All rights reserved.
 */

#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/io.h>
#include<linux/time.h>
#include<linux/delay.h>

MODULE_AUTHOR("Ryuichi Ueda and Tomoya Yoshida");
MODULE_DESCRIPTION("driver for LED contron");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;
void ssleep(unsigned int seconds);        

int syori(char c){//Alphabet to Braille conversion process 
	if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){	
		if(c == 'a'|| c == 'A'){
			gpio_base[7] = 1 << 17;
		}else if(c == 'b'|| c == 'B'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 22;
		}else if(c == 'c'|| c == 'C'){		
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
		}else if(c == 'd'|| c == 'D'){                
			gpio_base[7] = 1 << 17;		
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
		}else if(c == 'e'|| c == 'E'){                        
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 25;
		}else if(c == 'f'|| c == 'F'){                        
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
		}else if(c == 'g'|| c == 'G'){
			gpio_base[7] = 1 << 17;
                        gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
		}else if(c == 'h'|| c == 'H'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
		}else if(c == 'i'|| c == 'I'){
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
		}else if(c == 'j'|| c == 'J'){
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
		}else if(c == 'k'|| c == 'K'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 12;
		}else if(c == 'l'|| c == 'L'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 12;
		}else if(c == 'm'|| c == 'M'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 12;
		}else if(c == 'n'|| c == 'N'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
		}else if(c == 'o'|| c == 'O'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
		}else if(c == 'p'|| c == 'P'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 12;
		}else if(c == 'q'|| c == 'Q'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
		}else if(c == 'r'|| c == 'R'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
		}else if(c == 's'|| c == 'S'){
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 12;
		}else if(c == 't'|| c == 'T'){
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
		}else if(c == 'u'|| c == 'U'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 12;
			gpio_base[7] = 1 << 26;
		}else if(c == 'v'|| c == 'V'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 12;
			gpio_base[7] = 1 << 26;
		}else if(c == 'w'|| c == 'W'){
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 22;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 26;
		}else if(c == 'x'|| c == 'X'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 12;
			gpio_base[7] = 1 << 26;
		}else if(c == 'y'|| c == 'Y'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 27;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
			gpio_base[7] = 1 << 26;
		}else if(c == 'z'|| c == 'Z'){
			gpio_base[7] = 1 << 17;
			gpio_base[7] = 1 << 25;
			gpio_base[7] = 1 << 12;
			gpio_base[7] = 1 << 26;
		}
		ssleep(3);
		gpio_base[10] = 1 << 17;                        
		gpio_base[10] = 1 << 27;         
		gpio_base[10] = 1 << 22;
		gpio_base[10] = 1 << 25;
		gpio_base[10] = 1 << 12;		
		gpio_base[10] = 1 << 26;
	}
	return 1;
}

static ssize_t led_write(struct file* filp, const char* buf,size_t count, loff_t* pos)
{
        char c;	       
       	if(copy_from_user(&c,buf,sizeof(char)))       
		return -EFAULT;	
	syori(c);
	if(c == '0'){//all LEDs turn off. 	
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 27;
		gpio_base[10] = 1 << 22;
		gpio_base[10] = 1 << 25;
		gpio_base[10] = 1 << 12;
		gpio_base[10] = 1 << 26;
	}else if(c == '1'){//all LEDs turn out.
		gpio_base[7] = 1 << 17;
		gpio_base[7] = 1 << 27;
		gpio_base[7] = 1 << 22;
		gpio_base[7] = 1 << 25;
		gpio_base[7] = 1 << 12;
		gpio_base[7] = 1 << 26;
		}

	        printk(KERN_INFO "receive %c\n",c);
		return 1;
}

static struct file_operations led_fops = {        
	.owner = THIS_MODULE,	        
	.write = led_write
};

static int __init init_mod(void)
{        
	int retval;	        
	retval = alloc_chrdev_region(&dev, 0, 1, "myled");		        
	if(retval < 0){			                
		printk(KERN_ERR "alloc_chrdev_region failed \n");					                
		return retval;									        }			        
	printk(KERN_INFO "%s is loaded. major:%d \n",__FILE__,MAJOR(dev));				        
	cdev_init(&cdv, &led_fops);					        
	retval = cdev_add(&cdv,dev,1);						        
	if(retval < 0){							                
		printk(KERN_ERR"cdev_add failed. major:%d minor %d\n ",MAJOR(dev),MINOR(dev));
                return retval;
        }

        cls = class_create(THIS_MODULE,"myled");
        if(IS_ERR(cls)){
                printk(KERN_ERR"class_create failed");
                return PTR_ERR(cls);
        }

        device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));

        gpio_base = ioremap_nocache(0xfe200000,0xA0);

        const u32 led1 = 17 ,led2 = 27,led3 = 22,led4 = 25,led5 = 12,led6 = 26;
        const u32 index1 = led1/10, index2 = led2/10, index3 = led3/10, index4 = led4/10, index5 = led5/10, index6 = led6/10;
        const u32 shift1 = (led1%10)*3, shift2 = (led2%10)*3, shift3 = (led3%10)*3, shift4 = (led4%10)*3,shift5 = (led5%10)*3, shift6 = (led6%10)*3;
        const u32 mask1 = ~(0x7 << shift1),mask2 = ~(0x7 << shift2), mask3 = ~(0x7 << shift3), mask4 = ~(0x7 << shift4), mask5 = ~(0x7 << shift5), mask6 = ~(0x7 << shift6);
	gpio_base[index1] = (gpio_base[index1] & mask1) | (0x1 << shift1);
	gpio_base[index2] = (gpio_base[index2] & mask2) | (0x1 << shift2);
        gpio_base[index3] = (gpio_base[index3] & mask3) | (0x1 << shift3);
        gpio_base[index4] = (gpio_base[index4] & mask4) | (0x1 << shift4);
        gpio_base[index5] = (gpio_base[index5] & mask5) | (0x1 << shift5);
        gpio_base[index6] = (gpio_base[index6] & mask6) | (0x1 << shift6);

        return 0;
}


static void __exit cleanup_mod(void)
{
        cdev_del(&cdv);
        device_destroy(cls,dev);
        class_destroy(cls);
        unregister_chrdev_region(dev,1);
        printk(KERN_INFO "%s is unloaded. major:%d\n",__FILE__,MAJOR(dev));
}

module_init(init_mod);
module_exit(cleanup_mod);

