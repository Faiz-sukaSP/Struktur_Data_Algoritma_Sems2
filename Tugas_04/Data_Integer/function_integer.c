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

// insertion sor
void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i]; // array i akan menjadi kunci
        j = i - 1;

        // menggeser elemen yang lebih besar dari key ke kanan
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

// fungsi bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // flag optimasi

        for (j = 0; j < n - 1 - i; j++)
        {
            comparison++;

            // untuk menukar element
            if (arr[j] > arr[j + 1])
            {
                swapInt(&arr[j], &arr[j + 1]);
                swapCount++;
                swapped = 1;
            }
        }

        // jika array sudah ter urut, berhenti
        if (!swapped)
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

// fungsi selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        // elemen pertama menjadi index
        minIndex = i;

        // cari elemen terkecil
        for (j = i + 1; j < n; j++)
        {
            comparison++;

            // bandingkan array ke-j dan minIndex
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // jika ditemukan lebih kecil, tukar
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

    // alokasi memori
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        printf("---------------------\n");
        printf("Gagal alokasi memori\n");
        printf("---------------------\n");
        exit(EXIT_FAILURE);
    }

    int i, j, k;

    // Menyalin data asli ke sub-array sementara L dan R
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // gabungkan kembali dengan membandingkan nilai terkecil
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

    // Menyalin sisa elemen L jika masih ada
    while (i < n1)
    {
        arr[k++] = L[i++];
        swapCount++;
    }

    // Menyalin sisa elemen R jika masih ada
    while (j < n2)
    {
        arr[k++] = R[j++];
        swapCount++;
    }

    // bebaskan memory
    free(L);
    free(R);
}

// Fungsi merge sort
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

/*
=================
    QUICK SORT
=================
*/

// memilih bagian pivot dan membagi data menjadi dua
static int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // element terakhir menjadi pivot
    int i = low - 1;       // indeks elemen yang lebih kecil
    int temp;

    for (int j = low; j < high; j++)
    {
        comparison++;

        // tukar
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

    // letakkan pivot di tengah
    if (i + 1 != high)
    {
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swapCount++;
    }

    return i + 1; // Mengembalikan indeks posisi pivot sekarang
}

// fungsi utama quick sort (rekursif)
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

// Menampilkan data
void DisplayArrInt(int arr[], int n, int jumlahTampil)
{
    int tampil = (n < jumlahTampil) ? n : jumlahTampil;

    for (int i = 0; i < tampil; i++)
    {

        printf("%-10d", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    // Hanya cetak enter jika baris terakhir belum ter-enter otomatis oleh loop
    if (tampil % 10 != 0)
    {
        printf("\n");
    }
    printf("\n");

    // menampilkan jumlah data yang tidak ditampilkan ke layar
    if (n > jumlahTampil)
    {
        printf("-------------------------------------------\n");
        printf("... (%d data tidak ditampilkan)\n", n - jumlahTampil);
        printf("-------------------------------------------\n");
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
    int n = 0;
    int pilihan;

    srand(time(NULL));

    printf("\n      ====================================\n");
    printf("            PROGRAM SORTING INTEGER\n");
    printf("      ====================================\n");

    while (1)
    {
        printf("Masukkan jumlah data awal (1 < n <= 5000000): ");
        scanf("%d", &n);

        if (n > 1 && n <= 5000000)
        {
            break; // Input benar, keluar dari validasi
        }
        printf("Input salah! Batas data harus di antara 2 sampai 5.000.000.\n");
        printf("-----------------------------------------------------------\n");
    }

    // mengalokasikan memory
    int *data = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    // validasi apakah malloc berhasil
    if (data == NULL || temp == NULL)
    {
        printf("=====================\n");
        printf("Gagal alokasi memori.\n");
        printf("=====================\n");
        return;
    }
    // memanggil fungsi untuk menghasilkan angka random
    generateData(data, n);
    printf("Berhasil membuat %d data acak awal....\n", n);
    printf("-----------------------------------------------------\n");

    do
    {
        printf("\n Silahkan Pilih Algoritma yang Diinginkan");
        printf("\n==========================================\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Mengacak ulang bilangan\n");
        printf("7. Keluar\n");
        printf("==========================================\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        // validasi pilihan user
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
            //
            clock_t end = clock();
            double waktuMs = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

            printf("                                =======================");
            printf("\n                                  Data Setelah Sorting\n");
            printf("                                -----------------------\n");

            // menampilkan kata dan ringkasan
            DisplayArrInt(temp, n, 100);
            tampilkanRingkasan(namaAlgoritma, n, waktuMs);
        }

        else if (pilihan == 6)
        {
            {
                // meminta user untuk menentukan jumlah data yang ingin di urutkan
                printf("\n---------------------------------------------\n");
                printf("Masukkan jumlah data (Max = 5000000): ");
                scanf("%d", &n);
                printf("---------------------------------------------\n");

                // Batas 5 juta
                while (n <= 1 || n > 5000000)
                {
                    printf("Input harus 1 < n <= 5000000\n");
                    printf("\n==============================\n");
                    printf("Masukkan jumlah data (n): ");
                    printf("==============================\n");
                    scanf("%d", &n);
                }

                // Bebaskan memori lama, alokasi memori baru
                free(data);
                free(temp);
                data = malloc(n * sizeof(int));
                temp = malloc(n * sizeof(int));

                // validasi malloc
                if (data == NULL || temp == NULL)
                {
                    printf("=====================\n");
                    printf("Gagal alokasi memori\n");
                    printf("=====================\n");
                    return;
                }

                // generate data baru
                generateData(data, n);
                printf("====================================================\n");
                printf("Data baru (%d angka acak) berhasil di-generate\n", n);
                printf("====================================================\n");
            }
        }

    } while (pilihan != 7);

    free(data);
    free(temp);
}