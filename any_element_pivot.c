#include <stdio.h>

void display(int *ptr,int front, int back){
	int i;
	//printf("Array:\n");
	for(i=front;i<=back;i++){
		printf(" %d ",ptr[i]);
	}
}

int partition(int *ptr,int front, int back){
	int i,j,temp;

	//u change pivot index(start, middle, end) here, this case chooses middle.
	
	int pivot = (back+front)/2;          //we only store the pivot index
		
	i=front;
	
	for(j=front;j<=back;j++){
		
		
		if(ptr[j]<=ptr[pivot]){
			
			temp=ptr[j];
			ptr[j]=ptr[i];
			ptr[i]=temp;
			
			
			if(j==pivot) pivot=i;
			
			i++;
		}
		
	}
	
	//Swaping pivot to correct position
	temp = ptr[i-1];
	ptr[i-1]=ptr[pivot];
	ptr[pivot]=temp;
	
	
	pivot=i-1;
	
	
	return pivot;
}

void quicksort(int *ptr,int front, int back){
	
	int pivot;
	if(front<back){
		
		pivot = partition(ptr,front,back);
	
		quicksort(ptr,front,pivot-1);
		quicksort(ptr,pivot+1,back);
	}
}
int main(){
	int a[]={3,1,-9,2,3,9,9,9};
	int *p;
	p=a;
	quicksort(p,0,7);
	printf("\n\n\n\n\n\nSorted Array:\n");
	display(p,0,7);
	return 0;
}
