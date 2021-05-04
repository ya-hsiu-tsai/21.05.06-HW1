#include <stdio.h>
#include <string.h>
#include <sys/time.h>
char L[1000001][101];
char R[1000001][101];

void strmergesort(char str[][101], int left, int right)
{
	int middle;
	int i, j, k;
	int n1, n2;

	if(left < right)
	{
		middle = left+(right-left)/2;
		strmergesort(str, left, middle);
		strmergesort(str, middle+1, right);
		n1 = middle - left + 1;
		n2 = right - middle;
		for(i=0; i<n1; i++)
		{
			strcpy(L[i], str[left + i]);
		}
		for(j=0; j<n2; j++)
		{
			strcpy(R[j], str[middle + 1 + j]);
		}
		i = 0; j = 0; k = left;
		while(i < n1 && j < n2)
		{
			if(strcmp(L[i], R[j])<=0)
			{
				strcpy(str[k], L[i]);
				i++;
			}
			else
			{
				strcpy(str[k], R[j]);
				j++;
			}
			k++;
		}
		while(i < n1)
		{
			strcpy(str[k], L[i]);
			i++;
			k++;
		}
		while(j < n2)
		{
			strcpy(str[k], R[j]);
			j++;
			k++;
		}
	}
}