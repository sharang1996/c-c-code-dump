


#include <stdio.h>

int main(int argc, char **argv)
{
	char **names;
   names = "Alan";
   names++;
   names = "abc";
    printf("%c \n %s",names[0][0],names[1]);
	return 0;
}

