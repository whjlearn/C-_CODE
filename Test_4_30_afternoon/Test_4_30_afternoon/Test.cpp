#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b = a;
	cout << typeid(a).name()<< endl;
	cout << typeid(b).name() << endl;

	//权限不能放大
	const int c = 20;//可读
	const int& d = c;

	//权限可以缩小
	int e = 30;//可读可写
	const int& f = e;//只可以读

	return 0;
}