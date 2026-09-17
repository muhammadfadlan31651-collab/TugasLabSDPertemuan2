#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    void tambahBelakang(int nilai) {
        Node* baru = new Node();
        baru->nilai = nilai;
        baru->next = nullptr;

        if (head == nullptr) {
            head = baru;
        } else {
            Node* bantu = head;
            while (bantu->next != nullptr) {
                bantu = bantu->next;
            }
            bantu->next = baru;
        }
    }
    void tambahDepan(int nilai) {
        Node* baru = new Node();
        baru->nilai = nilai;
        baru->next = head;
        head = baru;
    }
    void tambahSetelah(int nilaiCari, int nilaiBaru) {
        Node* bantu = head;

        while (bantu != nullptr && bantu->nilai != nilaiCari) {
            bantu = bantu->next;
        }

        if (bantu == nullptr) {
            cout << "nilai " << nilaiCari << " tidak ada" << endl;
            return;
        }

        Node* baru = new Node();
        baru->nilai = nilaiBaru;
        baru->next = bantu->next;
        bantu->next = baru;
    }

    void hapus(int nilai) {
        if (head == nullptr) {
            cout << "List kosong, tidak bisa menghapus" << endl;
            return;
        }
        if (head->nilai == nilai) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* sebelum = head;
        while (sebelum->next != nullptr && sebelum->next->nilai != nilai) {
            sebelum = sebelum->next;
        }

        if (sebelum->next == nullptr) {
            cout << "nilai " << nilai << " tidak ada" << endl;
            return;
        }

        Node* target = sebelum->next;
        sebelum->next = target->next;
        delete target;
    }
    void tampilkan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        Node* bantu = head;
        while (bantu != nullptr) {
            cout << bantu->nilai;
            if (bantu->next != nullptr) {
                cout << " -> ";
            }
            bantu = bantu->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int dataAwal[10] = {100, 92, 45, 87, 71, 99, 95, 60, 55, 88};
    for (int i = 0; i < 10; i++) {
        list.tambahBelakang(dataAwal[i]);
    }

    cout << "Data awal:" << endl;
    list.tampilkan();
    cout << endl;

    list.tambahDepan(70);
    cout << "setelah tambah 70 di depan:" << endl;
    list.tampilkan();
    cout << endl;

    list.tambahBelakang(50);
    cout << "setelah tambah 50 di belakang:" << endl;
    list.tampilkan();
    cout << endl;

    list.tambahSetelah(45, 0);
    cout << "setelah tambah 0 setelah 45:" << endl;
    list.tampilkan();
    cout << endl;

    list.hapus(99);
    cout << "setelah hapus 99:" << endl;
    list.tampilkan();
    cout << endl;

    list.hapus(60);
    cout << "setelah hapus 60:" << endl;
    list.tampilkan();
    cout << endl;

    return 0;
}
