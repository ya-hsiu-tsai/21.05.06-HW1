#include <stdio.h>
#include <sys/time.h>

void numquicksort(int *num, int left, int right)
{
	int i = left-1;
	int j;
	int temp;
	int p;

	if(left < right)
	{
		for(j=left; j<right; j++)
		{
			if(num[j] <= num[right])
			{
				i++;
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		i++;
		temp = num[i];
		num[i] = num[right];
		num[right] = temp;
		p = i;
		numquicksort(num, left, p-1);
		numquicksort(num, p+1, right);
	}
}