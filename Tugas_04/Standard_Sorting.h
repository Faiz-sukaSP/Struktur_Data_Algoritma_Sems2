#ifndef STANDARD_SORTING_H
#define STANDARD_SORTING_H

// Library yang digunakan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern long long comparison; // Menghitung jumlah perbandingan data selama sorting
extern long long swapCount;  // Menghitung jumlah pertukaran atau perpindahan data

// Utilitas
void generateData(int arr[], int n);                                       // Menghasilkan data berupa Integer
void copyArray(int source[], int destination[], int n);                    // Menyalin seluruh isi array sumber ke array tujuan
void DisplayArrInt(int arr[], int n, int jumlahTampil);                    // Menampilkan isi array ke layar
void tampilkanRingkasan(const char *namaAlgoritma, int n, double waktuMs); // output statistik program
// Fungsi standard sorting
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

// Fungsi Advance sorting
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

#endif