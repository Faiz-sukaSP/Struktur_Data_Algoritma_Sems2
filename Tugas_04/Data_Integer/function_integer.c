#include "function_integer.h"

/*
==================================
    VARIABEL GLOBAL STATISTIK
==================================
*/

// Fungsi meghitung jumlah perbandingan dan pertukaran data
long long comparison = 0;
long long swapCount = 0;

/*
======================
    FUNGSI PEMBANTU
======================
*/

// Menukar dua bilangan integer
static void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Menyalin isi array
void copyArray(const int source[], int destination[], int n)
{
    memcpy(destination, source, n * sizeof(int));
}

/*
===========================
    GENERATE DATA RANDOM
===========================
*/

// Mengisi array dengan angka acak
void generateData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

/*
=====================
    INSERTION SORT
=====================
*/

void insertionSort(int arr[], int n)
{
    int i, j, key;

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

/*
===================
    BUBBLE SORT
===================
*/

void bubbleSort(int arr[], int n)
{
    int i, j, tertukar;

    for (i = 0; i < n - 1; i++)
    {
        tertukar = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            comparison++;

            if (arr[j] > arr[j + 1])
            {
                swapInt(&arr[j], &arr[j + 1]);
                swapCount++;
                tertukar = 1;
            }
        }

        if (!tertukar)
        {
            break;
        }
    }
}

/*
=====================
    SELECTION SORT
=====================
*/

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

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
==================
    MERGE SORT
==================
*/

// Fungsi untuk menggabungkan dua Sub-array yang sudah ter urut
static void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        printf("Gagal alokasi memori.\n");
        exit(EXIT_FAILURE);
    }

    int i, j, k;

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

void mergeSort(int arr[],
               int left,
               int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/*
=================
    QUICK SORT
=================
*/

// memilih bagian pivot dan membagi data menjadi dua
static int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        comparison++;

        if (arr[j] < pivot)
        {
            i++;

            if (i != j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                swapCount++;
            }
        }
    }

    if (i + 1 != high)
    {
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        swapCount++;
    }

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

/*
=======================
    TAMPILKAN ARRAY
=======================
*/

void DisplayArrInt(int arr[], int n, int jumlahTampil)
{
    int tampil = (n < jumlahTampil) ? n : jumlahTampil;

    for (int i = 0; i < tampil; i++)
    {
        printf("%10d", arr[i]);

        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");

    if (n > jumlahTampil)
    {
        printf("... (%d data tidak ditampilkan)\n",
               n - jumlahTampil);
    }
}

/*
======================
    RINGKASAN HASIL
======================
*/

void tampilkanRingkasan(const char *namaAlgoritma, int n, double waktuMs)
{
    printf("\n====================================\n");
    printf("Algoritma           : %s\n", namaAlgoritma);
    printf("Jumlah Data         : %d\n", n);
    printf("Jumlah Perbandingan : %lld\n", comparison);
    printf("Jumlah Pertukaran   : %lld\n", swapCount);
    printf("Waktu Eksekusi      : %.3f ms\n", waktuMs);
    printf("====================================\n");
}

/*
===========
    MENU
===========
*/

void menuSorting(void)
{
    int n;
    int pilihan;

    srand(time(NULL));

    printf("Masukkan jumlah data (n): ");
    scanf("%d", &n);

    while (n <= 1 || n > 500000)
    {
        printf("Input harus 1 < n <= 500000\n");
        scanf("%d", &n);
    }

    int *data = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    if (data == NULL || temp == NULL)
    {
        printf("Gagal alokasi memori.\n");
        return;
    }

    generateData(data, n);

    do
    {
        printf("\n====================================\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Acak Ulang Data\n");
        printf("7. Keluar\n");
        printf("====================================\n");

        printf("Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 5)
        {
            copyArray(data, temp, n);

            comparison = 0;
            swapCount = 0;

            const char *namaAlgoritma;

            clock_t start = clock();

            switch (pilihan)
            {
            case 1:
                namaAlgoritma = "Insertion Sort";
                insertionSort(temp, n);
                break;

            case 2:
                namaAlgoritma = "Bubble Sort";
                bubbleSort(temp, n);
                break;

            case 3:
                namaAlgoritma = "Selection Sort";
                selectionSort(temp, n);
                break;

            case 4:
                namaAlgoritma = "Merge Sort";
                mergeSort(temp, 0, n - 1);
                break;

            default:
                namaAlgoritma = "Quick Sort";
                quickSort(temp, 0, n - 1);
            }

            clock_t end = clock();

            double waktuMs =
                ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

            printf("\nData Setelah Sorting:\n");
            DisplayArrInt(temp, n, 100);

            tampilkanRingkasan(namaAlgoritma, n, waktuMs);
        }

        else if (pilihan == 6)
        {
            generateData(data, n);
            printf("Data berhasil diacak ulang.\n");
        }

    } while (pilihan != 7);

    free(data);
    free(temp);
}