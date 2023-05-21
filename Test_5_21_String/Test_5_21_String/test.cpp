#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
int main()
{
	try
	{
		//whj::test_string1();
		//whj::test_string2();
		whj::test_string3();

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}