NAMA: FAIZ ASRA
NPM: 250810701100062
KELAS: B

## DESKRIPSI PROYEK

Program ini dirancang untuk memenuhi Tugas 4 mata kuliah Struktur Data dan Algoritma. Proyek ini terdiri dari dua program utama yang mengimplementasikan dan membandingkan performa lima algoritma pengurutan (Sorting) baik secara kuantitatif maupun kualitatif:

1. PROGRAM SORTING INTEGER:
   Mengurutkan bilangan bulat acak yang dihasilkan secara dinamis menggunakan alokasi memori dinamis (malloc dan free). Program ini mampu menangani skala data besar hingga 5.000.000 elemen dan menyediakan fitur pengacakan ulang serta pengubahan ukuran data (n) secara interaktif melalui Menu 6.

2. PROGRAM SORTING STRING:
   Mengurutkan kata/istilah (string) yang dibaca secara eksternal dari sebuah file teks (dbterms.txt). Program menangani pembacaan aman menggunakan batasan `MAX_WORD` (30.000 kata) dan `MAX_WORD_LEN` (100 karakter) serta memanfaatkan fungsi manipulasi string standar (strcmp, strcpy) untuk perbandingan dan pertukaran elemen.

Kedua program dilengkapi dengan mekanisme pencatatan statistik global untuk menghitung jumlah operasi perbandingan (comparison), jumlah pertukaran/pergeseran (swap count), serta waktu eksekusi presisi dalam satuan milidetik (ms).

## STRUKTUR FILE

Proyek ini diorganisasikan ke dalam modul-modul terpisah untuk memisahkan logika data integer dan data string:

1. Data_Integer:
   ->function_integer.h : Header file berisi definisi prototipe fungsi sorting integer dan variabel statistik.
   ->function_integer.c : Implementasi algoritma pengurutan, fungsi utilitas, dan menu interaktif integer.

2. Modul String:
   ->function_string.h`  Header file berisi definisi konstanta (MAX_WORD, MAX_WORD_LEN), prototipe fungsi, dan variabel statistik string.
->function_string.` : Implementasi pembacaan file teks, algoritma pengurutan string, dan menu interaktif string.

3. Program Utama:
   ->main.c : Titik masuk utama (entry point) eksekusi program.

## CARA KOMPILASI DAN MENJALANKAN PROGRAM

Gunakan compiler GCC atau Clang melalui terminal (CMD/PowerShell/Linux Terminal) untuk melakukan kompilasi.

1. Kompilasi Versi Integer:
   ->clang -g -Wall -o program main.c function_integer.c

   Jalankan program:
   ./program

2. Kompilasi Versi String:
   ->clang -g -Wall -o program main.c function_string.c

   Jalankan program:
   ./program

   Jalankan program (pastikan file 'dbterms.txt' berada di direktori yang sama)

=========================
VARIABEL GLOBAL STATISTIK
=========================
Digunakan untuk menghitung jumlah perbandingan (comparison) dan pertukaran/pergeseran data (swapCount) secara akurat selama proses algoritma sorting berlangsung. Variabel ini di-reset menjadi 0 setiap kali sebuah algoritma mulai dijalankan agar hasil perbandingan antar metode tetap adil dan independen.

===============
HELPER INTERNAL
===============
Fungsi internal (static void swapInt / swapString) digunakan untuk menukar dua elemen posisi dalam array. Bersifat lokal di dalam file implementasi masing-masing untuk menjaga enkapsulasi kode dan mencegah konflik tautan (linkage conflict).

====================
GENERATE DATA RANDOM
====================
Khusus program integer, fungsi ini mengisi array heap secara dinamis dengan bilangan acak positif memanfaatkan fungsi bawaan `rand()`. Data acak ini bertindak sebagai basis data mentah yang belum terstruktur sebelum diuji oleh kelima algoritma pengurutan.

====================
READ FILE (STRING)
====================
Khusus program string, fungsi `readFile` membuka file teks (misalnya `dbterms.txt`) dalam mode baca ("r"), mengekstrak kata demi kata menggunakan `fscanf` dengan batasan lebar string aman (`%99s`) guna mencegah terjadinya buffer overflow, serta mengembalikan total jumlah kata yang berhasil dimuat.

==============
INSERTION SORT
==============
Mengurutkan data dengan cara membagi array menjadi dua bagian (terurut dan belum terurut). Elemen dari bagian belum terurut diambil satu per satu (sebagai `key`) lalu disisipkan ke posisi yang tepat pada bagian array yang sudah terurut dengan menggeser elemen-elemen yang lebih besar ke arah kanan.

Kompleksitas Waktu:

