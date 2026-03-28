#include <stdio.h>
#include <string.h>
#include "queue.h"

void menu_arr()
{
    QueueArr q_arr;
    init_arr(&q_arr); // memanggil fungsi yang telah dibuat sebelumnya

    int pilihan;

    do
    {
        printf("\n===== Simulasi Printer (Array) =====\n");
        printf("1. Tambahkan Dokumen\n");
        printf("2. Keluarkan Dokumen\n");
        printf("3. Tampilkan Antrian Dokumen\n");
        printf("4. Lihat Dokumen yang Akan Dicetak\n");
        printf("5. Keluar Dari Simulasi\n");

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
            while (getchar() != '\n')
                ;
            continue;
        }

        while (getchar() != '\n')
            ; // membersihkan newline

        switch (pilihan)
        {
        case 1:
        {
            char doc[100];
            printf("\n===============================\n");
            printf("Masukkan ID Dokumen: "); // user diminta untuk mengintput ID dokumen untuk ditambahkan kedalam antrian
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
}

void menu_ll()
{
    QueueLL q_ll;
    init_ll(&q_ll);

    int pilihan;

    do
    {
        printf("\n===== Simulasi Printer (Linked list) =====\n");
        printf("1. Tambahkan Dokumen\n");
        printf("2. Keluarkan  Dokumen\n");
        printf("3. Tampilkan Antrian Dokumen\n");
        printf("4. Lihat Dokumen yang Akan Dicetak\n");
        printf("5. Keluar Dari Simulasi\n");

        printf("\nMasukkan pilihan yang anda inginkan: ");
        // validasi apakah user menginpuy menu yang benar sebelum masuk switch
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
            while (getchar() != '\n')
                ;
            continue;
        }

        while (getchar() != '\n')
            ; // membersihkan new line

        switch (pilihan)
        {
        case 1:
        {
            char data[100];
            printf("\n===============================\n");
            printf("Masukkan ID dokumen: "); // user diminta untuk mengintput ID dokumen untuk ditambahkan kedalam antrian
            scanf(" %[^\n]", data);

            enqueue_ll(&q_ll, data); // memanggil fungsi enqueue
            break;
        }
        case 2:
        {
            dequeue_ll(&q_ll);
            break;
        }
        case 3:
        {
            display_ll(&q_ll);
            break;
        }
        case 4:
        {
            peek_ll(&q_ll);
            break;
        }
        case 5:
        {
            clear_ll(&q_ll);
            printf("\n===== Terima Kasih Telah Menggunakan Simulasi Ini =====\n");
            break;
        }
        default:
            printf("\nPilihan yang anda pilih tidak sesuai / Salah\n");
        }

    } while (pilihan != 5);
}

int main()
{
    int pilihan;
    do
    {
        printf("\n===============================================\n");
        printf("Selamat Datang di Simulasi Antrian(String/LL)\n");
        printf("===============================================\n");
        printf("1. Simulasi Dengan String\n");
        printf("2. Simulasi Dengan Linked List\n");
        printf("3. Keluar Program\n");
        printf("-----------------------------------------------\n");

        printf("Masukkan Simulasi yang Ingin Anda Coba: ");
        // validasi apakah user menginpuy menu yang benar sebelum masuk switch
        if (scanf("%d", &pilihan) != 1)
        {
            printf("\n===============================\n");
            printf("Input yang Anda Masukkan Tidak Sesuai, Harus Berupa Angka!! \n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (pilihan < 1 || pilihan > 3)
        {
            printf("\n===============================\n");
            printf("Input yang Anda Masukkan Tidak Sesuai, Hanya 1-3!! \n");
            continue;
        }

        switch (pilihan)
        {
        case 1:
            menu_arr();
            break;

        case 2:
            menu_ll();
            break;

        case 3:
            printf("\n===== Terima Kasih Telah Menggunakan Simulasi Ini =====\n");
            break;

        default:
            printf("Pilihan yang anda pilih tidak sesuai!\n");
        }

    } while (pilihan != 3);

    return 0;
}