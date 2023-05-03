#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	//��Ƶ�����ã����Է�����������Ϊinline(��������)
	int GetMonthDay(int year,int month)
	{
		//��Ƶ������,���ھ�̬��
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			_day += 1;//�����һ��
		}

		return day;
	}

	//���캯����Ƶ�����ã����Է�����������Ϊinline(��������)
	Date(int year = 1900, int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//ֻ����������  
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	//���ڼ����� +  +=
	Date operator+(int day);
	Date& operator+=(int day);

	void Print();
	Date& operator++();
	Date operator++(int);





	//�������캯��
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//}

	////���������     d1 = d3;
	////�Լ����Լ���ֵ d2 = d2��
	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	
	//	return* this;//Ϊ��������ֵ
	//}
private:
	int _year;
	int _month;
	int _day;
};
