#include <stdio.h>


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int *arr, int left, int right)
{
	int i = left;
	int pivot = arr[left];
	int j = left+1;
	for(; j <= right; ++j)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i], &arr[left]);
	return i;
}


void quicksort(int *a, int left, int right)
{
	if(left < right)
	{
		int pos = partition(a, left, right);
		quicksort(a, left, pos-1);
		quicksort(a, pos+1, right);
	}
}



int main(int argc, char const *argv[])
{
	
	int a[10] = {1, 4, 3, 9, 5, 2, 11, 12, -1, -9};
	quicksort(a, 0, 9);
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}