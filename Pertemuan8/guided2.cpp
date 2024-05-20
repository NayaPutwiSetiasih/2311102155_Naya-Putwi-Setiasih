#include <iostream>
#include <conio.h> // Digunakan untuk _getche()
#include <iomanip> // Digunakan untuk setw()

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; // Array yang akan diurutkan dan dicari
int cari; // Variabel untuk menyimpan nilai yang dicari

// Fungsi untuk mengurutkan array menggunakan Selection Sort
void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        // Tukar nilai minimum dengan nilai pada indeks ke-i
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

// Fungsi untuk melakukan Binary Search pada array yang sudah diurutkan
void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false; // Penanda apakah data ditemukan atau tidak
    awal = 0;
    akhir = 6; // Batas bawah dan atas dari range pencarian
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2; // Cari titik tengah
        if (dataArray[tengah] == cari) {
            b_flag = true; // Jika data ditemukan, set penanda menjadi true
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1; // Jika data di tengah lebih kecil dari yang dicari, geser batas bawah
        } else {
            akhir = tengah - 1; // Jika data di tengah lebih besar dari yang dicari, geser batas atas
        }
    }
    // Tampilkan hasil pencarian
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    
    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    
    // Input data yang dicari
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    
    // Urutkan data dengan selection sort
    selection_sort();
    
    // Tampilkan data setelah diurutkan
    cout << "\nData diurutkan: ";
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    
    // Lakukan binary search
    binarysearch();
    
    // Menunggu input untuk menutup program
    _getche();
    return 0;
}
