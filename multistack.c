//... C Language program to implement the Multiple Stacks
#include<stdio.h >
#include<conio.h >
#include<stdlib.h>
#define max 10
int  main()
{
	int stack[max],  data, n, size, sno;
	int top[10], bottom[10], limit[10];
	int i, option, reply;
	printf("\n C Language program to implement the Multiple Stacks \n");
	printf("\n Enter No of Stacks  U want to Create ? : ");
	scanf("%d", &n);
	size = max / n; //... Get Max. size for each Stack
	//Initialize bottom for each Stack
	//Initialize top of each Stack
	//Initial value for i'th Stack is equal to its Bottom Value
	top[0]=bottom[0] = -1; //Bottom and top of first Stack is -1
	for(i = 1; i < n; i++)
	{

		bottom[i] = bottom[i-1] + size;
		top[i] = bottom[i];
	}
	//... Initialize Limit of each Stack
	for(i = 0; i < n-1; i++) //... Limit of i'th Stack is bottomom of i'th Stack + Size
		limit[i] = bottom[i] + size;
	//operations on stack
	do
	{
		printf("\n **** Multiple Stacks ****** \n");
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Display");
		printf("\n 4. Exit \n");
		printf("\n Select proper option\t: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1 : //Push
				printf("\n Enter a Logical Stack Number (0 to %d) : ", n-1);
				scanf("%d", &sno);
				printf("\n Enter a Value: ");
				scanf("%d", &data);
				reply = push(stack, sno, top, limit, &data);
				if( reply == -1)
					printf("\n Stack %d is Full", sno);
				else
					printf("\n %d is Pushed in Stack No. %d \n", data, sno);
				break;
			case 2 : //Pop
				printf("\n Enter a Logical Stack Number (0 to %d) : ", n-1);
				scanf("%d", &sno);
				reply = pop( stack, sno, top, bottom, &data);
				if( reply == -1)
					printf("\n Stack %d is Empty \n", sno);
				else
					printf("\n %d is popped from Stack No. %d \n", data, sno);
				break;
			case 3 : //display
			printf("\n Enter a Logical Stack Number (0 to %d) : ", n-1);
				scanf("%d", &sno);
				display( stack, sno, top,limit,bottom);
			break;	
			case 4:exit(0);
		} // switch
	}while(1);
	return 0;
} // main

void display( int stack[max], int sno, int top[], int limit[], int bottom[])
{
	int i;
	if( top[sno] == bottom[sno] )
			printf("\n Stack %d is Empty \n", sno);
	else
	{
		printf("\n Contents of Stack %d is\n",sno);
		for(i=top[sno];i>bottom[sno];i--)
		printf("%d\t",stack[i]);
	} // else
} // display

int push( int stack[max], int sno, int top[], int limit[], int *data )
{
	if( top[sno] == limit[sno] )
		return(-1);
	else
	{
		top[sno]++;
		printf("\n Stack no is  %d and Top is %d",sno,top[sno]);
		stack[ top[sno] ] = *data;
		return(1);
	} // else
} // push
int pop( int stack[max], int sno, int top[], int bottom[], int *data)
{
	if( top[sno] == bottom[sno] )
		return(-1);
	else
	{
		*data = stack[ top[sno] ];
		top[sno]--; 
		return(1);
	} // else
} // pop
