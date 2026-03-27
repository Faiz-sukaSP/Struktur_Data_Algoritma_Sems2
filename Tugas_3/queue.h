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
void enqueue_arr(QueueArr *q_arr, char *doc); // menambahkan dokumen kedalam antrian
void dequeue_arr(QueueArr *q_arr);            // mengeluarkan antrian
void display_arr(QueueArr *q_arr);            // menampilkan antrian
void peek_arr(QueueArr *q_arr);               // melihat antrian

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
void init_queue_ll(QueueLL *q_ll);
int isempty_ll(QueueLL *q_ll);
void enqueue_ll(QueueLL *q_ll, const char *data);
void dequeue_LL(QueueLL *q_ll);
void peek_LL(QueueLL *q_ll);
void display_LL(QueueLL *q_ll);

#endif