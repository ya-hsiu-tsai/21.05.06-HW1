#include <stdio.h>
#include <sys/time.h>
#include "numRadix.h"

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long diff;
	int num[1000001];
	int x, cnt, i;

	cnt = 0;
	while(scanf("%d", &x)!=EOF)
	{
		num[cnt] = x;
		cnt++;
	}
	gettimeofday(&start, NULL);
	numradixsort(num, cnt);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("Sorting performance %ld us (equal %f sec)\n", diff, diff/1000000.0);

	return 0;
}