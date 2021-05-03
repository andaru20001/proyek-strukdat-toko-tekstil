# PROGRAM SISTEM ANTRIAN PEMESANAN TOKO TEKSTIL

Anggota Kelompok:
* Muhammad Daffa Alifiandi (14081020016)
* Andaru Danurdara Wibisana (140810200020)
* Mu'az Abdul Rohim (140810200026)
---
## Latar Belakang

Pada zaman sekarang, hampir segala aspek kehidupan sudah dipengaruhi dan disesuaikan dengan teknologi. Dengan teknologi, berbagai pekerjaan yang membosankan dan memakan waktu lama menjadi lebih menyenangkan dan hanya memakan waktu yang sangat singkat. Selain itu, dengan teknologi kemungkinan cacat atau hilangnya data dapat diminimalisasi sehingga dapat lebih diandalkan. Namun, ada beberapa aspek yang masih menggunakan cara tradisional atau cara lama sehingga mengurangi keefektifan kinerjanya, salah satunya yaitu dalam toko tekstil.

Toko tekstil tentu memiliki customer dan memiliki antrian pemesanan. Antrian pemesanan digunakan untuk manajemen pesanan-pesanan dari customer, seperti mencatat pesanan apa saja yang masuk dan mengatur pesanan mana yang harus dilayani terlebih dahulu. Akan tetapi, beberapa toko tekstil masih menggunakan cara lama untuk mencatat dan mengatur antrian pemesanan, yaitu menggunakan catatan tertulis dalam sebuah catatan atau buku. Apabila data antrian pemesanan dicatat dalam sebuah catatan atau buku, data akan rawan hilang karena bisa saja terdapat catatan atau lembaran dalam buku terlepas sehingga akan terjadi kehilangan data. Selain itu, sebuah catatan atau buku bisa saja mengalami kerusakan seperti terdapat halaman yang robek, tersiram air atau cairan-cairan lainnya sehingga data mengalami kerusakan. Lalu, apabila ingin melakukan pencarian data, maka data harus dicari satu persatu sehingga memakan waktu yang lama. Hal ini tentu membuat proses pendataan dan pencarian data menjadi lebih lama dan kemungkinan data cacat dan hilang akan jauh lebih besar.

Melihat masalah ini, kami terpikirkan untuk membuat sebuah program yang dapat melacak antrian pemesanan yang masuk, pesanan yang sudah diselesaikan, melihat daftar antrian pemesanan, dan lain-lain. Dengan program ini, proses manajemen antrian pemesanan toko tekstil akan menjadi lebih mudah dan log perubahan akan tercatat di sebuah file sehingga tidak ada data yang selip atau hilang. Dari program ini diharapkan dapat membantu toko-toko tekstil untuk mempermudah manajemen antrian pemesanan di tokonya.

## Tujuan dan Manfaat

* Tujuan dari proposal proyek ini adalah:
    1. Menyelesaikan tugas ujian akhir semester.
    2. Mengaplikasikan materi pembelajaran.

* Adapun manfaat dari proyek ini adalah sebagai berikut:
    - Bagi mahasiswa
        Manfaat pengerjaan proyek ini bagi mahasiswa adalah menambah pengalaman dan wawasan implementasi struktur data dalam kehidupan nyata khususnya di pembuatan sistem antrian pemesanan.
    - Bagi masyarakat umum
        Dalam skala yang kecil, pengerjaan proyek ini diharapkan dapat menambah wawasan masyarakat umum dalam mengorganisir antrian pesanan secara digital. Manfaat lain yang lebih umum dari proyek ini adalah mengajak masyarakat untuk menggunakan komputer untuk menyelesaikan masalah sehari-hari dan meninggalkan cara tradisional yang kurang efektif.

## Penjelasan Aplikasi

Program yang dikerjakan dalam proyek ini mengenai pengaplikasian struktur data dalam sistem antrian pemesanan toko tekstil. Struktur data yang digunakan dalam proyek ini adalah _Stack_, _Priority Queue_, dan _Linked List_.

_Stack_ dan _Priority Queue_ diimplementasikan dengan cara _Linked List_. _Linked List_ adalah metode penyimpanan data yang tidak diurutkan berdasarkan penempatan fisik melainkan setiap elemen menunjuk ke elemen selanjutnya. Penyimpanan data ini bersifat _non-contagious_ dan besar data yang dapat diubah secara dinamis.

