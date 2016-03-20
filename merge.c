#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
	int i, j, k, temp[50];
	k=i=low;
	j=mid+1;

	while(i<=mid && j<=high){
		if(a[i]<=a[j]){
			temp[k]=a[i];
			i++;
		}
		else{
			temp[k]=a[j];
			j++;
		}
		k++;
	}

	if(i>mid){
		for(i=j;i<=high;i++){
			temp[k]=a[i];
			k++;
		}
	}
	else{
		for(i; i<=mid; i++){
			temp[k]=a[i];
			k++;
		}
	}

	for(i=low; i<=high; ++i) a[i]=temp[i];
}

void msort(int a[], int low, int high)
{
	int mid;
	if(low>=high) return;
	mid=low+(high-low)/2;
	
	msort(a, low, mid);
	msort(a, mid+1, high);
	merge(a, low, mid, high);
}

int main()
{
	int a[50], n, i;

	printf("enter no of elements");
	scanf("%d", &n);
	printf("enter numbers");

	for(i=0; i<n; ++i) scanf("%d", &a[i]);
	msort(a, 0, n-1);
	for(i=0; i<n; ++i) printf("%d ", a[i]);

	return 0;
}


/* 15 12 54 45 78 45 78 65 54 12 12 32 65 89 45 65 */
