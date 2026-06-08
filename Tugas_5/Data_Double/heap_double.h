#ifndef FUNGSI_HEAP_H
#define FUNGSI_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
================
    KONSTANTA
================s
*/

#define MAX_DOUBLE 3000000                           // Batas maksimum bilangan
#define OUTPUT_DOUBLE_FILE "hasil_sort_bilangan.txt" // Nama file output untuk hasil sorting Integer

/*
===========================
   DEKLARASI NAMA FUNGSI
===========================
*/

void generateData(double *arr, long long n);                          // menciptakan angka random dalam bentuk bilangan desimal
void minHeapify(double *arr, long long n, long long i);               // memperbaiki properti min heap dari posisi i ke bawah (digunakan dalam fungsi utama heapsort(Iteratif))
void buildMinHeap(double *arr, long long n);                          // membangun struktur min heap dari seluruh array berukuran n
void heapSortDesc(double *arr, long long n);                          //  mengurutkan array bilangan real secara DESCENDING
int savetoFile(const double *arr, long long n, const char *filename); // menyimpan hasil pengurutan kedalam file

/*
=====================
   FUNGSI UTILITAS
=====================
*/

void displayTime(double elapsed_seconds); // menampilkan waktu eksekusi
void menu(void);                          // main menu

#endif