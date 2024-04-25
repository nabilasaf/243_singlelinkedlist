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
}