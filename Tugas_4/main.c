#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BST.h"

int main()
{
    treenode root = NULL;
    char namaFile[200];

    // nenbaca file sesuai nama yang dimasukkan oleh user
    printf("Masukkan nama file teks: ");
    if (scanf("%199s", namaFile) != 1)
    {
        fprintf(stderr, "Gagal membaca nama file.\n");
        return 1;
    }

    // Baca dan kelompokkan kata dari file ke dalam BST + Linked List
    root = readFile(root, namaFile);
    if (root == NULL)
    {
        fprintf(stderr, "BST kosong. Program berhenti.\n");
        return 1;
    }

    printf("\nPembacaan isi file teks dan pengelompokkan selesai...\n");

    // output pada layar
    int pilihan;
    do
    {
        printf("\n==== MENU PILIHAN ====\n");
        printf("1) Menampilkan kata-kata sesuai huruf pertama yang diinputkan\n");
        printf("2) Menampilkan statistik dari kata urut secara ascending (kecil ke\n");
        printf("   besar) berdasarkan huruf pertama dari kata\n");
        printf("3) Keluar (free memory)\n");
        printf("\n Masukkan pilihan anda: ");

        if (scanf("%d", &pilihan) != 1)
        {
            // Bersihkan buffer jika input bukan angka
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Input tidak valid. Masukkan angka 1-3.\n");
            continue;
        }

        switch (pilihan)
        {
        case 1:
        {
            /* --------------------------------------------------
             * Pilihan 1: Tampilkan kata berdasarkan huruf pertama
             * -------------------------------------------------- */
            char inputHuruf[10];
            printf("\nHuruf: ");
            scanf("%9s", inputHuruf);

            char huruf = (char)tolower((unsigned char)inputHuruf[0]);

            if (!isalpha((unsigned char)huruf))
            {
                printf("Input bukan huruf yang valid.\n");
                break;
            }

            treenode hasil = findBST(root, huruf);
            if (hasil == NULL)
            {
                printf("Tidak ada kata yang diawali huruf '%c'.\n", huruf);
            }
            else
            {
                int total = countList(hasil->head);
                printf("\n%c  ", huruf);

                // Tampilkan maks 5 kata
                listnode curr = hasil->head;
                int shown = 0;
                while (curr != NULL && shown < 5)
                {
                    if (shown > 0)
                        printf(",");
                    printf("%s", curr->kata);
                    shown++;
                    curr = curr->next;
                }
                printf(" (%d)\n", total);
            }
            break;
        }

        case 2:
        {
            /* --------------------------------------------------
             * Pilihan 2: Tampilkan statistik inorder (ascending)
             * -------------------------------------------------- */
            printf("\nStatistik kata (urut ascending berdasarkan huruf pertama):\n");
            printf("%-5s %-8s %s\n", "Huruf", "Jumlah", "Kata (maks 5)");
            printf("-------------------------------------------\n");
            inorderStat(root);
            break;
        }

        case 3:
        {
            /* --------------------------------------------------
             * Pilihan 3: Bebaskan memori dan keluar
             * -------------------------------------------------- */
            printf("\nMembebaskan memori...\n");
            freeBST(root);
            root = NULL;
            printf("Selesai. Sampai jumpa!\n");
            break;
        }

        default:
            printf("Pilihan tidak valid. Masukkan angka 1-3.\n");
            break;
        }

    } while (pilihan != 3);

    return 0;
}