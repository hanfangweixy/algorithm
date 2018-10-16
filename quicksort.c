/* ===========================================================================
 * > File Name: quicksort.c
 * > Author: geometry
 * > Mail: 
 * > Created Time: Tue 16 Oct 2018 05:27:13 PM CST
 * =========================================================================*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	int num1 = *pa;
	int num2 = *pb;

	return (num1 - num2);
}

void quicksort(int array[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = array[(left+right) / 2];
	int i = left;
	int Lp = left;
	int Rp = right;

	while (i <= Rp)
	{
		if (array[i] > pivot)
		{
			int temp = array[Rp];
			array[Rp] = array[i];
			array[i] = temp;
			Rp--;
		}
		else if (array[i] < pivot)
		{
			int temp = array[Lp];
			array[Lp] = array[i];
			array[i] = temp;
			i++;
			Lp++;
		}
		else
		{
			i++;
		}
	}
	quicksort(array, left, Lp-1);
	quicksort(array, Rp+1, right);
}

int main(void)
{
	int array[2000000] = {0};
	srand(time(0));
	int length = sizeof(array)/sizeof(int);
	int i;

	for (i = 0; i < length; i++)
	{
		array[i] = rand()%1000-50;
	}
/*
 	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");
*/

	quicksort(array, 0, length-1);

	clock_t beg = clock();	// Get the CPU time occupancy value before entering.

	quicksort(array, 0, length-1);
	//qsort(array, length, sizeof(int), compare);	//C standard library.

	clock_t end = clock();	// Get the CPU time occupancy value after execution.
	
	printf("%lf\n", (double)(end - beg) / CLOCKS_PER_SEC);	// unit converted to milliseconds. clock_t is long intege.
/*
	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");

	printf("%lf\n", (double)(end - beg) / CLOCKS_PER_SEC);	// unit converted to milliseconds. clock_t is long intege.
*/
	return 0;
}
