#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;

	srand(time(NULL));
	for(i=0; i<1000000; i++)
	{
		printf("%d\n", rand());
	}

	return 0;
}