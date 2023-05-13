#include<string>
#include<iostream>
#include<string>
#include<list>

using namespace std;

void test_string1()
{
	string s1;
	string s2("hello,world");
	//string s2 = "hello,world";//��������ʽ���͵�ת�����ȹ���һ����ʱ�����������  ��ʱ���� ȥ ��������
							//�������������Ż� ֱ�ӹ���

	cout << s2<< endl;

	string s3(s2,4);

	cout << s3 << endl;
	string s5(s2, 4,5);//�����������ǣ���4��λ�ÿ���5���ַ�
	cout << s5 << endl;

	string s4(100,'x');//��100��x��ʼ��

	string s6(10, 'xba');//������д ֻ������һ����ĸ��Ч  a
	cout << s6 << endl;

	cout << s4 << endl;


}

void test_string2()
{
	string s1;
	string s2 = "hello,world";
	s1 = s2;//��ֵ  ������ֵ
	cout << s1<<endl;

	s1 = "xxx";//��ֵ  �ַ�����ֵ
	cout << s1 << endl;

	s1 = 'd';//��ֵ  �ַ���ֵ
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
	string::iterator it = s.begin();//������
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor -- �Զ��������Զ��жϽ���
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
	//��Χfor�ײ���ʵ���ǵ�����
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