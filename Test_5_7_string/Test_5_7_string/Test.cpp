#include<iostream>
using namespace std;
//已经申请空间的
//定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象
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
//	//怎么初始化p2   ？？
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc is fail");
//	}
//	new(p2)A(10);
//	cout << "就是打个断点" << endl;
//	return 0;
//}

//////////////////////////////////
//模版 
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
//	//交换两个值
//	return 0;
//}
//template<typename T>
//T* Add(T& left, T& right)
//{
//	return left + right;
//}





//不是模版的时候可以进行隐式类型转换 Add(10,10.2);10.2 double类型会转换为 int
//int Add(const int& left,const int& right)
//{
//	return left + right;
//}

//是模版的时候   不能  进行  隐式类型  的转换  Add(10,10.2);
//template<class T>
//T Add(  T& left,  T& right)//不加const 调用Add<int>(a1,d1);      Add(a1,(int)d1); 编译错误
//{
//	return left + right;
//}
//
//template<class T>
//T Add(const T& left,const T& right)//不加const 调用Add<int>(a1,d1);      Add(a1,(int)d1); 编译错误
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
//	double d = Add<double>(a2, d2);//显示实例化
//	cout<< ret <<"----" << d << endl;
//	return 0;
//}
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(const T &left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}
//int main()
//{
//	Test();
//	return 0;
//}
//////////////////////////////////

//类模版

//typedef int STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	int top;
//	int capacity;
//};

//类模版

template<typename T>
class Stack
{
public:
	Stack(size_t capacity = 0)
		/*:_a(nullptr)
		,_capacity(0)
		,_top(0)*///初始化列表
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
		delete[] _a;//释放资源
		_a = nullptr;
		_top = _capacity = 0;
	}
	void push(const T& x)
	{
		if (_top ==_capacity)//没有空间了或者还没开空间
		{	//1.开新空间
			//2.拷贝数据
			//3.释放旧空间
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

	T Top()//取栈顶的元素
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
		//类模版都是显示实例化
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