#include <time.h>
#include<iostream>
using namespace std;
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}int main(){	return 0;}