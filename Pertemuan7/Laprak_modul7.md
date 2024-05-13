# <h1 align="center">Laporan Praktikum Modul 7 Queue</h1>
<p align="center">Naya Putwi Setiasih_2311102155</p>

## Dasar Teori

Queue/antrian adalah ordered list dengan penyisipan di satu ujung, sedang penghapusan di ujung lain. Ujung penyisipan biasa disebutrear/tail, sedang ujung penghapusa disebut front/head. Fenomena yang muncul adalah elemen yang lebih dulu disisipkan akan juga lebih dulu diambil. Queue berdisiplin FIFO (First In, First Out). Queue merupakan kasus khusus ordered list. Dengan karakteristik terbatas itu maka kita dapat melakukan optimasi representasi ADT Queue untuk memperoleh kerja paling optimal. 
Operasi - operasi dasar dari sebuah queue adalah :
1. Enqueue : proses penambahan atau memasukkan satu elemen si belakang.
2. Dequeue : proses pengambilan atau mengeluarkan satu elemen di posisi depan.
Proses penyimpanan queue dalam linked list mirip dengan operasi single linked list yang menggunakan penyisipan di akhir atau belakang dan penghapusan diawal atau depan
fungsi kosong berguna untuk memeriksa apakah suatu queue dalam keadaan kosong. fungsi ini berguna ketika proses dequeue yaitu ketika sebuah elemen akan diambil, maka harus diperiksa dahulu apakah memiliki data atau tidak. fungsi ini akan mempunyai nilai benar jika front atau rear bernilai nil.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Kode tersebut merupakan implementasi sederhana dari struktur data antrian (queue) menggunakan array dalam bahasa C++. Dalam kode tersebut, terdapat variabel global seperti maksimalQueue, front, back, dan array queueTeller yang digunakan untuk menyimpan elemen-elemen dalam antrian. Ada beberapa fungsi yang digunakan dalam pengelolaan antrian. Fungsi isFull() dan isEmpty() digunakan untuk memeriksa apakah antrian sudah penuh atau kosong. Fungsi enqueueAntrian() menambahkan elemen ke dalam antrian. Jika antrian penuh, pesan "Antrian penuh" ditampilkan. Jika antrian kosong, elemen baru ditambahkan di indeks pertama, sedangkan jika tidak kosong, ditambahkan di indeks terakhir. Fungsi dequeueAntrian() menghapus elemen pertama dari antrian. Jika antrian kosong, pesan "Antrian kosong" ditampilkan, jika tidak, semua elemen antrian digeser ke depan satu indeks. Fungsi countQueue() menghitung jumlah elemen dalam antrian, sementara clearQueue() mengosongkan seluruh antrian dengan mengatur front dan back menjadi 0. Fungsi viewQueue() menampilkan semua elemen dalam antrian beserta nomor antriannya, dan jika suatu elemen kosong, ditampilkan "(kosong)". Dalam main(), dilakukan beberapa operasi seperti menambahkan elemen ke dalam antrian, menampilkan antrian dan jumlah elemennya, menghapus elemen pertama dari antrian, mengosongkan antrian, dan menampilkan antrian serta jumlah elemennya kembali.

## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadilinked list]

```C++
#include <iostream>
using namespace std;

// Node untuk merepresentasikan setiap elemen dalam linked list
struct Node {
    string data_155; // Data yang disimpan dalam node
    Node* next; // Pointer ke node selanjutnya dalam linked list
};

// Struktur Queue menggunakan linked list
class Queue {
private:
    Node* front; // Pointer ke elemen pertama dalam queue
    Node* back; // Pointer ke elemen terakhir dalam queue
    int size_155; // Ukuran queue (banyaknya elemen)

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
    void enqueue(const string& data) {
        // Buat node baru
        Node* newNode = new Node;
        newNode->data_155 = data;
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

    // Method untuk mendapatkan elemen di depan queue
    string peek() {
        // Jika queue kosong, kembalikan string kosong
        if (isEmpty()) {
            return "";
        }

        // Kembalikan data dari node depan
        return front->data_155;
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
        cout << "Data antrian teller:" << endl;
        while (current != nullptr) {
            cout << current->data_155 << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue queue;

    // Tambahkan elemen ke dalam queue
    queue.enqueue("Andi");
    queue.enqueue("Maya");

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
```
#### Output:
![alt text](<Screenshot 2024-05-14 042942.png>)

Program di atas mengimplementasikan struktur data antrian (queue) menggunakan linked list dalam bahasa C++. Antrian tersebut memungkinkan penambahan elemen baru ke bagian belakang dan penghapusan elemen dari bagian depan, mengikuti prinsip FIFO (First In First Out). Dengan menggunakan dua pointer, yaitu front dan back, kelas Queue mengatur elemen-elemen dalam antrian. Setiap elemen direpresentasikan oleh sebuah node dalam linked list yang menyimpan nilai data dan pointer ke node selanjutnya. Berbagai method seperti enqueue(), dequeue(), peek(), isEmpty(), getSize(), clear(), dan display() memungkinkan manipulasi dan akses data dalam antrian. Dalam fungsi main(), program menunjukkan cara penggunaan kelas Queue dengan membuat objek antrian, menambahkan dan menghapus elemen, serta menampilkan status antrian pada setiap langkah operasi. Ini memberikan gambaran tentang implementasi struktur data antrian menggunakan linked list dalam C++.

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIMMahasiswa]
```C++


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Adlaimi, N. (2019). STRUKTUR DATA MAJEMUK (QUEUE).
[2] Dharmayanti, D. (2011). Queue.