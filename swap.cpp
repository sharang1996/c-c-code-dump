#include<stdio.h>
#include<conio.h>

main()
{
	int n=0;
	int m=0;
	int *ptr1;
    int *ptr2;

    printf("enter two numbers");
	scanf("%d %d",&n,&m);
	ptr1=&n;
	ptr2=&m;
		printf("numbers are %d %d",*ptr1,*ptr2);	
	*ptr1+=*ptr2;
	*ptr2=*ptr1-*ptr2;
	*ptr1-=*ptr2;
	
	printf("swapped numbers are %d %d",*ptr1,*ptr2);


getch();
	
}

