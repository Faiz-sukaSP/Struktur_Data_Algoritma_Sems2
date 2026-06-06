#ifndef FUNCTION_STRING_H
#define FUNCTION_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
==================================
    VARIABEL GLOBAL STATISTIK
==================================
*/

// Mendefinikan panjang baris dan jumlah huruf
#define MAX_WORD_LEN 100
#define MAX_WORD 30000

// Menghitung berapa kali komparasi dan pertukaran
extern long long comparison;
extern long long swapCount;

/*
============
    FILE
============
*/
// Fungsi untuk membaca file dan menyalin kata
int readFile(const char *namaFile, char data[][MAX_WORD_LEN]);
void copyArray(const char src[][MAX_WORD_LEN], char dst[][MAX_WORD_LEN], int n);

/*
=======================
    SORTING FUNCTION
=======================
*/

// Standard Sorting
void insertionSort(char arr[][MAX_WORD_LEN], int n);
void bubbleSort(char arr[][MAX_WORD_LEN], int n);
void selectionSort(char arr[][MAX_WORD_LEN], int n);

// Advance Sorting
void mergeSort(char arr[][MAX_WORD_LEN], int left, int right);
void quickSort(char arr[][MAX_WORD_LEN], int low, int high);

/*
=======================
    DISPLAY FUNCTION
=======================
*/

void displayWord(char arr[][MAX_WORD_LEN], int n, int displayAmount);
void displayStat(const char *namaAlgoritma, int n, double waktuMs);
void mainMenu(void);

#endif
