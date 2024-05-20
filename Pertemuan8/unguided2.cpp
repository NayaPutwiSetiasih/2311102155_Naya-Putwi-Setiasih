#include <iostream>

using namespace std;

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int hitungVokal(const char str[]) {
    int jumlahVokal_155 = 0; // Variabel untuk menyimpan jumlah huruf vokal
    int i = 0; // Variabel untuk iterasi karakter dalam kalimat
    while (str[i] != '\0') { // Loop hingga mencapai akhir kalimat ('\0')
        char ch = str[i]; // Ambil karakter pada posisi i
        // Periksa apakah karakter adalah huruf vokal
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            jumlahVokal_155++; // Tambahkan ke jumlah huruf vokal jika karakter adalah huruf vokal
        }
        i++; // Pindah ke karakter selanjutnya
    }
    return jumlahVokal_155; // Kembalikan jumlah huruf vokal
}

int main() {
    const int MAX_LENGTH_155 = 100; // Panjang maksimum kalimat
    char kalimat_155[MAX_LENGTH_155]; // Array untuk menyimpan kalimat

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    cin.getline(kalimat_155, MAX_LENGTH_155);

    // Hitung banyaknya huruf vokal dalam kalimat
    int jumlahVokal = hitungVokal(kalimat_155);

    // Output hasil perhitungan
    cout << "Banyaknya huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
