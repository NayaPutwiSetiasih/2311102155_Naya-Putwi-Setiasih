#include <iostream>
using namespace std;

// Node untuk merepresentasikan setiap elemen dalam linked list
struct Node {
    string nama_155; // Nama mahasiswa
    string nim_155;  // NIM mahasiswa
    Node* next;  // Pointer ke node selanjutnya dalam linked list
};

// Struktur Queue menggunakan linked list
class Queue {
private:
    Node* front; // Pointer ke elemen pertama dalam queue
    Node* back;  // Pointer ke elemen terakhir dalam queue
    int size_155;    // Ukuran queue (banyaknya elemen)

public:
    // Konstruktor
    Queue() {
        front = nullptr;
        back = nullptr;
        size_155 = 0;
    }

    // Destruktor
    ~Queue() {
        // Hapus semua elemen dalam queue saat objek dihancurkan
        clear();
    }

    // Method untuk menambahkan elemen ke dalam queue
    void enqueue(const string& nama, const string& nim) {
        // Buat node baru
        Node* newNode = new Node;
        newNode->nama_155 = nama;
        newNode->nim_155 = nim;
        newNode->next = nullptr;

        // Jika queue kosong, node baru menjadi front dan back
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            // Tambahkan node baru ke belakang queue
            back->next = newNode;
            back = newNode;
        }

        // Tambah ukuran queue
        size_155++;
    }

    // Method untuk menghapus elemen dari depan queue
    void dequeue() {
        // Jika queue kosong, tidak ada yang dihapus
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        // Simpan node depan yang akan dihapus
        Node* temp = front;

        // Pindahkan front ke node selanjutnya
        front = front->next;

        // Jika setelah penghapusan queue menjadi kosong, update back menjadi nullptr
        if (front == nullptr) {
            back = nullptr;
        }

        // Hapus node depan
        delete temp;

        // Kurangi ukuran queue
        size_155--;
    }

    // Method untuk memeriksa apakah queue kosong
    bool isEmpty() {
        return size_155 == 0;
    }

    // Method untuk mendapatkan ukuran queue
    int getSize() {
        return size_155;
    }

    // Method untuk menghapus semua elemen dalam queue
    void clear() {
        // Lakukan dequeue sampai queue kosong
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Method untuk menampilkan semua elemen dalam queue
    void display() {
        // Jika queue kosong, tampilkan pesan
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        // Mulai dari elemen pertama (front) dan tampilkan semua elemen
        Node* current = front;
        cout << "Data antrian mahasiswa:" << endl;
        while (current != nullptr) {
            cout << "Nama: " << current->nama_155 << ", NIM: " << current->nim_155 << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;

    // Tambahkan elemen ke dalam queue
    queue.enqueue("Naya", "2311102155");
    queue.enqueue("Amanda", "2311102121");

    // Tampilkan semua elemen dalam queue
    queue.display();

    // Tampilkan jumlah elemen dalam queue
    cout << "Jumlah antrian = " << queue.getSize() << endl;

    // Hapus elemen pertama dari queue
    queue.dequeue();

    // Tampilkan semua elemen dalam queue setelah penghapusan
    queue.display();

    // Tampilkan jumlah elemen dalam queue setelah penghapusan
    cout << "Jumlah antrian = " << queue.getSize() << endl;

    // Hapus semua elemen dalam queue
    queue.clear();

    // Tampilkan semua elemen dalam queue setelah penghapusan
    queue.display();

    // Tampilkan jumlah elemen dalam queue setelah penghapusan
    cout << "Jumlah antrian = " << queue.getSize() << endl;

    return 0;
}
