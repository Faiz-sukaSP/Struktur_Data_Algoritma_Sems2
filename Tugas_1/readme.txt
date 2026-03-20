NAMA: FAIZ ASRA
NPM: 250810701100062
KELAS: B

DESKRIPSI PROYEK
----------------
->Program ini saya buat sesuai dengan arahan dan instruksi yang diberikan. Program ini berbasis bahasa C dan dirancang 
untuk membaca sebuah file teks bernama "dbterms.txt" lalu membaca isi file tersebut baris demi baris dan mengambil
huruf pertama setiap kata dan dikonversikan menjadi sebuah index 0-25 (menggunakan metode hashing sederhana "index = tolower(kata[0]) - 'a';")
berdasarkan huruf awalnya (a-z). Kata yang diambil tersebut lalu dimasukkan ke dalam linked list berdasarkan huruf awalnya.
Untuk operasi penghapusan kata, program ini memiliki kompleksitas O(n/k).

STRUKTUR DATA
-------------
1. Array: Berfungsi sebagai tabel hash sederhana dengan index 0 (a) sampai 25 (z).
2. Single Linked List: Menyimpan kata-kata yang memiliki awalan huruf yang sama 
   secara dinamis.

STRUKTUR FILE
-------------
- main.c      : Logika utama program, proses pembacaan file, dan antarmuka pengguna.
- linklist.c  : Implementasi fungsi-fungsi linked list (insert, display, free memory).
- linklist.h  : Header file yang berisi definisi struktur data dan prototipe fungsi.
- dbterms.txt : File sumber data berisi daftar kata/istilah yang akan diproses.

CARA KOMPILASI DAN MENJALANKAN PROGRAM INI
------------------------------------------
Gunakan compiler GCC/CLANG untuk mengompilasi program:

    =============================================
   | clang -g -Wall -o program main.c linklist.c |
    =============================================

Setelah berhasil dikompilasi, jalankan program dengan:

    ===========
   | ./program |
    ===========

UNTUK MELAKUKAN PENGETESAN MEMORY (MEMORY LEAK CHECK)
----------------------------------------------------
->Program ini telah dioptimalkan untuk manajemen memori dinamis. Untuk 
memastikan tidak ada kebocoran memori (memory leak), pengetesan dilakukan 
menggunakan perintah:

    =============================
   | leaks --atExit -- ./program |
    =============================

Mengapa saya tidak menggunakan  "mtrace" dan "valgrind"??
->karena mtrace dan valgrind tersebut berbasis linux dan saya menggunakan macOS monterey 12.7.6
dan jika saya menggunakan virtual machine linux maka hal tersebut dapat menurunkan kemampuan mac saya 
dan os linux pun tidak dapat bekerja dengan maksimal(crash). sehingga saya menggunakan tool bawaan macOS


"leaks --atExit -- ./program"
-----------------------------
Artinya:
leaks -> jalankan memory leak checker
--atExit -> jalankan pengecekan saat program selesai
-- -> pemisah antara opsi leaks dan nama program
./program -> executable yang ingin diuji

FITUR UTAMA
-----------
1. Membaca data baris demi baris dari `dbterms.txt`.
2. Pengelompokan otomatis ke index 0-25 berdasarkan karakter pertama.
3. Penanganan memori dinamis (malloc/free) untuk setiap node kata.
4. Output yang menampilkan daftar kata yang terkelompok sesuai abjad.

========================================================================

 ==============================
| ALUR SAAT PROGRAM DIJALANKAN |
 ==============================

->Apabila dijalankan dengan tool bawaan macOS untuk mengecek kebocoran memori, maka hasilnya sebagai berikut:

*jika user memilih pilihan yang pertama maka user diminta untuk memilih abjad yang diinginkan yaitu a-z jika user memilih abjad
lebih daripada 1 (ex. abc) maka akan menampilkan kata sesuai dengan huruf pertama inputan user dan apabila user menginput selain abjad
(angka/simbol) maka program akan error dan menampilkan output: "Input tidak valid! Masukkan huruf a-z." dan meminta user untuk memilih menu ulang.

*jika user memilih pilihan kedua maka user akan diminta memasukkan kata apa yang akan dihapus (ex. ayam) dan apabila kata ada dan
berhasil dihapus maka program akan menampilkan output: "Kata 'ayam' berhasil dihapus" dan apabila kata tidak ada dalam linklist maka outputnya sepertinya
"Kata 'adadsa' tidak ditemukan.".

