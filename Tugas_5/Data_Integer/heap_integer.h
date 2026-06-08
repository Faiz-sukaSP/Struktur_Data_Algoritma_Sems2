#ifndef FUNGSI_HEAP_H
#define FUNGSI_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
================
    KONSTANTA
================
*/

#define MAX_INT 3000000                              // Batas maksimum bilangan
#define OUTPUT_DOUBLE_FILE "hasil_sort_bilangan.txt" // Nama file output untuk hasil sorting Integer

/*
======================
   DEKLARASI FUNGSI
======================
*/

// Menciptakan angka random dalam bentuk bilangan desimal
void generateData(double *arr, long long n);

/*
 * Parameter:
 *   arr - array bilangan real
 *   n   - ukuran heap aktif (bagian yang belum diurutkan)
 *   i   - indeks node yang akan di-heapify
 */

// Sorting descending (digunakan dalam fungsi utama heapsort(Iteratif))
void min_heapify_double(double *arr, long long n, long long i);

/*
 * Parameter:
 *   arr - array bilangan real yang akan diubah menjadi min-heap
 *   n   - jumlah elemen dalam array
 */

// Membangun struktur min heap dari seluruh array berukuran n
void buildMinHeap(double *arr, long long n);

/*
 * heapsort_double_desc
 * Mengurutkan array bilangan real secara DESCENDING (besar ke kecil)
 * menggunakan algoritma Heap Sort berbasis min-heap
 * Kompleksitas: O(n log n) waktu, O(1) ruang tambahan (in-place)
 *
 * Prinsip: min-heap mengekstrak minimum ke posisi akhir berurutan
 * sehingga menghasilkan arr[0] >= arr[1] >= ... >= arr[n-1]
 *
 * Parameter:
 *   arr - array bilangan real yang akan diurutkan (dimodifikasi in-place)
 *   n   - jumlah elemen dalam array
 */

//  Mengurutkan array bilangan real secara DESCENDING
void heapSortDesc(double *arr, long long n);

/*
 * save_doubles_to_file
 * Menyimpan n bilangan real terurut ke file teks, satu bilangan per baris
 *
 * Parameter:
 *   arr      - array bilangan real (const: tidak dimodifikasi)
 *   n        - jumlah elemen
 *   filename - nama/path file tujuan
 *
 * Return: 0 jika berhasil, -1 jika gagal membuka/menulis file
 */

// menyimpan hasil pengurutan kedalam file
int savetoFile(const double *arr, long long n, const char *filename);

/* ================================================================
   DEKLARASI FUNGSI UTILITAS
   ================================================================ */

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
 * run_problem1
 * Menjalankan alur interaktif lengkap Problem 1:
 * input n → generate random → menu (sort/ulang/keluar)
 */
void run_problem1(void);

/*
 * run_problem2
 * Menjalankan alur interaktif lengkap Problem 2:
 * input filename → muat kata → menu (sort/muat ulang/keluar)
 */
void run_problem2(void);

#endif