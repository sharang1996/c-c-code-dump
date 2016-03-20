#include <stdio.h>
int d[50];
int link[50];
int si,n;
	
void create(){
int i;

	for(i=0;i<n;++i)
	{
		printf("enter data and link index\n");
		scanf("%d %d",&d[i],&link[i]);
	}
}

void print()
{
int t=si;
int i;
while(link[t]!=-1)
	{
		printf("%d\n",d[t]);
		t=link[t];
	}
for(i=0;i<n;++i)
	{
		if(link[i]==-1)
		printf("%d",d[i]);
	}
}

void insert_rear(int data)
{
	int i;
    d[n]=data;
	link[n]=-1;
	for(i=0;i<n;++i)
	{
		if(link[i]==-1)
		link[i]=n;
	}
	++n;
}

void insert_front(int data,int l)
{

    d[n]=data;
	link[n]=l;
	si=n;
	++n;
}

void insert_any(int data,int index)
{
	int i;
    d[n]=data;
	for(i=0;i<n;++i)
	{
		if(link[i]==index)
		link[i]=n;
	}
	link[n]=index;
	++n;
}

void delete_front()
{
si=link[si];
}

void delete_rear()
{
	int i;
for(i=0;i<n;++i)
	{
		if(link[(link[i])]==-1)
		{
			link[i]=-1;
		    break;
	    }
	}
	--n;
}

void delete_any(int index)
{
	int i;
for(i=0;i<n;++i)
	{
		if(link[i]==index)
		link[i]=link[index];
		break;
	}
}

int main(int argc, char **argv)
{
	int data,ch=0,l,index;

    printf("Enter the number of elements\n");
	scanf("%d",&n);
	
    printf("Enter starting index\n");
	scanf("%d",&si);
	while(ch!=9)
	{
	 printf("Enter 1 to create,2 to print,3 to insert in the front,4 to insert in the rear,5 to insert anywhere,6 to delete first,7 to delete rear,8 to delete any and 9 to exit\n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		 case 1:create(n);break;
		 
		 case 2:print(n);break;
		 
		 case 3:
		 printf("enter data to insert\n");
		 scanf("%d",&data);
		 printf("enter link for data\n");
		 scanf("%d",&l);
		 insert_front(data,l);
		 break;
		 
		 case 4:
		 printf("enter data to insert\n");
		 scanf("%d",&data);
		 insert_rear(data);
		 break;
		 
		 case 5:
		 printf("enter data to insert\n");
		 scanf("%d",&data);
		 printf("enter position to insert\n");
		 scanf("%d",&index);
		 insert_any(data,index-1);
		 break;
		 
		 case 6:delete_front();break;
		 
		 case 7:delete_rear();break;
		 
		 case 8:
		 printf("enter position to delete\n");
		 scanf("%d",&index);
		 delete_any(index-1);
		 break;
		 
		 case 9:break;
		 
	 }
	 }
    printf("enter data to insert\n");
	scanf("%d",&data);
	
	
	return 0;
}

