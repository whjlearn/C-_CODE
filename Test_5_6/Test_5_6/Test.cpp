#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));//C���Ե��÷�
//	int* p5 = (int*)calloc(1,sizeof(int));//C���Ե��÷�
//
//	int* p2 = new int;//c++
//	*p2 = 5;
//	
//	//c++11֧��new[]��{}��ʼ�� c++98��֧��
//	//���ӵ�ʱ���� p3,5
//	int* p3 = new int[5]{1,2,3,4,5};//����5��int������
//	
//	int* p4 = new int(5);//����һ��int ���� ��ʼ��Ϊ5
//
//	//�ͷ� 
//	free(p1);
//	//c++�ͷ�
//	delete  p2;
//	delete[] p3;
//	return 0;
//	//����������� û��̫�������
//}


///////////////////////////////////////////////////////////////////////////
//����Զ�������
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
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ�
	//������ù��캯������������
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;
	// ���������Ǽ�����һ����
	int* p3 = (int*)malloc(sizeof(int)); // C
	int* p4 = new int;
	free(p3);
	delete p4;
	A* p5 = (A*)malloc(sizeof(A) * 10);
	A* p6 = new A[10];
	//A* p6 = new A[10]{1,2,3,4,5};//c++11֧��
	
	free(p5);
	delete[] p6;
	return 0;
}

