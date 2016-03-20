#include<stdio.h>
int main()
{
	int a[10], *ptr, i, j, t;

	printf("enter 10 numbers");
	
	for(ptr=a; ptr<a+10; ++ptr) scanf("%d", ptr);
	
	for(i=0; i<10; ++i){
		for(j=0; j<10-i-1; ++j){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	for(ptr=a; ptr<a+10; ++ptr) printf("%d ", *ptr);
	
	return 0;
}
