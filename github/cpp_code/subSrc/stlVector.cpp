#include <iostream>
#include <vector>
#include <stdint.h>
#include "../include/test_case_common.h"

using namespace std;

/*
编程语言方面：vector是C++标准模板库中的部分内容，中文偶尔译作“容器”，但并不准确。它是一个多功能的，能够操作多种数据结构和算法的模板类和函数库。vector之所以被认为是一个容器，是因为它能够像容器一样存放各种类型的对象，简单地说，vector是一个能够存放任意类型的动态数组，能够增加和压缩数据
*/

github_err_t stlVector(uint32_t num, void *userData)
{
	vector<int> int_vector;
	vector<double> double_vector;

	int_vector.push_back(99);
	int_vector.push_back(9999);

	double_vector.push_back(99.99);
	double_vector.push_back(9999.9999);

	int size;
	size = int_vector.size();
	cout << "int vector size is " << size << endl; 
	for (int i = 0; i < size; i ++){
		cout << int_vector[i] << endl;
	}
	size = double_vector.size();
	cout << "double vector size is " << size << endl; 
	for (int j = 0; j < size; j ++){
		cout << double_vector[j] << endl;
	}
	return GITHUB_ERR_NONE;
}

github_err_t stlVectorMultiArray(uint32_t num, void *userData)
{
   vector< vector< vector<int> > > vI3Matrix(2, vector< vector<int> > (3, vector<int>(4,0)) );

   for(int kk=0; kk<4; kk++)
   {
      for(int jj=0; jj<3; jj++)
      {
         for(int ii=0; ii<2; ii++)
         {
            cout << vI3Matrix[ii][jj][kk] << endl;
         }
      }
   }
   return GITHUB_ERR_NONE;	
}


