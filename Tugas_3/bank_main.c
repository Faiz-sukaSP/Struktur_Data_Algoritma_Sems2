#include <stdio.h>
#include <string.h>
#include "queue.h"

/*
  ===============================
            MENU ARRAY
  ===============================
*/
void menu_arr()
{
    QueueArr jalur1, jalur2;
    init_arr(&jalur1);
    init_arr(&jalur2);

    int pilihan;

    do
    {
        printf("\n===== SIMULASI ANTRIAN (ARRAY) =====\n");
        printf("1. Tambah Nasabah\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Jumlah Antrian\n");
        printf("5. Sedang Dilayani\n");
        printf("6. Keluar\n");

        printf("\nMasukkan pilihan yang ingin anda coba: ");

        if (scanf("%d", &pilihan) != 1)
        {
            printf("Input harus angka!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (pilihan < 1 || pilihan > 6)
        {
            printf("Pilihan hanya 1-6!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        while (getchar() != '\n')
            ; // clear newline

        switch (pilihan)
        {
        case 1:
        {
            char nama[50];
            printf("Masukkan nama nasabah: ");
            scanf(" %[^\n]", nama);
            add_customers_arr(&jalur1, &jalur2, nama);
            break;
        }

        case 2:
            served_arr(&jalur1, &jalur2);
            break;

        case 3:
            display_all_arr(&jalur1, &jalur2);
            break;

        case 4:
            amount_arr(&jalur1, &jalur2);
            break;

        case 5:
            being_served_arr(&jalur1, &jalur2);
            break;

        case 6:
            printf("Keluar dari simulasi array...\n");
            break;
        }

    } while (pilihan != 6);
}

/*
  ===============================
         MENU LINKED LIST
  ===============================
*/
void menu_ll()
{
    QueueLL jalur1, jalur2;
    init_ll(&jalur1);
    init_ll(&jalur2);

    int pilihan;

    do
    {
        printf("\n===== SIMULASI ANTRIAN (LINKED LIST) =====\n");
        printf("1. Tambah Nasabah\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Jumlah Antrian\n");
        printf("5. Sedang Dilayani\n");
        printf("6. Keluar\n");

        printf("\nMasukkan pilihan: ");

        if (scanf("%d", &pilihan) != 1)
        {
            printf("Input harus angka!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (pilihan < 1 || pilihan > 6)
        {
            printf("Pilihan hanya 1-6!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        while (getchar() != '\n')
            ; // clear newline

        switch (pilihan)
        {
        case 1:
        {
            char nama[50];
            printf("Masukkan nama nasabah: ");
            scanf(" %[^\n]", nama);
            add_customers_ll(&jalur1, &jalur2, nama);
            break;
        }

        case 2:
            served_ll(&jalur1, &jalur2);
            break;

        case 3:
            display_all_ll(&jalur1, &jalur2);
            break;

        case 4:
            amount_ll(&jalur1, &jalur2);
            break;

        case 5:
            being_served_ll(&jalur1, &jalur2);
            break;

        case 6:
            clear_ll(&jalur1);
            clear_ll(&jalur2);
            printf("Keluar dari simulasi linked list...\n");
            break;
        }

    } while (pilihan != 6);
}

/*
  ===============================
           MAIN PROGRAM
  ===============================
*/
int main()
{
    int pilihan;

    do
    {
        printf("\n=====================================\n");
        printf(" ====== SIMULASI ANTRIAN BANK ====== \n");
        printf("=====================================\n");
        printf("1. Menggunakan Array\n");
        printf("2. Menggunakan Linked List\n");
        printf("3. Keluar\n");

        printf("Pilih: ");

        if (scanf("%d", &pilihan) != 1)
        {
            printf("Input harus angka!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (pilihan < 1 || pilihan > 3)
        {
            printf("Pilihan hanya 1-3!\n");
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
            printf("Terima kasih telah menggunakan simulasi ini!\n\n");
            break;
        }

    } while (pilihan != 3);
    return 0;
}