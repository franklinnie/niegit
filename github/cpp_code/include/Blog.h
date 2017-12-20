#ifndef  BLOG_H
#define BLOG_H

#pragma once  
#include <string>  
#include <iostream>  
using namespace std;  
#include <vector>  
#include "boost/weak_ptr.hpp"  
    
class Observer;//这里只能使用前置声明  
  
class Blog  
{  
public:  
    Blog()  
    {  
        cout<<"Blog()"<<endl;  
    }  
    ~Blog(void);  
    void set_name(const string& name)  
    {  
        name_ = name;  
    }  
    const string get_name()  
    {  
        return name_;  
    }  
    void set_status(const string& s)  
    {  
        status_ = s;  
    }  
    const string get_status(void) const  
    {  
        return this->status_;  
    }  
    void add_observer(const boost::shared_ptr<Observer>& pobserver)  
    {  
        observers_.push_back(pobserver);  
    }  
    void notify(void);  
  
private:  
    string name_;  
    string status_;  
    //这里使用weak_ptr是仅仅引用资源，而不产生使用计数，防止循环引用而不能析构  
    vector<boost::weak_ptr<Observer> > observers_;  
    typedef vector<boost::weak_ptr<Observer> >::iterator iter;  
};  
#endif






