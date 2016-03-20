#include<stdio.h>
int add(int a,int b)
{
	int c=a+b;
	return c;
}
int main()
{
int *(*ptr)(int,int);
ptr = (ptrdiff_t)add(1,2);
int x= *ptr;
printf("%d",x);
return 0;
}
