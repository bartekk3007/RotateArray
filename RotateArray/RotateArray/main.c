#include <stdio.h>
#include <stdlib.h>

char *createArray(char** box, int m, int n, int i)
{
	char *arrCol = (char*) malloc(sizeof(char) * m);
	if (arrCol)
	{
		for (int k = 0; k < m; k++)
		{
			arrCol[k] = *(*(box + (m - 1 - k)) + i);
		}
		return arrCol;
	}
	else
	{
		return NULL;
	}
}

char **rotateArray(char **box, int m, int n)
{
	char **arr = (char**) malloc(sizeof(char*) * n);
	if (arr)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = createArray(box, m, n, i);
		}
		return arr;
	}
	else 
	{
		return NULL;
	}
}

int main(void)
{
	int boxSize = 3;
	int boxColSize = 6;

	char boxCol1[] = { '#', '#', '*', '.', '*', '.' };
	char boxCol2[] = { '#', '#', '#', '*', '.', '.' };
	char boxCol3[] = { '.', '.', '#', '#', '#', '#' };
	char *box[] = { &boxCol1, &boxCol2, &boxCol3 };

	char **p = rotateArray(box, boxSize, boxColSize);

	for (int i = 0; i < boxColSize; i++)
	{
		for (int j = 0; j < boxSize; j++)
		{
			printf("%c ", *(*(p + i) + j));
		}
		printf("\n");
	}

	for (int i = 0; i < boxColSize; i++)
	{
		free(p[i]);
	}

	free(p);

	return 0;
}