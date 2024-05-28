# <h1 align="center">Laporan Praktikum Modul 9 Graph and Tree</h1>
<p align="center">Naya Putwi Setiasih_2311102155</p>

## Dasar Teori
1. Graph
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk edge atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai :
G = (V, E)
Dimana G adalah Graph, V adalah simpul atau vertex dan node sebagai titik atau egde. Dapat digambarkan:
![alt text](<Screenshot 2024-05-28 185637.png>)
Graph dapat digunakan dalam berbagai aplikasi, seperti jaringan sosial, pemetaan jalan, dan pemodelan data.
- Jenis - Jenis Graph
![alt text](<Screenshot 2024-05-28 185756.png>)
a. Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.
b. Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidakdiperhatikan. Misal busur e1 dapat disebut busur AB atau BA.
c. Weigth Graph : Graph yang mempunyai nilai pada tiap edgenya.
- Binary Search
BinarySearch adalah  cara  untuk pencarian  data  pada  array  yang  sudah terurut.  karena  salah  satu  syarat  dalam BinarySearchadalah data sudah dalam keadaan    terurut.    dengan    kata    lain apabila   data   belum   dalam   keadaan terurut,  pencarian Binarytidak  dapat dilakukan. BinarySearchini dilakukan untuk [10] :
a. Memperkecil jumlah operasi perbandingan yang harus dilakukan antara data yang dicari dengan data yang ada didalam tabel, khususnya untuk   jumlah   data   yang   sangat besar ukurannya.
b. Beban komputasi lebih kecil karena pencarian   dilakukan   dari   depan, belakang dan tengah.
c. Prinsip dasarnya adalah melakukan proses  pembagian  ruang  pencarian secara  berulang-ulang  sampai  data ditemukan  atau  sampai  pencarian tidak   dapat   dibagi   lagi   (berarti terdapatkemungkinandata  tidak dtiemukan).
Representasi Graph Representasi dengan Matriks
![alt text](<Screenshot 2024-05-28 190013.png>)
Representasi dengan Linked List
![alt text](<Screenshot 2024-05-28 190055.png>)
Yang perlu diperhatikan dalam membuat representasi graph dalam bentuk linked list adalah membedakan antara simpul vertex dengan simpul edge. Simpul vertex menyatakan simpul atau vertex dan simpul edge menyatakan busur (hubungan antar simbol). Struktur keduanya bisa sama bisa juga berbeda tergantung kebutuhan, namun biasanya disamakan. Yang membedakan antara simpul vertex dengan simpul edge nantinya adalah anggapan terhadap simpul tersebut juga fungsinya masing-masing.
![alt text](<Screenshot 2024-05-28 190200.png>)

2. Tree atau Pohon
Dalam ilmu komputer, pohon adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik 
![alt text](<Screenshot 2024-05-28 190255.png>)
yang terhubung, di mana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hierarki seperti pohon keluarga, skema pertandingan, struktur organisasi. Istilah dalam struktur data tree dapat dirangkum sebagai berikut:
Binary tree atau pohon biner merupakan struktur data pohon akan tetapi setiap simpul dalam pohon diprasyaratkan memiliki simpul satu level di bawahnya (child)
![alt text](<Screenshot 2024-05-28 190406.png>)
tidak lebih dari 2 simpul, artinya jumlah child yang diperbolehkan yakni 0, 1, dan 2. Gambar 1, menunjukkan contoh dari struktur data binary tree.
![alt text](<Screenshot 2024-05-28 190451.png>)
Membuat struktur data binary tree dalam suatu program (berbahasa C++) dapat menggunakan struct yang memiliki 2 buah pointer, seperti halnya double linked list.
Operasi pada Tree
a. Create: digunakan untuk membentuk binary tree baru yang masih kosong.
b. Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.
c. isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
d. Insert: digunakan untuk memasukkan sebuah node kedalam tree.
e. Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.
f. Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong.
g. Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointercurrent dengan syarat tree tidak boleh kosong.
h. Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruhdescendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
i. Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
j. Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakniPre-Order, In-Order, dan Post-Order.
- Pre-Order
Penelusuran secara pre-order memiliki alur:
a) Cetak data pada simpul root
b) Secara rekursif mencetak seluruh data pada subpohon kiri
c) Secara rekursif mencetak seluruhdata pada subpohon kanan Dapat kita turunkan rumus penelusuran menjadi:
![alt text](<Screenshot 2024-05-28 191224.png>)
Alur pre-order
![alt text](<Screenshot 2024-05-28 191318.png>)
- Pre-Order
Penelusuran secara in-order memiliki alur:
a. Secara rekursif mencetak seluruh data pada subpohon kiri
b. Cetak data pada root
c. Secara rekursif mencetak seluruhdata pada sub pohon kanan. Dapat kita turunkan rumus penelusuran menjadi:
![alt text](<Screenshot 2024-05-28 191428.png>)
- Post Order
Penelusuran secara in-order memiliki alur:
a. Secara rekursif mencetak seluruh data pada subpohon kiri
b. Secara rekursif mencetak seluruh data pada subpohon kanan
c. Cetak data pada root Dapat kita turunkan rumus penelusuran menjadi:
![alt text](<Screenshot 2024-05-28 191526.png>)

