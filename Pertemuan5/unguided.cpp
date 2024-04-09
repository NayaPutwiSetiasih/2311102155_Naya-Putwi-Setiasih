#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define Mahasiswa class
class Mahasiswa {
public:
    string nim;
    int nilai;
    Mahasiswa(string nim, int nilai) : nim(nim), nilai(nilai) {}
};

class HashMap {
private:
    static const int tableSize = 10;
    vector<Mahasiswa*>* table[tableSize]; // Vector of pointers to Mahasiswa objects

public:
    HashMap() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    int hashFunction(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); ++i) {
            hash += key[i];
        }
        return hash % tableSize;
    }

    void tambahData(string nim, int nilai) {
        int index = hashFunction(nim);
        if (table[index] == nullptr) {
            table[index] = new vector<Mahasiswa*>; // Initialize vector if null
        }
        table[index]->push_back(new Mahasiswa(nim, nilai)); // Push new Mahasiswa object
    }

    void cariDataDenganNIM(string nim) {
        int index = hashFunction(nim);
        if (table[index] == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        for (auto& mahasiswa : *table[index]) {
            if (mahasiswa->nim == nim) {
                cout << "NIM: " << mahasiswa->nim << ", Nilai: " << mahasiswa->nilai << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void cariDataDenganNilai(int minimalNilai, int maksimalNilai) {
        bool temukan = false;
        for (int i = 0; i < tableSize; ++i) {
            if (table[i] != nullptr) {
                for (auto& mahasiswa : *table[i]) {
                    if (mahasiswa->nilai >= minimalNilai && mahasiswa->nilai <= maksimalNilai) {
                        cout << "NIM: " << mahasiswa->nim << ", Nilai: " << mahasiswa->nilai << endl;
                        temukan = true;
                    }
                }
            }
        }
        if (!temukan) {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    void hapusData(string nim) {
        int index = hashFunction(nim);
        if (table[index] == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        for (auto it = table[index]->begin(); it != table[index]->end(); ++it) {
            if ((*it)->nim == nim) {
                delete *it; // Delete object
                table[index]->erase(it); // Erase pointer from vector
                cout << "Data berhasil dihapus" << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void tampilkanSemuaData() {
        for (int i = 0; i < tableSize; ++i) {
            if (table[i] != nullptr) {
                for (auto& mahasiswa : *table[i]) {
                    cout << "NIM: " << mahasiswa->nim << ", Nilai: " << mahasiswa->nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashMap hashMap;
    int choice;
    string nim;
    int nilai, minimalNilai, maksimalNilai;

    do {
        cout << "\nPROGRAM HASH TABLE DATA MAHASISWA" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Cari Data Mahasiswa berdasarkan NIM" << endl;
        cout << "3. Cari Data Mahasiswa berdasarkan Rentang Nilai" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashMap.tambahData(nim, nilai);
                break;
            case 2:
                cout << "Masukkan NIM: ";
                cin >> nim;
                hashMap.cariDataDenganNIM(nim);
                break;
            case 3:
                cout << "Masukkan Rentang Nilai (Minimal Maksimal): ";
                cin >> minimalNilai >> maksimalNilai;
                hashMap.cariDataDenganNilai(minimalNilai, maksimalNilai);
                break;
            case 4:
                cout << "Masukkan NIM: ";
                cin >> nim;
                hashMap.hapusData(nim);
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
    } while (choice != 0);

    return 0;
}
