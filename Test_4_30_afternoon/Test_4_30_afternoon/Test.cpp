#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b = a;
	cout << typeid(a).name()<< endl;
	cout << typeid(b).name() << endl;

	//Ȩ�޲��ܷŴ�
	const int c = 20;//�ɶ�
	const int& d = c;

	//Ȩ�޿�����С
	int e = 30;//�ɶ���д
	const int& f = e;//ֻ���Զ�

	return 0;
}