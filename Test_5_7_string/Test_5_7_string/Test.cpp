#include<iostream>
using namespace std;
//�Ѿ�����ռ��
//��λnew���ʽ�����ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//
//	A* p1 = new A(1);
//	 
//	//��ô��ʼ��p2   ����
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc is fail");
//	}
//	new(p2)A(10);
//	cout << "���Ǵ���ϵ�" << endl;
//	return 0;
//}

//////////////////////////////////
//ģ�� 
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}

//int main()
//{
//	int i = 1, p = 2;
//	double d1 = 1.1, d2 = 2.2;
//	Swap(i, p);
//	Swap(d1, d2);
//
//	//��������ֵ
//	return 0;
//}
//template<typename T>
//T* Add(T& left, T& right)
//{
//	return left + right;
//}





//����ģ���ʱ����Խ�����ʽ����ת�� Add(10,10.2);10.2 double���ͻ�ת��Ϊ int
//int Add(const int& left,const int& right)
//{
//	return left + right;
//}

//��ģ���ʱ��   ����  ����  ��ʽ����  ��ת��  Add(10,10.2);
//template<class T>
//T Add(  T& left,  T& right)//����const ����Add<int>(a1,d1);      Add(a1,(int)d1); �������
//{
//	return left + right;
//}
//
//template<class T>
//T Add(const T& left,const T& right)//����const ����Add<int>(a1,d1);      Add(a1,(int)d1); �������
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10;
//	int a2 = 20;
//
//	double d1 = 10.5;
//	double d2 = 20.1;
//
//
//	int ret =  Add(10,(int)10.2);
//
//	double d = Add<double>(a2, d2);//��ʾʵ����
//	cout<< ret <<"----" << d << endl;
//	return 0;
//}
//
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(const T &left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}
//int main()
//{
//	Test();
//	return 0;
//}
//////////////////////////////////

//��ģ��

//typedef int STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	int top;
//	int capacity;
//};

//��ģ��

template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 0)
		/*:_a(nullptr)
		,_capacity(0)
		,_top(0)*///��ʼ���б�
	{
		if (capacity > 0)
		{
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}
	~Stack()
	{
		delete[] _a;//�ͷ���Դ
		_a = nullptr;
		_top = _capacity = 0;
	}
	void push(const T& x)
	{
		if (_top ==_capacity)//û�пռ��˻��߻�û���ռ�
		{	//1.���¿ռ�
			//2.��������
			//3.�ͷžɿռ�
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			T* tmp = new T[newCapacity];
			if (_a)
			{
				memcpy(tmp,_a,sizeof(T) * _top);
				delete[] _a;
			}
			_a = tmp;
			_capacity = newCapacity;
		}
		_a[_top] = x;
		++_top;
	}
	void Pop()
	{
		assert(_top>0);
		--_top;
	}
	bool Empty()
	{
		return _top == 0;
	}

	T Top()//ȡջ����Ԫ��
	{
		assert(_top > 0);
		return _a[_top - 1];
	}
private:
	T* _a=nullptr;
	size_t _top = 0;
	size_t _capacity = 0;
};
int main()
{
	try
	{
		//��ģ�涼����ʾʵ����
		Stack <int>st1;
		Stack <char>st2;

		Stack <int>st3(100);
		Stack <char>st4(0);
	}
	catch (const exception& e)
	{
		cout<< e.what()<<endl;
	}
	

	return 0;
}