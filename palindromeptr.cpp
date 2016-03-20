#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_palindrome(char *str,int s)
{
	
	char b[s];
	
	char *ptr2;
	ptr2 = b+s-1;

	char *ptr;
	int sm=0;
	
	for(ptr=str;*ptr!='\0';ptr++)
	{
		*ptr2=*ptr;
		
		ptr2--;
	}
	ptr2++;
	
	
	if(strcmp(str,ptr2)==0)
		sm=1;
	
	return sm;
}
main()
{
	
int sm=0;
int n=0;
   
	char a[100];
	
		printf("enter a sentence: ");	
		gets(a);
		n=strlen(a);
sm=str_palindrome(a,n);
if(sm==1)
	printf("\npalindrome");
else
	printf("\nnot palindrome");
getch();
	
}
