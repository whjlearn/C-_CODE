#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//会频繁调用，所以放在类里面作为inline(内联函数)
	int GetMonthDay(int year,int month)
	{
		//会频繁调用,放在静态区
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			_day += 1;//闰年加一天
		}

		return day;
	}

	//构造函数会频繁调用，所以放在类里面作为inline(内联函数)
	Date(int year = 1900, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//只放他的声明  
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	//日期加天数 +  +=
	Date operator+(int day);
	Date& operator+=(int day);

	void Print();
	Date& operator++();
	Date operator++(int);





	//拷贝构造函数
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//}

	////运算符重载     d1 = d3;
	////自己给自己赋值 d2 = d2；
	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	
	//	return* this;//为了连续赋值
	//}
private:
	int _year;
	int _month;
	int _day;
};
