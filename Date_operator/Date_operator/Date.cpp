#include"Date.h"

//任何一个类，只需要写一个> == 或者< == 剩下的比较运算符重载复用即可
//那些运算符对该类有意义就有实现的必要

void Date::Print()
{
	cout << _year << "---" <<_month << "---" << _day << endl;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
//d1!=d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator>(const Date& d)
{
	if ((_year > d._year)
		||(_year == d._year && _month > d._month)
		||(_year == d._year && _month == d._month && _day > d._day))
	{
		return true;
	}
	else
	{
		//前面所有大于的情况都不满足，此时就是false
		return false;
	}

	
}
//d1> = d2;d1>d2 或者d1==d2
bool Date::operator>=(const Date& d)
{

	return (*this > d) || (*this == d);
}
//d1<d2  --->  !(d1>d2)
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

//d1<=d2  ---> !(d1>d2)||(d1==d2)
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

Date Date::operator+(int day)
{
	//Date ret(*this);//这里是拷贝构造

	Date ret = *this;//这里是拷贝构造
	 ret += day;
	 return ret;//传值返回生成一个拷贝
}
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day>GetMonthDay(_year,_month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
	//return *this += 1;
}
//后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	//Date tmp(*this);
	*this += 1;
	return tmp;
}