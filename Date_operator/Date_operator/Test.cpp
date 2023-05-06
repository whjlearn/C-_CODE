
#include"Date.h"
//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//析构函数
//	~Date(){}
//
//	//运算符重载
//	bool operator==(Date& d)
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//		
//};
//void TestDate1()
//{
//	Date d1(1999, 10, 21);
//	Date d2(d1);
//	Date d3(2023, 5, 3);
//	d1 = d3;//会被转换成---> d1.operator=(&d1,d3);
//	d2 = d1 = d3;//连续赋值
//	d2 = d2;//自己给自己赋值
//}
//void TestDate1()
//{
//	Date d1(1999, 10, 21);
//	Date d2(2000,10,25);
//	Date d3(1998, 7, 21);
//
//	cout <<"1-->" << (d1 == d2) << endl;
//	cout << "2-->" << (d1 != d2) << endl;
//	cout<< "3-->" << (d1 > d2) <<endl;
//	cout << "4-->" << (d1 >= d2) << endl;
//	cout << "5-->" << (d1 < d2) << endl;
//	cout << "6-->" << (d1 <= d2) << endl;
//
//
//
//}
//void TestDate2()
//{
//	Date d1(1999, 10, 21);
//
//	d1 += 4;
//	d1.Print();
//
//	d1 += 40;
//	d1.Print();
//
//	d1 += 400;
//	d1.Print();
//}

//void TestDate2()
//{
//	Date d1(1999, 10, 21);
//
//	//(d1 + 4).Print();
//
//	//(d1 + 40).Print();
//
//
//	//(d1 + 400).Print();
//	//(d1 + 4000).Print();
//
//	/*Date ret1 = d1++;
//	ret1.Print();*/
//	Date ret2 = ++d1;
//	ret2.Print();
//
//}

void TestDate2()
{
	Date d1(1999, 10, 21);
	Date d2(2000, 10, 21);
	Date d3;
	cout << d2 << d1;
	cin >> d3;
	


}

int main()
{
	TestDate2();

	return 0;
}