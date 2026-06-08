#include "heap_double.h"

/*
========================
    FUNGSI UTILITAS
========================
*/

// menampilkan waktu eksekusi dalam satuan yang sesuai
void displayTime(double elapsed_seconds)
{
    if (elapsed_seconds < 1.0)
    {
        printf("Waktu pengurutan : %.3f Ms\n",
               elapsed_seconds * 1000.0);
    }
}

/*
========================
    DEKLARASI FUNGSI
========================
*/

// mengasilkan bilangan random (desimal)
void generateData(double *arr, long long n)
{
    // iterasi mengisi setiap slot array dengan bilangan real acak
    for (long long i = 0; i < n; i++)
    {
        // menghasilkan nilai dalam rentang 0 < x < 1
        arr[i] = (double)rand() / ((double)RAND_MAX + 1.0);
    }
}

// memperbaiki properti min heap dari posisi i ke bawah (iteratif)
void minHeapfy(double *arr, long long n, long long i)
{
    long long current;  // posisi node yang sedang diperiksa saat ini
    long long smallest; // posisi elemen terkecil di antara node dan kedua anaknya
    long long left;     // indeks anak kiri: 2*current + 1
    long long right;    // indeks anak kanan: 2*current + 2
    double temp;        // variabel sementara untuk operasi tukar (swap)

    current = i; // i disimpan kedalam node yang akan diperiksa

    // Lanjutkan heapify selama belum mencapai kondisi heap yang valid
    while (1)
    {
        smallest = current;      // anggap current node terkecil
        left = 2 * current + 1;  // hitung indeks anak kiri
        right = 2 * current + 2; // hitung indeks anak kanan

        // periksa apakah node kiri VALID (dalam batas) dan lebih KECIL dari "smallest"
        if (left < n && arr[left] < arr[smallest])
        {
            smallest = left; // Anak kiri lebih kecil, perbarui posisi 'smallest'
        }

        // Periksa apakah anak kanan sesuai dan lebih kecil dari 'smallest'
        if (right < n && arr[right] < arr[smallest])
        {
            smallest = right; // Anak kanan lebih kecil, perbarui posisi 'smallest'
        }

        // Jika current sudah merupakan yang terkecil, properti min-heap terpenuhi
        if (smallest == current)
        {
            break; // Hentikan iterasi
        }

        // Tukar nilai pada posisi current dengan posisi smallest
        temp = arr[current];
        arr[current] = arr[smallest];
        arr[smallest] = temp;

        current = smallest; // Lanjutkan heapify ke bawah dari posisi yang baru
    }
}

// mengubah array arr menjadi struktur min heap secara inplace
void buildMinHeap(double *arr, long long n)
{
    long long i; // indeks loop, mulai dari node non leaf terakhir

    // Iterasi dari node non-leaf terakhir menuju root (indeks 0)
    for (i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i); // Terapkan min-heapify pada setiap node non-leaf
    }
}

// mengurutkan arr secara descending menggunakan algoritma Heap Sort
void heapSortDesc(double *arr, long long n)
{
    long long i;
    double temp;

    // memanggil fungsi untuk membangun min heap
    buildMinHeap(arr, n);

    // ekstrak minimum satu per satu ke posisi akhir — O(n log n)
    for (i = n - 1; i > 0; i--)
    {
        // Tukar root (nilai terkecil saat ini) dengan elemen terakhir yang belum di urutkan
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Perbaiki heap yang kini berukuran i (tanpa elemen ke-i yang sudah final)
        minHeapify(arr, i, 0);
    }
}

// menyimpan n bilangan real ke file teks dengan header informasi
int savetoFile(const double *arr, long long n, const char *filename)
{
    FILE *fp;

    // buka file dalam mode tulis
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        // validasi apabila gagal membuka file
        fprintf(stderr, "  [ERROR] Tidak dapat membuka '%s' untuk penulisan.\n", filename);
        return -1; /* Kembalikan kode error (-1) */
    }

    // tulis baris-baris header sebagai informasi file
    fprintf(fp, "============================================================\n");
    fprintf(fp, "Hasil Pengurutan Bilangan Real (Besar ke Kecil)\n");
    fprintf(fp, "Metode      : HEAP SORT (Min-Heap)\n");
    fprintf(fp, "Jumlah data : %lld bilangan\n", n);
    fprintf(fp, "============================================================\n");

    // tulis setiap bilangan real ke file, satu per baris
    for (long long i = 0; i < n; i++)
    {

        fprintf(fp, "%.15f\n", arr[i]);
    }

    fclose(fp); // Tutup file setelah selesai menulis
    return 0;
}