## Guided 

### 1. [Program Graph]

```C++
#include <iostream>
#include <iomanip> // Header file untuk manipulasi output

using namespace std;

// Array simpul yang berisi nama-nama simpul dalam graf
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", // Nama-nama simpul
    "Cianjur", "Purwokerto", "Yogyakarta"
};

// Matriks busur yang merepresentasikan bobot busur antar simpul
int busur[7][7] = {
    // Matriks bobot busur
    // Ciamis    Bandung   Bekasi    Tasikmalaya  Cianjur   Purwokerto  Yogyakarta
    {0, 7, 8, 0, 0, 0, 0},       // Ciamis
    {0, 0, 5, 0, 0, 15, 0},      // Bandung
    {0, 6, 0, 0, 5, 0, 0},       // Bekasi
    {0, 5, 0, 0, 2, 4, 0},       // Tasikmalaya
    {23, 0, 0, 10, 0, 0, 8},     // Cianjur
    {0, 0, 0, 0, 7, 0, 3},       // Purwokerto
    {0, 0, 0, 0, 9, 4, 0}        // Yogyakarta
};

// Fungsi untuk menampilkan graf
void tampilGraph() {
    // Iterasi untuk setiap baris dalam matriks busur
    for (int baris = 0; baris < 7; baris++) {
        // Menampilkan nama simpul untuk baris saat ini
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Iterasi untuk setiap kolom dalam matriks busur
        for (int kolom = 0; kolom < 7; kolom++) {
            // Jika ada busur dari simpul baris ke simpul kolom (nilai busur tidak nol)
            if (busur[baris][kolom] != 0) {
                // Menampilkan nama simpul tujuan dan bobot busur
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        // Pindah ke baris berikutnya setelah menampilkan semua busur dari simpul baris
        cout << endl;
    }
}

// Fungsi utama
int main() {
    // Memanggil fungsi untuk menampilkan graf
    tampilGraph();
    return 0;
}

```
Program yang diberikan adalah sebuah program dalam bahasa C++ yang menghasilkan output berupa graf dengan simpul-simpul dan busurbusurnya. Graf tersebut merepresentasikan beberapa lokasi dengan simpulsimpul sebagai titik-titik yang saling terhubung oleh busur-busur yang menunjukkan jarak antara lokasi-lokasi tersebut. Program ini menggunakan array `simpul` untuk menyimpan nama-nama lokasi dan array `busur` dua dimensi untuk menyimpan informasi jarak antara simpul-simpul. Fungsi `tampilGraph()` digunakan untuk menampilkan graf ke layar dengan mengiterasi setiap baris dan kolom dari array `busur` untuk mencetak nama simpul terhubung beserta jaraknya. Program utama `main()` memanggil fungsi `tampilGraph()` dan mengembalikan nilai 0 setelah selesai. Dengan demikian, program tersebut adalah alat yang sederhana untuk merepresentasikan dan memvisualisasikan hubungan dan jarak antara beberapa lokasi melalui graf dengan simpul-simpul dan busur-busurnya.

