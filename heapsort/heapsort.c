#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_adjust(int *A, int heap_size, int i)
{
    int left = 2*i;
    int right = left+1;
    int largest = 0;
    if(left <= heap_size && A[left]> A[i])
    {
        largest = left;
    }else
    {
        largest = i;
    }

    if(right <= heap_size && A[right]> A[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&A[largest], &A[i]);
        heap_adjust(A, heap_size, largest);
    }


}

void build_heap(int *A, int heap_size)
{
    int i = heap_size/2;
    while(i>=1)
    {
        heap_adjust(A, heap_size, i);
        --i;
    }

}

int main(void)
{
    
    return 0;
}

