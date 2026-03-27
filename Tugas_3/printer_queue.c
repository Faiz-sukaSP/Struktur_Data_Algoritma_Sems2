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
    return (q_arr->front == -1);
}

// Cek apakah array sudah penuh atau belum
int isfull_arr(QueueArr *q_arr)
{
    return (q_arr->rear == MAX - 1);
}

// membersihkan array
void clear_arr(QueueArr *q)
{
    // set kembali front dan rear menjadi -1
    q->front = -1;
    q->rear = -1;
    printf("=== Antrian dikosongkan ===\n"); // output setelah array berhasil dikosongkan
}

// Menambahkan antrian
void enqueue_arr(QueueArr *q_arr, char *doc)
{
    if (doc == NULL || strlen(doc) == 0) // cek apakah dokumen ada isi atau tidak
    {
        printf("\nDokumen yang anda berikan tidak valid!\n"); // output yang diberikan ketika dokumen tidak ada isi
        return;
    }

    if (isfull_arr(q_arr))
    {
        char pilihan;
        while (1) // loop sampai user memilih pilihan yang tepat
        {
            // program memberitahukan bahwa antrian sudah penuh dan diminta untuk memberikan sebuah inputan
            printf("\nKapasitas antrian sudah penuh, ingin dibersihkan (y/n)?");
            scanf(" %c", &pilihan); // menyimpan 1 huruf inputan dari user

            if (pilihan == 'y' || pilihan == 'Y') // jika user menginput huruf y/Y
            {
                // array dikosongkan dan user diberitahukan bahwa antrian telah kosong
                clear_arr(q_arr);
                break; // keluar dari loop
            }

            else if (pilihan == 'n' || pilihan == 'N') // jika user menginput n/N
            {
                return; // program berhenti
            }

            else
            {
                printf("\nanda menginput pilihan yang salah, pilih y/n!!\n"); // jika user bukan menginput pilihan yang sesuai
            }
        }
    }

    if (isempty_arr(q_arr))
    {
        q_arr->front = 0; // jika array masih kosong maka front sekarang bernilai 0
    }

    q_arr->rear++;                                   // rear bertambah setiap antrian ditambahkan
    strncpy(q_arr->data[q_arr->rear], doc, MAX - 1); // doc disimpan kedalam struct data maks 99
    q_arr->data[q_arr->rear][MAX - 1] = '\0';        // index ke-99/terakhir diisi dengan null terminator

    printf("Antrian berhasil ditambahkan\n"); // output ketika antrian berhasil ditambahkan
    printf("===============================\n");
}

// Mengeluarkan antrian
void dequeue_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr)) // cek apakah antrian kosong atau tidak
    {
        printf("\n===============================\n");
        printf("Antrian telah kosong, tidak ada dokumen lagi yang perlu di print\n");
        return;
    }
    printf("\n===============================\n");
    printf("Mencetak dokumen: \"%s\"...\n", q_arr->data[q_arr->front]); // memberitahukan bahwa dokumen berhasil di dequeue
    printf("===============================\n");
    // cek apakahnya hanya memiliki satu buah antrian saja
    if (q_arr->front == q_arr->rear)
    {
        // jika iya maka semua di set -1 kembali
        clear_arr(q_arr);
        return;
    }

    else
        q_arr->front++; // geser front ke elemen selanjutnya
}

// menampilkan antrian
void display_arr(QueueArr *q_arr)
{
    // cek terlebih dahulu apakah array kosong atau tidak
    if (isempty_arr(q_arr))
    {
        printf("Antrian kosong, tidak ada dokumen yang bisa ditampilkan\n");
        return;
    }
    // menampilkan setiap antrian
    printf("\n===============================\n");
    printf("=== Antrian dokumen(array) ===\n");
    for (int i = q_arr->front; i <= q_arr->rear; i++) // loop dimulai dari index perama hingga akhirs
    {
        printf("[%d] %s", i - q_arr->front + 1, q_arr->data[i]); // menampilkan urutan dan data dalam antrian
        if (i == q_arr->front)                                   // jika i = data pertama
            printf("  <- berikutnya dicetak");                   // akan mencetak ini sebaris dengan urutan dan data dalam antrian
        printf("\n");
    }
    printf("===============================\n");
}

