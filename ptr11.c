#include<stdio.h>
int sum(int a)
{
return a+1;

}
int main(int argc, char **argv)
{
int *(*ptr)(int);
ptr = sum(10);
return 0;
}
