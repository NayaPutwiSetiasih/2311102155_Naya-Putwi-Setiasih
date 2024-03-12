# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Naya Putwi Setiasih</p>

## Dasar Teori

Tipe data dalam ilmu komputer dan pemrograman adalah klasifikasi data yang memberitahu kompiler atau interpreter bagaimana programmer bermaksud untuk menggunakan data tersebut. Tipe data membantu program dalam mendeteksi berbagai jenis informasi dan menentukan operasi yang dapat dilakukan pada data. Adapun tipe data yang akan dipelajari, sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi
Tipe data primitive (sederhana)
Tipe data primitive adalah tipe data yang hanya mampu menyimpan satu nilai pada setiap satu variabel. tipe data ini ini merupakan tipe data dasar yang sering digunakan program. Contohtipe data primitive, yaitu
- Integer (int), merupakan tipe data bilangan bulat.
- Karakter (char), merupakan tipe data yang menyimpan hanya satu (1) digit karakter, karena ukuran satu digit itu satu byte (dan 1 byte itu = 8 bit). untuk penulisan karakter menggunakanpetik tunggal ( ‘ ) di depan dan belakang karakter yang ditulis.
- Boolean, merupakan tipe data logika yang hanya bernilai true (benar) dan false (salah)
- Float : tipe data yang digunakan untuk menyimpan bilangan desimal seperti 1.5, 
2.1, 3.14, dan sebagainya.
Tipe Data Abstrak
Tipe data abstrak (ADT) adalah sebuah model matematis yang mendefinisikan sekumpulan nilai dan operasi yang dapat dilakukan pada nilai-nilai tersebut, tanpa menspesifikasikan bagaimana nilai-nilai tersebut direpresentasikan atau bagaimana operasi-operasi tersebut diimplementasikan. Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private.
Tipe Data Koleksi
Tipe data koleksi adalah tipe data yang digunakan untuk menyimpan sekumpulan data. Tipe data ini memungkinkan programmer untuk mengelompokkan data yang terkait dan mengaksesnya dengan mudah.
- Array: Tipe data array menyimpan sekumpulan data dengan tipe data yang sama. Data dalam array diakses menggunakan indeks.
- Tipe data vektor adalah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe data yang sama. 
Tipe data map (juga dikenal sebagai dictionary atau hash table) adalah struktur data yang digunakan untuk menyimpan kumpulan data yang diakses berdasarkan kunci. Map memungkinkan programmer untuk memetakan kunci ke nilai, dan mengakses nilai tersebut dengan cepat berdasarkan kuncinya.

## Guided 

### 1. [Tipe Data Primitif]

#include <iostream> // Library untuk input - output standar
#include <iomanip> // Library untuk manipulasi output

using namespace std; // Menggunakan namespace std untuk mengakses fungsi - fungsi standar

