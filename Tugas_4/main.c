#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BST.h"

int main()
{
    treenode root = NULL;
    char namaFile[100];

    // nenbaca file sesuai nama yang dimasukkan oleh user
    printf("\n===========================================");
    printf("\nMasukkan nama file teks: ");
    if (scanf("%99s", namaFile) != 1)
    {
        fprintf(stderr, "Gagal membaca nama file.\n");
        return 1;
    }
    while (getchar() != '\n')
        ; // bersihlan buffer dari "\n"
    printf("-------------------------------------------\n");

    // Baca dan kelompokkan kata dari file ke dalam BST + Linked List
    root = readFile(root, namaFile);
    if (root == NULL)
    {
        fprintf(stderr, "\nBST kosong. Program berhenti.\n");
        return 1;
    }

    printf("\nPembacaan isi file teks dan pengelompokkan....\n");
    printf("---------------------------------------------------------\n");

    // output pada layar
    int pilihan;
    do
    {
        printf("\n\n             ========= MENU PILIHAN =========\n");
        printf("1) Menampilkan kata-kata sesuai huruf pertama yang diinputkan\n");
        printf("2) Menampilkan statistik dari kata urut secara ascending (kecil ke\n");
        printf("   besar) berdasarkan huruf pertama dari kata\n");
        printf("3) Keluar (free memory)\n");
        printf("----------------------------------------------------------------\n");
        printf("Masukkan pilihan anda: ");

        if (scanf("%d", &pilihan) != 1)
        {
            // Bersihkan buffer jika input bukan angka
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("\nInput tidak valid. Masukkan angka 1-3.\n");
            printf("--------------------------------------\n");
            continue;
        }

        switch (pilihan)
        {
        case 1:
        {
            // Pilihan 1: Tampilkan kata berdasarkan huruf pertama
            char inputHuruf[5];

            printf("\nMasukkan huruf pertama yang anda inginkan: ");
            scanf("%4s", inputHuruf);
            while (getchar() != '\n')
                ; // bersihlan buffer dari "\n"
            printf("=============================================\n");

            char huruf = (char)tolower((unsigned char)inputHuruf[0]);

            // cek apakah user menginput huruf atau bukan
            if (!isalpha((unsigned char)huruf))
            {
                printf("Input bukan huruf yang valid.\n");
                break;
            }

            // hasil didapat berdasarkan fungsi yang telah di deklarasikan
            treenode hasil = findBST(root, huruf);
            if (hasil == NULL)
            {
                printf("%c -- (0)\n", huruf);
            }

            else
            {
                int total = countList(hasil->head); // total didapat menggunakan fungsi countlist

                printf("\nMenampilkan 5 kata awal yang berawalan huruf \"%c\":\n", huruf);
                printf("--------------------------------------------\n");
                // Tampilkan maks 5 kata
                listnode curr = hasil->head;
                int shown = 1;
                while (curr != NULL && shown <= 5)
                {
                    printf("%d. %s\n", shown, curr->kata);
                    shown++;
                    curr = curr->next;
                }
                printf("total kata dari huruf tersebut adalah \"%d\" \n", total);
            }
            break;
        }

        case 2:
        {
            // menampilkan setiap huruf, kata dengan maksimal 5 kata, dan juga total kata sesuai huruf
            printf("\nStatistik kata (urut ascending berdasarkan huruf pertama)\n");
            printf("---------------------------------------------------------\n");
            inorderStat(root);
            break;
        }

        case 3:
        {
            // membebaskan memory dan keluar dari program
            printf("\nMembebaskan memori..... Selesai. Sampai jumpa!\n\n");
            freeBST(root);
            root = NULL;
            break;
        }

        default:
            printf("Pilihan tidak valid. Masukkan angka 1-3.\n");
            break;
        }

    } while (pilihan != 3);

    return 0;
}