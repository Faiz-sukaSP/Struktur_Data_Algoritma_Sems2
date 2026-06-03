#include "Standard_Sorting.h"

long long comparison = 0;
long long swapCount = 0;

/*
======================
    HELPER INTERNAL
======================
*/

// Fungsi untuk menukarkan nilai dari dua buah integer
static void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menduplikasi seluruh isi array ke array yang baru
void copyArray(const int source[], int destination[], int n)
{
    memcpy(destination, source, n * sizeof(int));
}

/*
==========================
   GENERATE DATA RANDOM
==========================
*/

void generateData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

/*
    ========================
        STANDART SORTING
    ========================
*/

// Insertion sort
void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i]; // nilai i menjadi kunci
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

// Buble sort
void bubbleSort(int arr[], int n)
{
    int i, j, tertukar;

    for (i = 0; i < n - 1; i++)
    {
        tertukar = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapInt(&arr[j], &arr[j + 1]);
                tertukar = 1;
            }
        }
        // pengecekan apabila tidak ada lagi pertukaran
        if (!tertukar)
            break;
    }
}

// Selection sort
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

/*
    ========================
        ADVANCE SORTING
    ========================
*/

// Fungsi untuk menggabungkan (Merge)
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

// Merge sort
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

// Membagi data
static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;
    int j, temp;

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

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

/*
==================================
   Tampilan & statistik sorting
==================================
 */

// Menampilkan isi array integer ke layar
void DisplayArrInt(int arr[], int n, int jumlahTampil)
{
    int tampil, i;

    // validasi jika data kosong
    if (n <= 0)
    {
        printf("(tidak ada data)\n");
        return;
    }

    // menentukan jumlah data yang ditampilkan
    tampil = (n < jumlahTampil) ? n : jumlahTampil;
    // menampilkan data
    for (i = 0; i < tampil; i++)
    {
        printf("%5d", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    // merapikan output jika baris terakhir pindah baris
    if (tampil % 10 != 0)
        printf("\n");

    // memberitahukan jumlah data yang tidak ditampilkan
    if (n > jumlahTampil)
        printf("... (%d data tidak ditampilkan)\n", n - jumlahTampil);

    // menampilkan jumlah total data
    printf("Total data: %d\n", n);
}

// output statistik program
void tampilkanRingkasan(const char *namaAlgoritma, int n, double waktuMs)
{
    printf("\n================================\n");
    printf("Algoritma  : %s\n", namaAlgoritma);
    printf("Jumlah data: %d\n", n);
    printf("Waktu      : %.2f ms\n", waktuMs);
    printf("================================\n");
}