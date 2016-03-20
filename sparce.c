#include <stdio.h>

int sparsify(int a[][50], int x, int y, int s[][3])
{
	int i,j,q=1,nze=0;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
		
			if(a[i][j]!=0)
			nze++;
		}
	}
	
	
	s[0][0]=x;
	s[0][1]=y;
	s[0][2]=nze;
	
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(a[i][j]!=0){
				s[q][0]=i;
				s[q][1]=j;
				s[q][2]=a[i][j];
				q++;
			}
		}
	}
	return q;
}	
	
	
int main()
{
	int x, y, i, j, q, a[50][50], s[50][3];

	printf("enter the no of rows\n");
	scanf("%d",&x);
	printf("enter the no of columns\n");
	scanf("%d",&y);
	printf("enter the elements of the matrix\n");

	for(i=0; i<x; i++)
		for(j=0; j<y; j++)
			scanf("%d", &a[i][j]);
	
	q=sparsify(a, x, y, s);
	
	for(i=0; i<q; i++){
		for(j=0; j<3; j++)
			printf("%d", s[i][j]);
		printf("\n");
	}
	
	return 0;
}
