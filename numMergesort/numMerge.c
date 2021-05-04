#include <stdio.h>
#include <sys/time.h>

void merge(int *num, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int L[n1], R[n2];

	for(i=0; i<n1; i++)
	{
		L[i] = num[left + i];
	}
	for(j=0; j<n2; j++)
	{
		R[j] = num[middle + 1 + j];
	}
	i = 0; j = 0; k = left;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			num[k] = L[i];
			i++;
		}
		else
		{
			num[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		num[k] = L[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		num[k] = R[j];
		j++;
		k++;
	}
}

void nummergesort(int *num, int left, int right)
{
	int middle;

	if(left < right)
	{
		middle = left+(right-left)/2;
		nummergesort(num, left, middle);
		nummergesort(num, middle+1, right);
		merge(num, left, middle, right);
	}
}