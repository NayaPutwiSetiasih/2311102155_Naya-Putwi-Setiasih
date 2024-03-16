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
