#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ===== FUNGSI UTAMA MAIN =====
int main()
{
    int pilihan = 0;
    char input_kata[50];
    char input_huruf;
    char buffer[10];

    // 1. Memanggil fungsi "inisialisasi" dari linklist.c
    inisialisasi();

    // 2. Memanggil fungsi "baca_file" untuk membaca file dari linklist.c
    baca_file("dbterms.txt");

    // penggunaan fungsi do while untuk perulangan permintaan user
    do
    {
        printf("\n==== MENU PILIHAN ====\n");
        printf("1. Menampilkan kata sesuai abjad pertama yang ditentukan \n");
        printf("2. Menghapus kata yang diinginkan dalam linklist \n");
        printf("3. Keluar \n");
        printf("---------------------------------------------------------- \n");
        printf("Masukkan pilihan yang ada inginkan(1-3): "); // meminta user untuk memilih pilihan menu

        // Baca seluruh baris input sebagai string
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            clearerr(stdin); // mereset status error apaila terjadi error pada stdin
            continue;        // Kembali ke awal loop untuk meminta input ulang
        }

        // Coba parse integer dari buffer
        if (sscanf(buffer, "%d", &pilihan) != 1)
        {
            // Input bukan angka → reset dan ulangi
            printf("Input tidak valid! Masukkan angka 1-3.\n");
            pilihan = 0;
            continue; // <-- langsung kembali ke atas loop, TIDAK masuk switch
        }

        switch (pilihan) // penggunaan switch untuk mengeksekusi salah satu fungsi yang user inginkan
        {
        case 1:
            printf("Masukkan huruf (a-z): ");

            //
            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
            {
                // Ambil karakter pertama yang bukan spasi/newline
                sscanf(buffer, " %c", &input_huruf);

                // Validasi: harus huruf a-z atau A-Z
                if (!isalpha((unsigned char)input_huruf))
                {
                    printf("Input tidak valid! Masukkan huruf a-z.\n");
                    break;
                }
                tampilkan_kata(input_huruf);
            }
            break;

        case 2:
            printf("Masukkan kata yang ingin anda hapus: ");

            //
            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
            {
                buffer[strcspn(buffer, "\n")] = '\0'; // hapus newline di akhir buffer
                strncpy(input_kata, buffer, 49);      // menyalin maksimal 49 karakter dari buffer ke input_kata
                input_kata[49] = '\0';                // karena "strncpy" tidak menjamin null-terminated maka array terakhir menjadi akhir string
                hapus_kata(input_kata);               // memanggil fungsi hapus_kata untuk menghapus input_kata
            }
            break;

        case 3:
            printf("Membersihkan memori dan keluar dari program...\n"); // output sederhana apabila user ingin keluar dari program
            break;

        default:
            printf("Menu yang anda pilih tidak sesuai"); // validasi input user bila tidak sesuai
        }
        printf("\n");

    } while (pilihan != 3);

    // 5. Fungsi tambahan untuk membersihkan memori agar tidak terjadi kebocoran memori
    hapus_semua();

    return EXIT_SUCCESS;
}
