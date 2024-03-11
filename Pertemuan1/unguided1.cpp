#include <iostream> // Library standar untuk input-output
#include <iomanip> // Library untuk manipulasi output


using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar


int main(){
    int pilih_Naya2155; // Variabel untuk menyimpan pilihan menu
    float r, s; // Variabel untuk menyimpan nilai jari-jari (r) dan sisi (s)
    float lp, ll; // Variabel untuk menyimpan luas persegi (lp) dan luas lingkaran (ll)
        // Menampilkan menu
        cout << " M E N U << \n";
        cout << "\n";
        cout << "1. Menghitung Luas Persegi \n";
        cout << "2. Menghitung Luas Lingkaran\n";
        cout << "\n";
        cout << " Pilih Nomor 1-2?"; // Meminta pengguna untuk memilih nomor menu
    cin >> pilih_Naya2155; // Mengambil pilihan menu dari input pengguna
    cout << "\n";

    // Melakukan pemrosesan berdasarkan pilihan menu
    switch(pilih_Naya2155){
    case 1:
        cout << "Panjang Sisi Persegi ?"; // Meminta pengguna untuk memasukkan panjang sisi persegi
        cin >> s; // Mengambil nilai panjang sisi persegi dari input pengguna
        lp =s*s; // Menghitung luas persegi
        cout << "Luas Persegi = " << lp; // Menampilkan luas persegi
        break;

    case 2:
        cout << "Jari - Jari Lingkaran ?"; // Meminta pengguna untuk memasukkan jari-jari lingkaran
        cin >> r; // Mengambil nilai jari-jari lingkaran dari input pengguna
        ll = 3.14*r*r; // Menghitung luas lingkaran
        cout << "Luas Lingkaran = " << ll; // Menampilkan luas lingkaran
        break;

    }
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}