void peek_arr(QueueArr *q_arr)
{
    // cek terlebih dahulu apakah ada array
    if (isempty_arr(q_arr))
    {
        printf("\n===============================\n");
        printf("Antrian kosong! Tidak ada dokumen yang akan dicetak.\n");
        return;
    }
    printf("\n===============================\n");
    printf("Dokumen berikutnya yang akan dicetak: \"%s\"\n", q_arr->data[q_arr->front]); // menampilkan data pertama
    printf("===============================\n");
}

/*
=================================
        QUEUE LINKED LIST
=================================
*/

// Inisialisasi awal lingked list
void init_queue_ll(QueueLL *q_ll)
{
    // inisialisasi awal bahwa queue masih kosong
    q_ll->front = NULL;
    q_ll->rear = NULL;
    q_ll->size = 0;
}

// Fungsi cek antrian
int isempty_ll(QueueLL *q_ll)
{
    return q_ll->front == NULL; // cek apakah fron bernilai NULL
}

// Fungsi menambahkan antrian (enqueue)
void enqueue_ll(QueueLL *q_ll, const char *data)
{
    NodeLL newnode = (NodeLL)malloc(sizeof(QueueNode)); // mengalokasikan memory di heap seukuran QueueNode

    if (newnode == NULL)
    {
        printf("\n===============================\n");
        printf("Gagal mengalokasikan memory.... memory penuh!"); // pemberitahuan apabila malloc gagal
        printf("\n===============================\n");
    }
    strcpy(newnode->data, data); // menyalin string input kedalam node
    newnode->next = NULL;        // set next = NULL

    if (isempty_ll(q_ll)) // cek apakah queue kosong
    {
        q_ll->front = q_ll->rear = newnode; // node pertama, front dan rear menunjuk ke node yang sama
    }
    else
    {
        q_ll->rear->next = newnode; // sambungkan ke node terakhir
        q_ll->rear = newnode;       // update rear ke node yang baru
    }

    q_ll->size++;                                // size bertambah
    printf("Dokumen %s masuk ke antrian", data); // output sistem
    printf("\n===============================\n");
}

// Fungsi untuk mengeluarkan antrian
void dequeue_LL(QueueLL *q_ll)
{
    if (is_emptyLL(q_ll)) // cek antrian
    {
        printf("Antrian kosong!\n"); // ouput apabila antian kosong
        return;                      // keluar dari fungsi
    }

    NodeLL temp = q_ll->front; // temp menyimpan alamat antrian pertama

    printf("Mencetak: %s\n", temp->data); // menampilkan data yang dicetak

    q_ll->front = temp->next; // front sekarang pindah ke node selanjutnya

    if (q_ll->front == NULL) // cek apakah antrian menjadi kosong seelah di dequeue
    {
        q_ll->rear = NULL; // set rear = NULL
    }

    free(temp);   // menghapus data yang disimpan oleh temp agar tidak ada kebocoran memory
    q_ll->size--; // size berkurang 1
}

// Fungsi untuk menampilkan elemen yang akan di cetak
void peak_LL(QueueLL *q_ll)
{
    if (isempty_ll(q_ll))
    {
        printf("\n===============================\n");
        printf("Antrian telah dicetak semuanya\n"); // output jika antrian telah kosong
        printf("\n===============================\n");
        return; // keluar dari fungsi
    }

    else
    {
        printf("\n===============================\n");
        printf("Dokumen berikutnya : %s\n", q_ll->front->data); // menampilkan dokumen yang akan dicetak
        printf("\n===============================\n");
    }
}

// Fungsi untuk menampilkan list antrian
void display_LL(QueueLL *q_ll)
{
    if (is_emptyLL(q_ll)) // cek apakah antrian kosong atau tidak
    {
        printf("Antrian kosong!\n"); // ouput apabila antian kosong
        return;                      // keluar dari fungsi
    }
    // menampilkan setiap antrian
    printf("\n===============================\n");
    printf("=== Antrian dokumen(LL) ===\n");

    NodeLL temp = q_ll->front; // temp menyimpan antrian terdepan
    while (temp != NULL)       // loop hingga antrian kosong
    {
        printf("Antrian: %s\n", temp->data);
        temp = temp->next; // temp menyimpan alamat selanjutnya
        printf("\n===============================\n");
    }
}