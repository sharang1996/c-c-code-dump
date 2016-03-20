#include <stdio.h>

int main()
{
	int a[10], i, j, t, min;

	printf("enter 10 numbers");

	for(i=0; i<10; ++i) scanf("%d", &a[i]);
	
	for(i=0; i<10; ++i){
		min=i;
		for(j=i+1; j<10; ++j) if(a[min]>a[j]) min=j;
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
	
	for(i=0; i<10; ++i) printf("%d ", a[i]);
	
	return 0;
}
