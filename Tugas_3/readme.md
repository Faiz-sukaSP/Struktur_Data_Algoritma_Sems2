NAMA: FAIZ ASRA
NPM: 250810701100062
KELAS: B

DESKRIPSI PROYEK
----------------
->Program ini dibuat sesuai dengan arahan dan instruksi yang diberikan pada Tugas 3. Program ini berbasis bahasa C 
dan dirancang untuk mengimplementasikan struktur data Queue menggunakan dua pendekatan yaitu Array dan Linked List. 
Program memiliki dua simulasi utama:
(1) simulasi antrian printer menggunakan Queue Array dan Linked List, dan
(2) simulasi antrian pelayanan bank dengan dua jalur layanan menggunakan Queue Array dan Linked List.

Pada simulasi bank, setiap nasabah yang datang akan secara otomatis dimasukkan ke jalur dengan antrian terpendek 
dan dilayani berdasarkan prinsip FIFO (First In First Out).


STRUKTUR DATA
-------------
1. Queue Array       : Implementasi queue menggunakan array statis berukuran MAX (100).
                       Digunakan pada simulasi printer dan bank untuk menyimpan antrian secara berurutan.

2. Queue Linked List : Implementasi queue menggunakan node dinamis (malloc/free).
                       Digunakan untuk menghindari batasan kapasitas dan mengelola antrian secara fleksibel.


STRUKTUR FILE
-------------
- bank_main.c      : Program utama simulasi antrian bank (menu interaktif dan user interface).
- bank_queue.c     : Implementasi fungsi queue (array & linked list) untuk simulasi bank.
- printer_main.c   : Program utama simulasi antrian printer.
- printer_queue.c  : Implementasi fungsi queue untuk simulasi printer.
- queue.h          : Header file berisi definisi struktur data dan prototipe fungsi.


CARA KOMPILASI DAN MENJALANKAN PROGRAM INI
------------------------------------------
Gunakan compiler GCC/CLANG untuk mengompilasi program:

    ============================================================
   | clang -g -Wall -o program bank_main.c bank_queue.c         |
    ============================================================

Untuk menjalankan simulasi printer:

    ============================================================
   | clang -g -Wall -o printer printer_main.c printer_queue.c   |
    ============================================================

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

Program ini memiliki dua simulasi utama, yaitu simulasi antrian bank dan simulasi antrian printer. Keduanya menggunakan konsep queue (FIFO), jadi yang masuk duluan akan dilayani duluan.

--------------------------
A. SIMULASI ANTRIAN BANK
--------------------------

Saat program dijalankan, user diminta memilih metode:
1. Menggunakan Array
2. Menggunakan Linked List

Setelah itu akan masuk ke menu utama.

- Tambah Nasabah  
  User memasukkan nama/ID nasabah. Program otomatis akan memasukkan nasabah ke jalur yang antriannya paling sedikit.

- Layani Nasabah  
  Program akan melayani nasabah dari depan antrian (FIFO). Jika jalur 1 kosong, maka akan mengambil dari jalur 2.

- Tampilkan Antrian  
  Menampilkan semua nasabah yang sedang menunggu di masing-masing jalur.

- Jumlah Antrian  
  Menampilkan jumlah nasabah di setiap jalur.

- Sedang Dilayani  
  Menampilkan siapa yang berada di posisi paling depan tanpa menghapus dari antrian.

- Keluar  
  Program berhenti. Untuk linked list, memory akan dibersihkan agar tidak terjadi kebocoran.

-----------------------------
B. SIMULASI ANTRIAN PRINTER
-----------------------------

User juga bisa memilih simulasi printer dengan array atau linked list.

- Tambahkan Dokumen  
  User memasukkan nama/ID dokumen, lalu dokumen akan masuk ke antrian.

- Cetak Dokumen  
  Dokumen paling depan akan dicetak dan dikeluarkan dari antrian.

- Tampilkan Antrian  
  Menampilkan semua dokumen yang sedang menunggu.

- Lihat Dokumen Berikutnya  
  Menampilkan dokumen yang akan dicetak selanjutnya tanpa menghapusnya.

- Keluar  
  Program selesai.

--------------------------------------------------------------------------

