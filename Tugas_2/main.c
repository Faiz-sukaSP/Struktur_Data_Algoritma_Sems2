#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
    int pilihan;
    char hasil_postfix[MAX] = ""; // variabel untuk menyimpan nilai postfix dari pilihan ke 2 ("") pencegahan apabila user langsung memilih menu 3

    printf("\n===== Program Stack =====\n");
    printf("1. Cek Kurung Seimbang (Arr)\n");
    printf("2. Konvert Infix ke Postfix (LL)\n");
    printf("3. Menentukan Nilai Akhir Ekspersi Postfix (LL & Arr)\n");
    printf("4. Keluar\n");

    do
    {
        printf("Masukkan Pilihan Menu: ");
        scanf("%d", &pilihan);
        getchar(); // untuk membersihkan newline

        switch (pilihan)
        {
        case 1:
        {
            char ekspresi[MAX];
            printf("\n------ Cek Kurung ------\n");
            printf("Masukkan Ekspresi Kurung: ");
            fgets(ekspresi, MAX, stdin); // menyimpan ekspresi yang diinput user melalui keyboard seukuran MAX dan disimpan kedalam ekspresi

            ekspresi[strcspn(ekspresi, "\n")] = '\0'; // menghapus karakter newline

            if (cek_kurung(ekspresi))
                printf("Hasil: Ekspresi \"%s\" Seimbang \n", ekspresi);

            else
                printf("Hasil: Ekspresi \"%s\" Tidak Seimbang \n", ekspresi);
            break;
        }

        case 2:
        {
            char infix[MAX];

            printf("\n------ Infix -> Postfix ------\n");
            printf("Masukkan Ekspresi Infix: ");
            fgets(infix, MAX, stdin); // menyimpan ekspresi yang diinput user melalui keyboard seukuran MAX dan disimpan kedalam Infix

            infix[strcspn(infix, "\n")] = '\0'; // menghapus karakter newline

            // Validasi apakah kurung seimbang atau tidak
            if ((!cek_kurung(infix)))
            {
                printf("Ekspresi Infix Tidak Sesuai(Kurung tidak seimbang)\n");
                break;
            }

            infix_to_postfix(infix, hasil_postfix);

            printf("Ekspresi Infix: %s\n", infix);
            printf("Ekspresi Postfix: %s\n", hasil_postfix);
            break;
        }
        case 3:
        {
            // Cek apakah menu 2 sudah dijalankan
            if (strlen(hasil_postfix) == 0)
            {
                printf("Belum ada ekspresi postfix!\n");
                printf("Silakan jalankan Menu 2 terlebih dahulu.\n");
                break;
            }

            printf("Ekspresi Postfix  : %s\n", hasil_postfix);

            int hasil_arr = ev_post_arr(hasil_postfix);
            int hasil_LL = ev_postLL(hasil_postfix);

            printf("Hasil Postfix(Arr): %d\n", hasil_arr);
            printf("Hasil Postfix(LL): %d\n", hasil_LL);
            break;
        }
        default:
            printf("Input yang Anda Masukkan Tidak Sesuai(1-4)!!");
            break;
        }
        printf("\n");

    } while (pilihan != 4);
    printf("Program Selesai, Membersihkan Memori....\n");

    return 0;
}
