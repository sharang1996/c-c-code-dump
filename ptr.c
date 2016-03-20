#include <stdio.h>

int main()
{
	int a=12,b=4;
	int *p1;
	int *p2;
	p1=&a;
	p2=&b;
	int x=0;
	x=4* -(*p1/(*p2))+10;
	printf("%d",x);
	return 0;
}
