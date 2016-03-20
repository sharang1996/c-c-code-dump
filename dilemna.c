#include <stdio.h>
void swap(int *ptr,int i1,int i2)
{
	int t =ptr[i1];
	ptr[i1]=ptr[i2];
	ptr[i2]=t;
}
void display(int *ptr,int high)
{
	int i;
	for(i=0;i<high;++i) printf("%d\t",ptr[i]);
	printf("\n");
}





int partition(int *ptr,int low,int high)
{
	int i=low,j=low+1,p=(high+low)/2;
	printf("partition display\n");
	display(ptr,high);
	for(;j<=high;++j)
	{
		if(ptr[j]<=ptr[p])
		{ 
			printf("if 1 display\n");
			display(ptr,high);
		swap(ptr,++i,j); printf("i is %d and j is %d\n",i,j);
	
		if(j==p)
		{ 	p=i; 
			printf("pivot dsiplay %d\n",ptr[p]);
			printf("i is %d and j is %d\n",i,j);
		}
		printf("if 2 display\n");
		display(ptr,high);
		
	}}
	swap(ptr,i,p); printf("final swap\n");
	return i;
}

void quicksort(int *ptr,int low,int high)
{int j;
	if(low>=high) return;
	else
	{
		j=partition(ptr,low,high);
		quicksort(ptr,low,j-1);
		quicksort(ptr,j+1,high);
	}
}

int main(int argc, char **argv)
{int i;
	int a[]={3,19,0,1,1,9,11,6,13};
	quicksort(a,0,9);
	for(i=0;i<9;++i) printf("%d\t",a[i]);
	return 0;
}

