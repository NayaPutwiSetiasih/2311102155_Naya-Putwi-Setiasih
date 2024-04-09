#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define Mahasiswa class
class Mahasiswa {
public:
    string nim_155;
    int nilai_155;
    Mahasiswa(string nim_155, int nilai_155) : nim_155(nim_155), nilai_155(nilai_155) {}
};

class HashMap {
private:
    static const int tableSize = 10;
    vector<Mahasiswa*>* table_155[tableSize]; // Vector of pointers to Mahasiswa objects

public:
    HashMap() {
        for (int i = 0; i < tableSize; ++i) {
            table_155[i] = nullptr;
        }
    }

    int hashFunction(string key_155) {
        int hash = 0;
        for (int i = 0; i<key_155.length(); ++i) {
            hash += key_155[i];
        }
        return hash % tableSize;
    }

    void tambahData(string nim_155, int nilai_155) {
        int index = hashFunction(nim_155);
        if (table_155[index] == nullptr) {
            table_155[index] = new vector<Mahasiswa*>; // Initialize vector if null
        }
        table_155[index]->push_back(new Mahasiswa(nim_155, nilai_155)); // Push new Mahasiswa object
    }

    void cariDataDenganNIM(string nim_155) {
        int index = hashFunction(nim_155);
        if (table_155[index] == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        for (auto& mahasiswa : *table_155[index]) {
            if (mahasiswa->nim_155 == nim_155) {
                cout << "NIM: " << mahasiswa->nim_155 << ", Nilai: " << mahasiswa->nilai_155 << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void cariDataDenganNilai(int minimalNilai_155, int maksimalNilai_155) {
        bool temukan = false;
        for (int i = 0; i < tableSize; ++i) {
            if (table_155[i] != nullptr) {
                for (auto& mahasiswa : *table_155[i]) {
                    if (mahasiswa->nilai_155 >= minimalNilai_155 && mahasiswa->nilai_155 <= maksimalNilai_155) {
                        cout << "NIM: " << mahasiswa->nim_155 << ", Nilai: " << mahasiswa->nilai_155 << endl;
                        temukan = true;
                    }
                }
            }
        }
        if (!temukan) {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    void hapusData(string nim_155) {
        int index = hashFunction(nim_155);
        if (table_155[index] == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        for (auto it = table_155[index]->begin(); it != table_155[index]->end(); ++it) {
            if ((*it)->nim_155 == nim_155) {
                delete *it; // Delete object
                table_155[index]->erase(it); // Erase pointer from vector
                cout << "Data berhasil dihapus" << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void tampilkanSemuaData() {
        for (int i = 0; i < tableSize; ++i) {
            if (table_155[i] != nullptr) {
                for (auto& mahasiswa : *table_155[i]) {
                    cout << "NIM: " << mahasiswa->nim_155 << ", Nilai: " << mahasiswa->nilai_155 << endl;
                }
            }
        }
    }
};

int main() {
    HashMap hashMap;
    int choice_155;
    string nim_155;
    int nilai_155, minimalNilai_155, maksimalNilai_155;

    do {
        cout << "\nPROGRAM HASH TABLE DATA MAHASISWA" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Cari Data Mahasiswa berdasarkan NIM" << endl;
        cout << "3. Cari Data Mahasiswa berdasarkan Rentang Nilai" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> choice_155;

        switch (choice_155) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim_155;
                cout << "Masukkan Nilai: ";
                cin >> nilai_155;
                hashMap.tambahData(nim_155, nilai_155);
                break;
            case 2:
                cout << "Masukkan NIM: ";
                cin >> nim_155;
                hashMap.cariDataDenganNIM(nim_155);
                break;
            case 3:
                cout << "Masukkan Rentang Nilai (Minimal Maksimal): ";
                cin >> minimalNilai_155 >> maksimalNilai_155;
                hashMap.cariDataDenganNilai(minimalNilai_155, maksimalNilai_155);
                break;
            case 4:
                cout << "Masukkan NIM: ";
                cin >> nim_155;
                hashMap.hapusData(nim_155);
                break;
            case 5:
                cout << "Semua data mahasiswa:" << endl;
                hashMap.tampilkanSemuaData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (choice_155 != 0);

    return 0;
}
