=========================
VARIABEL GLOBAL STATISTIK
=========================
Digunakan untuk menghitung jumlah perbandingan dan pertukaran data selama proses sorting berlangsung.

===============
HELPER INTERNAL
===============
Fungsi internal untuk menukar dua nilai integer dalam array. Fungsi ini hanya digunakan oleh algoritma sorting tertentu.

====================
GENERATE DATA RANDOM
====================
Mengisi array dengan bilangan acak menggunakan fungsi rand(). Data yang dihasilkan digunakan sebagai data uji algoritma sorting.

==============
INSERTION SORT
==============
Mengurutkan data dengan cara menyisipkan elemen ke posisi yang sesuai pada bagian array yang sudah terurut.

Kompleksitas:
Best Case : O(n)
Average : O(n²)
Worst Case : O(n²)

===========
BUBBLE SORT
===========
Mengurutkan data dengan cara membandingkan dua elemen yang bersebelahan kemudian menukarnya jika urutannya salah.

Kompleksitas:
Best Case : O(n)
Average : O(n²)
Worst Case : O(n²)

==============
SELECTION SORT
==============
Mengurutkan data dengan mencari elemen terkecil pada bagian array yang belum terurut kemudian menempatkannya pada posisi yang benar.

Kompleksitas:
Best Case : O(n²)
Average : O(n²)
Worst Case : O(n²)

==========
MERGE SORT
==========
Fungsi internal Merge Sort, bertugas menggabungkan dua sub-array yang sudah terurut menjadi satu array yang tetap terurut.

Array dibagi menjadi dua bagian yang lebih kecil, kemudian masing-masing bagian diurutkan dan digabungkan kembali.

Kompleksitas:
Best Case : O(n log n)
Average : O(n log n)
Worst Case : O(n log n)

==========
QUICK SORT
==========

Fungsi internal Quick Sort, memilih elemen pivot kemudian membagi data menjadi dua bagian:

1. Elemen yang lebih kecil dari pivot.
2. Elemen yang lebih besar dari pivot.

Data dibagi berdasarkan pivot, kemudian masing-masing bagian diurutkan secara rekursif.

Kompleksitas:
Best Case : O(n log n)
Average : O(n log n)
Worst Case : O(n²)

===============
TAMPILKAN ARRAY
===============

Menampilkan sebagian isi array ke layar agar output tetap rapi. Jika jumlah data sangat besar, hanya sejumlah elemen tertentu yang ditampilkan.

===============
RINGKASAN HASIL
===============
Menampilkan statistik hasil pengujian algoritma sorting:

- Nama algoritma
- Jumlah data
- Jumlah perbandingan
- Jumlah pertukaran
- Waktu eksekusi
