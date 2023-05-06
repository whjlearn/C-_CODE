#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));//C语言的用法
//	int* p5 = (int*)calloc(1,sizeof(int));//C语言的用法
//
//	int* p2 = new int;//c++
//	*p2 = 5;
//	
//	//c++11支持new[]用{}初始化 c++98不支持
//	//监视的时候是 p3,5
//	int* p3 = new int[5]{1,2,3,4,5};//申请5个int的数组
//	
//	int* p4 = new int(5);//申请一个int 对象 初始化为5
//
//	//释放 
//	free(p1);
//	//c++释放
//	delete  p2;
//	delete[] p3;
//	return 0;
//	//针对内置类型 没有太大的区别
//}


///////////////////////////////////////////////////////////////////////////
//针对自定义类型
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
int main()
{
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间
	//还会调用构造函数和析构函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;
	// 内置类型是几乎是一样的
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;
	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	//A* p6 = new A[10]{1,2,3,4,5};//c++11支持
	
	free(p5);
	delete[] p6;
	return 0;
}