- Best Case : O(n) -> Terjadi ketika data masukan sudah dalam keadaan terurut sempurna.
- Average Case : O(n²) -> Terjadi pada distribusi data acak normal.
- Worst Case : O(n²) -> Terjadi ketika data masukan terurut terbalik (descending).

===========
BUBBLE SORT
===========
Mengurutkan data dengan cara melakukan iterasi berulang melintasi array, membandingkan dua elemen yang saling bersebelahan, dan menukarnya jika urutannya salah. Ditambahkan optimalisasi berupa variabel flag 'swapped' (boolean) untuk menghentikan loop lebih awal jika dalam satu pass penuh tidak ada lagi elemen yang bertukar posisi.

Kompleksitas Waktu:

- Best Case : O(n) -> Berkat optimasi flag, loop langsung berhenti jika data sudah terurut sejak awal.
- Average Case : O(n²) -> Terjadi pada distribusi data acak biasa.
- Worst Case : O(n²) -> Terjadi ketika data masukan terurut terbalik.

==============
SELECTION SORT
==============
Mengurutkan data dengan memindai seluruh sub-array yang belum terurut untuk mencari elemen dengan nilai terkecil (`minIndex`). Setelah ditemukan, elemen terkecil tersebut ditukar secara langsung dengan elemen pertama dari sub-array non-terurut tersebut. Proses ini diulangi hingga seluruh indeks terisi.

Kompleksitas Waktu:

- Best Case : O(n²) -> Tetap memindai array untuk mencari nilai minimum meskipun data sudah terurut.
- Average Case : O(n²) -> Jumlah perbandingan selalu konstan terlepas dari susunan awal elemen.
- Worst Case : O(n²) -> Memiliki perilaku performa yang stabil namun lambat pada skala data besar.

==========
MERGE SORT
==========
Algoritma pengurutan tingkat lanjut menggunakan pendekatan rekursif (Divide and Conquer). Array dipecah menjadi dua sub-array secara berulang hingga mencapai elemen tunggal, kemudian sub-array tersebut digabungkan kembali menggunakan fungsi pembantu `merge` secara terurut ke dalam memori sementara yang dialokasikan secara dinamis.

Kompleksitas Waktu:

- Best Case : O(n log n) -> Pembelahan logaritmik dan penggabungan linier konstan di semua kondisi.
- Average Case : O(n log n) -> Sangat efisien dan stabil untuk tipe data berskala jutaan elemen.
- Worst Case : O(n log n) -> Memerlukan memori tambahan O(n) untuk alokasi sub-array temporer.

==========
QUICK SORT
==========
Algoritma pengurutan tingkat lanjut berbasis rekursif (Divide and Conquer). Fungsi ini memilih elemen terakhir sebagai `pivot` lalu mempartisi array melalui fungsi `partition` sedemikian rupa sehingga elemen yang lebih kecil dari pivot berpindah ke sisi kiri dan elemen yang lebih besar berpindah ke sisi kanan pivot. Proses penyusunan ulang ini dilanjutkan secara rekursif pada sub-array kiri dan kanan.

Kompleksitas Waktu:

- Best Case : O(n log n) -> Terjadi ketika pivot selalu berhasil membagi array menjadi dua bagian yang seimbang.
- Average Case : O(n log n) -> Algoritma sorting tercepat dalam praktik nyata untuk data acak berskala besar.
- Worst Case : O(n²) -> Terjadi jika data masukan sudah terurut (atau terurut terbalik) dan pivot dipilih dari elemen ujung, menyebabkan pembelahan menjadi tidak seimbang (skewed).

===============
TAMPILKAN ARRAY
===============
Menampilkan isi array ke layar secara terformat (menggunakan format lebar kolom `%-20s` agar tersusun lurus). Demi menjaga kerapian tampilan terminal pada pengujian data berskala masif, jumlah elemen yang dicetak dibatasi (maksimal 100 data teratas), disertai informasi jumlah sisa data yang disembunyikan.

===============
RINGKASAN HASIL
===============
Menampilkan blok kesimpulan data performa hasil pengujian algoritma sorting setelah selesai dieksekusi. Informasi ringkasan mencakup:

- Nama Algoritma : Mengidentifikasi metode pengurutan yang diuji.
- Jumlah Data (n) : Ukuran sampel data yang diproses.
- Jumlah Perbandingan : Total operasi komparasi elemen (menunjukkan efisiensi logika pencarian posisi).
- Jumlah Pertukaran : Total operasi perpindahan memori/nilai (menunjukkan beban penulisan data).
- Waktu Eksekusi : Durasi pemrosesan riil dari awal hingga akhir dalam milidetik (ms).
