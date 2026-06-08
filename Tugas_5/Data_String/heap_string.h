#ifndef HEAP_STRING_H
#define HEAP_STRING_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
================
    KONSTANTA
================
*/

#define MAX_WORD_LEN 512                        // panjang maksimal dari satu kata
#define MAX_WORD 327G8                          // kapasitas awal array dinamis untuk menyimpan kata
#define OUTPUT_WORDS_FILE "hasil_sort_kata.txt" // hasil output sorting

/*
======================
   DEKLARASI FUNGSI
======================
*/

/*
 * Parameter:
 *   words    - triple pointer; fungsi mengalokasikan dan mengisi *words
 *   capacity - pointer ke kapasitas saat ini (bisa bertambah)
 *   filename - nama/path file teks yang akan dibaca
 * Return: jumlah kata berhasil dibaca (>= 1), atau -1 jika terjadi kesalahan
 */

// Membaca semua kaya dari file teks
int loadFile(char ***words, int *capacity, const char *filename);

/*
 * Parameter:
 *   words - array pointer ke string
 *   n     - ukuran heap aktif
 *   i     - indeks node yang akan di-heapify
 */
// Memperbaiki properti max heap dari posisi i ke bawah
void maxHeapifyWords(char **words, int n, int i);
/*
 * Parameter:
 *   words - array pointer ke string yang akan diubah menjadi max-heap
 *   n     - jumlah elemen
 */
// Membangun struktu max heap
void buildMaxHeap(char **words, int n);

/*
 * Prinsip: max-heap mengekstrak maksimum ke posisi akhir berurutan
 * sehingga menghasilkan words[0] <= words[1] <= ... <= words[n-1]
 * Parameter:
 *   words - array pointer ke string yang akan diurutkan (dimodifikasi in-place)
 *   n     - jumlah elemen
 */
// Mengurutkan array kata (ascending)
void heapSortAsc(char **words, int n);

/*
 * Parameter:
 *   words    - array pointer ke string (const: tidak dimodifikasi)
 *   n        - jumlah kata
 *   filename - nama/path file tujuan
 */

// Menyimpan hasil pengurutan kedalam sebuah file
int saveWordsToFile(const char **words, int n, const char *filename);

/*
===============
    UTILITAS
===============
*/

/*
 * display_time
 * Menampilkan waktu eksekusi dalam satuan yang paling mudah dibaca:
 *   - < 1 milidetik  : tampilkan dalam mikrodetik (µs)
 *   - < 1 detik      : tampilkan dalam milidetik  (ms)
 *   - >= 1 detik     : tampilkan dalam detik      (s)
 *
 * Parameter:
 *   elapsed_seconds - waktu eksekusi dalam satuan detik (double)
 */
void display_time(double elapsed_seconds);

/*
 * run_problem2
 * Menjalankan alur interaktif lengkap Problem 2:
 * input filename → muat kata → menu (sort/muat ulang/keluar)
 */
void menu(void);

#endif