#include <stdio.h>
void swap(int *ptr,int i1,int i2)
{
	int t =ptr[i1];
	ptr[i1]=ptr[i2];
	ptr[i2]=t;
}

int partition(int *ptr,int low,int high)
{
	int i=low,j=low,p=(high+low)/2;
	for(;j<=high;++j)
	{
		if(ptr[j]<=ptr[p])
		{ swap(ptr,i,j);
		if(j==p) p=i;
		i++;
	}}
	swap(ptr,i-1,p);
	return i-1;
}

void quicksort(int *ptr,int low,int high)
{
	int j;
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
	int a[6]={3,9,0,1,1,7};
	quicksort(a,0,6);
	for(i=0;i<6;++i) printf("%d",a[i]);
	return 0;
}

