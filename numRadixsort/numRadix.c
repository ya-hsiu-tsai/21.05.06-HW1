#include <stdio.h>
#include <sys/time.h>
int bucket[10][1000001];

int maxnum(int *num, int cnt)
{
	int max, i;

	max = num[0];
	for(i=1; i<cnt; i++)
	{
		if(num[i] > max)
		{
			max = num[i];
		}
	}

	return max;
}

int findDigit(int *num, int cnt)	//找最高有幾位數
{
	int max, digit = 1;

	max = maxnum(num, cnt);
	while(max > 9)
	{
		digit++;
		max = max / 10;
	}

	return digit;
}

void numradixsort(int *num, int cnt)
{
	int bucketcnt[10];
	int i, j, k, r, d, digit, divisor;

	digit = 0;
	divisor = 1;
	digit = findDigit(num, cnt);
	for(d=0; d<digit; d++)
	{
		for(i=0; i<10; i++)
		{
			bucketcnt[i] = 0;
		}
		for(i=0; i<cnt; i++)
		{
			r = (num[i] / divisor) % 10;
			bucket[r][bucketcnt[r]] = num[i];
			bucketcnt[r]++;
		}
		i = 0;
		for(k=0; k<10; k++)
		{
			for(j=0; j<bucketcnt[k]; j++)
			{
				num[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
	}
}