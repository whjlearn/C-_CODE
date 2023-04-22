//#include<iostream>
//using namespace std;
//namespace whj
//{
//	int rand = 10;
//}
//
//int main()
//{
//	printf("%d\n", whj::rand);
//	cout << whj::rand << endl;
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int d = 0;
//	std::cout << "hello whj" << std::endl;
//	std::cin >> i >> d;
//	std::cout << i <<d<< std::endl;
//	return 0;
//}
//函数重载
//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型 顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}
//#include<iostream>
//#include<stdio.h>
//void TestRef()
//{
//    int a = 10;
//    int& ra = a;//<====定义引用类型
//    printf("%p\n", &a);//取地址
//    printf("%p\n", &ra);
//    std::cout << a << std::endl;
//    std::cout << &a << std::endl;
//
//    std::cout << ra << std::endl;
//    std::cout << &ra << std::endl;
//
//}
//int main()
//{
//    TestRef();
//    return 0;
//}
#include<iostream>
int main()
{
	int a = 10;
	int& b = a;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return 0;
}