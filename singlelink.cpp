#include <iostream>
using namespace std;

struct Node{
    int noMHS;
    string name;
    Node* next;
};

Node* START =NULL;

void addNode(){
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMHS = nim;
    nodeBaru->name = nama;

    if (START == NULL || nim <= START->noMHS){
        if (START != NULL && nim == START->noMHS)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        nodeBaru->next = START;
        START =nodeBaru;
        return;
    }

    Node* previous = START;
    Node* current = START;

    while ((current != NULL) && (nim >= current ->noMHS))
    {
        if (nim == current->noMHS)
        {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    nodeBaru->next = current;
    previous->next = nodeBaru;
}

bool serachNode(int nim, Node* current, Node* previous) {
    previous = START;
    current = START;
    while (current != NULL && nim > current->noMHS)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return false;
    }
    else if (current->noMHS == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool deletNode(int nim){
    Node* current = START;
    Node* previous = START;
    if (serachNode(nim, previous, current) == false)
    return false;
    previous->next = current->next;
    if (current == START)
    START = current->next;
    return true;
}

bool listEmpty() {
    if (START == NULL)
    return true;
    else
    return false;
}

void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << "NIM:" << currentNode->noMHS << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void searchdata() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        system ("pause");
        system("cls");
        return;
    }
    else {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode = NULL) {
            if (currentNode->noMHS == nim) {
                cout << "NIM: " << currentNode->noMHS << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

int main() {
    int pilihan;
    do
    {
        try
        {
            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Cari Data" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
                case 1:
                  addNode();
                  cout << "Data Berhasil Ditambahkan" << endl;
                  system("pause");
                  system("cls");
                  break;
                case 2:
                  if (listEmpty())
                  {
                    cout << "List kosong" << endl;
                    system ("pause");
                    system ("cls");
                    break;
                  }
                  int nim;
                  cout << "Masukkan NIM: ";
                  cin >> nim;
                  if (deletNode(nim)) {
                    cout << "nim: " << "berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                  }
                  else
                  cout << "Data tidak ditemukan" << endl;
                  break;
                  case 3:
                  traverse();
                  break;
                  case 4:
                  searchdata();
                  break;
                  case 5:
                  break;
                  defualt:
                  cout << "Pilihan tidak ada" << endl;
                  break;
            }
        }
        catch (exception e)
        {
            cout << "Terjadi kesalahan" << endl;
        }
    } while (pilihan != 5);
}

            
        
    
