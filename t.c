#include <stdio.h>

int main()
{
	int a, i=5, x, y, z;
	x=y=z=-1;
	a=((++i) + (y=++i) + (z=++i));
	printf("a=%d; x=%d; y=%d; z=%d;\n", a, x, y, z);
	puts("-1 indicates not observed value.");
	return 0;
}
