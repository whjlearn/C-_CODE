//#include<iostream>
//int main()
//{
//	std::cout << "hello,word" << std::endl;
//	return 0;
//}
// F.h

// F.cpp

// main.cpp
//#include "F.h"
//int main()
//{
//	f(10);
//	return 0;
//}
// ���Ӵ���main.obj : error LNK2019: �޷��������ⲿ���� "void __cdecl
//f(int)" (?f@@YAXH@Z)���÷����ں��� _main �б�����

//#include <string>
//#include <map>
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange",
//   "����" },
//	  {"pear","��"} };
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}

//#include <string>
//#include <map>
//typedef std::map<std::string, std::string> Map;
//int main()
//{
//	Map m{ { "apple", "ƻ��" },{ "orange", "����" }, {"pear","��"} };
//	Map::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}

//int main()
//{
//    int x = 10;
//    auto a = &x;
//    auto* b = &x;
//    auto& c = x;
//    cout << typeid(a).name() << endl;
//    cout << typeid(b).name() << endl;
//    cout << typeid(c).name() << endl;
//    *a = 20;
//    *b = 30;
//    c = 40;
//    return 0;
//}
