#include <iostream>

class Base
{
public:
	virtual void func()
	{
		std::cout << "This is base class" << std::endl;
	}
};

class Der1 : public Base
{
public:
	void func()
	{
		std::cout << "This is der1 class" << std::endl;
	}
};

class Der2 : public Base
{};


void main(void)
{
	Base base;
	Der1 der1;
	Der2 der2;

	typedef void(*pFun)(void*);
	pFun func;

	func = (pFun)(*(unsigned int*)(*(unsigned int*)&base));
	func(&base);

	func = (pFun)(*(unsigned int*)(*(unsigned int*)&der1));
	func(&der1);

	func = (pFun)(*(unsigned int*)(*(unsigned int*)&der2));
	func(&der2);

}