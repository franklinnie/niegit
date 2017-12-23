#include<linux/module.h>  
#include<linux/init.h>  
#include<linux/list.h>//包含内核链表头文件  
  
struct score  
{  
    int num;  
    int English;  
    int math;  
    struct list_head list;//链表链接域  
};  
  
struct list_head score_head;//所建立链表的链表头  
struct list_head *pos;//定义一个结点指针  
  
//定义三个节点 然后插入到链表中  
struct score stu1, stu2, stu3;  

struct score *tmp;//定义一个score结构体变量  
  
int mylist_init(void)  
{  
    INIT_LIST_HEAD(&score_head);//初始化链表头 完成一个双向循环链表的创建  
      
    stu1.num = 1;  
    stu1.English = 59;  
    stu1.math = 99;  
      
    //然后将三个节点插入到链表中  
    list_add_tail(&(stu1.list), &score_head);//使用尾插法  
    {
	/*
	static inline void list_add_tail(struct list_head *new, struct list_head *head)
	{
		__list_add(new, head->prev, head);
	}

	
	static inline void __list_add(struct list_head *new,
				      struct list_head *prev,
				      struct list_head *next)
	{
		next->prev = new;
		new->next = next;
		new->prev = prev;
		WRITE_ONCE(prev->next, new);
	}
	*/
    }			
      
    stu2.num = 2;  
    stu2.English = 69;  
    stu2.math = 98;  
    list_add_tail(&(stu2.list), &score_head);  
      
    stu3.num = 3;  
    stu3.English = 89;  
    stu3.math = 97;  
    list_add_tail(&(stu3.list), &score_head);  
      
    //遍历整个链表，每次遍历将数据打印出来  
    list_for_each(pos, &score_head)//这里的pos会自动被赋新值  
    {  
        tmp = list_entry(pos, struct score, list);  
        printk(KERN_WARNING"num: %d, English: %d, math: %d\n", tmp->num, tmp->English, tmp->math);  
    }  
      
    return 0;  
}  
  
void mylist_exit(void)  
{  
    //退出时删除结点  
    list_del(&(stu1.list));  
    list_del(&(stu2.list));  
    printk(KERN_WARNING"mylist exit!\n");  
}  
  
module_init(mylist_init);  
module_exit(mylist_exit);  
