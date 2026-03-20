#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

root kamus_abjad[26]; // array kamus berisi 26 elemen

// === FUNGSI INISIALISASI ARRAY ===
void inisialisasi()
{
    for (int i = 0; i < 26; i++)
    {
        kamus_abjad[i].head = NULL; // mengosongkan setiap pointer
        kamus_abjad[i].size = 0;    // jumlah kata berawal dengan nilai 0
    }
}

// === FUNgSI SISIPKAN KATA KEDALAM LINKLIST ===
void sisipkan_kata(char *kata_baru)
{
    if (!isalpha(kata_baru[0]))
        return;

    int index = tolower(kata_baru[0]) - 'a'; // membuat input menjadi huruf kecil dan index menjadi "0-25"

    // pengecekan kata yang sama
    nodeptr cek = kamus_abjad[index].head; // membuat pointer cek yang menunjuk ke head
    while (cek != NULL)
    {
        if (strcmp(cek->kata, kata_baru) == 0) // membandingkan kata yang ditunjuki
            return;                            // jika sudah ada maka batalkan penambahan kata
        cek = cek->next;
    }

    // Membuat node baru
    nodeptr node_baru = (nodeptr)malloc(sizeof(node)); // mengalokasikan memori di heap sebesar ukuran struct node
    if (node_baru == NULL)                             // proteksi apabila memori penuh
        return;

    snprintf(node_baru->kata, sizeof(node_baru->kata), "%s", kata_baru); // salin string kata_baru ke field kata dengan pembatasan ukuran buffer

    // Menyisipkan kata dari depan
    node_baru->next = kamus_abjad[index].head; // menyambungkan "next" "node_baru" ke "head" yang lama
    kamus_abjad[index].head = node_baru;       // menggeser head ke node_baru
    kamus_abjad[index].size++;                 // menambahkan jumlah size
}

// === FUNGSI MEMBACA FILE ===
void baca_file(const char *nama_file)
{
    FILE *file = fopen(nama_file, "r");
    if (file == NULL) // Validasi apakah file berhasil dibuka atau tidak
    {
        printf("File tidak ditemukan/kosong\n");
        return;
    }

    char kata[50];                            // mengalokasikan jumlah string sebanyak 50
    while (fscanf(file, "%49s", kata) != EOF) // loop untuk membaca baris file sampai akhir kata
    {
        for (int i = 0; kata[i]; i++)
        {
            kata[i] = tolower(kata[i]); // mengubah setiap kata yang dibaca menjadi hurug kecip
        }
        sisipkan_kata(kata); // kata yang sudah dibaca dimasukkan kedalam fungsi "sisipkan_kata"
    }
    fclose(file);                                                        // file telah berhasil dibaca dan ditutup
    printf("\n=== File telah berhasil dibaca dan di kelompokkan ===\n"); // output ketika berhasil
}

// ===== FUNGSI MENAMPILKAN KATA YANG TELAH DI SISIPKAN ====
void tampilkan_kata(char huruf)
{
    // validasi input user apakah huruf alfabet atau bukan
    if (!isalpha(huruf))
    {
        printf("\nInput yang anda berikan tidak sesuai!! harus huruf a-z\n"); // output apabila user bukan menginput huruf alfabet
        return;
    }

    int index = tolower(huruf) - 'a'; // setiap kata menjadi huruf kecil dan memberikan index untuk setiap alfabet seperti a = 0 hingga z = 25

    // cek apakah huruf yang diminta ada didalam kamus
    if (kamus_abjad[index].head == NULL)
    {
        printf("Tidak ada kata dengan huruf '%c'\n", huruf); // menampil pemberitahuan bahwa huruf tersebut tidak ada
        return;
    }

    // tampilkan juga jumlah kata menggunakan size dari Root
    printf("\nKata-kata dengan huruf awal '%c' (%u kata):\n", huruf, kamus_abjad[index].size);

    // menampilkan kata satu persatu sesua dengan abjad yang ada pada index dan terdapat di kamus
    nodeptr temp = kamus_abjad[index].head;

    int hitung = 0;      // inisialisasi hitung
    while (temp != NULL) // loop selama masih ada node
    {
        printf("- %-25s", temp->kata); // output "kata" dengan format rata kiri sebanyak 25 karakter
        hitung++;                      // hitung +1

        if (hitung % 6 == 0) // jika kata sudah mencapai 6 atau kelipatannya
            printf("\n");    // mencetak baris baru

        temp = temp->next; // lanjut ke node selanjutnya
    }
    printf("\n");
}

// ===== FUNGSI UNTUK MENGHAPUS KATA =====
void hapus_kata(char *kata)
{
    // fungsi untuk mengubah setiap kata menjadi huruf kecil dahulu semua
    for (int i = 0; kata[i]; i++)
    {
        kata[i] = tolower(kata[i]);
    }

    // pemgecekan input user harus berupa huruf
    if (!isalpha(kata[0]))
    {
        printf("Input tidak valid.\n"); // output apabila user menginput simbol/angka
        return;
    }

    int index = tolower(kata[0]) - 'a'; // setiap kata menjadi huruf kecil dan memberikan index untuk setiap alfabet seperti a = 0 hingga z = 25

    nodeptr temp = kamus_abjad[index].head; // temporary dimulai dari head sesuai dengan index kata
    nodeptr prev = NULL;                    // previus deberi nilai NULL

    while (temp != NULL)
    {
        if (strcmp(temp->kata, kata) == 0)
        {
            if (prev == NULL)
                kamus_abjad[index].head = temp->next; // Hapus head
            else
                prev->next = temp->next; // Hapus tengah/akhir

            free(temp);
            kamus_abjad[index].size--;                     // Kurangi jumlah kata
            printf("Kata '%s' berhasil dihapus.\n", kata); // output apabila kata berhasil dihapus
            return;
        }
        prev = temp;       // simpan node saat ini ke node sebelumnya
        temp = temp->next; // maju ke node selanjutnya
    }
    printf("Kata '%s' tidak ditemukan.\n", kata);
}

// Fungsi tambahan untuk membersihkan memory(pencegahan kebocoran memori)
void hapus_semua()
{
    for (int i = 0; i < 26; i++) // looping untuk seluruh alfabet
    {
        nodeptr temp = kamus_abjad[i].head; // temp dimulai dari node pertama (head)
        while (temp != NULL)                // while berjalan sampai bertemu null
        {
            nodeptr hapus = temp; // "hapus" menyimpan node yang akan dihapus
            temp = temp->next;    // " "temp" maju ke depan"
            free(hapus);          // menggunakan fungsi "free" untuk membebaskan memori node yang disimpan
        }
        kamus_abjad[i].head = NULL; // reset head
        kamus_abjad[i].size = 0;    // mereset jumlah kata
    }
}