#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
=================================
          QUEUE ARRAY
=================================
*/

// inisialisasi awal front dan rear
void init_arr(QueueArr *q_arr)
{
    q_arr->front = -1;
    q_arr->rear = -1;
}

// Cek apakah array kosong atau tidak
int isempty_arr(QueueArr *q_arr)
{
    return q_arr->front == -1;
}

// Cek apakah array sudah penuh atau belum
int isfull_arr(QueueArr *q_arr)
{
    return q_arr->rear == MAX - 1; // mengembalikan nilai true apabila rear di index MAX - 1
}

// set kembali array menjadi kosong (fungsi sama dengan inisialisasi)
void clear_arr(QueueArr *q_arr)
{
    q_arr->front = -1;
    q_arr->rear = -1;
}

// menghitung nilai elemen didalam antrian
int count_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr)) // cek apakah antrian kosong
        return 0;           // keluar dari fungsi apabila antrian kosong

    return q_arr->rear - q_arr->front + 1; // mengembalikan nilai dari hasil selisih antara rear dan front + 1
}

// Menambahkan antrian
void enqueue_arr(QueueArr *q_arr, char *data)
{
    // cek apakah antrian sudah penuh atau tidak
    if (isfull_arr(q_arr))
    {
        printf("\nKapasitas antrian sudah penuh"); // output jika antrian penuh
        return;                                    // keluar dari fungsi
    }

    if (isempty_arr(q_arr)) // jika array masih bisa di isi /kosong
    {
        q_arr->front = 0; // set fron = 0
    }

    q_arr->rear++;                                                       // rear pinda ke index selanju
    strncpy(q_arr->data[q_arr->rear], data, sizeof(q_arr->data[0]) - 1); // data disimpan kedalam pointer data dengan maksimal MAX - 1
    q_arr->data[q_arr->rear][sizeof(q_arr->data[0]) - 1] = '\0';         // set string data ke 99 berupa NULL terminator
}

// fungsi untuk mengeluarkan antrian
void dequeue_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr))
    { // cek apakah antrian kosong
        printf("=== Antrian Kosong ===\n");
        printf("===============================\n\n");
        return; // keluar dari fungsi apabila antrian kosong
    }

    if (q_arr->front == q_arr->rear) // cek apakah nilai front sama dengan rear
    {
        // set bahwa antrian telah kosong
        q_arr->front = -1;
        q_arr->rear = -1;
    }

    // jika front belum sama dengan rear
    else
    {
        q_arr->front++; // menggeser front ke index selanjutnya
    }
}

void display_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr))
    { // cek apakah antrian kosong
        printf("=== Antrian Kosong ===\n");
        printf("===============================\n\n");
        return; // keluar dari fungsi apabila antrian kosong
    }

    printf("\n===============================\n");
    // loop untuk menampilkan setiap antrian
    int index = 1;
    for (int i = q_arr->front; i <= q_arr->rear; i++) // loop dari antrian awal (front) hingga sama dengan antrian terakhir (rear)
    {
        printf("Antrian ke-%d = %s \n", index++, q_arr->data[i]); // menampilkan setiap data
    }
    printf("===============================\n\n");
}

// melihat antrian yang akan dilayani
void peek_arr(QueueArr *q_arr)
{
    // cek terlebih dahulu apakah ada array
    if (isempty_arr(q_arr))
    {
        printf("\n===============================\n");
        printf("Antrian kosong.\n");
        return;
    }
    printf("\n===============================\n");
    printf("Antrian berikutnya yang akan dilayani: \"%s\"\n", q_arr->data[q_arr->front]); // menampilkan data pertama
    printf("===============================\n");
}

/*
---------------------------------------
      FUNGSI TAMBAHAN QUEUE ARRAY
---------------------------------------
*/

