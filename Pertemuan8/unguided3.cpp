#include <iostream>

using namespace std;

// Fungsi untuk menghitung jumlah angka 4 menggunakan Sequential Search
int hitungEmpat(const int arr[], int length, int target) {
    int count = 0; // Variabel untuk menyimpan jumlah angka 4
    for (int i = 0; i < length; i++) { // Loop melalui setiap elemen array
        if (arr[i] == target) { // Jika elemen saat ini sama dengan angka 4
            count++; // Tambahkan ke jumlah angka 4
        }
    }
    return count; // Kembalikan jumlah angka 4
}

int main() {
    const int data_155[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array data
    const int length_155 = sizeof(data_155) / sizeof(data_155[0]); // Panjang array
    const int target_155 = 4; // Angka yang dicari

    // Hitung jumlah angka 4 dalam array
    int jumlahEmpat = hitungEmpat(data_155, length_155, target_155);

    // Output hasil perhitungan
    cout << "Banyaknya angka " << target_155 << " dalam data adalah: " << jumlahEmpat << endl;

    return 0;
}
