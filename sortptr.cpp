#include<stdio.h>
#include<conio.h>
void sort(int *a,int s)
{
	int *ptr1;
	int *ptr2;
	
	int c=0;
	int sm=0;
	for(ptr1=a;ptr1<a+s;ptr1++)
	{
		for(ptr2=a;ptr2<a+s;ptr2++)
		{
			if(*ptr2>*ptr1)
			{
				c=*ptr1;
				*ptr1=*ptr2;
				*ptr2=c;
			}
		}
		
	}
	
}
main()
{
	
int *sm;
int n=0;
int *p;
    printf("enter the length");
	scanf("%d",&n);
	int a[n];
	
		printf("enter the numbers");	
		for(p=a;p<a+n;p++)
		{
			scanf("%d",p);
		}
sort(a,n);

for(p=a;p<a+n;p++)
{
	printf("%d",*p);
}


getch();
	
}
