#include <stdio.h>
void swap(int *ptr,int i1,int i2)
{
	int t =ptr[i1];
	ptr[i1]=ptr[i2];
	ptr[i2]=t;
}

int partition(int *ptr,int low,int high)
{
	int i=low,j;
    for(j=low+1;j<=high;++j)
    {
	if(ptr[j]<=ptr[low]) swap(ptr,++i,j);
    }
swap(ptr,low,i);
return i;
}

void quicksort(int *ptr,int low,int high)
{
	int j;
	if(low>=high) return;
	else
	{
		j=partition(ptr,low,high);
		quicksort(ptr,j+1,high);
		quicksort(ptr,low,j-1);
	}
}
	
int main(int argc, char **argv)
{
	int i;
	int a[11]={6,9,1,0,0,9,9,9,1000,28,7};
	quicksort(a,0,10);
	for(i=0;i<11;++i) printf("%d\n",a[i]);
	return 0;
}

