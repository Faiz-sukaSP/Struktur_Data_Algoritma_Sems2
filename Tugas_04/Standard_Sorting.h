#ifndef STANDARD_SORTING_H
#define STANDARD_SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
==================================
    VARIABEL GLOBAL STATISTIK
==================================
*/

extern long long comparison;
extern long long swapCount;

/*
======================
    FUNGSI UTILITAS
======================
*/

void generateData(int arr[], int n);
void copyArray(const int source[], int destination[], int n);

/*
=========================
    ALGORITMA SORTING
=========================
*/

void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

/*
===========================
    TAMPILAN DAN OUTPUT
===========================
*/

void DisplayArrInt(int arr[], int n, int jumlahTampil);
void tampilkanRingkasan(const char *namaAlgoritma,
                        int n,
                        double waktuMs);

/*
===============
   MAIN MENU
===============
*/
void menuSorting(void);

#endif