#include<stdio.h>
#include<string.h>
main()
{
	char s[100];
	int i=0;
	printf("enter a sentence");
	gets(s);
	int j=0;
	char t;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]<'A'||(s[i]>'Z'&&s[i]<'a')||s[i]>'z')
		{
			for(j=0;j<strlen(s)-1;j++)
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
				
			}
		}
		
	}
		printf("sentence %s",s);
	
	
}