_User_ akan  disajikan dengan dengan daftar pilihan pesanan dan jenis input yang akan dieksekusi. Dalam pembuatan antrian pesanan, akan diimplementasikan menggunakan _Priority Queue_. Pesanan yang diinputkan akan di-_enqueue_ ke dalam _queue_. Pesanan akan ditempatkan berdasarkan tenggat waktu penyelesaian pesanan. Setiap kali pesanan diselesaikan, node paling akhir akan di-_dequeue_.

Setiap kali _user_ menambah atau mengubah pesanan ke dalam _queue_, _stack_ akan ditambahkan _node_ yang berisi informasi pesanan yang diinput atau dalam pilihan edit pesanan, akan ditambahkan informasi pesanan sebelum pengubahan terjadi. Ketika _user_ memilih _undo_, tumpukan paling atas _stack_ akan diambil dan nilainya akan dimasukan ke node _Queue_ yang diubah sebelumnya secara terbalik.

Fitur _search_ akan diimplementasikan dengan traversal _queue_ berdasarkan kriteria dari query yang diinputkan.

## Gambar Rancangan Antar Muka
<!--
Buat rancangan antar muka selengkap mungkin sesuai fungsi aplikasinya. rancangan antar muka
diusahakan serapih dan seindah mungkin. tools yang digunakan dalam pembuatan rancangan gambar
dibebaskan sesuai kreatifitas kalian
!-->

Perancangan antarmuka meliputi perancangan struktur menu dan perancangan tampilan dari program yang dilihat oleh pengguna program _Sistem Antrian Pemesanan Toko Tekstil_.

![](/images/diagram.png)

Ada enam hal yang ditampilkan dalam menu user website profile ini, yaitu halaman Tambah, Hapus, Search dan Daftar pesanan dan Undo. Halaman Tambah berisi tentang penginputan data yang ingin ditambah ke antrian. Halaman hapus berisi tentang pendeskripsian data yang ingin dihapus oleh user. Halaman Search berisi pendeskripsian data yang ingin dicari oleh user. Halaman Edit pesanan akan mencari data pesanan yang ingin dirubah dan user dapat memanipulasi data tersebut. Halaman Daftar Pesanan menampilkan data - data di _Sistem Antrian Pemesanan Toko Tekstil_. Halaman Undo akan menampilkan proses apa yang di undo.

**Tampilan Halaman Utama (Menu)**

![](/images/menu.png)

**Tampilan Halaman Tambah**

![](/images/tambah.png)

**Tampilan Halaman Hapus**

![](/images/hapus.png)

**Tampilan Halaman Search**

![](/images/search.png)

**Tampilan Halaman Daftar Pesanan**

![](/images/daftar.png)

**Tampilan Halaman Edit Pesanan**

![](/images/edit.png)

**Tampilan Halaman Undo**

![](/images/undo.png)

## Rencana Pengerjaan Projek
<!--
Dalam kondisi pandemi seperti ini, tidak memungkinkan untuk bertemu bertatap muka. Maka dari itu
jelaskan bagaimana kalian bekerja sama, berkoordinasi, pembagian kerja.Tools apa yang kalian gunakan
untuk bekerja bersama sama cth github, google docs, google meet>ibebaskan sesuai kreatifitas kalian
!-->

Dalam perancangan proyek UAS ini, kami melakukan teknik targeting, dimana kami menetapkan target waktu tertentu untuk menyelesaikan suatu task yang nantinya dibagi ke setiap anggota kelompok. Untuk targetnya sendiri kami akan melakukan pengerjaan bagian Menu, Tambah, Hapus, dan Search pada tanggal 5 Mei 2021 hingga 10 Mei 2021. Pengerjaan Daftar Pesanan, Edit Pesanan, dan Undo akan dilaksanakan pada 11 Mei 2021  hingga 17 Mei 2021.

Dalam pengerjaan proyek ini kami menggunakan media line dan discord untuk berdiskusi secara langsung maupun tidak langsung. Bentuk koordinasi kami dalam pengerjaan proyek ini adalah dengan saling sharing dan membantu berkaitan dengan materi yang dibutuhkan untuk menyelesaikan proyek program Sistem Antrian Pemesanan Toko Tekstil.

## Lisensi

MIT License 2021
