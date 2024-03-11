#include <iostream> // Library standar untuk input-output
#include <iomanip> // Library untuk manipulasi output


using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar

// Mendefinisikan class Mahasiswa
class Mahasiswa {
public :
    string nama_Naya2155; // Variabel untuk menyimpan nama mahasiswa
    int umur_Naya2155; // Variabel untuk menyimpan umur mahasiswa
    // Method untuk menampilkan informasi mahasiswa
    void display(){
        cout << "Nama : " << nama_Naya2155 << endl; // Menampilkan nama mahasiswa
        cout << "Umur : " << umur_Naya2155 << " Tahun " << endl; // Menampilkan umur mahasiswa
    }
};

// Fungsi utama
int main(){
    Mahasiswa mhs1; // Mendeklarasikan objek mhs1 dari class Mahasiswa
    // Mengisi data untuk objek mhs1
    mhs1.nama_Naya2155 = "Dita"; // Mengisi nama mahasiswa
    mhs1.umur_Naya2155 = 21; // Mengisi umur mahasiswa
    // Memanggil method display dari objek mhs1 untuk menampilkan informasi mahasiswa
    mhs1.display();

    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}
    