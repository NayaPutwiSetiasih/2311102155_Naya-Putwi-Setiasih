# <h1 align="center">Laporan Praktikum Modul 8 Algoritma Searching</h1>
<p align="center">Naya Putwi Setiasih_2311102155</p>

## Dasar Teori
- Sequential Search
Sequential Search merupakan salah satu algoritma pencarian data yang biasa
digunakan untuk data yang berpola acak atau belum terurut. Sequential search juga
merupakan teknik pencarian data dari array yang paling mudah, dimana data dalam
array dibaca satu demi satu dan diurutkan dari index terkecil ke index terbesar, maupun
sebaliknya.
- Binary Search
BinarySearch adalah  cara  untuk pencarian  data  pada  array  yang  sudah terurut.  karena  salah  satu  syarat  dalam BinarySearchadalah data sudah dalam keadaan    terurut.    dengan    kata    lain apabila   data   belum   dalam   keadaan terurut,  pencarian Binarytidak  dapat dilakukan. BinarySearchini dilakukan untuk [10] :
a. Memperkecil jumlah operasi perbandingan yang harus dilakukan antara data yang dicari dengan data yang ada didalam tabel, khususnya untuk   jumlah   data   yang   sangat besar ukurannya.
b. Beban komputasi lebih kecil karena pencarian   dilakukan   dari   depan, belakang dan tengah.
c. Prinsip dasarnya adalah melakukan proses  pembagian  ruang  pencarian secara  berulang-ulang  sampai  data ditemukan  atau  sampai  pencarian tidak   dapat   dibagi   lagi   (berarti terdapatkemungkinandata  tidak dtiemukan).


## Guided 

### 1. [Sequential Search]

```C++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk ukuran array
    int n = 10;

    // Inisialisasi array dengan 10 elemen
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};

    // Angka yang akan dicari dalam array
    int cari = 10;

    // Variabel boolean untuk menandai apakah angka ditemukan
    bool ketemu = false;

    // Variabel indeks
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        // Jika elemen array sama dengan angka yang dicari
        if (data[i] == cari) {
            // Tandai bahwa angka ditemukan
            ketemu = true;
            // Keluar dari loop
            break;
        }
    }

    // Output informasi tentang program
    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Cek apakah angka ditemukan
    if (ketemu) {
        // Jika ditemukan, tampilkan indeks di mana angka ditemukan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        // Jika tidak ditemukan, tampilkan pesan bahwa angka tidak ditemukan
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```
Program di atas adalah implementasi sederhana dari algoritma pencarian berurutan (sequential search) dalam bahasa C++. Tujuan dari program ini adalah untuk mencari sebuah angka dalam sebuah array dan menginformasikan apakah angka tersebut ditemukan serta di indeks ke berapa. Program dimulai dengan mendeklarasikan ukuran array (n) sebesar 10 dan menginisialisasi array data dengan 10 elemen. Angka yang akan dicari, yaitu 10, disimpan dalam variabel cari.

Program menggunakan variabel boolean ketemu untuk menandai apakah angka tersebut ditemukan dalam array, dan variabel i sebagai indeks dalam loop. Dalam loop for, setiap elemen array diperiksa satu per satu. Jika elemen yang diperiksa sama dengan angka yang dicari, variabel ketemu diatur menjadi true dan loop dihentikan menggunakan perintah break.

Setelah loop selesai, program menampilkan informasi tentang array yang digunakan dan hasil pencarian. Jika angka ditemukan (ketemu bernilai true), program akan mencetak pesan yang menunjukkan indeks di mana angka ditemukan. Jika tidak ditemukan, program akan menampilkan pesan bahwa angka tersebut tidak ditemukan dalam data. Program ini diakhiri dengan return 0, yang menandakan bahwa program telah berjalan dengan sukses.

### 2. [Binary Searching]
```C++
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
```
Program di atas adalah implementasi algoritma pencarian biner (binary search) dalam bahasa C++. Program ini dimulai dengan mendeklarasikan sebuah array dataArray yang berisi tujuh elemen integer yang akan diurutkan dan dicari. Pengguna diminta untuk memasukkan nilai yang ingin dicari, yang disimpan dalam variabel cari.

Langkah pertama dalam program ini adalah mengurutkan array menggunakan algoritma Selection Sort. Fungsi selection_sort() mengurutkan array dengan cara mencari elemen terkecil dari sisa array dan menukarnya dengan elemen saat ini, berulang kali hingga seluruh array terurut. Setelah array diurutkan, program menampilkan array yang sudah terurut.

Setelah pengurutan, program melakukan pencarian biner menggunakan fungsi binarysearch(). Pencarian biner dilakukan dengan membagi array yang sudah diurutkan menjadi dua bagian dan memeriksa elemen tengah. Jika elemen tengah adalah nilai yang dicari, pencarian selesai. Jika tidak, pencarian dilanjutkan pada separuh array yang sesuai (bagian kiri jika nilai yang dicari lebih kecil, dan bagian kanan jika lebih besar). Variabel boolean b_flag digunakan untuk menandai apakah nilai ditemukan atau tidak.

