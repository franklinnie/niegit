#include <iostream>

class a
{
	public:
	void a(){
		printf("this is parent create a\n");
	}
	virtual ~a(){
		printf("this is parent destory a\n);
	}
};

class b: public  a
{
	public:
	void b(){
		printf("this is parent create b\n");
	}
	virtual ~b(){
		printf("this is parent destory b\n");
	}
};

int main()
{
	a *A  = new b;
	delete A;
	return 0;
}


