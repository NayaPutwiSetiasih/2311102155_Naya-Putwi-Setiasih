#include <iostream>
#include <stack>
#include <cctype> // Library untuk menggunakan isalnum() function

using namespace std;

// Fungsi untuk membersihkan kalimat dari karakter non-alphanumeric dan mengubah huruf menjadi lowercase
string cleanString(const string& str) {
    string cleanedStr_155;
    for (char ch : str) {
        if (isalnum(ch)) { // Memeriksa apakah karakter merupakan alphanumeric
            cleanedStr_155 += tolower(ch); // Mengubah huruf menjadi lowercase
        }
    }
    return cleanedStr_155;
}

// Fungsi untuk menentukan apakah kalimat merupakan palindrom atau tidak
bool isPalindrome(const string& str) {
    stack<char> charStack_155;
    string cleanedStr_155 = cleanString(str); // Membersihkan kalimat
    int length = cleanedStr_155.length();
    int mid = length / 2;

    // Push setengah pertama karakter ke dalam stack
    for (int i = 0; i < mid; ++i) {
        charStack_155.push(cleanedStr_155[i]);
    }

    // Jika panjang kalimat ganjil, lewati karakter di tengah
    if (length % 2 != 0) {
        ++mid;
    }

    // Mulai membandingkan setengah kedua karakter dengan karakter dalam stack
    for (int i = mid; i < length; ++i) {
        if (cleanedStr_155[i] != charStack_155.top()) {
            return false; // Jika tidak cocok, kalimat bukan palindrom
        }
        charStack_155.pop();
    }
    return true; // Jika semua karakter cocok, kalimat adalah palindrom
}
int main() {
    string kalimat_155;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_155);

    if (isPalindrome(kalimat_155)) {
        cout << "Kalimat merupakan palindrom." << endl;
    } else {
        cout << "Kalimat bukan palindrom." << endl;
    }

    return 0;
}