Program menampilkan hasil pencarian biner, yaitu indeks di mana nilai ditemukan atau pesan bahwa nilai tidak ditemukan. Program ditutup dengan _getche(), yang menunggu input dari pengguna sebelum mengakhiri eksekusi, memungkinkan pengguna untuk melihat hasil pencarian sebelum program ditutup.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
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
```
#### Output:
![alt text](<Screenshot 2024-05-20 210320.png>)

Program di atas mengimplementasikan algoritma Bubble Sort dan Binary Search dalam bahasa C++. Program dimulai dengan mengimpor header iostream untuk input-output dan menggunakan namespace std. Fungsi bubbleSort mengurutkan elemen dalam array karakter menggunakan Bubble Sort, sedangkan fungsi binarySearch mencari karakter tertentu dalam array yang sudah diurutkan.

Dalam fungsi main, program mendeklarasikan array karakter untuk menyimpan kalimat input dari pengguna dan karakter yang akan dicari. Setelah pengguna memasukkan kalimat dan huruf, panjang kalimat dihitung, lalu diurutkan menggunakan bubbleSort. Program kemudian mencari huruf yang diinput menggunakan binarySearch.

Hasil pencarian ditampilkan: jika huruf ditemukan, program mencetak pesan bahwa huruf tersebut ditemukan, jika tidak, mencetak pesan bahwa huruf tidak ditemukan. Program diakhiri dengan mengembalikan nilai 0, menandakan program selesai berjalan dengan sukses.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]
```C++
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
```
#### Output :
![alt text](<Screenshot 2024-05-20 210953.png>)

Program di atas adalah implementasi dalam bahasa C++ yang menghitung jumlah huruf vokal dalam sebuah kalimat yang diinput oleh pengguna. Program dimulai dengan mengimpor header file iostream untuk menangani input dan output, dan menggunakan namespace std agar tidak perlu menulis std:: secara berulang.

Fungsi hitungVokal bertugas menghitung jumlah huruf vokal dalam sebuah array karakter (str). Fungsi ini menginisialisasi variabel jumlahVokal_155 untuk menyimpan jumlah vokal yang ditemukan, dan menggunakan loop untuk iterasi melalui setiap karakter dalam kalimat hingga mencapai karakter null ('\0') yang menandakan akhir kalimat. Setiap karakter diperiksa apakah termasuk huruf vokal (baik huruf kecil maupun huruf besar). Jika ya, maka jumlahVokal_155` ditambahkan satu.

Dalam fungsi main, program mendeklarasikan sebuah array karakter kalimat_155 dengan panjang maksimum 100 untuk menyimpan kalimat yang diinput oleh pengguna. Pengguna diminta memasukkan kalimat melalui cin.getline. Kalimat yang diinput kemudian diproses oleh fungsi hitungVokal, yang menghitung dan mengembalikan jumlah huruf vokal dalam kalimat tersebut.

Hasil perhitungan jumlah huruf vokal kemudian ditampilkan ke layar menggunakan cout. Program diakhiri dengan return 0, yang menandakan bahwa program telah selesai berjalan dengan sukses.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]
```C++
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
```
#### Output :
![alt text](<Screenshot 2024-05-20 211422.png>)

Program di atas merupakan implementasi dalam bahasa C++ yang menghitung jumlah kemunculan angka 4 dalam sebuah array menggunakan Sequential Search. Program dimulai dengan mengimpor header file iostream untuk menangani input dan output, dan menggunakan namespace std agar tidak perlu menulis std:: secara berulang.

Fungsi hitungEmpat bertugas menghitung jumlah kemunculan angka 4 dalam sebuah array integer (arr). Fungsi ini menggunakan loop for untuk mengiterasi melalui setiap elemen array dan memeriksa apakah elemen tersebut sama dengan angka yang dicari (dalam kasus ini, angka 4). Jika ditemukan, variabel count yang merepresentasikan jumlah angka 4 akan bertambah satu.

Dalam fungsi main, program mendeklarasikan sebuah array integer data_155 yang berisi data, panjang array length_155 dihitung menggunakan formula sizeof(data_155) / sizeof(data_155[0]), dan angka yang dicari target_155 diinisialisasi dengan nilai 4.

Selanjutnya, program memanggil fungsi hitungEmpat untuk menghitung jumlah kemunculan angka 4 dalam array data_155. Hasil perhitungan tersebut kemudian ditampilkan ke layar menggunakan cout. Program diakhiri dengan return 0, yang menandakan bahwa program telah selesai berjalan dengan sukses.

## Kesimpulan
Dari implementasi searching menggunakan Binary Search dan Sequential Search dalam bahasa C++ tersebut, dapat disimpulkan beberapa hal:
1. Kita dapat menggunakan algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat yang sudah diinput. Algoritma ini efisien karena membagi kalimat menjadi dua bagian setiap kali melakukan pencarian, mengurangi jumlah langkah yang diperlukan untuk menemukan huruf yang dicari.
2. Untuk menghitung banyaknya huruf vokal dalam sebuah kalimat, kita perlu membuat program yang dapat mengidentifikasi huruf vokal dalam kalimat tersebut dan menghitung jumlahnya. Dalam implementasi programnya, kita bisa menggunakan pendekatan yang sederhana dengan melakukan iterasi melalui setiap karakter dalam kalimat dan memeriksa apakah karakter tersebut termasuk huruf vokal.
3. Algoritma Sequential Search dapat digunakan untuk menghitung berapa kali angka 4 muncul dalam sebuah data yang telah diberikan. Dalam implementasi programnya, kita perlu melakukan iterasi melalui setiap elemen dalam data dan menghitung berapa kali angka 4 ditemukan.

## Referensi
[1] Religia, Y. (2019). Analisis Algoritma Sequential Search Dan Binary Search Pada Big Data: Analysis Of Sequential Search And Binary Search Algorithm In Big Data. Pelita Teknologi, 14(1), 74-79.