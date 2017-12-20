#include "../include/Blog.h"  
#include "../include/Observer.h"//在这里包含头文件  
#include "../include/test_case_common.h"
#include <stdint.h>
Blog::~Blog(void)  
{  
    cout<<"~Blog()"<<endl;  
}  
  
void Blog::notify(void)  
{  
    iter i = observers_.begin();  
    //标准写法  
    while(i!=observers_.end())  
    {  
        //weak_ptr本身不具备访问能力（单一职责），都是通过shared_ptr来实现 
        boost::shared_ptr<Observer> pobserver(i->lock());  
        //判断对象是否已经析构  
        if (pobserver)  
        {  
            pobserver->update();  
            //迭代器在这里前进  
            ++i;  
        }  
        //已经析构的对象不再引用  
        else  
        {  
            i = observers_.erase(i);  
        }  
    }  
}  	

github_err_t blog(uint32_t num, void *userData) 
{  
    boost::shared_ptr<Blog> pblog(new Blog());  
    pblog->set_name("CalmReason CSDN Blog");  
      
    boost::shared_ptr<Observer> pobserver1(new Observer("张三",pblog));  
    boost::shared_ptr<Observer> pobserver2(new Observer("李四",pblog));  
  
    pblog->add_observer(pobserver1);  
    pblog->add_observer(pobserver2);  
  
  
    pblog->set_status("发表了博客：C++的内存管理");  
    pblog->notify();  
  
    pblog->set_status("发表了博客：weak_ptr的基本用法");  
    pblog->notify();  
  
    return GITHUB_ERR_NONE;  
}  





