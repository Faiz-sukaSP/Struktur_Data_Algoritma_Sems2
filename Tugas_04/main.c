#include "Standard_Sorting.h"

//
int main()
{
    int n;
    int pilihan;

    srand(time(NULL));

    printf("Masukkan Jumlah Bilangan (n): ");
    scanf("%d", &n);

    while (n <= 1 || n > 500000)
    {
        printf("Input harus 1 < n <= 500000\n");
        printf("Masukkan ulang n : ");
        scanf("%d", &n);
    }

    int *data = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    generateData(data, n);

    printf("Pengacakan data dalam array selesai\n");

    do
    {
        printf("====================================");
        printf("\n       Selamat Datang     \n");
        printf("Silahkan pilih algoritma pengurutan");
        printf("\n====================================\n");
        printf("1. INSERTION SORT\n");
        printf("2. BUBBLE SORT\n");
        printf("3. SELECTION SORT\n");
        printf("4. MERGE SORT\n");
        printf("5. QUICK SORT\n");
        printf("6. Acak ulang data dalam array\n");
        printf("7). Selesai\n");

        printf("Masukkan pilihan anda : ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 5)
        {
            copyArray(data, temp, n);

            comparison = 0;
            swapCount = 0;

            clock_t start = clock();

            switch (pilihan)
            {
            case 1:
                insertionSort(temp, n);
                break;

            case 2:
                bubbleSort(temp, n);
                break;

            case 3:
                selectionSort(temp, n);
                break;

            case 4:
                mergeSort(temp, 0, n - 1);
                break;

            case 5:
                quickSort(temp, 0, n - 1);
                break;
            }

            clock_t end = clock();

            double elapsed =
                (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nData Terurut:\n");
            DisplayArrInts(temp, n);

            printf("\nJumlah Perbandingan : %lld\n",
                   comparison);

            printf("Jumlah Pertukaran Data : %lld\n",
                   swapCount);

            printf("Waktu Eksekusi : %.6f detik\n",
                   elapsed);
        }

        else if (pilihan == 6)
        {
            printf("Masukkan Jumlah Bilangan (n): ");
            scanf("%d", &n);

            while (n <= 1 || n > 500000)
            {
                printf("Input harus 1 < n <= 500000\n");
                printf("Masukkan ulang n : ");
                scanf("%d", &n);
            }

            free(data);
            free(temp);

            data = (int *)malloc(n * sizeof(int));
            temp = (int *)malloc(n * sizeof(int));

            generateData(data, n);

            printf("Random data dalam array selesai\n");
        }

    } while (pilihan != 7);

    free(data);
    free(temp);

    return 0;
}