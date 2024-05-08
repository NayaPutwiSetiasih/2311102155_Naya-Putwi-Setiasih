#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseSentence(const string& kal) {
    stack<string> stack_155;
    stringstream r047(kal);
    string kat_155;

    // Memasukkan setiap kat (yang sudah dibalik) ke dalam stack
    while (r047 >> kat_155) {
        reverse(kat_155.begin(), kat_155.end()); // Membalikkan kat
        stack_155.push(kat_155);
    }

    string reversedSentence;
    while (!stack_155.empty()) {
        reversedSentence += stack_155.top();
        stack_155.pop();
        // Tambahkan spasi setelah kat kecuali untuk kat terakhir
        if (!stack_155.empty()) {
            reversedSentence += " ";
        }
    }

    return reversedSentence;
}

int main() {
    string kal_155;
    cout << "Masukkan kalimat: ";
    getline(cin, kal_155);
    string hasil = reverseSentence(kal_155);
    cout << "Kalimat: " << kal_155 << endl;
    cout << "Hasil: " << hasil << endl;
    return 0;
}
