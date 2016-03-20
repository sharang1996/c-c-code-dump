#include<stdio.h>
#include<stdlib.h>
void arighshift(int *ptr1,int *ptr2,int gi,int *lb)
{
	int i;
	*lb=ptr2[gi];
	for(i=gi-1;i>=0;--i) ptr2[i+1]=ptr2[i];
	ptr2[0]=ptr1[gi];
	for(i=gi-1;i>=0;--i) ptr1[i+1]=ptr1[i];
	if(ptr1[1]==0) ptr1[0]=0;
	else ptr1[0]=1;
}
	
void add(int *ptr1,int *ptr2,int gi)
{
	int i;
	for(i=0;i<=gi;++i) ptr2[i]=ptr1[i]+ptr2[i];

	for(i=gi;i>=0;--i)
	{
		if(ptr2[i]>1)
		{
			ptr2[i]-=2;
			++ptr2[i-1];
		}
	}
}

void subtract(int *ptr1,int *ptr2,int gi)
{
	int i;
	for(i=gi;i>=0;--i) 
	{
		ptr2[i]=ptr2[i]-ptr1[i];
		if(ptr2[i]<0) 
		{
			ptr2[i]+=2;
			--ptr2[i-1];
		}
	}

}
	
	
void shift(int *ptr,int li,int gi)
{
	int i,j=li;
	while(j<gi)
	{
		for(i=li;i>=0;--i) ptr[i+1]=ptr[i];
		ptr[0]=0; 
		++li;
		++j;
	}
}	
	
	
	
	
	
void twoscompliment(int *ptr,int li)
{
	int i;
	for(i=0;i<=li;i++)
	{
		if(ptr[i]==0) ptr[i]=1;
		else ptr[i]=0;
	}
	
	ptr[li]+=1;
	for(i=li;i>0;i--)
	{
		if(ptr[i]>1)
		{
			ptr[i]-=2;
			ptr[i-1]++;
		}
	}
	
}
	
	
	
int convert(int *ptr,int n)
{
	int li=0,t;
	
	t=n;
while(t!=0)
{
t/=2;
li++;
}
	ptr+=li;
	--ptr;
while(n!=0)
{
*ptr=n%2;
n/=2;
ptr--;
}

return li;

}

int main(int argc,char **argv)
{
int a[50];
int b[50];
int acc[50];
int i,p,q,li1,li2,gi,s1,s2,lb=0;
int *ptr=&lb;
printf("enter 2 numbers");
scanf("%d%d",&p,&q);
if(p>=0) s1=0;
else s1=1;
li1=convert(a,p);
if(q>=0) s2=0;
else s2=1;
li2=convert(b,q);
//gi=(li1>li2?li1:li2);
if(li1>li2) gi=li1+1;
else gi=li2+1;

shift(a,li1,gi);
shift(b,li2,gi);

if(s1==1)
twoscompliment(a,gi-1);
if(s2==1)
twoscompliment(b,gi-1);

for(i=0;i<gi;i++)
{
	acc[i]=0;
}
printf("\n");
//subtract(a,acc,gi-1);
//add(a,acc,gi-1);
//arighshift(acc,b,gi-1,ptr);
for(i=0;i<gi;i++)
{
	printf("%d",acc[i]);
}
printf("\n");
for(i=0;i<gi;i++)
{
	printf("%d",a[i]);
}
printf("\n\n");

for(i=0;i<gi;i++)
{
	printf("%d",b[i]);
}
printf("\n%d",lb);
return 0;
}





