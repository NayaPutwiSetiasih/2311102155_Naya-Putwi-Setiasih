#include <iostream> // Menggunakan header file untuk input dan output

using namespace std; // Menggunakan namespace std agar tidak perlu menulis std:: secara berulang

// Fungsi untuk mengurutkan string menggunakan Bubble Sort
void bubbleSort(char str[], int length_155) {
    for (int i = 0; i < length_155 - 1; i++) { // Loop untuk mengakses setiap elemen dari 0 hingga panjang - 2
        for (int j = 0; j < length_155 - 1 - i; j++) { // Loop untuk membandingkan elemen berpasangan
            if (str[j] > str[j + 1]) { // Jika elemen saat ini lebih besar dari elemen berikutnya
                // Tukar elemen
                char temp = str[j]; // Simpan elemen saat ini di variabel sementara
                str[j] = str[j + 1]; // Gantikan elemen saat ini dengan elemen berikutnya
                str[j + 1] = temp; // Gantikan elemen berikutnya dengan elemen sementara
            }
        }
    }
}

// Fungsi untuk melakukan Binary Search pada string
bool binarySearch(const char str[], int length_155, char target_155) {
    int left = 0; // Inisialisasi batas kiri
    int right = length_155 - 1; // Inisialisasi batas kanan

    while (left <= right) { // Loop selama batas kiri kurang dari atau sama dengan batas kanan
        int mid = left + (right - left) / 2; // Hitung indeks tengah

        if (str[mid] == target_155) { // Jika elemen tengah sama dengan target
            return true; // Karakter ditemukan
        } else if (str[mid] < target_155) { // Jika elemen tengah lebih kecil dari target
            left = mid + 1; // Geser batas kiri ke kanan
        } else { // Jika elemen tengah lebih besar dari target
            right = mid - 1; // Geser batas kanan ke kiri
        }
    }

    return false; // Karakter tidak ditemukan
}

int main() {
    const int MAX_LENGTH_155 = 100; // Deklarasi panjang maksimum untuk kalimat
    char kalimat_155[MAX_LENGTH_155]; // Deklarasi array karakter untuk menyimpan kalimat
    char huruf_155; // Deklarasi karakter untuk menyimpan huruf yang dicari

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: "; // Tampilkan pesan kepada pengguna
    cin.getline(kalimat_155, MAX_LENGTH_155); // Baca kalimat dari input pengguna

    // Input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: "; // Tampilkan pesan kepada pengguna
    cin >> huruf_155; // Baca huruf dari input pengguna

    // Hitung panjang kalimat
    int length = 0; // Inisialisasi panjang kalimat
    while (kalimat_155[length] != '\0') { // Loop hingga akhir kalimat (null character)
        length++; // Tambah panjang kalimat
    }

    // Urutkan kalimat menggunakan Bubble Sort
    bubbleSort(kalimat_155, length); // Panggil fungsi bubbleSort untuk mengurutkan kalimat

    // Cari huruf menggunakan Binary Search
    bool ditemukan = binarySearch(kalimat_155, length, huruf_155); // Panggil fungsi binarySearch untuk mencari huruf

    // Output hasil pencarian
    if (ditemukan) { // Jika huruf ditemukan
        cout << "Huruf '" << huruf_155 << "' ditemukan dalam kalimat." << endl; // Tampilkan pesan bahwa huruf ditemukan
    } else { // Jika huruf tidak ditemukan
        cout << "Huruf '" << huruf_155 << "' tidak ditemukan dalam kalimat." << endl; // Tampilkan pesan bahwa huruf tidak ditemukan
    }

    return 0; // Mengembalikan nilai 0, menandakan program berakhir dengan sukses
}