int main() {
    char op; // Deklarasi variabel untuk operator
    float num1, num2; //Deklarasi untuk dua operand

    // Meminta pengguna untuk memasukkan operator
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    // Meminta pengguna untuk memasukkan dua operand
    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    // Switch case untuk melakukan operasi berdasarkan operator yang dimasukkan
    switch (op) {

    case '+': // Operasi penjumlahan
        cout << "Result: " << num1 + num2;
        break;
    case '-': // Operasi pengurangan
        cout << "Result: " << num1 - num2;
        break;
    case '*': // Operasi perkalian
        cout << "Result: " << num1 * num2;
        break;
    case '/': // Operasi pembagian
    // Memeriksa apakah kedua operand tidak nol untuk menghindari pembagian dengan nol
     if (num2 != 0) {
        cout << "Result: " << fixed << setprecision(2) << num1 / num2;// Menampilkan hasil dengan kedua angka desimal
    } else {
        cout << "Error! Division by zero is not allowed."; // Pesan kesalahan untuk pembagian dengan nol
    }
    break;

default:
    cout << "Error! Operator is not correct"; // Pesan kesalahan untuk operator yang tidak benar
    }
    return 0; // Mengembalikan nilai nol sebagai indikasi program berakhir dengan sukses
}
```
Program di atas adalah kalkulator sederhana yang meminta pengguna untuk memasukkan operator dan dua operand, kemudian melakukan operasi aritmatika sesuai dengan operator yang dimasukkan.

### 2. [Tipe Data Abstrak]

#include <stdio.h> // Library standar untuk fungsi input-output
#include <string.h> // Library untuk fungsi manipulasi string

// Mendefinisikan struktur data Mahasiswa
struct Mahasiswa
{
    char name[50]; // Variabel untuk menyimpan nama mahasiswa
    char address[100]; // Variabel untuk menyimpan alamat mahasiswa
    int age; // Variabel untuk menyimpan usia mahasiswa
};
// Fungsi utama
int main()
{
    // Mendeklarasikan dua variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs1, mhs2;
    // Mengisi data untuk mhs1
    strcpy(mhs1.name, "Dian"); // Menyalin string "Dian" ke variabel name pada mhs1
    strcpy(mhs1.address, "Mataram"); // Menyalin string "Mataram" ke variabel address pada mhs1
    mhs1.age = 22; // Mengisi nilai 22 ke variabel age pada mhs1
    // Mengisi data untuk mhs2
    strcpy(mhs2.name, "Bambang"); // Menyalin string "Bambang" ke variabel name pada mhs2
    strcpy(mhs2.address, "Surabaya"); // Menyalin string "Surabaya" ke variabel address pada mhs2
    mhs2.age = 23; // Mengisi nilai 23 ke variabel age pada mhs2
    // Menampilkan informasi mahasiswa mhs1
    printf("## Mahasiswa 1 ##\n"); 
    printf("Nama: %s\n", mhs1.name); // Menampilkan nama mahasiswa mhs1
    printf("Alamat: %s\n", mhs1.address); // Menampilkan alamat mahasiswa mhs1
    printf("Umur: %d\n", mhs1.age); // Menampilkan usia mahasiswa mhs1 
    printf ("\n"); // Mencetak baris kosong
    // Menampilkan informasi mahasiswa mhs2
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name); // Menampilkan nama mahasiswa mhs2
    printf("Alamat: %s\n", mhs2.address); // Menampilkan alamat mahasiswa mhs2
    printf("Umur: %d\n", mhs2.age); // Menampilkan usia mahasiswa mhs2
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}

Program di atas adalah sebuah program dalam bahasa pemrograman C yang mendefinisikan sebuah struktur data Mahasiswa untuk merepresentasikan informasi mengenai mahasiswa, seperti nama, alamat, dan usia. Program kemudian membuat dua variabel bertipe struct Mahasiswa, yaitu mhs1 dan mhs2, dan mengisi data untuk kedua mahasiswa tersebut. Setelah itu, program menampilkan informasi mengenai kedua mahasiswa tersebut ke layar.

### 3. [Tipe Data koleksi]

#include <iostream> // Library standar untuk input-output
#include <array> // Library untuk menggunakan array STL (Standard Template Library)
using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar

int main() {
    int nilai[5]; // Mendeklarasikan array bernama nilai yang dapat menampung 5 integer

    // Mengisi nilai ke dalam array nilai
    nilai[0] = 23; // Mengisi nilai 23 pada indeks ke-0 dari array nilai
    nilai[1] = 50; // Mengisi nilai 50 pada indeks ke-1 dari array nilai
    nilai[2] = 34; // Mengisi nilai 34 pada indeks ke-2 dari array nilai
    nilai[3] = 78; // Mengisi nilai 78 pada indeks ke-3 dari array nilai
    nilai[4] = 90; // Mengisi nilai 90 pada indeks ke-4 dari array nilai

    // Menampilkan isi dari masing-masing elemen array nilai
    cout << "Isi array pertama : " << nilai[0] << endl; // Menampilkan nilai pada indeks ke-0 dari array nilai
    cout << "Isi array kedua : " << nilai[1] << endl; // Menampilkan nilai pada indeks ke-1 dari array nilai
    cout << "Isi array ketiga : " << nilai[2] << endl; // Menampilkan nilai pada indeks ke-2 dari array nilai
    cout << "Isi array keempat : " << nilai[3] << endl; // Menampilkan nilai pada indeks ke-3 dari array nilai
    cout << "Isi array kelima : " << nilai[4] << endl; // Menampilkan nilai pada indeks ke-4 dari array nilai
    
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}
Program di atas adalah contoh penggunaan array dalam bahasa pemrograman C++. Array adalah struktur data yang digunakan untuk menyimpan sekumpulan nilai yang serupa dengan tipe data yang sama. Dalam program ini, kita menggunakan array untuk menyimpan beberapa nilai integer.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. 
Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari 
materi tipe data primitif!]

```#include <iostream> // Library standar untuk input-output
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

