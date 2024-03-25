#include <iostream>
using namespace std;

// Node untuk menyimpan data mahasiswa
struct Node {
    string nama_Naya2155;
    int usia_Naya2155;
    Node* next;
};

// Kelas untuk Single Linked List
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menyisipkan node di depan
    void insertFront(string nama_Naya2155, int usia_Naya2155) {
        Node* newNode = new Node;
        newNode->nama_Naya2155 = nama_Naya2155;
        newNode->usia_Naya2155 = usia_Naya2155;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menyisipkan node di belakang
    void insertBack(string nama_Naya2155, int usia_Naya2155) {
        Node* newNode = new Node;
        newNode->nama_Naya2155 = nama_Naya2155;
        newNode->usia_Naya2155 = usia_Naya2155;
        newNode->next = nullptr;

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

    // Fungsi untuk menyisipkan node setelah node tertentu
    void insertAfter(string key, string nama_Naya2155, int usia_Naya2155) {
        Node* temp = head;
        while (temp != nullptr && temp->nama_Naya2155 != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan kunci " << key << " tidak ditemukan" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->nama_Naya2155 = nama_Naya2155;
        newNode->usia_Naya2155 = usia_Naya2155;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menghapus node
    void removeNode(string key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->nama_Naya2155 == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->nama_Naya2155 != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan kunci " << key << " tidak ditemukan" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah data node
    void updateNode(string key, string newNama, int newUsia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama_Naya2155 != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node dengan kunci " << key << " tidak ditemukan" << endl;
            return;
        }

        temp->nama_Naya2155 = newNama;
        temp->usia_Naya2155 = newUsia;
    }

    // Fungsi untuk menampilkan semua data
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama_Naya2155 << " " << temp->usia_Naya2155 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // Menambahkan data sesuai urutan
    list.insertFront("John", 19);
    list.insertBack("Jane", 20);
    list.insertBack("Michael", 18);
    list.insertBack("Yusuke", 19);
    list.insertBack("Akechi", 20);
    list.insertBack("Hoshino", 18);
    list.insertBack("Karin", 18);

    // Hapus data Akechi
    list.removeNode("Akechi");

    // Tambahkan data Futaba di antara John dan Jane
    list.insertAfter("John", "Futaba", 18);

    // Tambahkan data Igor di awal
    list.insertFront("Igor", 20);

    // Ubah data Michael menjadi Reyn
    list.updateNode("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    list.display();

    return 0;
}
