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
