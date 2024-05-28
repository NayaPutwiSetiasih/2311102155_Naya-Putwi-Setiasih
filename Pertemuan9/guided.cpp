#include <iostream>
#include <iomanip> // Header file untuk manipulasi output

using namespace std;

// Array simpul yang berisi nama-nama simpul dalam graf
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", // Nama-nama simpul
    "Cianjur", "Purwokerto", "Yogyakarta"
};

// Matriks busur yang merepresentasikan bobot busur antar simpul
int busur[7][7] = {
    // Matriks bobot busur
    // Ciamis    Bandung   Bekasi    Tasikmalaya  Cianjur   Purwokerto  Yogyakarta
    {0, 7, 8, 0, 0, 0, 0},       // Ciamis
    {0, 0, 5, 0, 0, 15, 0},      // Bandung
    {0, 6, 0, 0, 5, 0, 0},       // Bekasi
    {0, 5, 0, 0, 2, 4, 0},       // Tasikmalaya
    {23, 0, 0, 10, 0, 0, 8},     // Cianjur
    {0, 0, 0, 0, 7, 0, 3},       // Purwokerto
    {0, 0, 0, 0, 9, 4, 0}        // Yogyakarta
};

// Fungsi untuk menampilkan graf
void tampilGraph() {
    // Iterasi untuk setiap baris dalam matriks busur
    for (int baris = 0; baris < 7; baris++) {
        // Menampilkan nama simpul untuk baris saat ini
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Iterasi untuk setiap kolom dalam matriks busur
        for (int kolom = 0; kolom < 7; kolom++) {
            // Jika ada busur dari simpul baris ke simpul kolom (nilai busur tidak nol)
            if (busur[baris][kolom] != 0) {
                // Menampilkan nama simpul tujuan dan bobot busur
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        // Pindah ke baris berikutnya setelah menampilkan semua busur dari simpul baris
        cout << endl;
    }
}

// Fungsi utama
int main() {
    // Memanggil fungsi untuk menampilkan graf
    tampilGraph();
    return 0;
}
