//#include <iostream>
//using namespace std;
//
//// ΪʲôC�������Ѿ���malloc/free��C++Ҳ�����ã����ǻ���Ҫnew/delete
//// 1���������������new����malloc����һ����
//// 2������Զ�������,new��Ҫ���ù��캯����ɳ�ʼ����delete��Ҫ�������������������
//// ���ۣ�C++�н���ʹ��new/delete
//
//// C
//typedef struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//}ListNode_C;
//
////typedef struct ListNode_C ListNode_C;
//ListNode_C* BuyListNode_C(int val)
//{
//	ListNode_C* node_c = (ListNode_C*)malloc(sizeof(ListNode_C));
//	node_c->_val = 1;
//	node_c->_next = NULL;
//	node_c->_prev = NULL;
//
//	return node_c;
//}
//
//void DestoryListNode_C(ListNode_C* node);
//
//struct ListNode_CPP
//{
//	int _val;
//	struct ListNode_CPP* _next; // ����C struct���÷�
//	ListNode_CPP* _prev;        // ��CPP�У�struct�Ѿ�������Ϊ���࣬��classһ����������Ĭ�Ϸ����޶���
//
//	ListNode_CPP(int val = 0)
//		:_val(val)
//		,_next(nullptr)
//		, _prev(nullptr)
//	{
//		cout << "ListNode_CPP(int val = 0)" << endl;
//	}
//
//	~ListNode_CPP()
//	{
//		cout << "~ListNode_CPP()" << endl;
//	}
//};
//
////int main()
////{
////	int* p1 = (int*)malloc(sizeof(int));
////	int* p2 = new int;
////
////	ListNode_C* node1 = BuyListNode_C(1);
////	ListNode_C* node2 = BuyListNode_C(2);
////	ListNode_C* node3 = BuyListNode_C(3);
////
////	ListNode_CPP* node4 = new ListNode_CPP;
////	ListNode_CPP* node5 = new ListNode_CPP(5);
////
////	delete node4;
////	delete node5; 
////
////	return 0;
////}
//
//void f(int n)
//{
//	//Sum a[n];
//	//Sum* p = new Sum[10];
//}
//
//int main()
//{
//	ListNode_CPP a[10];
//	ListNode_CPP* p = new ListNode_CPP[10];
//	delete[] p;
//
//	return 0;
//}


#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p3 = (A*)operator new(sizeof(A));
//
//	// operator new��malloc��������ʲô��
//	// ����:ʹ�÷�ʽ��һ�����������ķ�ʽ��һ��
//	size_t size = 2;
//	void* p4 = malloc(size*1024*1024*1024);
//	cout << p4 << endl; // ʧ�ܷ���0
//	//free(p4);
//
//	try
//	{
//		void* p5 = operator new(size * 1024 * 1024 * 1024);
//		cout << p5 << endl; // ʧ�����쳣  ������������ķ�ʽ��
//		//operator delete(p5);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// malloc
//	// operator new ==> malloc+ʧ�����쳣ʵ��
//	// new          ==> operator new + ���캯��
//	// new ����malloc��һ���ĵط���1�����ù��캯����ʼ�� 2��ʧ�������쳣
//	// delete ����free��һ���ĵط���1������������������
//	// operator free �� freeû������Ϊ�ͷſռ�ʧ��ֱ����ֹ���̡� ����ΪҪ��operator new�ɶԳ��ֲŲ���
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1); // �ڴ��
//		cout << "memory pool allocate" << endl;
//
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode; // ȫ��operator new + ���캯��
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	// void PushBack(int val);
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//
//		delete _head;
//		_head = nullptr;
//	}
//
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//
//	return 0;
//}
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//	
//	// ��ģ���������Ϊ
//	// ��ʾ������A�Ĺ��캯������������
//	A* p2 = (A*)operator new(sizeof(A));
//	// ���Ѿ����ڵ�һ��ռ���ù��캯����ʼ��. ��λnew/replacement new
//	new(p2)A(10);  // new(�ռ��ָ��)����(����)
//
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}

//int main()
//{
//	// 1G
//	char* p = new char[1024*1024*1024];
//	// �ڴ�й©��pָ��Ŀռ䲻��Ҫ�ˣ����ǻ�����ԭ��û���ͷ�pָ��Ŀռ䣬���ڴ�й©��
//	// �ڴ�й©Σ�����������еĳ���(��Ϸ����)�������ڴ�й©Σ���ܴ󡣻����豸���ڴ汾���С��Ҳ��Σ����
//
//	return 0;
//}

#include <iostream>
using namespace std;

//int main()
//{
//	size_t n = 2;
//	try
//	{
//		void* p = new char[n * 1024 * 1024 * 1024];
//		cout << "new:" << p << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//
//// ...
//
//int main()
//{
//	int a = 0, b = 1;
//	Swap(a, b);
//	double c = 1.11, d = 2.22;
//	Swap(c, d);
//
//	return 0;
//}

// ���ͱ��
// ģ�� -> д�������޹صĴ���
// ����ģ��
// template<class T>
//template<typename T>    // ģ�����-������
//void Swap(T& x1, T& x2)
//{
//	T x = x1;
//	x1 = x2;
//	x2 = x;
//}

// ������õ��Ƿ���ͬһ��������
// ����
// �������ǲ��ܵ��ú���ģ�壬���õ��Ǻ���ģ��ʵ�������ɵĶ�Ӧ���͵ĺ���
//int main()
//{
//	//int a = 0, b = 1;
//	//Swap(a, b);
//
//	//double c = 1.11, d = 2.22;
//	//Swap(c, d);
//
//	//char e = 'a', f = 'b';
//	//Swap(e, f);
//
//	return 0;
//}


// C�������ʵ��һ��Stack_C
typedef int STDateType;
struct Stack_C
{
	STDateType* _a;
	int  _size; // _top
	int  _capacity;
};

typedef struct Stack_C Stack_C;

void Stack_CInit(Stack_C* ps)
{}
void Stack_CDestory(Stack_C* ps)
{}
void Stack_CPush(Stack_C* ps, STDateType x)
{}
void Stack_CPop(Stack_C* ps)
{}
// ...

template<class T>
class Stack_CPP
{
public:
	Stack_CPP()
	{}

	~Stack_CPP()
	{}

	void Push(T x)
	{}

private:
	T* _a;
	int _size;
	int _capacity;
};

int main()
{
	// 1. ���ǳ�ʼ��������                    -> ���캯��+��������
	// 2. û�з�װ��˭�������޸Ľṹ�������  -> ��+�����޶���
	// 3. �����ͬʱ��������ջ��һ��ջ��int��һ��ջ��double�������� -> ģ��
	Stack_C st_c;
	Stack_CInit(&st_c);
	Stack_CPush(&st_c, 1);
	Stack_CPush(&st_c, 2);
	Stack_CPush(&st_c, 3);
	Stack_CPush(&st_c, 4);
	// �Ƿ��޸�
	st_c._capacity = 0;
	Stack_CDestory(&st_c);

	Stack_CPP<int> st_cpp_int;
	st_cpp_int.Push(1);  // ʵ����Ҳ��������������һ����������thisָ��
	st_cpp_int.Push(2);
	st_cpp_int.Push(3);
	st_cpp_int.Push(4);
	//st_cpp_int._capacity = 0;

	Stack_CPP<double> st_cpp_double;
	st_cpp_double.Push(1.1);
	st_cpp_double.Push(2.2);

	return 0;
}