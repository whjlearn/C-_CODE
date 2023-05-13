#include<string>
#include<iostream>
#include<string>
#include<list>

using namespace std;

void test_string1()
{
	string s1;
	string s2("hello,world");
	//string s2 = "hello,world";//本质是隐式类型的转换，先构造一个临时对象，在用这个  临时对象 去 拷贝构造
							//编译器会对这个优化 直接构造

	cout << s2<< endl;

	string s3(s2,4);

	cout << s3 << endl;
	string s5(s2, 4,5);//第三个参数是，从4的位置拷贝5个字符
	cout << s5 << endl;

	string s4(100,'x');//用100个x初始化

	string s6(10, 'xba');//这样书写 只有最有一个字母有效  a
	cout << s6 << endl;

	cout << s4 << endl;


}

void test_string2()
{
	string s1;
	string s2 = "hello,world";
	s1 = s2;//赋值  拷贝赋值
	cout << s1<<endl;

	s1 = "xxx";//赋值  字符串赋值
	cout << s1 << endl;

	s1 = 'd';//赋值  字符赋值
	cout << s1 << endl;
}

void test_string3()
{
	string s1("hello,world");
	cout<< s1.at(10)<<endl;
	cout << s1[10] << endl;

}

void test_string4()
{
	string s("hello");
	string::iterator it = s.begin();//迭代器
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for -- 自动迭代，自动判断结束
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;

	list<int> lt(10, 1);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
	//范围for底层其实就是迭代器
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}



int main()
{
	try
	{
		test_string4();
	}
	catch (const std::exception&e)
	{
		cout << e.what() << endl;
	}
	return 0;
}