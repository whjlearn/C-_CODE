#include<iostream>
#include<assert.h>
using namespace std;
template <typename T>
class Stack
{
public:
	Stack(size_t capacity = 0)//没有传参数的时候就用4来初始化参数，传了参数就用传的参数
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
	//判空
	bool Empty()
	{
		return _top == 0;
	}

	//Top 取栈顶的元素
	//T&	Top()//传引用返回 别名  可以在外面修改 //不安全
	//{
	//	assert(_top > 0);//判言一下，_top>0 才证明栈顶有元素
	//	return _a[_top - 1];
	//}

	const T& Top()//加上const 返回的是const 的别名 不可以在外面修改
	{
		assert(_top > 0);//判言一下，_top>0 才证明栈顶有元素
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

//模版不支持分离编译。声明放在 .h 定义放在 .cpp
//
// 
// 但在同一个文件中 可以 这样玩
//
template<class T>
void Stack<T>::Push(const T& x) 
	{
		if (_top == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
			T* tmp = new T[newCapacity];
			if (_a)//如果原来有空间  有数据 拷贝
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