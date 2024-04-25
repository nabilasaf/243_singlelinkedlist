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

    while ((curret != NULL) && (nim >= current ->noMHS))
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
    previous->next + nodeBaru;
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
    else id (current->noMHS == nim)
    {
        return true;
    }
    else
    {
        return false;
    }
}