#include <iostream>
using namespace std;

// Node untuk menyimpan data produk
struct Node {
    string namaProduk_Naya2155;
    int harga_Naya2155;
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
        newNode->namaProduk_Naya2155 = namaProduk;
        newNode->harga_Naya2155 = harga;
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
    void insertBetween(string prevNama_Naya2155, string nextNama_Naya2155, string namaProduk_Naya2155, int harga_Naya2155) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk_Naya2155 != prevNama_Naya2155) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << prevNama_Naya2155 << " tidak ditemukan" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk_Naya2155 = namaProduk_Naya2155;
        newNode->harga_Naya2155 = harga_Naya2155;
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
    void deleteNode(string namaProduk_Naya2155) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk_Naya2155 != namaProduk_Naya2155) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << namaProduk_Naya2155 << " tidak ditemukan" << endl;
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
    void updateNode(string namaProduk_Naya2155, string newNama_Naya2155, int newHarga_Naya2155) {
        Node* temp = head;
        while (temp != nullptr && temp->namaProduk_Naya2155 != namaProduk_Naya2155) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan nama " << namaProduk_Naya2155 << " tidak ditemukan" << endl;
            return;
        }

        temp->namaProduk_Naya2155 = newNama_Naya2155;
        temp->harga_Naya2155 = newHarga_Naya2155;
    }

    // Fungsi untuk menampilkan semua data
    void display() {
        Node* temp = head;
        cout << "Nama Produk\tHarga" << endl;
        while (temp != nullptr) {
            cout << temp->namaProduk_Naya2155 << "\t\t" << temp->harga_Naya2155 << endl;
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

    int choice_Naya2155;
    do {
        cout << "Pilihan Anda: ";
        cin >> choice_Naya2155;
        switch (choice_Naya2155) {
            case 1: {
                string namaProduk_Naya2155;
                int harga_Naya2155;
                cout << "Masukkan Nama Produk: ";
                cin.ignore();
                getline(cin, namaProduk_Naya2155);
                cout << "Masukkan Harga: ";
                cin >> harga_Naya2155;
                list.insertBack(namaProduk_Naya2155, harga_Naya2155);
                break;
            }
            case 2: {
                string namaProduk_Naya2155;
                cout << "Masukkan Nama Produk yang Ingin Dihapus: ";
                cin.ignore();
                getline(cin, namaProduk_Naya2155);
                list.deleteNode(namaProduk_Naya2155);
                break;
            }
            case 3: {
                string namaProduk_Naya2155, newNama_Naya2155;
                int harga_Naya2155, newHarga_Naya2155;
                cout << "Masukkan Nama Produk yang Ingin Diupdate: ";
                cin.ignore();
                getline(cin, namaProduk_Naya2155);
                cout << "Masukkan Nama Produk Baru: ";
                getline(cin, newNama_Naya2155);
                cout << "Masukkan Harga Baru: ";
                cin >> newHarga_Naya2155;
                list.updateNode(namaProduk_Naya2155, newNama_Naya2155, newHarga_Naya2155);
                break;
            }
            case 4: {
                string prevNama_Naya2155, nextNama_Naya2155, namaProduk_Naya2155;
                int harga_Naya2155;
                cout << "Masukkan Nama Produk Sebelum: ";
                cin.ignore();
                getline(cin, prevNama_Naya2155);
                cout << "Masukkan Nama Produk Setelah: ";
                getline(cin, nextNama_Naya2155);
                cout << "Masukkan Nama Produk Baru: ";
                getline(cin, namaProduk_Naya2155);
                cout << "Masukkan Harga Baru: ";
                cin >> harga_Naya2155;
                list.insertBetween(prevNama_Naya2155, nextNama_Naya2155, namaProduk_Naya2155, harga_Naya2155);
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
    } while (choice_Naya2155 != 8);
    return 0;
}