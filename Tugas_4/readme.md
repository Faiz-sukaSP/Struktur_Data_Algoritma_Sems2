NAMA: FAIZ ASRA
NPM: 250810701100062
KELAS: B

DESKRIPSI PROYEK
----------------
->Program ini dibuat sesuai dengan arahan dan instruksi yang diberikan pada Tugas 4. Program ini berbasis bahasa C
dan dirancang untuk mengimplementasikan gabungan struktur data Binary Search Tree (BST) dan Linked List untuk
menghimpun kata-kata dari sebuah file teks berdasarkan huruf awal dari kata tersebut.

Setiap node pada BST menyimpan sebuah huruf dan pointer ke Linked List yang berisi semua kata berawalan huruf
tersebut. Program dapat menampilkan kata berdasarkan huruf yang diinputkan user, menampilkan statistik
keseluruhan secara terurut (ascending), serta membebaskan semua memori yang digunakan saat program selesai agar tidak
terjadi kebocoran memori.


STRUKTUR DATA
-------------
1. Binary Search Tree (BST) : Setiap node BST menyimpan satu huruf alfabet sebagai kunci, pointer ke Linked List (head), 
                              jumlah data dalam list, serta pointer left dan right ke node BST lainnya.

2. Linked List              : Setiap node Linked List menyimpan satu kata dan pointer next ke node berikutnya. Linked List 
                              terhubung ke node BST sesuai huruf awal katanya.


STRUKTUR FILE
-------------
- main.c   : Program utama berisi menu interaktif dan seluruh alur input/output kepada user.
- BST.c    : Implementasi semua fungsi BST dan Linked List (insert, find, inorder, free, dll).
- BST.h    : Header file berisi definisi struct dan prototipe fungsi yang digunakan.


CARA KOMPILASI DAN MENJALANKAN PROGRAM
---------------------------------------
Gunakan compiler GCC/CLANG untuk mengompilasi program:

    ============================================================
   | clang -g -Wall -o p main.c BST.c                          |
    ============================================================

Setelah berhasil dikompilasi, jalankan program dengan:

    ===========
   | ./program       |
    ===========

Saat dijalankan, program akan meminta nama file teks yang ingin dibaca:

    ============================================================
   | Masukkan nama file teks: dbterms.txt                      |
    ============================================================

UNTUK MELAKUKAN PENGETESAN MEMORY (MEMORY LEAK CHECK)
------------------------------------------------------
->Program ini telah dioptimalkan untuk manajemen memori dinamis. Untuk
memastikan tidak ada kebocoran memori (memory leak), pengetesan dilakukan
menggunakan perintah:

    =============================
   | leaks --atExit -- ./program       |
    =============================

saya menggunakan tool bawaan macOS untuk melakukan pengetesan kebocoran memori.

 ==============================
| ALUR SAAT PROGRAM DIJALANKAN |
 ==============================

Saat program dijalankan, user diminta memasukkan nama file teks. Program kemudian membaca
file tersebut baris per baris, mengambil kata pertama dari setiap baris, lalu memasukkannya
ke dalam BST berdasarkan huruf awalnya. Setelah pembacaan selesai, program masuk ke menu
pilihan utama.

--------------------------------
MENU PILIHAN YANG TERSEDIA
--------------------------------

- Pilihan 1: Menampilkan kata berdasarkan huruf pertama
  User memasukkan sebuah huruf. Program mencari node BST dengan huruf tersebut,
  lalu menampilkan maksimal 5 kata dari Linked List beserta total seluruh kata
  berawalan huruf itu.

  Contoh output (huruf ada):
   Menampilkan kata yang berawalan huruf "a":
    --------------------------------------------
    1. as
    2. anak
    3. air
    4. and
    5. asean
    total kata dari huruf tersebut adalah "1363"

  Contoh output (huruf tidak ada):
      z -- (0)

- Pilihan 2: Menampilkan statistik ascending
  Program melakukan traversal inorder pada BST sehingga setiap huruf ditampilkan
  secara urut dari a sampai z, beserta total kata yang dimiliki masing-masing huruf.

  Contoh output:
    Statistik kata (urut ascending berdasarkan huruf pertama)
    ---------------------------------------------------------
    a     1363
    b     1882
    c     804
    d     2236
    e     444
    f     406
    g     566
    dan seterusnya

- Pilihan 3: Keluar (free memory)
  Program membebaskan seluruh memori yang telah dialokasikan (BST + semua Linked List)
  menggunakan fungsi freeBST(), lalu program berhenti.

---------------------------------------
BUKTI HASIL PENGECEKAN KEBOCORAN MEMORY
---------------------------------------
Membebaskan memori..... Selesai. Sampai jumpa!

Process:         p [15119]
Path:            /Users/USER/Desktop/*/p
Load Address:    0x10c2ff000
Identifier:      p
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [15118]

Date/Time:       2026-04-13 23:39:46.747 +0700
Launch Time:     2026-04-13 23:39:30.939 +0700
OS Version:      macOS 12.7.6 (21H1320)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         4620K
Physical footprint (peak):  4960K
----

leaks Report Version: 4.0
Process 15119: 172 nodes malloced for 17 KB
Process 15119: 0 leaks for 0 total leaked bytes.

Terlihat pada baris terakhir "0 leaks for 0 total leaked bytes." 
yang berarti tidak ada kebocoran memori.
--------------------------------------------------------------------------------------------