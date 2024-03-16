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
