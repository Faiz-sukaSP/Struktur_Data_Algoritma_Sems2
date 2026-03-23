#include <stdio.h>
#include <string.h>
#include "queue.h"

int main()
{
    QueueArr q_arr;
    init_arr(&q_arr); // memanggil fungsi yang telah dibuat sebelumnya

    int pilihan;
    printf("\n===== Simulasi Printer (Array) =====\n");
    printf("1. Tambahkan Dokumen\n");
    printf("2. Keluarkan Dokumen\n");
    printf("3. Tampilkan Dokumen\n");
    printf("4. Lihat Dokumen\n");
    printf("5. Keluar Dari Simulasi\n");

    do
    {
        printf("\nMasukkan pilihan yang anda inginkan: ");
        if (scanf("%d", &pilihan) != 1)
        {
            printf("\n===============================\n");
            printf("Input yang Anda Masukkan Tidak Sesuai, Harus Berupa Angka!! \n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (pilihan < 1 || pilihan > 5)
        {
            printf("\n===============================\n");
            printf("Input yang Anda Masukkan Tidak Sesuai, Hanya 1-5!! \n");
            continue;
        }

        getchar(); // membersihkan newline

        switch (pilihan)
        {
        case 1:
        {
            char doc[100];
            printf("\n===============================\n");
            printf("Masukkan ID Dokumen: ");
            scanf(" %[^\n]", doc);

            enqueue_arr(&q_arr, doc);
            break;
        }
        case 2:
            dequeue_arr(&q_arr);
            break;

        case 3:
            display_arr(&q_arr);
            break;
        case 4:
            peek_arr(&q_arr);
            break;

        case 5:
            printf("\n===== Terima Kasih Telah Menggunakan Simulasi Ini =====\n");
            break;

        default:
            printf("\nPilihan yang anda pilih tidak sesuai / Salah\n");
            break;
        }

    } while (pilihan != 5);

    return 0;
}