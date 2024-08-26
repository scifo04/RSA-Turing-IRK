# Implementasi Turing Machine dalam Kriptografi RSA
## **Daftar Isi**

- [Author](#author)
- [Deskripsi Program](#deskripsi-program)
- [Requirement Program](#requirements-program)
- [Set Up dan Build Program](#set-up-dan-build-program)
- [Cara Menggunakan Program](#cara-menggunakan-program)
- [Home Page](#home-page)
- [Test](#test)

## **Author**

|   NIM    |           Nama           |
| :------: | :----------------------: |
| 13522110 | Marvin Scifo Y. Hutahaean  |

## **Deskripsi Program**

<p align="justify">
Aplikasi ini adalah aplikasi emulator Kriptografi RSA yang dibuat dengan bahasa C++. Aplikasi ini bisa menerima string ASCII untuk melakukan enkripsi dan menggunakan string yang dienkripsi tersebut untuk melakukan dekripsi. Aplikasi ini juga akan melakukan perbandingan antara enkripsi RSA dengan dekripsi RSA

</p>

## **Tech Stack**
1. C++

## **Algoritma dan Penjelasannya**
Algoritma yang digunakan dalam aplikasi ini adalah Turing Machine. Turing Machine adalah robot terbatas yang dapat membaca, menulis, dan menghapus simbol pada pita yang panjangnya tak terhingga. Rekaman itu dibagi menjadi beberapa kotak, dan setiap kotak berisi simbol. Turing Machine hanya dapat membaca satu simbol dalam satu waktu, dan menggunakan seperangkat aturan (fungsi transisi) untuk menentukan tindakan selanjutnya berdasarkan keadaan saat ini dan simbol yang dibacanya.

## **Cara Menggunakan Program** ##
1. Pastikan mempunyai C++17 dan GMP (GMP dibutuhkan untuk menghitung angka-angka yang besar)
2. Langsung saja buka file executablenya di folder bin
3. Jika ingin melakukan kompilasi, silakan gunakkan command ini: g++ -o ../bin/RSA-Turing -I"C:/msys64/mingw64/include" -L"C:/msys64/mingw64/lib" -std=c++17 Engine.cpp Main.cpp Serialize.cpp Util.cpp Turing.cpp -lgmp -lgmpxx
4. Pastikan msys64 sudah mempunyai gmp.h dan gmpxx.h
5. Masukkan string yang ingin dienkripsi/dekripsi
6. Masukkan p dan q
7. Masukkan e yang relatif prima dengan toitent N (hasil (p-1)*(q-1))
8. Masukkan d yang jika dikalikan dengan e bersisa 1 ketika dimoduluskan dengan n (p*q)
9. Pilih opsi antara simulasi atau langsung cari solusi
10. Enjoy!!!

<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
