#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "strQuick.h"
char str[1000001][101];

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	char x[101];
	int cnt, i;

	cnt = 0;
	while(scanf("%s", x)!=EOF)
	{
		strcpy(str[cnt], x);
		cnt++;
	}
	gettimeofday(&start, NULL);
	strquicksort(str, 0, cnt-1);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("Sorting performance %ld us (equal %f sec)\n", diff, diff/1000000.0);

	return 0;
}