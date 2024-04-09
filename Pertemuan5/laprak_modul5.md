# <h1 align="center">Laporan Praktikum Modul Hah Table</h1>
<p align="center">Naya Putwi Setiasih_2311102155</p>

## Dasar Teori

1. Pengertian Hash table
Hashing adalah struktur data untuk mencari elemen dari koleksi dengan tujuan utama mencapai kompleksitas waktu yang konstan. Dengan menggunakan fungsi hash (key) untuk menghasilkan alamat atau nilai hash dari suatu elemen dalam tabel hash. Tabel hash adalah kumpulan slot di memori yang ditentukan untuk menyimpan sekumpulan kunci. Nilai hash dapat dihasilkan oleh fungsi hash apapun dan selanjutnya, nilai terkompresi dihasilkan untuk memetakan kunci input. Hash table biasanya terdiri dari dua komponenutama:
array (atau vector) dan fungsi hash.
Kunci, slot, dan fungsi hash merupakan tabel hash.
-  Kunci dapat berisi semua jenis data.
-  Slot, juga dikenal sebagai bucket, adalah unit yang digunakan oleh tabel hash untuk menyimpan data, yaitu wadah tempat data sebenarnya disimpan. Ini pada dasarnya adalah indeks dalam array yang menyimpan nilai yang terkait dengan kunci.
-   Fungsi hash memetakan kunci ke lokasi slot dimana data harus disimpan. Ini memainkan peran penting dalam menghubungkan nilai-nilai ke setiap kunci. Fungsi hash dinyatakan sebagai: addr = h(key), dimana addr mewakili lokasi slot.
2. Operasi hash Table
- Insertion
Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash untuk menentukan posisi bucket yang tepat, dan kemudianmenambahkan data ke bucket tersebut.
- Deletion
Menghapus data dari hash table dengan mencari data menggunakanfungsi hash, dan kemudian menghapusnya dari bucket yangsesuai.
- Searching 
Mencari data dalam hash table dengan memasukkan input kunci kefungsi hash untuk menentukan posisi bucket, dan kemudianmencari data di dalam bucket yang sesuai.
- Update
Memperbarui data dalam hash table dengan mencari datamenggunakan fungsi hash, dan kemudian memperbarui datayangditemukan.
- Traversal
Melalui seluruh hash table untuk memproses semua data yangadadalam tabel
3. Open Hashing (Chaining)
Metode chaining mengatasi collision dengan caramenyimpan semua itemdata dengan nilai indeks yang samake dalam sebuah linked list. Setiap node pada linkedlist merepresentasikan satu item data. Ketika ada pencarianatau penambahan item data, pencarian atau penambahandilakukan pada linked list yang sesuai dengan indeks yangtelah dihitung dari kunci yang dihash. Ketika linkedlist memiliki banyak node, pencarian atau penambahan itemdatamenjadi lambat, karena harus mencari di seluruh linkedlist. Namun, chaining dapat mengatasi jumlah itemdata yangbesar dengan efektif, karena keterbatasan array dihindari.
4. Closed Hashing
- Linear Probing
Pada saat terjadi collision, maka akan mencari posisi yang kosong di bawah tempat terjadinya collision, jikamasih penuh terus ke bawah, hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong berarti HashTable sudah penuh. 
- Quadratic Probing
Penanganannya hampir sama dengan metode linear, hanya lompatannyatidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, … )
-  Double Hashing
Pada saat terjadi collision, terdapat fungsi hash yangkedua untuk menentukan posisinya kembali.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Program di atas memanfaatkan array dinamis "table" untuk menyimpan bucket dalam hash table. Setiap bucket direpresentasikan sebagai sebuah linked list, di mana setiap node mewakili satu item data. Fungsi hash sederhana digunakanuntuk memetakan setiap kunci input ke nilai indeks array menggunakan operasimodulus.

