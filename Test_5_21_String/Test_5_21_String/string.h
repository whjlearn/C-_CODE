#pragma once
#include<string>
#include<iostream>
#include<cassert>
using namespace std;
namespace whj
{
	class string
	{
		public:
			//迭代器
			typedef char* iterator;
			iterator begin()
			{
				return _str;
			}
			iterator end()
			{
				return _str + _size;
			}

		//const 迭代器 只能读 不能写
		typedef const char* const_iterator;
			const_iterator begin() const
			{
				return _str;
			}
			const_iterator end()const
			{
				return _str + _size;
			}



			//无参的构造函数
			//string()
			//	:_str(new char[1])
			//	, _size(0)
			//	, _capacity(0)
			//{
			//	_str[0] = '\0';//开一个空间 是给 \0 的
			//}

			//有参数的构造函数

		//string(const char* str )
		//	:_str(new char[strlen(str)+1])
		//	,_size(strlen(str))
		//	,_capacity(strlen(str)) //初始化列表初始化顺序 跟着private 中的声明顺序 初始化的
		//{
		//	strcpy(_str, str);//拷贝
		//}

			string(const char* str = "")//当没有给参数时  给缺省参数 ""
			{
				_size = strlen(str);
				_capacity = _size;
				_str = new char[_capacity + 1];//开辟空间

				strcpy(_str, str);
			}


			//传统写法
			// 
			////拷贝构造s2(s1) 深拷贝
			//string(const string& s)
			//	:_str(new char[s._capacity + 1])
			//	, _size(s._size)
			//	, _capacity(s._capacity)
			//{
			//	strcpy(_str, s._str);
			//}


			////s1 = s3
			////赋值 = 运算符 重载
			//string&	operator=(const string& s )
			//{
			//	if (this != &s)//如果 自己给自己赋值  则直接返回
			//	{
			//		char* tmp = new char[s._capacity + 1];//开辟新空间  让_str 指向新开的空间
			//		
			//		//将旧数据拷贝过来
			//		strcpy(tmp, s._str);

			//		delete[] _str;//释放旧空间
			//		_str = tmp;
			//		_size = s._size;
			//		_capacity = s._capacity;
			//	}
			//	
			//	return *this;
			//}									//_capacity 表示有效的数据    +1 为 \0 多开一个 




			void swap(string& tmp)
			{
				::swap(_str, tmp._str);//调的是全局的 swap
				::swap(_size, tmp._size);//调的是全局的 swap
				::swap(_capacity, tmp._capacity);//调的是全局的 swap
			}


			//现代写法    资本主义/老板思维
			//拷贝构造s2(s1) 深拷贝

			//s1(s)
			string(const string& s)
				:_str(nullptr)
				, _size(0)
				, _capacity(0)
			{
				string tmp(s._str);//调用构造函数  构造一个打工人
				//将打工人的 的果实 给 拷贝构造的对象进行交换
				swap(tmp);//this->swap(tmp);
			
			}


			//s1 = s3
			//赋值 = 运算符 重载
			string& operator=(const string& s)
			{
				if (this != &s)//如果 自己给自己赋值  则直接返回
				{
					char* tmp = new char[s._capacity + 1];//开辟新空间  让_str 指向新开的空间

					//将旧数据拷贝过来
					strcpy(tmp, s._str);

					delete[] _str;//释放旧空间
					_str = tmp;
					_size = s._size;
					_capacity = s._capacity;
				}

				return *this;
			}									//_capacity 表示有效的数据    +1 为 \0 多开一个 




		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const//字符串长度
		{
			return _size;
		}

		//运算符重载
		char& operator[](size_t pos) //<----普通对象调
		{
			assert(pos<_size);
			return _str[pos];
		}

		//const 对象就不能写
		const char& operator[](size_t pos) const //<----const 对象调
		{
			assert(pos < _size);
			return _str[pos];
		}
	private:
		
		
		size_t _capacity;
		size_t _size;
		char* _str;
	};


	//测试/////////////////////////////////////

	void test_string1()
	{
		string s1("hello word");
		string s2;

		cout << s1.c_str() <<endl;
		cout << s2.c_str() <<endl;
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout <<s1[i] <<" ";
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
	}

	//测试
	void test_string2()
	{
		string s1("hello word");
		string::iterator it = s1.begin();
		while(it!=s1.end())
		{
			cout << *it << " ";
			++it;
		}

		it = s1.begin();
		while (it != s1.end())
		{
			 *it += 1;
			++it;
		}
		cout << endl;

		for (auto ch:s1)
		{
			cout << ch << " ";

		}
		cout << endl;
	}



	void test_string3()
	{
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3 = "1111111111111";
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}
}
