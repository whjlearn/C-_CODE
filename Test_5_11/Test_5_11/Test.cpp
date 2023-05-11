#include<iostream>
#include<assert.h>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack(size_t capacity = 0)//û�д�������ʱ�����4����ʼ�����������˲������ô��Ĳ���
		:_a(nullptr)
		,_top(0)
		,_capacity(0)
	{
		if(capacity>0)
		{ 
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}

	void Push(const T& x);
	

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}
	//�п�
	bool Empty()
	{
		return _top == 0;
	}

	//Top ȡջ����Ԫ��
	//T&	Top()//�����÷��� ����  �����������޸� //����ȫ
	//{
	//	assert(_top > 0);//����һ�£�_top>0 ��֤��ջ����Ԫ��
	//	return _a[_top - 1];
	//}

	const T& Top()//����const ���ص���const �ı��� �������������޸�
	{
		assert(_top > 0);//����һ�£�_top>0 ��֤��ջ����Ԫ��
		return _a[_top - 1];
	}


	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

private:
	T* _a;
	int _top;
	int _capacity;
};

//ģ�治֧�ַ�����롣�������� .h ������� .cpp
//
// 
// ����ͬһ���ļ��� ���� ������
//
template<class T>
void Stack<T>::Push(const T& x) 
	{
		if (_top == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			T* tmp = new T[newCapacity];
			if (_a)//���ԭ���пռ�  ������ ����
			{
				memcpy(tmp, _a, sizeof(T) * _capacity);//
				delete[] _a;
			}
			_a = tmp;
			_capacity = newCapacity;
		}
	_a[_top] = x;
	++_top;
	}
//
//
//
int main()
{
	try
	{
		//int i = 10;
	//int b = 20;
	//double c = 20.1;
	//
	//swap(i,b);

		Stack<int> st1;
		st1.Push(1);
		st1.Push(2);
		st1.Push(3);
		st1.Push(4);
		st1.Push(5);

		while (!st1.Empty())
		{
			cout << st1.Top() <<" ";
			st1.Pop();
		}
		cout<<endl;
		//Stack<char>st2;
	}
	catch (const std::exception& e)
	{
		cout<<e.what()<<endl;
	}
	

	return 0;
}