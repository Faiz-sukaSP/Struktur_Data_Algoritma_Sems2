NAMA: FAIZ ASRA
NPM: 250810701100062
KELAS: B

DESKRIPSI PROYEK
----------------
->Program ini dibuat sesuai dengan arahan dan instruksi yang diberikan pada Tugas 2. Program ini berbasis bahasa C 
dan dirancang untuk mengimplementasikan struktur data Stack menggunakan dua pendekatan yaitu Array dan Linked List. 
Program memiliki tiga fitur utama: 
(1) validasi ekspresi tanda kurung seimbang menggunakan Stack Array,
(2) konversi ekspresi aritmatika infix ke postfix menggunakan Stack Linked List, dan 
(3) evaluasi nilai akhir ekspresi postfix menggunakan Stack Array dan Linked List.


STRUKTUR DATA
-------------
1. Stack Array       : Implementasi stack menggunakan array statis berukuran MAX (100).
                       Digunakan pada fitur cek kurung seimbang dan evaluasi postfix.

2. Stack Linked List : Implementasi stack menggunakan node dinamis (malloc/free).
                       Digunakan pada fitur konversi infix ke postfix dan evaluasi postfix.

STRUKTUR FILE
-------------
- main.c    : Logika utama program, menu interaktif, dan user interface.
- stack.c   : Implementasi seluruh fungsi stack (array & linked list), cek kurung,
              konversi infix-postfix, dan evaluasi postfix.
- stack.h   : Header file berisi definisi struktur data dan prototipe fungsi.

CARA KOMPILASI DAN MENJALANKAN PROGRAM INI
------------------------------------------
Gunakan compiler GCC/CLANG untuk mengompilasi program:

    =============================================
   | clang -g -Wall -o program main.c stack.c   |
    =============================================

Setelah berhasil dikompilasi, jalankan program dengan:

    ===========
   | ./program |
    ===========

UNTUK MELAKUKAN PENGETESAN MEMORY (MEMORY LEAK CHECK)
------------------------------------------------------
->Program ini telah dioptimalkan untuk manajemen memori dinamis. Untuk
memastikan tidak ada kebocoran memori (memory leak), pengetesan dilakukan
menggunakan perintah:

    =============================
   | leaks --atExit -- ./program |
    =============================

saya menggunakan tool bawaan macOS untuk melakukan pengetesan kebocoran memori.


 ==============================
| ALUR SAAT PROGRAM DIJALANKAN |
 ==============================

->Apabila dijalankan, maka hasilnya sebagai berikut:

*Menu 1 -> user memasukkan ekspresi kurung -> program menampilkan "Seimbang" atau "Tidak Seimbang".

*Menu 2 -> user memasukkan ekspresi infix (contoh: "1+2*3/2+4") -> program menampilkan
           hasil konversi postfix (contoh: "123*2/+4+") dan menyimpannya otomatis untuk menu 3.

*Menu 3 -> program langsung menggunakan postfix dari menu 2 -> menampilkan hasil
           evaluasi menggunakan Stack Array dan Stack Linked List (contoh: hasil = 8).
           Jika menu 2 belum dijalankan, program meminta user menjalankan menu 2 terlebih dahulu.

*Menu 4 -> program berhenti dan menampilkan "Program Selesai, Membersihkan Memori...."

 ========
| Output |
 ========

faizasra@MacBook-Pro-faiz Tugas_2 % leaks --atExit -- ./program

===== Program Stack =====
1. Cek Kurung Seimbang (Arr)
2. Konvert Infix ke Postfix (LL)
3. Menentukan Nilai Akhir Ekspersi Postfix (LL & Arr)
4. Keluar
Masukkan Pilihan Menu: 1

------ Cek Kurung ------
Masukkan Ekspresi Kurung: (({({([[( ) ( )]])})}))
Hasil: Ekspresi "(({({([[( ) ( )]])})}))" Seimbang 

Masukkan Pilihan Menu: ([{({([[( ) ( )]))})}))

------ Cek Kurung ------
Masukkan Ekspresi Kurung: Hasil: Ekspresi "[{({([[( ) ( )]))})}))" Tidak Seimbang 

Masukkan Pilihan Menu: 2

------ Infix -> Postfix ------
Masukkan Ekspresi Infix: (8/2)+3*2
Ekspresi Infix: (8/2)+3*2
Ekspresi Postfix: 82/32*+

Masukkan Pilihan Menu: 3
Ekspresi Postfix  : 82/32*+
Hasil Postfix(Arr): 10
Hasil Postfix(LL): 10

Masukkan Pilihan Menu: 4
Program Selesai, Membersihkan Memori....

Program Selesai, Membersihkan Memori....
Process:         program [8670]
Path:            /Users/USER/Desktop/*/program
Load Address:    0x107306000
Identifier:      program
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [8669]

Date/Time:       2026-03-10 12:20:29.576 +0700
Launch Time:     2026-03-10 12:16:38.375 +0700
OS Version:      macOS 12.7.6 (21H1320)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         2052K
Physical footprint (peak):  2052K
----

leaks Report Version: 4.0
Process 8670: 171 nodes malloced for 17 KB
Process 8670: 0 leaks for 0 total leaked bytes.