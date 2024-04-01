#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama_Naya155;
    string nim_Naya155;
    Node* next;

    Node(string nama_Naya155, string nim_Naya155) {
        this->nama_Naya155 = nama_Naya155;
        this->nim_Naya155 = nim_Naya155;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama_Naya155, string nim_Naya155) {
        Node* newNode = new Node(nama_Naya155, nim_Naya155);
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama_Naya155, string nim_Naya155) {
        Node* newNode = new Node(nama_Naya155, nim_Naya155);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void tambahTengah(string nama_Naya155, string nim_Naya155, int posisi_Naya155) {
        if (posisi_Naya155 < 1) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        Node* newNode = new Node(nama_Naya155, nim_Naya155);
        if (posisi_Naya155 == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < posisi_Naya155 - 1; i++) {
            if (temp == nullptr) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data di depan telah dihapus." << endl;
    }

    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Data terakhir telah dihapus." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Data terakhir telah dihapus." << endl;
    }

    void hapusTengah(int posisi_Naya155) {
        if (posisi_Naya155 < 1) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        if (posisi_Naya155 == 1) {
            hapusDepan();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < posisi_Naya155 - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Data pada posisi " << posisi_Naya155 << " telah dihapus." << endl;
    }
    void ubahDepan(string namaBaru, string nimBaru) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        head->nama_Naya155 = namaBaru;
        head->nim_Naya155 = nimBaru;
        static bool pesanDitampilkan = false;
        if (!pesanDitampilkan) {
            cout << "Data di depan telah diubah." << endl;
            pesanDitampilkan = true;
        }
    }
    void ubahBelakang(string namaBaru, string nimBaru) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->nama_Naya155 = namaBaru;
        temp->nim_Naya155 = nimBaru;
        static bool pesanDitampilkan = false;
        if (!pesanDitampilkan) {
            cout << "Data terakhir telah diubah." << endl;
            pesanDitampilkan = true;
        }
    }
    void ubahTengah(string namaBaru, string nimBaru, int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < posisi; i++) {
            if (temp == nullptr) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
            temp = temp->next;
        }
        string namaLama = temp->nama_Naya155;
        temp->nama_Naya155 = namaBaru;
        temp->nim_Naya155 = nimBaru;
        cout << "Data (" << namaLama << ") telah diubah menjadi (" << namaBaru << ")." << endl;
    }

    void hapusList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        cout << "Seluruh data telah dihapus." << endl;
    }

    void tampilkan() {
        Node* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (temp != nullptr) {
            cout << temp->nama_Naya155 << "\t" << temp->nim_Naya155 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    while (true) {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        int pilih;
        cout << endl;
        cout << "Pilih Operasi: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) {
            string nama_Naya155, nim_Naya155;
            cout << "Tambah depan\n";
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, nama_Naya155);
            cout << "Masukkan NIM: ";
            cin >> nim_Naya155;
            linkedList.tambahDepan(nama_Naya155, nim_Naya155);
            cout << "Data telah ditambahkan" << endl;
        }
        else if (pilih == 2) {
            string nama_Naya155, nim_Naya155;

            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, nama_Naya155);
            cout << "Masukkan NIM: ";
            cin >> nim_Naya155;
            linkedList.tambahBelakang(nama_Naya155, nim_Naya155);
            cout << "Data telah ditambahkan" << endl;
        }
        else if (pilih == 3) {
            string nama_Naya155, nim_Naya155;
            int posisi_naya155;
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama: ";
            getline(cin, nama_Naya155);
            cout << "Masukkan NIM: ";
            cin >> nim_Naya155;
            cout << "Masukkan Posisi: ";
            cin >> posisi_naya155;
            linkedList.tambahTengah(nama_Naya155, nim_Naya155, posisi_naya155);
            cout << "Data telah ditambahkan" << endl;
        }
        else if (pilih == 4) {
            string namaBaru, nimBaru;
            cout << "Ubah Depan\n";
            cout << endl;
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nimBaru;
            cout << endl;
            linkedList.ubahDepan(namaBaru, nimBaru);
        }
        else if (pilih == 5) {
            string namaBaru, nimBaru;
            cout << "Ubah Belakang\n";
            cout << endl;
            cin.ignore(); // Menggunakan cin.ignore() agar getline()  bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nimBaru;
            cout << endl;
            linkedList.ubahBelakang(namaBaru, nimBaru);
        }
        else if (pilih == 6) {
            string namaBaru, nimBaru;
            cout << "Ubah Tengah\n";
            cout << endl;
            int posisi;
            cin.ignore(); // Menggunakan cin.ignore() agar getline() bekerja dengan benar setelah cin
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> nimBaru;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            linkedList.ubahTengah(namaBaru, nimBaru, posisi);
        }
        else if (pilih == 7) {
            linkedList.hapusDepan();
        }
        else if (pilih == 8) {
            linkedList.hapusBelakang();
        }
        else if (pilih == 9) {
            int posisi_Naya155;
            cout << "Masukkan Posisi: ";
            cin >> posisi_Naya155;
            linkedList.hapusTengah(posisi_Naya155);
        }
        else if (pilih == 10) {
            linkedList.hapusList();
        }
        else if (pilih == 11) {
            cout << "Tampilkan List\n";
            cout << endl;
            linkedList.tampilkan();
        }
        else if (pilih == 0) {
            cout << "Program selesai." << endl;
            break;
        }
        else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
