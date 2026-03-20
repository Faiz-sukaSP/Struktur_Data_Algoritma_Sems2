// PENCEGAHAN REDEFINITOIN APABILA FILE INI DIPANGGIL OLEH LEBIH DARI 1 FILE.C
#ifndef linklist_h
#define linklist_h

// DEKLARASI STRUCT ALAMAT MEMORI PADA AWAL MENGGUNAKAN "nodeptr" SEHINGGA NEXT BUKAN LAGI "STRUCT *NODE"
typedef struct node *nodeptr;

// ==STRUKTUR LINKLIST==

// Deklarasi node next
typedef struct node
{
    char kata[60];
    nodeptr next; // pointer yang menghubungkan ke alamat seterusnya
} node;

// Deklarasi root head
typedef struct root
{
    nodeptr head;      // pointer ke node pertama
    unsigned int size; // menghitung jumlah kata pada linklist
} root;

extern root kamus_abjad[26]; // mendeklarasikan jumlah array sebanyak 26 (A-Z)

// MENDEKLARASIKAN FUNGSI-FUNGSI YANG AKAN SAYA GUNAKAN
void inisialisasi();
void sisipkan_kata(char *kata_baru);
void baca_file(const char *nama_file);
void tampilkan_kata(char huruf);
void hapus_kata(char *kata);
void hapus_semua();

#endif