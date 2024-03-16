#include <iostream>
using namespace std;
int main(){

    // Deklarasi variabel
    int maks, a, i = 1, lokasi;

    // Meminta pengguna untuk memasukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // Membuat array dengan ukuran sesuai input pengguna
    int array[a];

    // Meminta pengguna untuk memasukkan nilai-nilai array
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // Menginisialisasi nilai maksimum dengan elemen pertama array
    maks = array[0];

    // Mencari nilai maksimum dan lokasinya dalam array
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }

    // Menampilkan nilai maksimum dan lokasinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}