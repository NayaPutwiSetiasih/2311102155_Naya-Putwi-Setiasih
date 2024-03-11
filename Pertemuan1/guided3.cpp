#include <iostream> // Library standar untuk input-output
#include <array> // Library untuk menggunakan array STL (Standard Template Library)
using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar

int main() {
    int nilai[5]; // Mendeklarasikan array bernama nilai yang dapat menampung 5 integer

    // Mengisi nilai ke dalam array nilai
    nilai[0] = 23; // Mengisi nilai 23 pada indeks ke-0 dari array nilai
    nilai[1] = 50; // Mengisi nilai 50 pada indeks ke-1 dari array nilai
    nilai[2] = 34; // Mengisi nilai 34 pada indeks ke-2 dari array nilai
    nilai[3] = 78; // Mengisi nilai 78 pada indeks ke-3 dari array nilai
    nilai[4] = 90; // Mengisi nilai 90 pada indeks ke-4 dari array nilai

    // Menampilkan isi dari masing-masing elemen array nilai
    cout << "Isi array pertama : " << nilai[0] << endl; // Menampilkan nilai pada indeks ke-0 dari array nilai
    cout << "Isi array kedua : " << nilai[1] << endl; // Menampilkan nilai pada indeks ke-1 dari array nilai
    cout << "Isi array ketiga : " << nilai[2] << endl; // Menampilkan nilai pada indeks ke-2 dari array nilai
    cout << "Isi array keempat : " << nilai[3] << endl; // Menampilkan nilai pada indeks ke-3 dari array nilai
    cout << "Isi array kelima : " << nilai[4] << endl; // Menampilkan nilai pada indeks ke-4 dari array nilai
    
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}