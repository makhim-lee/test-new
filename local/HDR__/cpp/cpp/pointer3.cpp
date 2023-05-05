#include<cstdio>
int main()
{
	int a = 0x12345678;
	//int *p;
   //p = &a;
	char *p;
	//p = static_cast<char *>(&a);
	p = reinterpret_cast<char *>(&a);
	printf("0x%x\n", *p);
	return 0;
}
