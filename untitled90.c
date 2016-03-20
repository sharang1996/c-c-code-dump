/*
 * C Program to Reverse the String using Recursion
 */
#include <stdio.h>
#include <string.h>
 
void reverse(char [], int, int,int *);
int main()
{
    char str1[20];
    int size;
    int c=0;
int *ptr = &c;
    printf("Enter a string ");
    scanf("%s", str1);
    size = strlen(str1);
    reverse(str1, 0, size - 1,ptr);
    if(c==0) puts("palindrome");
    else puts("not palindrome");

    return 0;
}
 
void reverse(char str1[], int index, int size,int *ptr)
{
    if(index==size) return;
   if( str1[index] != str1[size - index])
   { *ptr=1;
   return;}
    reverse(str1, index + 1, size,ptr);
    *ptr=0;
}
