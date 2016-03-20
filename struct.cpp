#include<stdio.h>
#include<string.h>
#include<conio.h>
    
     struct date{
       	int d;
       	int m;
       	int y;
       };
	struct student
	{
    	char name[20];
       int prn;
       char branch[20];
       float percentage;
      struct date dob;
    	
    }s[10],s1;
     
   int n=0;
      void accept()
      {
      	printf("Enter the number of students:");
      	scanf("%d",&n);
	      int i=0;
           //printf("enter name,prn,branch ,percentage and date of birth ");
		   for(i=0;i<n;i++)  
		   {
		   	printf("Enter name,prn,branch ,percentage and date of birth for student %d: ",i+1);
		   	//gets(s[i].name);
		   	scanf("%s",s[i].name);
		   	scanf("%d",&s[i].prn);
		   	scanf("%s",s[i].branch);
		   	//gets(s[i].branch);
		   	scanf("%f",&s[i].percentage);
		   	scanf("%d%d%d",&s[i].dob.d,&s[i].dob.m,&s[i].dob.y);
		   	
		  }
      }
        void display()
         {
         	int i;
            printf("sr.no \t prn \t name \t branch \t percentage \t date of birth \n ");
		   for(i=0;i<n;i++)  
		   {
		   	//printf("%d \t",i+1,"%s \t",s[i].name,"%d \t",s[i].prn,"%s \t",s[i].branch,"%2.2f \t",s[i].percentage,"%d / %d / %d \n",s[i].dob.d,s[i].dob.m,s[i].dob.y );
		   	printf("%d\t%d\t%s\t%s\t%2.2f \t %d%d%d\n",i+1,s[i].prn,s[i].name,s[i].branch,s[i].percentage,s[i].dob.d,s[i].dob.m,s[i].dob.y );
		   
		   }
         }
         void search()
         {
         	int i=0;
         
         	char ns[20];
         	printf("enter name");
         	scanf("%s",ns);
         	for(i=0;i<n;i++)
         	{
         		if(strcmp(ns,s[i].name)==0)
         		{
         		printf("sr.no \t prn \t name \t branch \t percentage \t date of birth \n ");
         		printf("%d\t%d\t%s\t%s\t%2.2f \t %d%d%d\n",i+1,s[i].prn,s[i].name,s[i].branch,s[i].percentage,s[i].dob.d,s[i].dob.m,s[i].dob.y );
         		
         	    }
         	}
         	
         }
         void modify()
         {
         	int i=0;
         	char ns[20];
         	char nb[20];
         	printf("enter name");
         	scanf("%s",ns);
         	printf("enter new branch");
         	scanf("%s",nb);
         	for(i=0;i<n;i++)
         	{
         		if(strcmp(ns,s[i].name)==0)
         		{
         			strcpy(s[i].branch,nb);
         		printf("sr.no \t prn \t name \t new branch \t percentage \t date of birth \n ");
         		printf("%d\t%d\t%s\t%s\t%2.2f \t %d%d%d\n",i+1,s[i].prn,s[i].name,s[i].branch,s[i].percentage,s[i].dob.d,s[i].dob.m,s[i].dob.y );
         		
         	    }
         	}
         	
         }
         void dele()
         {
         	char delname[20];
         	printf("enter name to delete");
         	scanf("%s",delname);
         	int i=0;
         	int k=0;
         
         
         	for(i=0;i<n;i++)
         	{
         		if(strcmp(delname,s[i].name)!=0)
         		{
         			printf("sr.no \t prn \t name \t branch \t percentage \t date of birth \n ");
         		    printf("%d\t%d\t%s\t%s\t%2.2f \t %d%d%d\n",i+1,s[i].prn,s[i].name,s[i].branch,s[i].percentage,s[i].dob.d,s[i].dob.m,s[i].dob.y );
         		    
         	    }
         	}
         	
         	
         	
         }
         void insert()
         {
         	int pos=0;
			 int i=0;
         	printf("enter position to insert");
         	scanf("%d",&pos);
         	printf("enter details");
         	scanf("%d",&s1.prn);
			 scanf("%s",&s1.name);
			 scanf("%s",&s1.branch);
			 scanf("%f",&s1.percentage);   
			 scanf("%d",&s1.dob.d);
			 scanf("%d",&s1.dob.m);
			 scanf("%d",&s1.dob.y);      	
         	
         	for(i=n;i>(pos-1);i--)
         	{
         		s[i]=s[i-1];
         		
         	}
         	s[pos-1]=s1;
         	
         	for(i=0;i<=n;i++)
         	{
         	
         		printf("sr.no\tprn\tname\tbranch\tpercentage\tdate of birth\n ");
         		printf("%d\t%d\t%s\t%s\t%2.2f\t %d%d%d\n",i+1,s[i].prn,s[i].name,s[i].branch,s[i].percentage,s[i].dob.d,s[i].dob.m,s[i].dob.y );
         		
         	    
         	}
         	
         }

main()
{
	int c=0;
	
	accept();
    display();
    
	printf("enter choice,1 for search,2 for modify,3 for delete,and 4 for insert");
	scanf("%d",&c);
	
    switch(c)
	{
    
    case 1 : search();
    break;
    case 2 : modify();
    break;
    case 3 : dele();
    break;
    case 4 : insert();
    break;
    default:printf("wrong choice");
      getch();
  }
}
