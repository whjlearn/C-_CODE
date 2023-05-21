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
			//������
			typedef char* iterator;
			iterator begin()
			{
				return _str;
			}
			iterator end()
			{
				return _str + _size;
			}

		//const ������ ֻ�ܶ� ����д
		typedef const char* const_iterator;
			const_iterator begin() const
			{
				return _str;
			}
			const_iterator end()const
			{
				return _str + _size;
			}



			//�޲εĹ��캯��
			//string()
			//	:_str(new char[1])
			//	, _size(0)
			//	, _capacity(0)
			//{
			//	_str[0] = '\0';//��һ���ռ� �Ǹ� \0 ��
			//}

			//�в����Ĺ��캯��

		//string(const char* str )
		//	:_str(new char[strlen(str)+1])
		//	,_size(strlen(str))
		//	,_capacity(strlen(str)) //��ʼ���б��ʼ��˳�� ����private �е�����˳�� ��ʼ����
		//{
		//	strcpy(_str, str);//����
		//}

			string(const char* str = "")//��û�и�����ʱ  ��ȱʡ���� ""
			{
				_size = strlen(str);
				_capacity = _size;
				_str = new char[_capacity + 1];//���ٿռ�

				strcpy(_str, str);
			}


			//��ͳд��
			// 
			////��������s2(s1) ���
			//string(const string& s)
			//	:_str(new char[s._capacity + 1])
			//	, _size(s._size)
			//	, _capacity(s._capacity)
			//{
			//	strcpy(_str, s._str);
			//}


			////s1 = s3
			////��ֵ = ����� ����
			//string&	operator=(const string& s )
			//{
			//	if (this != &s)//��� �Լ����Լ���ֵ  ��ֱ�ӷ���
			//	{
			//		char* tmp = new char[s._capacity + 1];//�����¿ռ�  ��_str ָ���¿��Ŀռ�
			//		
			//		//�������ݿ�������
			//		strcpy(tmp, s._str);

			//		delete[] _str;//�ͷžɿռ�
			//		_str = tmp;
			//		_size = s._size;
			//		_capacity = s._capacity;
			//	}
			//	
			//	return *this;
			//}									//_capacity ��ʾ��Ч������    +1 Ϊ \0 �࿪һ�� 




			void swap(string& tmp)
			{
				::swap(_str, tmp._str);//������ȫ�ֵ� swap
				::swap(_size, tmp._size);//������ȫ�ֵ� swap
				::swap(_capacity, tmp._capacity);//������ȫ�ֵ� swap
			}


			//�ִ�д��    �ʱ�����/�ϰ�˼ά
			//��������s2(s1) ���

			//s1(s)
			string(const string& s)
				:_str(nullptr)
				, _size(0)
				, _capacity(0)
			{
				string tmp(s._str);//���ù��캯��  ����һ������
				//�����˵� �Ĺ�ʵ �� ��������Ķ�����н���
				swap(tmp);//this->swap(tmp);
			
			}


			//s1 = s3
			//��ֵ = ����� ����
			string& operator=(const string& s)
			{
				if (this != &s)//��� �Լ����Լ���ֵ  ��ֱ�ӷ���
				{
					char* tmp = new char[s._capacity + 1];//�����¿ռ�  ��_str ָ���¿��Ŀռ�

					//�������ݿ�������
					strcpy(tmp, s._str);

					delete[] _str;//�ͷžɿռ�
					_str = tmp;
					_size = s._size;
					_capacity = s._capacity;
				}

				return *this;
			}									//_capacity ��ʾ��Ч������    +1 Ϊ \0 �࿪һ�� 




		//��������
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

		size_t size() const//�ַ�������
		{
			return _size;
		}

		//���������
		char& operator[](size_t pos) //<----��ͨ�����
		{
			assert(pos<_size);
			return _str[pos];
		}

		//const ����Ͳ���д
		const char& operator[](size_t pos) const //<----const �����
		{
			assert(pos < _size);
			return _str[pos];
		}
	private:
		
		
		size_t _capacity;
		size_t _size;
		char* _str;
	};


	//����/////////////////////////////////////

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

	//����
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
