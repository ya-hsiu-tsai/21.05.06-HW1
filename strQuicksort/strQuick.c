#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void strquicksort(char str[][101], int left, int right)
{
	int i = left-1;
	int j;
	char temp[101];
	int p;

	if(left < right)
	{
		for(j=left; j<right; j++)
		{
			if(strcmp(str[j], str[right])<=0)
			{
				i++;
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
		i++;
		strcpy(temp, str[i]);
		strcpy(str[i], str[right]);
		strcpy(str[right], temp);
		p = i;
		strquicksort(str, left, p-1);
		strquicksort(str, p+1, right);
	}
}