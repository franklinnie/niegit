#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cstring>
#include <list>
#include "../include/test_case_common.h"
#include <stdint.h>"

using namespace std;

github_err_t stlListInit(uint32_t num, void *userData) 
{
     int buffer[5] = {1,2,3,4,5};	
     //list<int> a1(5,2);
     list<int> a1(buffer, buffer+5);	
     list<int>::iterator it;
     for(it = a1.begin();it!=a1.end();it++){
         cout << *it << "\t";
     }
     cout << endl;
     return GITHUB_ERR_NONE;
}









