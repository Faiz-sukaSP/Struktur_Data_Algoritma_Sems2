#include "function_string.h"

// Menghitung berapa kali komparasi dan pertukaran
long long comparison = 0;
long long swapCount = 0;

/*
======================
    FUNGSI PEMBANTU
======================
*/

// Menyalin isi array
void copyArray(const char src[][MAX_WORD_LEN], char dst[][MAX_WORD_LEN], int n)
{
    memcpy(dst, src, n * MAX_WORD_LEN * sizeof(char));
}

/*
====================
    BACA FILE
====================
*/
// Membaca kata - kata dari sebuah file teks dan menyimpannya ke dalam array 2D.
int readFile(const char *namaFile, char data[][MAX_WORD_LEN])
{
    FILE *fp;
    int jumlahData = 0;

    fp = fopen(namaFile, "r");

    if (fp == NULL)
    {
        printf("File gagal dibaca, periksa ulang data kamu\n");
        printf("------------------------------------\n");
        return -1;
    }

    while (fscanf(fp, "%99s", data[jumlahData]) == 1)
    {
        jumlahData++;

        if (jumlahData >= MAX_WORD)
        {
            break;
        }
    }

    fclose(fp);

    return jumlahData;
}

/*
=====================
    INSERTION SORT
=====================
*/

// Fungsi Insertion Sort
void insertionSort(char arr[][MAX_WORD_LEN], int n)
{
    int i, j;
    char key[MAX_WORD_LEN];

    for (i = 1; i < n; i++)
    {
        // deklarasi awal
        strcpy(key, arr[i]);
        j = i - 1;

        while (j >= 0)
        {
            comparison++; // menghitung perbandingan
            if (strcmp(arr[j], key) > 0)
            {
                // pertukaran (j + 1 = j) karena arr j lebih besar dari key
                strcpy(arr[j + 1], arr[j]);
                swapCount++; // menghitung pertukaran
                j--;         // mundur
            }
            else
            {
                break;
            }
        }
        // arr j + 1 sekarang sama dengan key
        strcpy(arr[j + 1], key);
    }
}

/*
===================
    BUBBLE SORT
===================
*/

void bubbleSort(char arr[][MAX_WORD_LEN], int n)
{
    int i, j, swapped;
    char temp[MAX_WORD_LEN]; // temp seukuran MAX_WORD_LEN

    for (i = 0; i < n - 1; i++)
    {
        // deklarasi nilai tertukar awal = 0
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            comparison++; // menghitung perbandingan

            // lakukan perbandingan
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                // tukar
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);

                // bertambah setiap perbandingan
                swapCount++;
                swapped = 1;
            }
        }
        // jika tidak melakukan pertukaran
        if (!swapped)
            break;
    }
}
/*
=====================
    SELECTION SORT
=====================
*/

