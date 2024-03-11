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