### 2. [Program Tree]
```C++
#include <iostream>
#include <iomanip>
using namespace std;
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child  kanan !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
   buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);

    cout << "\n PreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;

    cout << " InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    
    cout << " PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
}
```
Program di atas merupakan implementasi sederhana dari struktur data Pohon Binari dalam bahasa C++. Pohon Binari digunakan untuk menyimpan dan mengelola kumpulan data secara hierarkis. Program ini memungkinkan pengguna untuk membuat, mengubah, dan menghapus simpul-simpul dalam pohon binari. Selain itu, program juga menyediakan fungsi-fungsi lain seperti traversal pada pohon, menghitung ukuran dan tinggi pohon, serta menampilkan informasi karakteristik pohon. Program ini memberikan pemahaman dasar tentang konsep pohon binari dan operasinya, serta dapat digunakan sebagai dasar untuk pengembangan struktur data yang lebih kompleks.

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.Output Program]

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n_155;

    // Meminta input jumlah simpul (kota)
    cout << "Silakan masukan jumlah simpul : ";
    cin >> n_155;

    vector<string> kota(n_155);

    // Meminta input nama-nama simpul
    for(int i = 0; i < n_155; ++i) {
        cout << "Silakan masukan nama simpul\n";
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i];
    }

    vector<vector<int>> jarak(n_155, vector<int>(n_155));

    // Meminta input bobot (jarak) antar simpul termasuk dirinya sendiri
    for(int i = 0; i < n_155; ++i) {
        for(int j = 0; j < n_155; ++j) {
            cout << kota[i] << "--->" << kota[j] << " = ";
            cin >> jarak[i][j];
        }
    }

    // Menampilkan matriks jarak dengan header yang dirapikan
    cout << "\n\t";
    for(int i = 0; i < n_155; ++i) {
        cout << kota[i] << "\t";
    }
    cout << "\n";

    for(int i = 0; i < n_155; ++i) {
        cout << kota[i] << "\t";
        for(int j = 0; j < n_155; ++j) {
            cout << jarak[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
```
#### Output:
![alt text](<Screenshot 2024-05-28 194516.png>)

Program di atas adalah aplikasi sederhana untuk membangun dan menampilkan adjacency matrix berdasarkan input pengguna. Berikut adalah deskripsi programnya:
1. Program meminta pengguna untuk memasukkan jumlah simpul.
2. Pengguna diminta untuk memasukkan nama simpul-simpul yang akan digunakan.
3. Program meminta pengguna untuk memasukkan bobot antar simpul.
4. Setelah semua input diterima, program akan menampilkan adjacency matrix berdasarkan input yang diberikan.
5. Adjacency matrix ditampilkan dengan format yang rapi, dengan simpul-simpul sebagai label di baris dan kolom, dan bobot antar simpul sebagai elemen-elemen matrix.
6. Program selesai dan program akan berakhir.
Dengan program ini, pengguna dapat dengan mudah memasukkan jumlah
simpul, memberikan nama pada masing-masing simpul, serta menentukan
bobot antar simpul. Hasilnya, adjacency matrix akan ditampilkan dengan
jelas dan rapi, sehingga pengguna dapat dengan mudah melihat dan
menganalisis hubungan antar simpul dalam graf yang direpresentasikan.

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data  tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan  descendant dari node yang diinput kan!]
```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pohon {
    char data_155;
    Pohon *left, *right, *parent;
};

Pohon *root = NULL;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data_155 = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data_155 << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon* baru = new Pohon();
            baru->data_155 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data_155 << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data_155 << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon* baru = new Pohon();
            baru->data_155 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data_155 << endl;
            return baru;
        }
    }
}

void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!" << endl;
        } else {
            char temp = node->data_155;
            node->data_155 = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data_155 << endl;
        }
    }
}

void find(Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data_155 << endl;
            cout << "Root: " << root->data_155 << endl;
            if (!node->parent) cout << "Parent: (tidak punya parent)" << endl;
            else cout << "Parent: " << node->parent->data_155 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) cout << "Sibling: " << node->parent->left->data_155 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) cout << "Sibling: " << node->parent->right->data_155 << endl;
            else cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left) cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else cout << "Child Kiri: " << node->left->data_155 << endl;
            if (!node->right) cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else cout << "Child Kanan: " << node->right->data_155 << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon* node) {
    if (node != NULL) {
        cout << " " << node->data_155;
        preOrder(node->left);
        preOrder(node->right);
    }
}

// inOrder
void inOrder(Pohon* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data_155;
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data_155;
    }
}