### 2. [Nama Topik]
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Pada program di atas, HashNode adalah kelas yang digunakan untuk mewakili setiap simpul (node) dalam tabel hash. Setiap simpul memiliki atribut namadan nomor telepon karyawan. HashMap adalah kelas yang digunakan untuk mengimplementasikan struktur tabel hash dengan menggunakan vektor yangmenyimpan pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawanyang diberikan. Fungsi insert digunakan untuk menambahkan data barukedalam tabel hash. Jika nama karyawan sudah ada dalam tabel, nomor teleponakan diperbarui. Fungsi remove digunakan untuk menghapus data dari tabel hash berdasarkan nama karyawan. Fungsi searchByName digunakan untukmencari nomor telepon karyawan berdasarkan nama yang diberikan. Dalam program ini, pengguna dapat menyisipkan data karyawan, mencari nomor telepon karyawan berdasarkan nama, dan menghapus data karyawan. Seluruh tabel hash kemudian dicetak untuk menampilkan data yang tersimpan.

## Unguided 

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : 
### a. Setiap mahasiswa memiliki NIM dan nilai. 
### b. Program memiliki tampilan pilihan menu berisi poin C. 
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).]

```C++
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
        for (int i = 0; i < key_155.length(); ++i) {
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
```
#### Output:
### 1. Tampilan menu, dan menambahkan data NIM user dengan menginputkan nilai 1.
![Screenshot output](<Screenshot 2024-04-09 222110.png>)
### 2. Menampilkan semua data yang sudah ditambahkan dengan menginputkan nilai 5.
![Screenshot output](<Screenshot 2024-04-09 222451.png>)
### 3. Mencari data berdasarkan NIM, dengan menginputkan nilai 2.
![Screenshot output](<Screenshot 2024-04-09 222757.png>)
### 4. Mencari data berdasarkan rentang nilai 80-90, dengan menginputkan nilai 3.
![Screenshot output](<Screenshot 2024-04-09 223544.png>)
### 5. Menghapus data, dengan menginputkan nilai 4.
![Screenshot output](<Screenshot 2024-04-09 223746.png>)


Program di atas merupakan implementasi sederhana dari struktur data hashtable. Program ini memungkinkan pengguna untuk menambahkandatamahasiswa ke dalam hash table menggunakan NIM dan nilai, mencari datamahasiswa berdasarkan NIM, mencari data mahasiswa berdasarkan rentangnilai, dan menampilkan semua data mahasiswa yang telah ditambahkan. Program ini menggunakan fungsi hash untuk menghitung nilai hash dari NIMdan menggunakan linked list untuk menangani kolisi. Dengan menggunakanstruktur data hash table, program ini dapat menyimpan data mahasiswa dengan efisien dan memungkinkan pencarian yang cepat berdasarkan NIMataurentang nilai.

## Kesimpulan
Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengaksesdata dengan cepat menggunakan fungsi hash. Dalam hash table, data disimpandalam array berindeks dengan menggunakan fungsi hash untuk mengonversi kunci menjadi indeks array. Ini memungkinkan akses langsung ke data dengankompleksitas waktu rata-rata O(1). Ketika dua kunci menghasilkan indeks yangsama (kolisi), teknik seperti chaining atau linear probing digunakan untukmenangani kolisi tersebut. Operasi utama pada hash table meliputi penambahandata, penghapusan data, dan pencarian data berdasarkan kunci. Hash tablememiliki berbagai aplikasi, seperti pengindeksan, pencarian cepat, penyimpanandata, dan implementasi struktur data seperti set dan kamus. Penting untukmerancang atau memilih fungsi hash yang baik agar meminimalkan kolisi danmemastikan distribusi yang merata. Memahami prinsip dan implementasi hashtable akan membantu Anda dalam pengelolaan data dan pencarian efisien dalampemrograman.
## Referensi
[1] Yusuf, A. D., Abdullahi, S., Boukar, M. M., & Yusuf, S. I. (2021). Collision resolution techniques in hash table: A review. International Journal of Advanced Computer Science and Applications, 12(9).
[2] Wang, X., & Liu, L. (2020). Image encryption based on hash table scrambling and DNA substitution. IEEE Access, 8, 68533-68547.