// output program (entry point)
void menu(void)
{
    double *arr = NULL;
    long long n = 0;
    int quit = 0;
    char buf[64];
    clock_t tStart;
    clock_t tEnd;
    double elapsed;
    long long i;
    int pilihan;

    printf("\n=========================================================\n");
    printf("         PENGURUTAN BILANGAN REAL DENGAN HEAP SORT     \n");
    printf("=========================================================\n");

    /* Loop utama: ulangi seluruh proses jika user memilih opsi 2 (acak ulang) */
    while (!quit)
    {

        // meminta user untuk menginpun banyak bilangan terlebih dahulu
        n = 0; // riset n = 0
        do
        {

            printf("Masukkan Jumlah Bilangan (n): ");
            printf("--------------------------------------------");

            // Baca input dengan fgets untuk menghindari buffer overflow
            if (fgets(buf, (int)sizeof(buf), stdin) == NULL)
            {
                // EOF atau error pembacaan stdin
                fprintf(stderr, "Gagal membaca input (EOF).\n");
                if (arr != NULL)
                {
                    // Bebaskan memori jika sudah dialokasikan
                    free(arr);
                    arr = NULL;
                }
                return;
            }

            n = atoll(buf); // konversi string input ke long long

            // validasi rentang (1 < x ≤ 3000000)
            if (n <= 1 || n > (long long)MAX_DOUBLE)
            {
                printf("Nilai n harus antara 2 dan %d. Coba lagi.\n", MAX_DOUBLE);
            }
        } while (n <= 1 || n > (long long)MAX_DOUBLE); // ulangi jika input tidak valid

        /* bebaskan memori lama sebelum alokasi baru (hindari memory leak) */
        if (arr != NULL)
        {
            free(arr);
            arr = NULL;
        }

        // alokasikan memori dinamis untuk n elemen double
        arr = (double *)malloc((size_t)n * sizeof(double));
        if (arr == NULL)
        {
            // malloc gagal (memori tidak mencukupi)
            fprintf(stderr,
                    "Gagal mengalokasikan memori untuk %lld elemen (%.1f MB)\n", n, (double)n * sizeof(double) / (1024.0 * 1024.0));
            return;
        }

        // set seed acak berdasarkan waktu saat ini agar hasil selalu berbeda
        srand((unsigned int)time(NULL));

        // isi seluruh array dengan bilangan real acak
        generateData(arr, n);
        printf("Random bilangan real dalam array selesai...\n");

        {
            int menuOn = 1; // Flag loop menu: 1 = tampilkan menu, 0 = keluar menu

            while (menuOn)
            {
                // tampilkan opsi menu ke layar
                printf("\nPilihan\n");
                printf("  1) Mengurutkan data bilangan real dengan metode HEAP SORT dan\n");
                printf("     menyimpan hasil dalam file teks serta menampilkan waktu\n");
                printf("     pengurutan\n");
                printf("  2) Tentukan jumlah bilangan dan acak ulang bilangan real dalam\n");
                printf("     array\n");
                printf("  3) Selesai\n");
                printf("Pilihan anda: ");

                // baca pilihan user
                if (fgets(buf, (int)sizeof(buf), stdin) == NULL)
                {
                    quit = 1;
                    menuOn = 0;
                    break;
                }
                pilihan = atoi(buf); // konversi string ke integer

                // pilihan menu 1
                if (pilihan == 1)
                {
                    printf("===============================");
                    printf("\nMengurutkan %lld bilangan real \n", n);
                    printf("===============================");

                    // catat waktu CPU tepat sebelum sorting
                    tStart = clock();

                    // jalankan algoritma heap sort descending pada array
                    heapsort_double_desc(arr, n);

                    // catat waktu CPU tepat setelah sorting selesai
                    tEnd = clock();

                    // hitung waktu eksekusi
                    elapsed = (double)(tEnd - tStart) / (double)CLOCKS_PER_SEC;

                    // tampilkan waktu eksekusi
                    display_time(elapsed);

                    // tampilkan sampel 10 data pertama (nilai terbesar)
                    printf("\n  --- Sampel 10 Data Pertama (Terbesar) ---\n");
                    {
                        long long show; // Jumlah data yang akan ditampilkan
                        show = (n < 10LL) ? n : 10LL;
                        for (i = 0; i < show; i++)
                        {
                            // tampilkan nomor urut dan nilai bilangan
                            printf("    [%7lld] %.15f\n", i + 1LL, arr[i]);
                        }
                    }

                    // Jika data > 20, tampilkan juga 10 data terakhir (terkecil) */
                    if (n > 20LL)
                    {

                        printf("  --- Sampel 10 Data Terakhir (Terkecil) ---\n");
                        for (i = n - 10LL; i < n; i++)
                        {
                            // tampilkan nomor urut dan nilai bilangan
                            printf("    [%7lld] %.15f\n", i + 1LL, arr[i]);
                        }
                    }

                    // simpan seluruh data terurut ke file teks
                    printf("--------------------------------------------------");
                    printf("\n  Menyimpan %lld data ke '%s'...\n", n, OUTPUT_DOUBLE_FILE);

                    // validasi apabila berhasil menyimpan
                    if (save_doubles_to_file(arr, n, OUTPUT_DOUBLE_FILE) == 0)
                    {

                        printf("Hasil berhasil disimpan ke '%s'\n", OUTPUT_DOUBLE_FILE);
                        printf("--------------------------------------------------");
                    }
                }

                // pilihan menu 2
                else if (pilihan == 2)
                {
                    menuOn = 0;
                }

                // pilihan menu 3
                else if (pilihan == 3)
                {
                    //
                    // keluar dari seluruh program
                    printf("\n  Keluar dari Program 1.\n");
                    quit = 1;
                    menuOn = 0;
                }

                // validasi jika user menginput bukan angka 1-3
                else
                {
                    printf("================================================\n");
                    printf("Pilihan tidak valid. Masukkan angka 1, 2, atau 3\n");
                    printf("------------------------------------------------\n");
                }
            }
        }
    }

    // membebaskan semua memori yang masih dialokasikan
    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }
}