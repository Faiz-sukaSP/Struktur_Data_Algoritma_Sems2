#include "Standard_Sorting.h"

long long comparison = 0;
long long swapCount = 0;

/* =========================================
   GENERATE DATA RANDOM
========================================= */

void generateData(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

/* =========================================
   COPY ARRAY
========================================= */

void copyArray(int source[], int destination[], int n)
{
    memcpy(destination, source, n * sizeof(int));
}

/* =========================================
   PRINT ARRAY
========================================= */

void printArray(int arr[], int n)
{
    int i;

    if (n <= 100)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("\n20 data pertama:\n");

        for (i = 0; i < 20; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n...\n");

        printf("20 data terakhir:\n");

        for (i = n - 20; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

/* =========================================
   INSERTION SORT
========================================= */

void insertionSort(int arr[], int n)
{
    int i;
    int j;
    int key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0)
        {
            comparison++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swapCount++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

/* =========================================
   BUBBLE SORT
========================================= */

void bubbleSort(int arr[], int n)
{
    int i;
    int j;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            comparison++;

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapCount++;
            }
        }
    }
}

/* =========================================
   SELECTION SORT
========================================= */

void selectionSort(int arr[], int n)
{
    int i;
    int j;
    int minIndex;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            comparison++;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swapCount++;
        }
    }
}

/* =========================================
   MERGE SORT
========================================= */

static void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    int i;
    int j;
    int k;

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        comparison++;

        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }

        swapCount++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
        swapCount++;
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
        swapCount++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/* =========================================
   QUICK SORT
========================================= */

static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;
    int j;
    int temp;

    for (j = low; j < high; j++)
    {
        comparison++;

        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            swapCount++;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    swapCount++;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}