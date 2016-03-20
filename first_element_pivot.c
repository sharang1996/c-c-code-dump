//add other header files for windows(conio) and getch in the end
#include <stdio.h>
void swap(int *ptr,int i1,int i2)          //swap function for simplicity
{
	int t =ptr[i1];
	ptr[i1]=ptr[i2];
	ptr[i2]=t;
}

int partition(int *ptr,int low,int high)
{
	int i=low,j;                            //low is the pivot index
    for(j=low+1;j<=high;++j)                //we run the loop from low +1 to high,leaving the pivot as it is
    {
	if(ptr[j]<=ptr[low]) swap(ptr,++i,j);   //we swap the jth element and ++ith element if jth element is less than or equal to pivot
    }
swap(ptr,low,i);                               //we eventually switch the pivot with ith element,which is its right position
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
	int a[11]={6,9,1,0,0,9,9,9,1000,28,7};  //can change elements if u want...
	quicksort(a,0,10);                       //but change the size as well!!!
	for(i=0;i<11;++i) printf("%d\n",a[i]);
	return 0;
}

