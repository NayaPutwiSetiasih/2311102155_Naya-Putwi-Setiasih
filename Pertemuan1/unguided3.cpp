#include <iostream> // Library standar untuk input-output
#include <map> // Library untuk menggunakan map
#include <iomanip> // Library untuk manipulasi output

using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar

// Fungsi untuk memesan tiket
void pesanTiket(map<string, int>& tiket_Naya2155, const string& film_Naya2155, int jumlahTiket_Naya2155) {
    // Memeriksa apakah film ada dalam daftar tiket
    if (tiket_Naya2155.find(film_Naya2155) != tiket_Naya2155.end()) {
        // Memeriksa apakah stok tiket mencukupi
        if (tiket_Naya2155[film_Naya2155] >= jumlahTiket_Naya2155) {
            // Mengurangi stok tiket
            tiket_Naya2155[film_Naya2155] -= jumlahTiket_Naya2155;
            cout << "Pemesanan tiket untuk film " << film_Naya2155 << " berhasil!" << endl; // Menampilkan pesan berhasil
        } else {
            cout << "Maaf, stok tiket untuk film " << film_Naya2155 << " tidak mencukupi." << endl;  // Menampilkan pesan stok tidak mencukupi
        }
    } else {
        cout << "Film " << film_Naya2155 << " tidak ditemukan dalam daftar." << endl; // Menampilkan pesan film tidak ditemukan
    }
}

// Fungsi utama
int main() {
    // Membuat map tiketBioskop yang berisi daftar film dan stok tiketnya
    map<string, int> tiketBioskop_Naya2155 = {
        {"Mariposa", 35}, // Film Mariposa dengan stok 35 tiket
        {"Agak Laen", 15}, // Film Agak Laen dengan stok 15 tiket
        {"Dilan 1990", 5} // Film Dilan 1990 dengan stok 5 tiket
    };

// Menampilkan daftar film yang tersedia
    cout << "Daftar film yang tersedia : " << endl;
    for (const auto& pair : tiketBioskop_Naya2155) {
        cout << "-" << pair.first << endl; // Menampilkan nama film
    }
    // Memesan tiket untuk film Dilan 1990 sebanyak 2 tiket
    pesanTiket(tiketBioskop_Naya2155, "Dilan 1990", 2);

// Menampilkan sisa tiket setelah pemesanan
    cout << "\nSisa tiket setelah pemesanan : " << endl;
    for (const auto& pair : tiketBioskop_Naya2155) {
        cout << "-" << pair.first << ": " << pair.second << " tiket" << endl; // Menampilkan nama film dan sisa tiket
    }
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}
