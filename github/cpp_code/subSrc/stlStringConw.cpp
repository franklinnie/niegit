#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<cstring>
#include "../include/test_case_common.h"
#include <stdint.h>

using namespace std;

const int array_size = 200;
const int loop_count = 1000000;

void test_strncpy ()
{
    char s1[array_size ];
    char* s2= new char[ array_size];
    memset( s2, 'c' , array_size);
    size_t start=clock ();
    for( int i =0;i!= loop_count;++i ) strncpy( s1,s2 , array_size);
    cout<< __func__ << " : " << clock()- start<<endl ;
    delete s2;
    s2 = NULL;
}

void test_string_copy ()
{
    string s1;
    string s2;
    s2. append(array_size , 'c');
    size_t start=clock ();
    for( int i =0;i!= loop_count;++i ) s1= s2;
    cout<< __func__ << " : " << clock()- start<<endl ;
}

github_err_t stlStringConw(uint32_t num, void *userData) 
{
    test_strncpy();
    test_string_copy();
    return GITHUB_ERR_NONE;
}