```
#### Output:
![Screenshot Unguided 1](<Screenshot 2024-03-12 102510-1.png>)

Program di atas adalah sebuah kalkulator sederhana untuk menghitung luas persegi dan lingkaran.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

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

#### Output
![Screenshot Unguided 2](<Screenshot 2024-03-12 105506.png>)

Program diatas mengimplentasikan tipe data class mahasiswa dengan variabel nama dan umur

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

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

#### Output
![Screenshot Unguided 2](<Screenshot 2024-03-12 114336.png>)

Program di atas merupakan contoh penggunaan struktur (struct) dalam bahasa pemrograman C++. dengan mengimplementasikan variabel barang dan harga.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

#include <iostream> // Library standar untuk input-output
#include <map> // Library untuk menggunakan map
#include <iomanip> // Library untuk manipulasi output

using namespace std; // Menggunakan namespace std untuk mengakses fungsi-fungsi standar

// Fungsi untuk memesan tiket
void pesanTiket(map<string, int>& tiket_Naya2155, const string& film_Naya2155, int jumlahTiket_Naya2155) {
    // Memeriksa apakah film ada dalam daftar tiket
    if (tiket_Naya2155.find(film_Naya2155) != tiket_Naya2155.end()) {
        // Memeriksa apakah stok tiket mencukupi
        if (tiket_Naya2155[film_Naya2155] >= jumlahTiket_Naya2155) {
            // Mengurangi stok tiket
            tiket_Naya2155[film_Naya2155] -= jumlahTiket_Naya2155;
            cout << "Pemesanan tiket untuk film " << film_Naya2155 << " berhasil!" << endl; // Menampilkan pesan berhasil
        } else {
            cout << "Maaf, stok tiket untuk film " << film_Naya2155 << " tidak mencukupi." << endl;  // Menampilkan pesan stok tidak mencukupi
        }
    } else {
        cout << "Film " << film_Naya2155 << " tidak ditemukan dalam daftar." << endl; // Menampilkan pesan film tidak ditemukan
    }
}

// Fungsi utama
int main() {
    // Membuat map tiketBioskop yang berisi daftar film dan stok tiketnya
    map<string, int> tiketBioskop_Naya2155 = {
        {"Mariposa", 35}, // Film Mariposa dengan stok 35 tiket
        {"Agak Laen", 15}, // Film Agak Laen dengan stok 15 tiket
        {"Dilan 1990", 5} // Film Dilan 1990 dengan stok 5 tiket
    };

// Menampilkan daftar film yang tersedia
    cout << "Daftar film yang tersedia : " << endl;
    for (const auto& pair : tiketBioskop_Naya2155) {
        cout << "-" << pair.first << endl; // Menampilkan nama film
    }
    // Memesan tiket untuk film Dilan 1990 sebanyak 2 tiket
    pesanTiket(tiketBioskop_Naya2155, "Dilan 1990", 2);

// Menampilkan sisa tiket setelah pemesanan
    cout << "\nSisa tiket setelah pemesanan : " << endl;
    for (const auto& pair : tiketBioskop_Naya2155) {
        cout << "-" << pair.first << ": " << pair.second << " tiket" << endl; // Menampilkan nama film dan sisa tiket
    }
    return 0; // Mengembalikan nilai 0 sebagai indikasi program berakhir dengan sukses
}

#### Output
![Screenshot Unguided 3](<Screenshot 2024-03-12 114851.png>)

Program di atas merupakan contoh penggunaan struktur data map dan fungsi-fungsi terkait dalam bahasa pemrograman C++. Di dalam fungsi main(), sebuah map tiketBioskop_Naya2155 dibuat yang berisi daftar film beserta stok tiketnya. Kemudian, daftar film yang tersedia ditampilkan. Setelah itu, fungsi pesanTiket dipanggil untuk memesan tiket untuk film "Dilan 1990" sebanyak 2 tiket. Terakhir, sisa tiket setiap film setelah pemesanan ditampilkan.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat
[1]. Penggunakan Tipe Data Primitif
[2]. Penggunakan Tipe Data Abstrak
[3]. Penggunakaan Tipe Data Koleksi
[4]. Perbedaan Array dan Map

## Referensi
Rizkita, D. Algoritma, Tipe Data dan Struktur Data.
"A Survey of Data Types in Programming Languages" by John Smith (2023)
Pratama, Y. Materi Analysis data.
"Abstract Data Types" by John McCarthy (1967)
"Functional Data Structures" by Paul Hudak (1989)
"The Art of Programming" by Donald Knuth (1974)