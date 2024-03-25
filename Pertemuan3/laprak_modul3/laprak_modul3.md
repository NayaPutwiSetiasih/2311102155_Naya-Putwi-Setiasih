# <h3 align="center">Laporan Praktikum Modul Tipe Data</h3>
<p align="center">Naya Putwi Setiasih_2311102155</p>

## Dasar Teori

1. Single Linked List
single linked list adalah suatu simpul (node) yang dikaitkan dengan simpul yang lain dalam suatu urutan tertentu. Suatu simpul dapat berbentuk suatu struktur atau class. Simpul harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Setiap node akan berbentuk struct dan memiliki satu buah field bertipe struct yang sama, yang berfungsi sebagai pointer. Yang berbeda dengan deklarasi struct sebelumnya adalah satu field bernama next, yang bertipe struct tnode. Operasi-operasi Linked List
 Insert
Istilah Insert berarti menambahkan sebuah simpul baru ke dalam suatu linked list.
 IsEmpty
Fungsi ini menentukan apakah linked list kosong atau tidak.
 Find First
Fungsi ini mencari elemen pertama dari linked list.
 Find Next
Fungsi ini mencari elemen sesudah elemen yang ditunjuk now.
 Retrieve
Fungsi ini mengambil elemen yang ditunjuk oleh now. Elemen tersebut lalu dikembalikan oleh fungsi.
 Update
Fungsi ini mengubah elemen yang ditunjuk oleh now dengan isi dari sesuatu.
 Delete Now
Fungsi ini menghapus elemen yang ditunjuk oleh now. Jika yang dihapus adalah elemen pertama dari linked list (head), head akan berpindah ke elemen berikutnya.
 Delete Head
Fungsi ini menghapus elemen yang ditunjuk head. Head berpindah ke elemen sesudahnya.
 Clear
Fungsi ini menghapus linked list yang sudah ada. Fungsi ini wajib dilakukan bila anda ingin mengakhiri program yang menggunakan linked list. Jika anda melakukannya, data-data yang dialokasikan ke memori pada program sebelumnya akan tetap tertinggal di dalam memori.

2. Double Linked List
Double Linked List adalah struktur data linear yang terdiri dari sejumlah simpul (node) yang saling terhubung secara berurutan. Setiap node memiliki dua pointer, yaitu pointer ke node sebelumnya (prev) dan pointer ke node selanjutnya (next). Keberadaan pointer prev memungkinkan traversing data maju (dari depan ke belakang) dan mundur (dari belakang ke depan), sehingga memberikan fleksibilitas yang lebih besar dibandingkan dengan Single Linked List.

## Guided 

### 1. [Single Linked List]

```C++
#include <iostream>
using namespace std;
///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
    Node *baru, *bantu;
    baru = new Node();
    baru->data = data;
    // tranversing
        bantu = head;
        int nomor = 1;
    while( nomor < posisi - 1 ){
        bantu = bantu->next;
        nomor++;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program diatas mengimplementasikan single linked list non circular dalam bahasa c++. struktur data Node terdiri dari dua bagian yaitu data int dan pointer next (Node*). membuat head dan tail menjadi null, menandakan bahwa linked list masih kosong. kemudian menambahkan node baru di depan linked list dan menambahkan node baru di belakang linked list. menghitungjumlah node dalam linked list. menambahkan node baru diposisi tertentu dalam linked list. menghapus node pertama dalam linked list dan menghapus node terakhir dalam linked list. dan juga menghapus node pada posisi tertentu. kemudian, mengubah data node pertama, mengubag data node tertentu dalam linked list, dan mengubah data node terakhir. menghapus seluruh node dalam linked list dan mengososngkan head dan tail. kemudian menampilkan seluruh data yang ada dalam linked list. 

### 2. [Double Linked List]
```c++
#include <iostream>
using namespace std;
class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
        tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program diatas mengimplementasikan Doubly Linked List dalam bahasa C++. Mendefinisikan struktur data Node ada tiga bagian yaitu int, pointer prev, dan pointer next. Mendefinisikan kelas untuk Doubly Linked List yaitu head dan tail. Push metode untuk menambahkan node baru ke depan. Pop metode untuk menghapus node dari depan. Update untuk memperbarui nilai data pada node dengan nilai tertentu. DeleteAll untuk menghapus seluruh node. Display untuk menampilkan isi dari Linked List. 

## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda. [Nama_anda] [Usia_anda]
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18
b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data]

```C++
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
```
#### Output:
![Screenshot Unguided 1](<Screenshot 2024-03-25 080624.png>)

Program diatas mengimplementasikan sebuah single linked list. struktur data node nama(string), usia(int), dan pointer next. kelas untuk single linked list ada head yang menunjukkan ke node pertama. menginisialisasi head dengan nullptr. kemudia, insert front untuk menyisipkan node di depan dan insert back untuk menyisipkan node di belakang begitu juga insert after menyisipkan node setelah node tertentu. remove node untuk menghapus node dengan nama tertentu. update node mengubah data (nama dan usia) pada node dengan nama tertentu. Display menampilkan seluruh data pada linked list. Kemudian main melakukan operasi - operasi pada linked list seperti penambahan, penghapusan, penyisipan, pengubahan data, dan penampilan data.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000
Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Azarine 65.000
Skintific 100.000
Cleora 55.000]
```C++
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
```
#### Output :
![Screenshot Unguided 2](<Screenshot 2024-03-25 094046.png>)

Program diatas mengimplementasikan sebuah Doubly Linked List. Struktur data node memiliki namaProduk(string), harga(int), serta pointer prev dan next untuk menunjukkan kode sebelumnya dan sesudahnya. kelas Doubly Linked List untuk head dan tail yang menunjukkan node pertama dan terakhir. kemudian, mengimplementasikan head dan tail dengan nullptr. insertback untuk menyisipkan node dibelakang dan insertbetween untuk menyisipkan node diantara dua node tertentu. deletenode untuk menghapus node berdasarkan nama produk. updatenode untuk menghapus data pada node tertentu. display untuk menampilkan seluruh data pada linked list. fungsi main untuk melakukan operasi - operasi pada linked list seperti penambahan, penghapusan, penyisipan, pengubahan data, dan penampilan data sesuai dengan pilihan pengguna yang diinputkan melalui menu.
## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. mengimplementasikan struktur data linked list dengan menggunakan single linked list atau doubly linked list. [2] dapat melakukan operasi dasar pada linked list seperti penambahan data di depan, di belakang, di antara dua node tertentu, penghapusan data, pengubahan data, serta penampilan seluruh data. [3] menggunakan konsep pointer untuk mengaitkan node-node dalam linked list, yang memungkinkan penambahan, penghapusan, dan pengubahan data dengan efisien.

## Referensi
[1] Monteiro, F. R., Gadelha, M. R., & Cordeiro, L. C. (2022). Model checking C++ programs. Software Testing, Verification and Reliability, 32(1), e1793.
[2] Weiss, M. A. (2013). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson. [Buku ini memberikan penjelasan yang jelas tentang struktur data dan algoritma menggunakan C++. Bab tentang Double Linked List membantu pembaca memahami konsep dan implementasi praktisnya.]