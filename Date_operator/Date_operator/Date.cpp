#include"Date.h"

//�κ�һ���ֻ࣬��Ҫдһ��> == ����< == ʣ�µıȽ���������ظ��ü���
//��Щ������Ը������������ʵ�ֵı�Ҫ

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
		//ǰ�����д��ڵ�����������㣬��ʱ����false
		return false;
	}

	
}
//d1> = d2;d1>d2 ����d1==d2
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
	//Date ret(*this);//�����ǿ�������

	Date ret = *this;//�����ǿ�������
	 ret += day;
	 return ret;//��ֵ��������һ������
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
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

//ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
	//return *this += 1;
}
//����++
Date Date::operator++(int)
{
	Date tmp = *this;
	//Date tmp(*this);
	*this += 1;
	return tmp;
}

Date Date::operator-(int day)
{
	Date ret= *this;
	ret -= day ;
	return ret;
	
}
Date& Date::operator-=(int day)
{
	if (day<0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day<=0)
	{
		--_month;//����һ����
		if (_month == 0)
		{
			--_year;
			_month = 12;

		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//����
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n*flag;
}
