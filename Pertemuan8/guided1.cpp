#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk ukuran array
    int n = 10;

    // Inisialisasi array dengan 10 elemen
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};

    // Angka yang akan dicari dalam array
    int cari = 10;

    // Variabel boolean untuk menandai apakah angka ditemukan
    bool ketemu = false;

    // Variabel indeks
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        // Jika elemen array sama dengan angka yang dicari
        if (data[i] == cari) {
            // Tandai bahwa angka ditemukan
            ketemu = true;
            // Keluar dari loop
            break;
        }
    }

    // Output informasi tentang program
    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Cek apakah angka ditemukan
    if (ketemu) {
        // Jika ditemukan, tampilkan indeks di mana angka ditemukan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        // Jika tidak ditemukan, tampilkan pesan bahwa angka tidak ditemukan
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