void selectionSort(char arr[][MAX_WORD_LEN], int n)
{
    int i, j;
    int minIndex;
    char temp[MAX_WORD_LEN];

    for (i = 0; i < n - 1; i++)
    {
        // data pertama menjadi index terkecil
        minIndex = i;

        // loop for langsung ke data kedua (awal)
        for (j = i + 1; j < n; j++)
        {
            // bertambah apabila masuk loop
            comparison++;

            // perbandingan
            if (strcmp(arr[j], arr[minIndex]) < 0)
            {
                // jika kondisi if benar maka minIndex menerima nilai j
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
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
static void merge(char arr[][MAX_WORD_LEN], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char (*L)[MAX_WORD_LEN] = malloc(n1 * sizeof(*L));
    char (*R)[MAX_WORD_LEN] = malloc(n2 * sizeof(*R));

    if (L == NULL || R == NULL)
    {
        printf("Gagal alokasi memori.\n");
        exit(EXIT_FAILURE);
    }

    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        strcpy(L[i], arr[left + i]);
    }

    for (j = 0; j < n2; j++)
    {
        strcpy(R[j], arr[mid + 1 + j]);
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        comparison++;

        if (strcmp(L[i], R[j]) <= 0)
        {
            strcpy(arr[k++], L[i++]);
        }
        else
        {
            strcpy(arr[k++], R[j++]);
        }

        swapCount++;
    }

    while (i < n1)
    {
        strcpy(arr[k++], L[i++]);
        swapCount++;
    }

    while (j < n2)
    {
        strcpy(arr[k++], R[j++]);
        swapCount++;
    }

    free(L);
    free(R);
}

void mergeSort(char arr[][MAX_WORD_LEN], int left, int right)
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
static int partition(char arr[][MAX_WORD_LEN], int low, int high)
{
    char pivot[MAX_WORD_LEN];
    strcpy(pivot, arr[high]); // Memilih elemen terakhir sebagai pivot

    int i = low - 1; // Indeks elemen terkecil
    char temp[MAX_WORD_LEN];

    for (int j = low; j < high; j++)
    {
        comparison++;

        // Jika elemen saat ini lebih kecil dari pivot secara alfabet
        if (strcmp(arr[j], pivot) < 0)
        {
            i++;

            // Tukar arr[i] dan arr[j] agar elemen yang lebih kecil berada di kiri
            if (i != j)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);

                swapCount++;
            }
        }
    }
    // Tempatkan pivot di posisi yang benar di antara elemen kecil dan besar
    if (i + 1 != high)
    {
        strcpy(temp, arr[i + 1]);
        strcpy(arr[i + 1], arr[high]);
        strcpy(arr[high], temp);
        swapCount++;
    }

    return i + 1;
}

// Fungsi Quick Sort
void quickSort(char arr[][MAX_WORD_LEN], int low, int high)
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

// menampilkan data
void DisplayArrString(char arr[][MAX_WORD_LEN], int n, int jumlahTampil)
{
    int tampil = (n < jumlahTampil) ? n : jumlahTampil;

    for (int i = 0; i < tampil; i++)
    {
        // menampilkan sebanyak 10 string
        printf("%-20s", arr[i]);

        // enter setiap kata
        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");

    // menampilkan jumlah data yang tidak ditampilkan
    if (n > jumlahTampil)
    {
        printf("-------------------------------------\n");
        printf("... (%d data tidak ditampilkan)\n", n - jumlahTampil);
        printf("-------------------------------------\n");
    }
}

/*
======================
    RINGKASAN HASIL
======================
*/

void displayStat(const char *namaAlgoritma, int n, double waktuMs)
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

void mainMenu(void)
{
    int pilihan;
    int totalWord;
    char nameFile[100];

    // Mengalokasikan memori dinamis di Heap untuk menghindari Stack Overflow
    char (*data)[MAX_WORD_LEN] = malloc(MAX_WORD * sizeof(*data));
    char (*temp)[MAX_WORD_LEN] = malloc(MAX_WORD * sizeof(*temp));

    // validasi malloc
    if (data == NULL || temp == NULL)
    {
        printf("\n====================================\n");
        printf("Gagal alokasi memori.\n");
        printf("====================================\n");
        return;
    }

    printf("\n====================================\n");
    printf("      PROGRAM SORTING STRING\n");
    printf("====================================\n");

    // loop untuk meminta user untuk menginput nama file hingga benar
    while (1)
    {
        printf("Masukkan nama file : ");
        scanf("%99s", nameFile);
        printf("------------------------------------\n");

        // isi file disimpan kedalam array
        totalWord = readFile(nameFile, data);

        // Jika readFile mengembalikan nilai > 0, artinya file sukses dibaca
        if (totalWord > 0)
        {
            printf("\n====================================\n");
            printf("File \"%s\" berhasil dibaca\n", nameFile);
            printf("Jumlah data : %d kata\n", totalWord);
            printf("====================================\n");
            break; // Keluar dari loop input file, lanjut ke menu algoritma
        }

        // Jika gagal, loop akan berulang dan meminta input lagi
        printf("\nSilakan masukkan kembali nama file dengan benar.\n");
        printf("------------------------------------\n");
    }

    do
    {
        printf("\n====================================\n");
        printf("        Silahkan Pilih Algoritma    \n");
        printf("====================================\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Baca File Baru\n");
        printf("7. Keluar\n");
        printf("====================================\n");

        printf("Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 5)
        {
            copyArray(data, temp, totalWord);

            comparison = 0;
            swapCount = 0;

            const char *namaAlgoritma;
            clock_t start = clock();

            switch (pilihan)
            {
            case 1:
                namaAlgoritma = "Insertion Sort";
                insertionSort(temp, totalWord);
                break;
            case 2:
                namaAlgoritma = "Bubble Sort";
                bubbleSort(temp, totalWord);
                break;
            case 3:
                namaAlgoritma = "Selection Sort";
                selectionSort(temp, totalWord);
                break;
            case 4:
                namaAlgoritma = "Merge Sort";
                mergeSort(temp, 0, totalWord - 1);
                break;
            case 5:
                namaAlgoritma = "Quick Sort";
                quickSort(temp, 0, totalWord - 1);
                break;
            }

            clock_t end = clock();
            double waktuMs = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

            printf("\n                            ================================\n");
            printf("                                   Data Setelah Sorting\n");
            printf("                            ================================\n");

            // memanggil fungsi yang telah di deklarasikan sebelumnya
            DisplayArrString(temp, totalWord, 100);
            displayStat(namaAlgoritma, totalWord, waktuMs);
        }
        else if (pilihan == 6)
        {
            char newFileName[100];
            printf("Masukkan nama file baru : ");
            scanf("%99s", newFileName);
            printf("------------------------------------\n");

            // Baca ke variabel sementara dulu agar jika gagal, data lama tidak hilang
            int checkData = readFile(newFileName, data);

            if (checkData <= 0)
            {
                printf("------------------------------------\n");
                printf("Gagal membaca \"%s\" Menolak memuat file baru\n", newFileName);
                printf("Program mempertahankan data dari file yang\ndi input sebelumnya\n");
                printf("------------------------------------\n");
            }
            else
            {
                strcpy(nameFile, newFileName);
                totalWord = checkData;
                printf("File baru berhasil dibaca.\n");
                printf("Jumlah data : %d kata\n", totalWord);
            }
        }

    } while (pilihan != 7);

    // Membebaskan memory dari heap
    free(data);
    free(temp);
}