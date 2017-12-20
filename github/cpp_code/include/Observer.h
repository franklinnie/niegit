#ifndef OBSERVER_H
#define OBSERVER_H

#pragma once  
#include <string>  
#include <iostream>  
using namespace std;  
#include "Blog.h"  
#include "boost/shared_ptr.hpp"  
#include "boost/weak_ptr.hpp"  
  
class Observer  
{  
public:  
    //由于只能指针都是值语义的，所以使用常值引用可以减少复制  
    Observer(const string& name,const boost::shared_ptr<Blog>& pblog)  
        :name_(name),blog_(pblog)  
    {  
        cout<<"Observer("<<name_<<")订阅了"<<blog_.lock()->get_name()<<endl;  
    }  
    ~Observer(void)  
    {  
        cout<<"~Observer("<<name_<<")"<<endl;  
    }  
    void update(void)  
    {  
        cout<<name_<<"知道了"  
            <<blog_.lock()->get_name()  
            <<blog_.lock()->get_status()<<endl;  
    }  
private:  
    string name_;  
    //这里使用weak_ptr是仅仅引用资源，而不产生使用计数，防止循环引用而不能析构  
    boost::weak_ptr<Blog> blog_;  
};  
#endif





