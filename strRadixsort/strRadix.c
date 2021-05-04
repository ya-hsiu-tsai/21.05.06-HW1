#include <stdio.h>
#include <string.h>
#include <sys/time.h>
char bucket[26][1000001][101];

void strradixsort(char str[][101], int cnt)
{
	int bucketcnt[26];
	int d, i, j, k, r;

	for(d=99; d>=0; d--)
	{
		for(i=0; i<26; i++)
		{
			bucketcnt[i] = 0;
		}
		for(i=0; i<cnt; i++)
		{
			r = str[i][d] - 'a';
			strcpy(bucket[r][bucketcnt[r]], str[i]);
			bucketcnt[r]++;
		}
		i = 0;
		for(k=0; k<26; k++)
		{
			for(j=0; j<bucketcnt[k]; j++)
			{
				strcpy(str[i], bucket[k][j]);
				i++;
			}
		}
	}
}