*jika user memilih pilihan ketiga maka program berhenti dan menampilkan output: "Membersihkan memori dan keluar dari program..." dan apabila dikompilasi
dengan tool bawaan macOS untuk mengecek kebocoran memory maka:
->Process:         program [5601]
Path:            /Users/USER/Desktop/*/program
Load Address:    0x104bfd000
Identifier:      program
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [5600]

Date/Time:       2026-03-03 03:00:24.207 +0700
Launch Time:     2026-03-03 02:53:54.919 +0700
OS Version:      macOS 12.7.6 (21H1320)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         4068K
Physical footprint (peak):  4112K
----

leaks Report Version: 4.0
Process 5601: 172 nodes malloced for 17 KB
Process 5601: 0 leaks for 0 total leaked bytes.
---------------
yang berarti program berjalan tanpa kebocoran memori yang tertulis pada bagian "Process 5601: 0 leaks for 0 total leaked bytes."
    

 ========
| Output |
 ========

=== File telah berhasil dibaca dan di kelompokkan ===

==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): 1
Masukkan huruf (a-z): x

Kata-kata dengan huruf awal 'x' (20 kata):
- xxvi                     - xlt                      - xxxxxxxx                 - xxiv                     - xanana                   - xin                      
- xp                       - xinhua                   - xaar                     - xi                       - xenia                    - xenon                    
- xxiii                    - xtra                     - xii                      - x                        - xhtml                    - xmlns                    
- xml                      - xviii                    


==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): 2 
Masukkan kata yang ingin anda hapus: xxvi
Kata 'xxvi' berhasil dihapus.


==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): 1
Masukkan huruf (a-z): x

Kata-kata dengan huruf awal 'x' (19 kata):
- xlt                      - xxxxxxxx                 - xxiv                     - xanana                   - xin                      - xp                       
- xinhua                   - xaar                     - xi                       - xenia                    - xenon                    - xxiii                    
- xtra                     - xii                      - x                        - xhtml                    - xmlns                    - xml                      
- xviii                    


==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): 4
Menu yang anda pilih tidak sesuai

==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): a 
Input tidak valid! Masukkan angka 1-3.

==== MENU PILIHAN ====
1. Menampilkan kata sesuai abjad pertama yang ditentukan 
2. Menghapus kata yang diinginkan dalam linklist 
3. Keluar 
---------------------------------------------------------- 
Masukkan pilihan yang ada inginkan(1-3): 3
Membersihkan memori dan keluar dari program...

Process:         program [6865]
Path:            /Users/USER/Desktop/*/program
Load Address:    0x107df2000
Identifier:      program
Version:         ???
Code Type:       X86-64
Platform:        macOS
Parent Process:  leaks [6864]

Date/Time:       2026-03-03 05:29:01.757 +0700
Launch Time:     2026-03-03 05:28:16.964 +0700
OS Version:      macOS 12.7.6 (21H1320)
Report Version:  7
Analysis Tool:   /usr/bin/leaks

Physical footprint:         4120K
Physical footprint (peak):  4120K
----

leaks Report Version: 4.0
Process 6865: 172 nodes malloced for 17 KB
Process 6865: 0 leaks for 0 total leaked bytes.

============================================================

TAMBAHAN BAGI PENGGUNA WINDOWS!!
--------------------------------
->bagi pengguna windows dan tidak menggunakan linux maka untuk pengecekan kebocoran memori(Memory Leaks)
bisa menggunakan:

compile:
->    gcc -fsanitize=address -g main.c linklist.c -o program.exe

jalankan di CMD/PowerShell:
->    program.exe



 =========================
|    CATATAN PROGRAMER    |  
 =========================

->Saya tidak menggunakan kompleksitas O(1) secara mutlak, melainkan menggunakan kompleksitas O(n/k). 
Hal ini karena meskipun proses penyisipan dilakukan di awal linked list yang secara teori dapat dianggap O(1),
tetap terdapat proses traversal di dalam bucket untuk pengecekan duplikasi maupun saat melakukan pencarian dan penghapusan kata. Oleh karena itu,
kompleksitas yang lebih tepat untuk menggambarkan kinerja program ini adalah O(n/k), karena performa sangat dipengaruhi oleh jumlah
data yang masuk ke setiap bucket. Analisis ini lebih realistis dan lebih sesuai untuk menggambarkan kondisi sebenarnya,
terutama jika data yang diproses berjumlah sangat besar.

->sisipkan_kata 
* akses index -> kompleksitas = O(1)
* cek duplikasi -> kompleksitas = O(n) -> the worst case 
    -> saya menambahkan fungsi ini karena melihat terdapat beberapa data yang terduplikasi 
    sehingga menurut saya fungsi ini sangat diperlukan untuk mengolah data yang diberikan.
* insert kata dari depan -> kompleksitas = O(1)

kompleksitas akhir = O(n) -> the worst case
-------------------------

->hapus_kata
* akses index -> kompleksitas = O(1)
* huruf besar -> huruf kecil = O(L)
* tranversal linked list -> O(n)

kompleksitas akhir = O(n) -> the worst case
-------------------------

ket:
n = total elemen (banyak kata)
k = jumlah bucket (index)