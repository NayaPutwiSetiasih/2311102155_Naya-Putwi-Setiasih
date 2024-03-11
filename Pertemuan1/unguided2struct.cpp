#include <iostream> // Library standar untuk input-output
#include <iomanip> // Library untuk manipulasi output

using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar
// Mendefinisikan struktur data Barang
struct Barang {
    string nama_Naya2155; // Variabel untuk menyimpan nama barang
    double harga_Naya2155; // Variabel untuk menyimpan harga barang
    // Method untuk menampilkan informasi barang
    void display(){
        cout << "Nama Barang : " << nama_Naya2155 << endl; // Menampilkan nama barang
        cout << "Harga : " << harga_Naya2155 << endl; // Menampilkan harga barang
    }
};

// Fungsi utama
int main(){
    Barang barang1; // Mendeklarasikan objek barang1 dari struct Barang
// Mengisi data untuk objek barang1
    barang1.nama_Naya2155 = "Tas"; // Mengisi nama barang
    barang1.harga_Naya2155 = 400000; // Mengisi harga barang
    // Memanggil method display dari objek barang1 untuk menampilkan informasi barang
    barang1.display();

    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}