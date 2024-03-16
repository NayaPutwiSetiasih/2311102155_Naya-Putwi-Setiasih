# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Naya Putwi Setiasih - 2311102155</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
// Deklarasi array
    int arr[2][3][3];
// Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                // Meminta pengguna untuk memasukkan nilai ke dalam array
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        // Mencetak baris kosong setelah input selesai
        cout << endl;
    }
// Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                // Menampilkan nilai array sesuai dengan indeksnya
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    // Tampilan array tanpa label
    cout << endl;
// Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                // Menampilkan nilai array tanpa label
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program meminta pengguna untuk memasukkan nilai ke dalam array 3 dimensi dengan ukuran 2x3x3. Dilakukan menggunakan tiga perulangan bersarang untuk mengakses setiap elemen array dan meminta input nilai dari pengguna. Setelah pengguna selesai memasukkan nilai, program akan menampilkan kembali nilai yang dimasukkan oleh pengguna. Program juga menampilkan kembali nilai array tanpa label indeks. Ini dilakukan dengan perulangan bersarang yang sama, tetapi kali ini hanya menampilkan nilai array tanpa label indeks.

## Guided 
### 2. [Mencari Nilai Maksismal Pada Array]
```c++
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
```
Program di atas adalah contoh sederhana untuk menemukan nilai maksimum dalam sebuah array dan menampilkan lokasi elemen tersebut dalam array. Program meminta pengguna untuk memasukkan panjang array yang diinginkan. Pengguna diminta untuk memasukkan nilai-nilai array sesuai dengan panjang yang telah ditentukan. Program mencari nilai maksimum di antara elemen-elemen array yang dimasukkan oleh pengguna. Menggunakan perulangan untuk membandingkan setiap elemen dengan nilai maksimum yang telah ditentukan sebelumnya. Setelah nilai maksimum ditemukan, program menampilkan nilai maksimum beserta lokasinya dalam array.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi array dan variabel
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int ganjil_Naya2155[5], genap_Naya2155[5];
    int ganjilIndex = 0, genapIndex = 0;

    // Input data array
    cout << "Data array: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    // Memisahkan angka ganjil dan genap ke dalam array terpisah
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            ganjil_Naya2155[ganjilIndex] = arr[i];
            ganjilIndex++;
        } else {
            genap_Naya2155[genapIndex] = arr[i];
            genapIndex++;
        }
    }

    // Menampilkan angka genap
    cout << "Angka genap: ";
    for (int i = 0; i < ganjilIndex; i++) {
        cout << ganjil_Naya2155[i] << " ";
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Angka ganjil: ";
    for (int i = 0; i < genapIndex; i++) {
        cout << genap_Naya2155[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot Unguided 1 ](<Screenshot 2024-03-16 164226.png>)

Kita mendefinisikan array arr_Naya2155 dengan isi 1-10 (bisa juga dihilangkan jika pengguna ingin memasukkan input sendiri). Selanjutnya, kita mendefinisikan dua array ganjil_Naya2155 dan genap_Naya2155 yang digunakan untuk menyimpan angka genap dan ganjil dari array arr_Naya2155. Kita juga mendefinisikan dua variabel ganjilIndex dan genapIndex yang digunakan untuk melacak jumlah angka genap dan ganjil yang sudah disimpan di array ganjil dan genap. Kita meminta pengguna untuk memasukkan 10 angka dengan menggunakan for loop dan cin. Selanjutnya, kita melakukan iterasi sebanyak 10 kali dengan menggunakan for loop untuk memeriksa setiap angka di array arr_Naya2155. Jika angka tersebut merupakan angka ganjil, maka akan disimpan di array ganjil dengan menggunakan variabel ganjilIndex untuk menentukan posisi index-nya. Begitu juga untuk angka genap yang disimpan di array genap. Setelah selesai memeriksa seluruh angka di array arr_Naya2155, kita mencetak isi array ganjil dan genap menggunakan for loop dan variabel ganjilIndex dan genapIndex.

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]
```c++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk ukuran array
    int size1_Naya2155, size2_Naya2155, size3_Naya2155;
    
    // Input ukuran array 3 dimensi
    cout << "Masukkan ukuran array 3 dimensi: ";
    cin >> size1_Naya2155 >> size2_Naya2155 >> size3_Naya2155;

    // Deklarasi array 3 dimensi
    int arr_Naya2155[size1_Naya2155][size2_Naya2155][size3_Naya2155];

    // Input elemen array 3 dimensi
    cout << "Masukkan elemen array 3 dimensi: \n";
    for (int i = 0; i < size1_Naya2155; i++) {
        for (int j = 0; j < size2_Naya2155; j++) {
            for (int k = 0; k < size3_Naya2155; k++) {
                cin >> arr_Naya2155[i][j][k];
            }
        }
    }

    // Output isi array 3 dimensi
    cout << "Isi array 3 dimensi:\n";
    for (int i = 0; i < size1_Naya2155; i++) {
        for (int j = 0; j < size2_Naya2155; j++) {
            for (int k = 0; k < size3_Naya2155; k++) {
                cout << arr_Naya2155[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output
![Screenshot Unguided 2](<Screenshot 2024-03-16 165534.png>)

Kita meminta pengguna untuk memasukkan ukuran array tiga dimensi dengan menggunakan cin. Ukuran tersebut disimpan di variabel size1_Naya2155, size2_Naya2155, dan size3_Naya2155. Selanjutnya, kita mendefinisikan array arr_Naya2155 dengan ukuran yang telah dimasukkan oleh pengguna menggunakan size1_Naya2155, size2_Naya2155, dan size3_Naya2155. Kita meminta pengguna untuk memasukkan elemen array dengan menggunakan for loop dan cin. Loop pertama digunakan untuk mengakses dimensi pertama, loop kedua digunakan untuk mengakses dimensi kedua, dan loop ketiga digunakan untuk mengakses dimensi ketiga. Setelah selesai menginput seluruh elemen array, kita mencetak isi array dengan menggunakan for loop dan cout. Loop pertama digunakan untuk mengakses dimensi pertama, loop kedua digunakan untuk mengakses dimensi kedua, dan loop ketiga digunakan untuk mengakses dimensi ketiga

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]
```c++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk panjang array
    int n_Naya2155;
    
    // Input panjang array
    cout << "Masukkan panjang array: ";
    cin >> n_Naya2155;
    
    // Deklarasi array
    int arr_Naya2155[n_Naya2155];
    
    // Input elemen array
    cout << "Masukkan elemen array: ";
    for (int i_Naya2155 = 0; i_Naya2155 < n_Naya2155; i_Naya2155++) {
        cin >> arr_Naya2155[i_Naya2155];
    }
    
    // Deklarasi variabel pilihan
    int choice_Naya2155;
    
    // Loop menu
    do {
        cout << "\nMenu:\n";
        cout << "1. Mencari nilai maksimum\n";
        cout << "2. Mencari nilai minimum\n";
        cout << "3. Mencari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice_Naya2155;
        
        // Switch berdasarkan pilihan
        switch (choice_Naya2155) {
            case 1: {
                int max = arr_Naya2155[0];
                // Mencari nilai maksimum
                for (int i = 1; i < n_Naya2155; i++) {
                    if (arr_Naya2155[i] > max) {
                        max = arr_Naya2155[i];
                    }
                }
                cout << "Nilai maksimum adalah " << max << endl;
                break;
            }
            case 2: {
                int min = arr_Naya2155[0];
                // Mencari nilai minimum
                for(int i = 1; i < n_Naya2155; i++) {
                    if (arr_Naya2155[i] < min) {
                        min = arr_Naya2155[i];
                    }
                }
                cout << "Nilai minimum adalah " << min << endl;
                break;
            }
            case 3: {
                double sum = 0;
                // Menghitung nilai rata-rata
                for (int i = 0; i < n_Naya2155; i++) {
                    sum += arr_Naya2155[i];
                }
                double avg = sum / n_Naya2155;
                cout << "Nilai rata-rata adalah " << avg << endl;
                break;
            }
            case 4: {
                cout << "Terima kasih!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid\n";
                break;
            }
        }
    } while (choice_Naya2155 != 4); // Loop sampai pengguna memilih untuk keluar
    
    return 0;
}
```
#### Output
![Screenshot Unguided 3](<Screenshot 2024-03-16 170937.png>)

Program ini meminta pengguna untuk memasukkan panjang array dan elemen array. Kemudian, program menampilkan menu dengan pilihan untuk mencari nilai maksimum, minimum, atau rata-rata dari array.Program menggunakan switch-case untuk mengeksekusi kode yang sesuai dengan pilihan pengguna. Untuk mencari nilai maksimum, program menggunakan loop for untuk membandingkan setiap elemen array dengan nilai maksimum sementara dan mengupdate nilai maksimum jika ditemukan nilai yang lebih besar. Untuk mencari nilai minimum, program menggunakan loop for untuk membandingkan setiap elemen array dengan nilai minimum sementara dan mengupdate nilai minimum jika ditemukan nilai yang lebih kecil.Untuk mencari nilai rata-rata, program menggunakan loop for untuk menjumlahkan semua elemen array, kemudian membagi jumlah tersebut dengan panjang array.Program keluar dari loop do- while ketika pengguna memilih opsi keluar.Program mengembalikan nilai 0 untuk menunjukkan bahwa program telah berakhir dengan sukses.

## Kesimpulan
Array adalah salah satu jenis variabel pada bahasa pemrograman yang memungkinkan kita untuk menyimpan sekumpulan data dengan tipe yang sama dalam satu variabel. Data dalam array dapat diakses dengan menggunakan indeks atau nomor urut yang dimulai dari 0.Secara umum, terdapat dua jenis array yaitu array satu dimensi dan array multi dimensi. Array satu dimensi merupakan array yang terdiri dari satu baris data, sedangkan array multi dimensi terdiri dari beberapa baris dan kolom.Untuk mendeklarasikan sebuah array pada bahasa pemrograman, kita harus menentukan tipe data elemen array dan ukuran array.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.