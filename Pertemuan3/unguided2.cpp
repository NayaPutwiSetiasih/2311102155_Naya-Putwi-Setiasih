#include <iostream>
using namespace std;

// Node untuk menyimpan data produk
struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// Kelas untuk Double Linked List
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Konstruktor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan data di belakang
    void insertBack(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Fungsi untuk menambahkan data di antara dua node tertentu
    void insertBetween(string prevNama, string nextNama, string namaProduk, int harga) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk != prevNama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << prevNama << " tidak ditemukan" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
    }

    // Fungsi untuk menghapus node
    void deleteNode(string namaProduk) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk != namaProduk) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << namaProduk << " tidak ditemukan" << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        delete temp;
    }

    // Fungsi untuk mengupdate data node
    void updateNode(string namaProduk, string newNama, int newHarga) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk != namaProduk) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << namaProduk << " tidak ditemukan" << endl;
            return;
        }

        temp->namaProduk = newNama;
        temp->harga = newHarga;
    }

    // Fungsi untuk menampilkan semua data
    void display() {
        Node* temp = head;
        cout << "Nama Produk\tHarga" << endl;
        while (temp != nullptr) {
            cout << temp->namaProduk << "\t\t" << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Menambahkan data awal
    list.insertBack("Originote", 60000);
    list.insertBack("Somethinc", 150000);
    list.insertBack("Skintific", 100000);
    list.insertBack("Wardah", 50000);
    list.insertBack("Hanasui", 30000);

    // Tampilkan menu
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;

    int choice;
    do {
        cout << "Pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan Nama Produk: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Masukkan Harga: ";
                cin >> harga;
                list.insertBack(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan Nama Produk yang Ingin Dihapus: ";
                cin.ignore();
                getline(cin, namaProduk);
                list.deleteNode(namaProduk);
                break;
            }
            case 3: {
                string namaProduk, newNama;
                int harga, newHarga;
                cout << "Masukkan Nama Produk yang Ingin Diupdate: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Masukkan Nama Produk Baru: ";
                getline(cin, newNama);
                cout << "Masukkan Harga Baru: ";
                cin >> newHarga;
                list.updateNode(namaProduk, newNama, newHarga);
                break;
            }
            case 4: {
                string prevNama, nextNama, namaProduk;
                int harga;
                cout << "Masukkan Nama Produk Sebelum: ";
                cin.ignore();
                getline(cin, prevNama);
                cout << "Masukkan Nama Produk Setelah: ";
                getline(cin, nextNama);
                cout << "Masukkan Nama Produk Baru: ";
                getline(cin, namaProduk);
                cout << "Masukkan Harga Baru: ";
                cin >> harga;
                list.insertBetween(prevNama, nextNama, namaProduk, harga);
                break;
            }
            case 5: {
                // Implementasi penghapusan data urutan tertentu
                break;
            }
            case 6: {
                // Implementasi penghapusan seluruh data
                break;
            }
            case 7: {
                // Menampilkan data
                list.display();
                break;
            }
            case 8: {
                cout << "Terima kasih!" << endl;
                break;
            }
           default: {
                cout << "Tidak valid" << endl;
                break;
            }
        }
    } while (choice != 8);
    return 0;
}