#include<stdio.h>
int add(int a,int b)
{
	int c=a+b;
	return c;
}
int main()
{
int (*ptr)(int,int);
ptr =& add;
int x= ptr(7, 8);
printf("%d",x);
return 0;
}