// Tambah ke jalur terpendek (array)
void add_customers_arr(QueueArr *q_arr1, QueueArr *q_arr2, char *nama)
{
    if (count_arr(q_arr1) <= count_arr(q_arr2)) // cek apakah nilai q_arr1 lebih sedikit/samadengan q_arr2
    {
        enqueue_arr(q_arr1, nama); // jika iya maka "nama" dimasukkan kedalam antrian q_arr1
        printf("\n===============================\n");
        printf("Nasabah dengan nama: \"%s\" masuk ke teler 1\n", nama);
        printf("===============================\n");
    }
    else
    {
        enqueue_arr(q_arr2, nama); // jika tidak maka "nama" dimasukkan kedalam antrian q_arr2
        printf("\n===============================\n");
        printf("Nasabah dengan nama: \"%s\" masuk ke teler 2\n", nama);
        printf("===============================\n");
    }
}

// Layani nasabah (array)
void served_arr(QueueArr *q_arr1, QueueArr *q_arr2)
{
    if (!isempty_arr(q_arr1)) // cek apakah jalur 1 tidak kosong
    {
        printf("\n===============================\n");
        printf("Melayani %s dari Jalur 1\n", q_arr1->data[q_arr1->front]); // output program
        dequeue_arr(q_arr1);                                               // menampilkan data dari jalur 1
        printf("===============================\n\n");
    }
    else if (!isempty_arr(q_arr2)) // cek apakah jalur 2 tidak kosong
    {
        printf("\n===============================\n");
        printf("Melayani %s dari Jalur 2\n", q_arr2->data[q_arr2->front]); // output program
        dequeue_arr(q_arr2);                                               // menampilkan data dari jalur 2
        printf("===============================\n\n");
    }
    else
    {
        // jika antrian kosong maka
        printf("\n===============================\n");
        printf("Semua antrian kosong!\n"); // maka diberikan output seperti ini
        printf("===============================\n\n");
    }
}

// Tampilkan semua antrian dari jalur
void display_all_arr(QueueArr *q_arr1, QueueArr *q_arr2)
{
    // menampilkan antrian dijalur 1
    printf("\nAntrian nasabah jalur 1: ");
    display_arr(q_arr1);

    // menampilkan antrian dijalur 2
    printf("\nAntrian nasabah jalur 2: ");
    display_arr(q_arr2);
}

// Jumlah antrian
void amount_arr(QueueArr *q_arr1, QueueArr *q_arr2)
{
    printf("\nBanyak antrian di jalur 1: %d\n", count_arr(q_arr1)); // menampilkan jumlah banyak antrian pada jalur 1
    printf("Banyak antrian di jalur 2: %d5", count_arr(q_arr2));    // menampilkan jumlah banyak antrian pada jalur 2
}

// menyimpan nilai dari front
char *front_arr(QueueArr *q_arr)
{
    if (isempty_arr(q_arr)) // cek apakah antrian penuh atau tidak
        return NULL;        // jika iya maka mengembalikan nilai NULL

    return q_arr->data[q_arr->front]; // jika tidak maka mengembalikan nilai dari data terdepan
}

// Antrian yang sedang dilayani
void being_served_arr(QueueArr *q_arr1, QueueArr *q_arr2)
{
    if (!isempty_arr(q_arr1))                                                        // cek apakah antrian tidak kosong
        printf("\nNasabah yang sedang dilayani: %s (Jalur 1)\n", front_arr(q_arr1)); // menampilkan nama/id yang terdapat pada front (jalur 1)

    else if (!isempty_arr(q_arr2))                                                   // cek juga pada jalur 2
        printf("\nNasabah yang sedang dilayani: %s (Jalur 2)\n", front_arr(q_arr2)); // menampilkan nama/id yang terdapat pada front (jalur 2)
    else
        printf("\nTidak ada yang dilayani\n"); // output apabila kedua jalur tidak ada antrian
}

/*
=================================
        QUEUE LINKED LIST
=================================
*/

// inisialisasi awal lingked list
void init_ll(QueueLL *q_ll)
{
    q_ll->front = NULL;
    q_ll->rear = NULL;
    q_ll->size = 0;
}

