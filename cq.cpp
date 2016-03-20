#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 2
 struct cqueue {
   int data[MAX];
   int rear,front;
} q;

void initialize()
{
	q.rear=q.front=-1;
}
int empty()
{
	if(q.rear==-1)
	return 1;
	else
	return 0;
}

int full()
{
	if(q.front == ((q.rear+1)%MAX))
	return 1;
	else
	return 0;
}

void enqueue(int item)
{
	int f;
	f=full();
	
	 if (q.front == -1)
	q.front=0;
	
	q.rear=((q.rear+1)%MAX);
  q.data[q.rear] = item;

		

}

void  dequeue()
{
	//int e;
	//e=;
	if(!empty())
	{
		printf("Deleted data is %d",q.data[q.front]);
		if(q.front==q.rear)
		q.front=q.rear=-1;
		else
			q.front= ((q.front+1)%MAX);
		
	}
	else
	{
		printf("\nQueue Underflow");
	}
//	return d;
}


void display()
{
	int i,e=empty();
	if(e!=1){
		if(q.front<=q.rear)
		{
		
	printf("\nQueue is \n");
	
		for(i=q.front;i<=q.rear;i++)
		printf("%d\t",q.data[i]);
	}
	else
	{
		  for(i=q.front;i<MAX;i++)
		printf("%d\t",q.data[i]);
		for(i=0;i<=q.rear;i++)
		printf("%d\t",q.data[i]);
	}
}
	else
		printf("\nQueue Underflow");
	
}
	
int main()
{
	int choice,item;
	char ans;
	initialize();
	printf("\n\tImplementation Of Queue");
   do {
      printf("\nMain Menu");
      printf("\n1.Insertion \n2.Deletion \n3.Display \n4.exit");
      printf("\nEnter Your Choice");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
      	  if(!full())
      	  {
      	  
         printf("\nEnter The item to be inserted\t");
         scanf("%d", &item);
                enqueue(item);}
        else
        printf("\nQueue Overflow");
         
         break;
      case 2:
                 dequeue();
                break;
      case 3:
         display();
         break;
      case 4:
      printf("Default Case");
      break;
      }
      printf("\nDo You want To Continue?");
      ans = getche();
   } while (ans == 'Y' || ans == 'y');
	return 0;
}



	

