#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100 // Mendeklarasikan nilai maksimal sebanyak 100

/*
=================================
        QUEUE ARRAY
=================================
*/

typedef struct
{
    char data[MAX][100];
    int front;
    int rear;
} QueueArr;

// fungsi array
void init_arr(QueueArr *q_arr);               // inisialisasi awal
int isempty_arr(QueueArr *q_arr);             // cek array apakah kosong atau terisi
int isfull_arr(QueueArr *q_arr);              // cek apakah array sudah penuh atau tidak
void clear_arr(QueueArr *q_arr);              // membersihkan array
int count_arr(QueueArr *q_arr);               // menghitung jumlah elemen didalam antrian
void enqueue_arr(QueueArr *q_arr, char *doc); // menambahkan dokumen kedalam antrian
void dequeue_arr(QueueArr *q_arr);            // mengeluarkan antrian
void display_arr(QueueArr *q_arr);            // menampilkan antrian
void peek_arr(QueueArr *q_arr);               // melihat antrian

// fungsi array tambahan

void add_customers_arr(QueueArr *q_arr1, QueueArr *q_arr2, char *nama); // tambah ke jalur terpendek (array)
void served_arr(QueueArr *q_arr1, QueueArr *q_arr2);                    // fungsi untuk melayani nasabah
void display_all_arr(QueueArr *q_arr1, QueueArr *q_arr2);               // fungsi untuk menampilkan antrian nasabah dari setiap jalur
void amount_arr(QueueArr *q_arr1, QueueArr *q_arr2);                    // fungsi untuk menampilkan jumlah antrian
char *front_arr(QueueArr *q_arr);                                       // menyimpan nilai dari front
void being_served_arr(QueueArr *q_arr1, QueueArr *q_arr2);              // menampilkan antrian yang sedang dilayani

/*
=================================
        QUEUE LINKED LIST
=================================
*/

typedef struct QueueNode *NodeLL;
typedef struct QueueNode
{
    char data[100];
    NodeLL next;
} QueueNode;

typedef struct
{
    NodeLL front;
    NodeLL rear;
    unsigned size;
} QueueLL;

// fungsi linked list
void init_ll(QueueLL *q_ll);                      // inisialisasi awal
int isempty_ll(QueueLL *q_ll);                    // mengecek apakah antrian kosong
int count_ll(QueueLL *q_ll);                      // menghitung elemen didalam array
void enqueue_ll(QueueLL *q_ll, const char *data); // menambahkan dokumen kedalam antrian
void dequeue_ll(QueueLL *q_ll);                   // mengeluarkan dokumen dari antrian
void display_ll(QueueLL *q_ll);                   // menampilkan antrian
void peek_ll(QueueLL *q_ll);                      // lihat dokumen yang akan di cetak

// fungsi linked list tambahan
void add_customers_ll(QueueLL *q_ll1, QueueLL *q_ll2, char *nama); // menambahkan nasabah kedalam antrian
void served_ll(QueueLL *q_ll1, QueueLL *q_ll2);                    // fungsi untuk melayani nasabah
void display_all_ll(QueueLL *q_ll1, QueueLL *q_ll2);               // Tampilkan semua antrian dari jalur
void amount_ll(QueueLL *q_ll1, QueueLL *q_ll2);                    // menampilkan jumlah antrian
char *front_ll(QueueLL *q_ll);                                     // menyimpan nilai dari front
void being_served_ll(QueueLL *q_ll1, QueueLL *q_ll2);              // menampilkan antrian yang sedang dilayani
void clear_ll(QueueLL *q_ll);                                      // fungsi pencegahan memory leaks

#endif