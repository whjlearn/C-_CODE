#include<iostream>
using namespace std;
//int main()
//{
//	cout << "helle"<<endl;
//	return 0;
//}

//class Myqueue
//{
//public:
//	void push(int x)
//	{
//
//	}
//private:
//	size_t _size = 0;
//	Stack _st1;
//	Stack _st2;
//};
//
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// 其他方法...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}


//int main()
//{
//	TestStack();
//
//	return 0;
//}



//运算符重载
class Date
{
public:
	Date(int year=1,int month=1,int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//运算符重载
bool operator==(Date x)
	{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	cout << (d1 == d2) << endl;
	return 0;
}