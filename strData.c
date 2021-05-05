#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char list[1000000][101];

int main()
{
	int i, j, k;

	srand(time(NULL));
	for(i=0; i<1000000; i++)
	{
		for(j=0; j<100; j++)
		{
			list[i][j] = 'a' + (rand() % 26);
		}
		list[i][j] = '\0';
	}
	for(k=0; k<1000000; k++)
	{
		printf("%s\n", list[k]);
	}

	return 0;
}