void showChildren(Pohon* node) {
    if (node) {
        if (node->left) cout << "Child Kiri: " << node->left->data_155 << endl;
        else cout << "Child Kiri: (tidak punya Child kiri)" << endl;
        if (node->right) cout << "Child Kanan: " << node->right->data_155 << endl;
        else cout << "Child Kanan: (tidak punya Child kanan)" << endl;
    } else {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
}

void showDescendants(Pohon* node) {
    if (node) {
        preOrder(node);
    } else {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon* searchNode(Pohon* node, char data) {
    if (node == NULL || node->data_155 == data) {
        return node;
    }
    Pohon* leftSearch = searchNode(node->left, data);
    if (leftSearch) return leftSearch;
    return searchNode(node->right, data);
}

// Fungsi untuk menghitung ukuran tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Fungsi untuk menghitung tinggi tree

// Fungsi untuk menghitung rata-rata nilai node tree
int totalNodeValue(Pohon* node) {
    if (node == NULL) {
        return 0;
    }
    return (node->data_155 - '0') + totalNodeValue(node->left) + totalNodeValue(node->right);
}

int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main() {
    int choice_155;
    char data_155;
    char parentData_155;
    Pohon* node;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah Child Kiri" << endl;
        cout << "3. Tambah Child Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve Node" << endl;
        cout << "6. Find Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Tampilkan Child dari Node" << endl;
        cout << "11. Tampilkan Descendant dari Node" << endl;
        cout << "12. Tampilkan Karakteristik Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice_155;

        switch (choice_155) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data_155;
                buatNode(data_155);
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                if (node) {
                    cout << "Masukkan data untuk child kiri: ";
                    cin >> data_155;
                    insertLeft(data_155, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                if (node) {
                    cout << "Masukkan data untuk child kanan: ";
                    cin >> data_155;
                    insertRight(data_155, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "Masukkan data node yang akan di-update: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                if (node) {
                    cout << "Masukkan data baru: ";
                    cin >> data_155;
                    update(data_155, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang akan diretrieve: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node yang akan dicari: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                find(node);
                break;
            case 7:
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                cout << "Masukkan data node yang akan ditampilkan child-nya: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                if (node) {
                    showChildren(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 11:
                cout << "Masukkan data node yang akan ditampilkan descendant-nya: ";
                cin >> parentData_155;
                node = searchNode(root, parentData_155);
                if (node) {
                    cout << "Descendants dari node " << parentData_155 << ": ";
                    showDescendants(node);
                    cout << endl;
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 12:
                characteristic();
                break;
            case 0:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Opsi tidak valid!" << endl;
                break;
        }
    } while (choice_155 != 0);

    return 0;
}
```
#### Output :
### 1. ![alt text](<Screenshot 2024-05-28 195644.png>)
### 2. ![alt text](<Screenshot 2024-05-28 195701.png>)
### 3. ![alt text](<Screenshot 2024-05-28 195716.png>)
### 4. ![alt text](<Screenshot 2024-05-28 195748.png>)
### 5. ![alt text](<Screenshot 2024-05-28 195805.png>)
### 6. ![alt text](<Screenshot 2024-05-28 195828.png>)
### 7. ![alt text](<Screenshot 2024-05-28 195847.png>)
### 8. ![alt text](<Screenshot 2024-05-28 195905.png>)
### 9. ![alt text](<Screenshot 2024-05-28 195924.png>)
### 10. ![alt text](<Screenshot 2024-05-28 195946.png>)
### 11. ![alt text](<Screenshot 2024-05-28 200015.png>)
### 12. ![alt text](<Screenshot 2024-05-28 200031.png>)
### 13. ![alt text](<Screenshot 2024-05-28 200044.png>)
### 14. ![alt text](<Screenshot 2024-05-28 200057.png>)
### 15. ![alt text](<Screenshot 2024-05-28 200113.png>)
### 16. ![alt text](<Screenshot 2024-05-28 200136.png>)
### 17. ![alt text](<Screenshot 2024-05-28 200149.png>)
### 18. ![alt text](<Screenshot 2024-05-28 200159.png>)
### 19. ![alt text](<Screenshot 2024-05-28 200224.png>)
### 20. ![alt text](<Screenshot 2024-05-28 200246.png>)

Program di atas adalah sebuah program C++ yang mengimplementasikan struktur data Tree (pohon). Program ini menyediakan berbagai fungsi untuk memanipulasi dan mengelola tree, serta menampilkan informasi tentang karakteristik tree yang dibentuk. Berikut adalah deskripsi singkat fungsi-fungsi utama yang ada dalam program ini:
1. `init()`: Inisialisasi pohon dengan mengatur pointer root menjadi NULL.
2. `isEmpty()`: Memeriksa apakah pohon kosong atau tidak.
3. `buatNode(char data)`: Membuat node baru dengan karakter data yang diberikan. Jika pohon masih kosong, maka node tersebut akan menjadi root.
4. `insertLeft(char data, Pohon* node)`: Menambahkan node baru dengan karakter data sebagai child kiri dari node yang ditunjuk oleh pointer `node`.
5. `insertRight(char data, Pohon* node)`: Menambahkan node baru dengan karakter data sebagai child kanan dari node yang ditunjuk oleh pointer `node`.
6. `update(char data, Pohon* node)`: Mengubah data dari node yang ditunjuk oleh pointer `node` menjadi karakter data yang baru.
7. `retrieve(Pohon* node)`: Menampilkan data dari node yang ditunjuk oleh pointer `node`.
8. `find(Pohon* node)`: Menampilkan informasi tentang node yang ditunjuk oleh pointer `node`, termasuk data node, root, parent, sibling, dan child.
9. `preOrder(Pohon* node = root)`: Menampilkan data dari node-node dalam pohon dalam urutan pre-order.
10. `inOrder(Pohon* node = root)`: Menampilkan data dari node-node dalam pohon dalam urutan in-order.
11. `postOrder(Pohon* node = root)`: Menampilkan data dari node-node dalam pohon dalam urutan post-order.
12. `deleteTree(Pohon* node)`: Menghapus seluruh pohon, dimulai dari node yang ditunjuk oleh pointer `node`.
13. `deleteSub(Pohon* node)`: Menghapus subtree yang dimulai dari node yang ditunjuk oleh pointer `node`.
14. `clear()`: Menghapus seluruh pohon.
15. `size(Pohon* node = root)`: Menghitung jumlah node dalam pohon.
16. `height(Pohon* node = root)`: Menghitung tinggi (level terdalam) dari pohon.
17. `characteristic()`: Menampilkan informasi tentang ukuran pohon, tinggi pohon, dan rata-rata node dalam pohon.
Program ini juga menyediakan sebuah main function yang melakukan penggunaan
fungsi-fungsi tersebut untuk membuat pohon, memanipulasinya, dan menampilkan
output yang relevan.

Hasil perhitungan jumlah huruf vokal kemudian ditampilkan ke layar menggunakan cout. Program diakhiri dengan return 0, yang menandakan bahwa program telah selesai berjalan dengan sukses.


## Kesimpulan
Program graph dan tree merupakan implementasi dasar dari dua struktur data yang penting dalam pemrograman, yaitu graph dan tree. Program graph menggunakan adjacency list untuk merepresentasikan kumpulan simpul yang saling terhubung oleh edge. Dalam program ini, kita dapat membuat simpul baru, menambahkan edge antara simpul, serta melakukan traversal graph menggunakan metode Breadth-First Search (BFS) dan Depth-First Search (DFS). Program tree menggunakan pointer untuk merepresentasikan hierarki kumpulan node, dengan satu node sebagai root. Program ini memungkinkan kita untuk membuat node, menambahkan child kiri dan kanan, mengubah data node, serta melakukan operasi lain seperti mencari informasi tentang parent, sibling, dan child. Selain itu, program tree juga menyediakan fungsi-fungsi untuk melakukan traversal tree seperti pre-order, in-order, dan post-order. Kedua program ini memberikan pemahaman tentang struktur data yang digunakan untuk mengorganisasi dan memanipulasi data yang memiliki hubungan kompleks dan hirarkis.

## Referensi
[1] Dalem, I. B. G. W. A. (2019). Penerapan algoritma A*(Star) menggunakan graph untuk menghitung jarak terpendek. Jurnal RESISTOR (Rekayasa Sistem Komputer), 1(1), 41-47.
[2] Maarif, S. (2019). Aplikasi pewarnaan titik pada graph dalam pembuatan jadwal pelajaran. Pi: Mathematics Education Journal, 1(1), 22-26.