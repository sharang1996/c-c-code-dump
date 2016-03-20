#include <stdio.h>
#include <stdlib.h>
void readmatrix(int a[10][10],int ,int );
void printmatrix(int a[10][10],int,int);
int sparse(int a[10][10],int,int,int sp1[10][10]);
void sparseaddition(int a[10][10],int b[10][10],int r1,int c1,int r2,int c2);
void sparsesubtraction(int a[10][10],int b[10][10],int r1,int c1,int r2,int c2);
void sparsesmptranspose(int a[10][10],int ,int ,int sp1[10][10]);
void sparsefasttranspose(int a[10][10],int ,int ,int sp1[10][10]);
int i,j,sp1[10][10],sp2[10][10];

void  main()
{
 int ch,r1,c1,r2,c2,nz1;
 int a[10][10],b[10][10],sp1[10][3],sp2[10][3];
 char ans;
 clrscr();
 printf("\nEnter No. of Rows\n");
 scanf("%d",&r1);
 printf("\nEnter Columns \n");
 scanf("%d",&c1);
 readmatrix(a,r1,c1);
 printmatrix(a,r1,c1);
do
{
 printf("\n************** Menu ********************\n");
 printf("\n1:Sparse Representation\n");
 printf("\n2:Addition\n");
 printf("\n3:Subtraction\n");
 printf("\n4:Simple Transpose\n");
 printf("\n5:Fast Transpose\n");
 printf("\n6.Exit");
 printf("\nEnter Ur Option\n");
 scanf("%d",&ch);

 switch(ch)
 {
        case 1:nz1=sparse(a,r1,c1,sp1);
          break;
       case 2:printf("\nEnter 2 matrix\n");
          printf("\nEnter Rows\n");
          scanf("%d",&r2);
          printf("\nEnter Columns\n");
          scanf("%d",&c2);
          readmatrix(b,r2,c2);
          //sparse(b,r2,c2,sp2);
          sparseaddition(a,b,r1,c1,r2,c2);

        break;
        case 3: printf("\nEnter 2 matrix\n");
          printf("\nEnter Rows\n");
          scanf("%d",&r2);
          printf("\nEnter Columns\n");
          scanf("%d",&c2);
          readmatrix(b,r2,c2);
          //sparse(b,r2,c2,sp2);
          sparsesubtraction(a,b,r1,c1,r2,c2);
               break;
        case 4: sparsesmptranspose(a,r1,c1,sp1);
               break;
        case 5:sparsefasttranspose(a,r1,c1,sp1);
        break;
}
printf("\nDo You Wnt to continue(Y/y)");
scanf("%s",&ans);
}while((ans=='Y')||(ans=='y'));
getch();
}



