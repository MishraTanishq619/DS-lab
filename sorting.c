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
// void insertionSort(int A[], int n)
// {
//     int i, j;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (A[i] > A[i + 1])
//         {
//             j = i + 1;
//             while (A[j] < A[j - 1])
//             {
//                 swap(&A[j], &A[j - 1]);
//                 j--;
//             }
//         }
//         showArray(A, n);
//     }
// }

void insertionSort(int A[], int n)
{
    int i, j, e;
    for (int i = 1; i < n; i++)
    {
        if (A[i - 1] > A[i])
        {
            j = i - 1;
            e = A[i];
            while (j >= 0 && e < A[j])
            {
                A[j + 1] = A[j];
                j--;
            }
            // j--;

            A[j + 1] = e;
        }
        showArray(A, n);
    }
}

// 4. mergeSort

void mergeTwoSorted(int A[], int i, int mid, int j)
{
    int a = i;
    int m = mid + 1;
    int b = j;

    int n1 = mid - i + 1;
    int n2 = j - mid;
    int L[n1], R[n2];
    for (int p = 0; p < n1; p++)
    {
        L[p] = A[p + i];
    }

    for (int q = 0; q < n2; q++)
    {
        R[q] = A[q + mid + 1];
    }

    int p = 0;
    int q = 0;
    int k = i;

    while (p < n1 && q < n2)
    {
        if (L[p] < R[q])
        {
            A[k++] = L[p++];
            // p++;
            // k++;
        }
        else
        {
            A[k++] = R[q++];
            // q++;
            // k++;
        }
    }

    while (p < n1)
    {
        A[k++] = L[p++];
        // p++;
        // k++;
    }

    while (q < n2)
    {
        A[k++] = R[q++];
        // q++;
        // k++;
    }
}

void mergeSort(int A[], int i, int j)
{
    if (i < j)
    {
        int mid = (i + j) / 2;
        mergeSort(A, i, mid);
        mergeSort(A, mid + 1, j);

        mergeTwoSorted(A, i, mid, j);
    }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// 5. quickSort

int partition(int A[], int st, int end)
{
    int i = st;
    int pi = end;
    int j = end - 1;

    while (st < end)
    {
        while (A[i] < A[pi])
            i++;

        while (A[j] > A[pi])
            j--;

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
        else
        {
            swap(&A[i], &A[pi]);
            return pi;
        }
    }
}

void quickSort(int A[], int st, int end)
{
    if (st < end)
    {
        int pi = partition(A, st, end);

        quickSort(A, st, pi - 1);
        quickSort(A, pi + 1, end);
    }
}

void main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int arr[] = {11, 22, 25, 64, 12, 34, 90};
    int N = sizeof(arr) / sizeof(arr[0]);

    showArray(arr, N);

    // bubbleSort(arr, N);
    // selectionSort(arr, N);
    // insertionSort(arr, N);

    // mergeSort(arr, 0, N - 1);
    // mergeTwoSorted(arr, 0, 3, N - 1);
    quickSort(arr, 0, N - 1);
    showArray(arr, N);
}