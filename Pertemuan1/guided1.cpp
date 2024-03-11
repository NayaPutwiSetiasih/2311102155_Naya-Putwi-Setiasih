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