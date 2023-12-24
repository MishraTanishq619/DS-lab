#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void showArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 1. BubbleSort
void bubbleSort(int A[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}
// 2. SelectionSort
void selectionSort(int A[], int n)
{
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        m = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            swap(&A[m], &A[i]);
        }
    }
}
// 3. InsertionSort
void insertionSort(int A[], int n)
{
    int i, j;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            j = i + 1;
            while (A[j] < A[j - 1])
            {
                swap(&A[j], &A[j - 1]);
                j--;
            }
        }
        // showArray(A, n);
    }
}

void main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(arr) / sizeof(arr[0]);

    showArray(arr, N);

    // bubbleSort(arr, N);
    // selectionSort(arr, N);
    insertionSort(arr, N);

    showArray(arr, N);
}