// fungsi cek antrian
int isempty_ll(QueueLL *q_ll)
{
    return q_ll->front == NULL; // cek apakah fron bernilai NULL
}

// menghitung elemen didalam linked list
int count_ll(QueueLL *q_ll)
{
    return q_ll->size; // mengembalikan nilai ke int berupa ukuran linked list
}

// menambahkan antrian
void enqueue_ll(QueueLL *q_ll, const char *data)
{

    NodeLL newnode = (NodeLL)malloc(sizeof(QueueNode)); // mengalokasikan memory di heap seukuran QueueNode

    if (newnode == NULL)
    {
        printf("\n===============================\n");
        printf("Gagal mengalokasikan memory.... memory penuh!"); // pemberitahuan apabila malloc gagal
        printf("\n===============================\n");
        return;
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
    printf("Nasabah %s masuk ke antrian", data); // output sistem
    printf("\n===============================\n");
}

// meengeluarkan antrian
void dequeue_ll(QueueLL *q_ll)
{
    if (isempty_ll(q_ll)) // cek antrian
    {
        printf("Antrian kosong!\n"); // ouput apabila antian kosong
        return;                      // keluar dari fungsi
    }

    NodeLL temp = q_ll->front; // temp menyimpan alamat antrian pertama

    q_ll->front = q_ll->front->next; // front sekarang pindah ke node selanjutnya

    if (q_ll->front == NULL) // cek apakah antrian menjadi kosong seelah di dequeue
    {
        q_ll->rear = NULL; // set rear = NULL
    }

    free(temp);   // menghapus data yang disimpan oleh temp agar tidak ada kebocoran memory
    q_ll->size--; // size berkurang 1
}

// Fungsi untuk menampilkan list antrian
void display_ll(QueueLL *q_ll)
{
    if (isempty_ll(q_ll)) // cek apakah antrian kosong atau tidak
    {
        printf("Antrian kosong!\n"); // ouput apabila antian kosong
        return;                      // keluar dari fungsi
    }
    // menampilkan setiap antrian
    printf("\n===============================\n");

    NodeLL temp = q_ll->front; // temp menyimpan antrian terdepan
    int i = 1;                 // memberikan indeks

    while (temp != NULL) // loop hingga antrian kosong
    {
        printf("%d. %s\n", i++, temp->data); // menampilkan indeks untuk setiap antrian
        temp = temp->next;                   // temp menyimpan alamat selanjutnya
    }
    printf("\nJumlah Antrian: \"%u\"", (unsigned)q_ll->size);
    printf("\n===============================\n");
}

// Fungsi untuk menampilkan elemen yang akan di cetak
void peek_ll(QueueLL *q_ll)
{
    if (isempty_ll(q_ll))
    {
        printf("\n===============================\n");
        printf("Antrian telah kosong\n"); // output jika antrian telah kosong
        printf("===============================\n");
        return; // keluar dari fungsi
    }

    else
    {
        printf("\n===============================\n");
        printf("Nasabah berikutnya : %s\n", q_ll->front->data); // menampilkan dokumen yang akan dicetak
        printf("===============================\n");
    }
}

/*
---------------------------------------
    FUNGSI TAMBAHAN QUEUE LINKED LIST
---------------------------------------
*/

// Tambah ke jalur terpendek (LL)
void add_customers_ll(QueueLL *q_ll1, QueueLL *q_ll2, char *nama)
{
    if (count_ll(q_ll1) <= count_ll(q_ll2)) // cek apakah nilai q_arr1 lebih sedikit/samadengan q_arr2
    {
        enqueue_ll(q_ll1, nama); // jika iya maka "nama" dimasukkan kedalam antrian q_arr1
        printf("\n===========================================\n");
        printf("Nasabah dengan nama: \"%s\" masuk ke teler 1\n", nama);
        printf("===========================================\n");
    }
    else
    {
        enqueue_ll(q_ll2, nama); // jika tidak maka "nama" dimasukkan kedalam antrian q_arr2
        printf("\n===========================================\n");
        printf("Nasabah dengan nama: \"%s\" masuk ke teler 2\n", nama);
        printf("===========================================\n");
    }
}

// Layani (linked list)
void served_ll(QueueLL *q_ll1, QueueLL *q_ll2)
{
    if (!isempty_ll(q_ll1)) // cek apakah jalur 1 tidak kosong
    {
        printf("\n===============================\n");
        printf("Melayani %s dari Jalur 1\n", q_ll1->front->data); // output program
        dequeue_ll(q_ll1);                                        // menampilkan data dari jalur 1
        printf("===============================\n\n");
    }
    else if (!isempty_ll(q_ll2)) // cek apakah jalur 2 tidak kosong
    {

        printf("\n===============================\n");
        printf("Melayani %s dari Jalur 2\n", q_ll2->front->data); // output program
        dequeue_ll(q_ll2);                                        // menampilkan data dari jalur 2
    }
    else
    {
        // jika antrian kosong maka
        printf("\n===============================\n");
        printf("Semua antrian kosong!\n"); // maka diberikan output seperti ini
        printf("===============================\n\n");
    }
}

// Tampilkan semua antrian dari jalur
void display_all_ll(QueueLL *q_ll1, QueueLL *q_ll2)
{
    // menampilkan antrian dijalur 1
    printf("\nAntrian nasabah jalur 1: ");
    display_ll(q_ll1); // menampilkan setian antrian nasabah pada jalur 1

    // menampilkan antrian dijalur 2
    printf("\nAntrian nasabah jalur 2: ");
    display_ll(q_ll2); // menampilkan setian antrian nasabah pada jalur 2
}

// Jumlah antrian
void amount_ll(QueueLL *q_ll1, QueueLL *q_ll2)
{
    printf("\n===============================\n");
    printf("Banyak antrian di jalur 1: %d\n", count_ll(q_ll1)); // menampilkan jumlah banyak antrian pada jalur 1
    printf("Banyak antrian di jalur 2: %d\n", count_ll(q_ll2)); // menampilkan jumlah banyak antrian pada jalur 2
    printf("\n===============================\n");
}

// menyimpan nilai dari front
char *front_ll(QueueLL *q_ll)
{
    if (isempty_ll(q_ll)) // cek apakah antrian penuh atau tidak
        return NULL;      // jika iya maka mengembalikan nilai NULL

    return q_ll->front->data; // jika tidak maka mengembalikan nilai dari data terdepan
}

// Antrian yang sedang dilayani
void being_served_ll(QueueLL *q_ll1, QueueLL *q_ll2)
{
    if (!isempty_ll(q_ll1))                                  // cek apakah antrian tidak kosong
        printf("Dilayani: %s (Jalur 1)\n", front_ll(q_ll1)); // menampilkan nama/id yang terdapat pada front (jalur 1)

    else if (!isempty_ll(q_ll2))                             // cek juga pada jalur 2
        printf("Dilayani: %s (Jalur 2)\n", front_ll(q_ll2)); // menampilkan nama/id yang terdapat pada front (jalur 1)

    else
        printf("Tidak ada yang dilayani\n"); // output apabila kedua jalur tidak ada antrian
}

// fungsi pencegahan memory leaks
void clear_ll(QueueLL *q_ll)
{
    NodeLL temp; // deklarasi temp bertipe NodeLL

    while (q_ll->front != NULL) // loop dari awal hingga antrian kosong
    {
        temp = q_ll->front;              // temp menyimpan nilai terdepan
        q_ll->front = q_ll->front->next; // front menyimpan alamat front yang menyimpan alamat node selanjutnya
        free(temp);                      // melepas data yang telah disimpan oleh temp
    }

    q_ll->rear = NULL; // set rear = NULL
    q_ll->size = 0;    // size diriset menjadi 0
}