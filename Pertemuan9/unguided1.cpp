#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n_155;

    // Meminta input jumlah simpul (kota)
    cout << "Silakan masukan jumlah simpul : ";
    cin >> n_155;

    vector<string> kota(n_155);

    // Meminta input nama-nama simpul
    for(int i = 0; i < n_155; ++i) {
        cout << "Silakan masukan nama simpul\n";
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i];
    }

    vector<vector<int>> jarak(n_155, vector<int>(n_155));

    // Meminta input bobot (jarak) antar simpul termasuk dirinya sendiri
    for(int i = 0; i < n_155; ++i) {
        for(int j = 0; j < n_155; ++j) {
            cout << kota[i] << "--->" << kota[j] << " = ";
            cin >> jarak[i][j];
        }
    }

    // Menampilkan matriks jarak dengan header yang dirapikan
    cout << "\n\t";
    for(int i = 0; i < n_155; ++i) {
        cout << kota[i] << "\t";
    }
    cout << "\n";

    for(int i = 0; i < n_155; ++i) {
        cout << kota[i] << "\t";
        for(int j = 0; j < n_155; ++j) {
            cout << jarak[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
