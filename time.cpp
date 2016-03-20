#include<stdio.h>
#include<conio.h>
	
	struct Time
	{
		int h;
		int m;
		int s;
	};
	
	
	void sum(struct Time t1,struct Time t2, struct Time *t3)
	{
		
		t3->h= t1.h + t2.h;
		t3->m= t1.m + t2.m;
		t3->s= t1.s + t2.s;
		
		if(t3 -> s>=60)
		{
			t3->s-=60;
			t3->m++;
		}
			if(t3->m>=60)
		{
			t3->m-=60;
			t3->h++;
		}
	}
	void difference(struct Time t1,struct Time t2, struct Time *t4)
	{
		
		t4->h= t1.h - t2.h;
		t4->m= t1.m - t2.m;
		t4->s= t1.s - t2.s;
		
		if(t4 -> s<0)
		{
			t4->s+=60;
			t4->m--;
		}
			if(t4->m<0)
		{
			t4->m+=60;
			t4->h--;
		}
	}
	
main()
{
	    struct Time s1, s2, s3 ,s4;
	     
		printf("enter hours");
		scanf("%d",&s1.h);
		printf("enter min");
		scanf("%d",&s1.m);
		printf("enter sec");
		scanf("%d",&s1.s);

        printf("enter hours");
		scanf("%d",&s2.h);
		printf("enter min");
		scanf("%d",&s2.m);
		printf("enter sec");
		scanf("%d",&s2.s);
		
		printf("sum \n");
		sum(s1, s2, &s3);
		printf("hours %d \n",s3.h);
		printf("minutes %d \n",s3.m);
		printf("seconds %d \n",s3.s);
		difference(s1, s2, &s4);
		printf("difference \n");
		printf("hours %d \n",s4.h);
		printf("minutes %d \n",s4.m);
		printf("seconds %d \n",s4.s);
		
getch();
	
}


