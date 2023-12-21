
#include <stdio.h>
#include <stdlib.h>

void printarr(int A[], int l)
{

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Quick Sort - pivots

int Partition(int A[], int st, int end)
{
    int pi = end;
    int pivPlace;
    int e = st;
    int i;
    int temp;
    while (e < end)
    {
        if (A[e] > A[pi])
        {
            printf("asd1 ");

            i = e;
            while (i < pi)
            {
                printf("asd2 ");

                if (A[i] < A[e])
                {
                    temp = A[i];
                    A[i] = A[e];
                    A[e] = temp;
                    e = i;
                }

                i++;
            }
        }
        e++;
    }

    temp = A[pi];
    A[pi] = A[e];
    A[e] = temp;
    return e;
    // printf(" `%d` ", e);
    // temp = A[e];
    // A[e] = A[pi];
    // A[pi] = temp;
}
void QS(int A[], int st, int end)
{
    if (st < end)
    {

        int piv = Partition(A, st, end);
        printf(" - %d - ", piv);
        QS(A, st, piv - 1);
        printarr(A, 7);
        QS(A, piv + 1, end);
        printarr(A, 7);
    }
}

void main()
{
    int arr[] = {11, 9, 29, 7, 2, 15, 28};
    printarr(arr, 7);

    QS(arr, 0, 6);
    // printarr(arr, 7);
}