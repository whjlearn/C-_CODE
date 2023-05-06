#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
	//��Ԫ����--��������ڲ�����ʹ��Date�������˽�б�����Ա
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
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
		if (!CheckDate())
		{
			Print();
			cout << "���ڷǷ�" << endl;
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

	//ֻ����������  
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator-(int day);
	Date& operator-=(int day);

	Date& operator--();
	Date operator--(int);//����
	//�������
	int operator-(const Date& d);



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
// ����������
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

// ����ȡ����
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	assert(d.CheckDate());

	return in;
}
