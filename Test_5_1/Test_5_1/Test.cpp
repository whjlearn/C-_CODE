#include<iostream>
using namespace std;
//C语言	宏函数
//#define	ADD(a,b) ((a)+(b))
//C++ 内联函数
//inline int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int ret =  ADD(a,b);
//	cout << ret << endl;
//	return 0;
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//范围for 
//	//自动依次取a的数据，赋值给e
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}
//typedef int DataType;
//struct Stack
//{
//	void Init(size_t capacity)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const DataType& data)
//	{
//		// 扩容
//		_array[_size] = data;
//		++_size;
//	}
//	DataType Top()
//	{
//		return _array[_size - 1];
//	}
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	cout << s.Top() << endl;
//	s.Destroy();
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year,int month,int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;//年
//	int _month;//月
//	int _day;//日
//};
//int main()
//{
//	Date d1;
//	d1.Init(2000, 5, 28);
//	d1.Print();
//	cout << sizeof(Date) << endl;
//	return 0;
//}
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;//年
//	int _month;//月
//	int _day;//日
//};
//int main()
//{
//	Date d1;
//	d1.Init(2000, 5, 28);
//	d1.Print();
//	cout << sizeof(Date) << endl;
//	return 0;
//}
class Date
{
public:
	void Print()
	{
		cout<<_year<<"--"<<_month<<"--"<<_day << endl;
	}
	/*Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}*///有全缺省了就不能定义这个函数了
	
	
//全缺省
	Date(int year=1,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(20000,8555,1112);
	
	d1.Print();
	return 0;
}