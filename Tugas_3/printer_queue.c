#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

// inisialisasi awal front dan rear
void init_arr(QueueArr *q_arr)
{
    q_arr->front = -1;
    q_arr->rear = -1;
}

// Cek apakah array kosong atau tidak
int isempty_arr(QueueArr *q_arr)
{
    return (q_arr->front = -1);
}

// Cek apakah array sudah penuh atau belum
int isfull_arr(QueueArr *q_arr)
{
    return (q_arr->rear = MAX - 1);
}

// Menambahkan antrian
void enqueue_arr(QueueArr *q_arr, char *doc)
{
    if (doc == NULL || strlen(doc) == 0)
    {
        printf("Dokumen yang anda berikan tidak valid!\n");
        return;
    }

    if (isfull_arr(q_arr))
    {
        char pilihan;
        while (1) // loop sampai user memilih pilihan yang tepat
        {
            // program memberitahukan bahwa antrian sudah penuh dan diminta untuk memberikan sebuah inputan
            printf("Kapasitas antrian sudah penuh, ingin dibersihkan(y/n)?");
            scanf(" %c", &pilihan); // menyimpan 1 huruf inputan dari user

            if (pilihan == 'y' || pilihan == 'Y') // jika user menginput huruf y/Y
            {
                // array dikosongkan dan user diberitahukan bahwa antrian telah kosong
                q_arr->front = -1;
                q_arr->rear = -1;
                printf("Antrian telah dikosongkan\n");
                break; // keluar dari loop
            }

            else if (pilihan == 'n' || pilihan == 'N') // jika user menginput n/N
            {
                return; // program berhenti
            }

            else
            {
                printf("anda menginput pilihan yang salah, pilih y/n!!\n"); // jika user bukan menginput pilihan yang sesuai
            }
        }
    }

    if (isempty_arr(q_arr))
    {
        q_arr->front = 0; // jika array masih kosong maka front sekarang bernilai 0
    }

    q_arr->rear++;                              // rear bertambah setiap antrian ditambahkan
    strncpy(q_arr->data[q_arr->rear], doc, 99); // doc disimpan kedalam struct data maks 99
    q_arr->data[q_arr->rear][99] = '\0';        // index ke-99/terakhir diisi dengan null terminator

    printf("Antrian berhasil ditambahkan\n"); // output ketika antrian berhasil ditambahkan
}

// Mengeluarkan antrian
void dequeue_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr)) // cek apakah antrian kosong atau tidak
    {
        printf("Antrian telah kosong, tidak ada dokomen lagi yang perlu di print\n");
        return;
    }
    printf("Mencetak dokumen: \"%s\"...\n", q_arr->data[q_arr->front]); // memberitahukan bahwa dokumen berhasil di dequeue

    // cek apakahnya hanya memiliki satu buah antrian saja
    if (q_arr->front == q_arr->rear)
    {
        // jika iya maka semua di set -1 kembali
        q_arr->front = -1;
        q_arr->rear = -1;
        return;
    }

    else
        q_arr->front++; // geser front ke elemen selanjutnya
}

// menampilkan antrian
void display_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr))
    {
        printf("Antrian kosong, tidak ada dokumen yang bisa ditampilkan");
        return;
    }
    printf("=== Antrian dokumen(array) ===\n");
    for (int i = q_arr->front; i < q_arr; i++)
    {
        printf("[%d] &s"), i - q_arr->front + 1, q_arr->data[i];
        if (i == q_arr->front)
            printf("  <- berikutnya dicetak");
        printf("\n");
    }
    printf("====================\n");
}

void peek_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr))
    {
        printf("Antrian kosong! Tidak ada dokumen yang akan dicetak.\n");
        return;
    }
    printf("Dokumen berikutnya yang akan dicetak: \"%s\"\n", q_arr->data[q_arr->front]);
}

// Mendeklarasikan fungi untuk menambahkan dokumen kedalam antrian
void tambah_dokumen(QueueArr *q_Arr)
{
    int data;
    printf("Masukkan ID Dokument: ");
    scanf("%d", data);
}