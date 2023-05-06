#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
	//友元函数--这个函数内部可以使用Date对象访问私有保护成员
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
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
		if (!CheckDate())
		{
			Print();
			cout << "日期非法" << endl;
		}
	}
	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day>0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//只放他的声明  
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator-(int day);
	Date& operator-=(int day);

	Date& operator--();
	Date operator--(int);//后置
	//日期相减
	int operator-(const Date& d);



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
// 流插入重载
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

// 流提取重载
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate());

	return in;
}