void readmatrix(int a[10][10],int r,int c)
{
printf("\n enter the elements of sparse matrix \t:");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\n element at [%d][%d]\t",i,j);
scanf("%d",&a[i][j]);
}
}
}

 void printmatrix(int a[10][10],int r,int c)
{
printf("\n matrix is \n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}

int sparse(int a[10][10],int r,int c,int sp[10][10])
{
     int nzterms=0,k=1;
      for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
       {
     if(a[i][j]!=0)
     {
       sp[k][0]=i;
      sp[k][1]=j;
      sp[k][2]=a[i][j];
      k++;
     nzterms++;
     }
       }
     }
     sp[0][0]=r;
     sp[0][1]=c;
     sp[0][2]=nzterms;


     printf("\nSparse Represenatation is \n");
     for(i=0;i<k;i++)
     {
    for(j=0;j<3;j++)
    {
     printf("%d\t",sp[i][j]);
    }
    printf("\n");
     }

  return nzterms;
}

void sparseaddition(int a[10][10],int b[10][10],int r1,int c1,int r2,int c2)
{
     int nzterms1,nzterms2,i,j,k,sp3[20][10];
     nzterms1=sparse(a,r1,c1,sp1);
     nzterms2=sparse(b,r2,c2,sp2);


     if(sp1[0][0]!=sp2[0][0])
      {
      printf("addition is not possible\n");
         }
      i=j=k=1;
     while(i<=sp1[0][2]&&j<=sp2[0][2])
{
if(sp1[i][0]< sp2[j][0])
{
  sp3[k][0]=sp1[i][0];
  sp3[k][1]=sp1[i][1];
  sp3[k][2]=sp1[i][2];
  k++;
  i++;
  }
else if(sp1[i][0]>sp2[j][0])
  {
  sp3[k][0]=sp2[j][0];
  sp3[k][1]=sp2[j][1];
  sp3[k][2]=sp2[j][2];
  k++;
  j++;
  }
  else if(sp1[i][1]<sp2[j][1])
    {
     sp3[k][0]=sp1[i][0];
     sp3[k][1]=sp1[i][1];
     sp3[k][2]=sp1[i][2];
      k++;     i++;
    }else if(sp1[i][1]>sp2[j][1])
    {
    sp3[k][0]=sp2[j][0];
  sp3[k][1]=sp2[j][1];
  sp3[k][2]=sp2[j][2];
  k++;
  j++;

    }
     else
  {
  sp3[k][0]=sp2[j][0];
  sp3[k][1]=sp2[j][1];
  sp3[k][2]=sp1[i][2]+sp2[j][2];
  i++;j++;k++;
  }
  }
// }
 // if(i!= sp1[0][2])
  //{
     while(i<=sp1[0][2])
     {
    sp3[k][0]=sp1[i][0];
    sp3[k][1]=sp1[i][1];
    sp3[k][2]=sp1[i][2];
    i++;k++;
     }
    // }
    // else if(j != sp2[0][2])
     //{
     while(j<=sp1[0][2])
     {
    sp3[k][0]=sp2[j][0];
    sp3[k][1]=sp2[j][1];
    sp3[k][2]=sp2[j][2];
    j++;k++;
        }
    // }
    // else if(j != sp2[0][2])
     //{
     while(j<=sp1[0][2])
     {
    sp3[k][0]=sp2[j][0];
    sp3[k][1]=sp2[j][1];
    sp3[k][2]=sp2[j][2];
    j++;k++;
     }
    // }

     sp3[0][0]=sp1[0][0];
     sp3[0][1]=sp1[0][1];
     sp3[0][2]=k-1;
     printf("\nAddition is \n");
      for(i=0;i<=sp3[0][2];i++)
     {
    for(j=0;j<3;j++)
    {
     printf("%d\t",sp3[i][j]);
    }
    printf("\n");
     }
   // }
//}

}
void sparsesubtraction(int a[10][10],int b[10][10],int r1,int c1,int r2,int c2)
{
     int nzterms1,nzterms2,i=1,k=1,j=1,sp3[20][3];
     nzterms1=sparse(a,r1,c1,sp1);
     nzterms2=sparse(b,r2,c2,sp2);
     if(sp1[0][0]!=sp2[0][0])
      {
      printf("addition is not possible\n");
      }
      else
      {
     while((i<=sp1[0][2])&&(j<=sp2[0][2]))
{
if(sp1[i][0]==sp2[j][0])
{
 if(sp1[i][1]<sp2[j][1])
  {
  sp3[k][0]=sp1[i][0];
  sp3[k][1]=sp1[i][1];
  sp3[k][2]=sp1[i][2];
  k++;
  i++;
  }
else if(sp1[i][1]>sp2[j][1])
  {
  sp3[k][0]=sp2[j][0];
  sp3[k][1]=sp2[j][1];
  sp3[k][2]=sp2[j][2];
  k++;
  j++;
  }
  else if(sp1[i][1]==sp2[j][1])
  {
  sp3[k][0]=sp1[i][0];
  sp3[k][1]=sp1[i][1];
  sp3[k][2]=sp1[i][2]- sp2[j][2];
  if(sp3[k][2]!=0)
  {
   k++;
    }
    i++;
    j++;
     }

  }
  else if(sp1[i][0]<sp2[j][0])
  {
  sp3[k][0]=sp1[i][0];
  sp3[k][1]=sp1[i][1];
  sp3[k][2]=sp1[i][2];
  k++;
  i++;
  }
  else if(sp1[i][0]>sp2[j][0])
  {
  sp3[k][0]=sp2[j][0];
  sp3[k][1]=sp2[j][1];
  sp3[k][2]=sp2[j][2];
  k++;
  j++;
  }
  }
  if(i!= sp1[0][2])
  {
     while(i<=sp1[0][2])
     {
    sp3[k][0]=sp1[i][0];
    sp3[k][1]=sp1[i][1];
    sp3[k][2]=sp1[i][2];
    i++;k++;
     }
     }
     else if(j != sp2[0][2])
     {
     while(j<=sp1[0][2])
     {
    sp3[k][0]=sp2[j][0];
    sp3[k][1]=sp2[j][1];
    sp3[k][2]=sp2[j][2];
    j++;k++;
     }
     }
}
     sp3[0][0]=sp1[0][0];
     sp3[0][1]=sp1[0][1];
     sp3[0][2]=k;
     printf("\nSubtraction is \n");
      for(i=0;i<=k;i++)
     {
    for(j=0;j<3;j++)
    {
     printf("%d\t",sp3[i][j]);
    }
    printf("\n");
     }

}
