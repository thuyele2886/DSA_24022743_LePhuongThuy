#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* dau;
    Node* cuoi;
    int size;

public:

    // Khoi tao danh sach rong
    DoublyLinkedList() {
        dau = NULL;
        cuoi = NULL;
        size = 0;
    }

    // Them vao dau
    void themDau(int x) {
        Node* p = new Node;

        p->data = x;
        p->prev = NULL;
        p->next = dau;

        if (size == 0) {
            dau = p;
            cuoi = p;
        }
        else {
            dau->prev = p;
            dau = p;
        }

        size++;
    }

    // Them vao cuoi
    void themCuoi(int x) {
        Node* p = new Node;

        p->data = x;
        p->next = NULL;
        p->prev = cuoi;

        if (size == 0) {
            dau = p;
            cuoi = p;
        }
        else {
            cuoi->next = p;
            cuoi = p;
        }

        size++;
    }

    // Them vao vi tri i
    void themViTri(int i, int x) {
        if (i < 0 || i > size) {
            return;
        }

        if (i == 0) {
            themDau(x);
            return;
        }

        if (i == size) {
            themCuoi(x);
            return;
        }

        Node* p = dau;

        for (int j = 0; j < i - 1; j++) {
            p = p->next;
        }

        Node* q = new Node;

        q->data = x;

        q->prev = p;
        q->next = p->next;

        p->next->prev = q;
        p->next = q;

        size++;
    }

    // Xoa dau
    void xoaDau() {
        if (size == 0) {
            return;
        }

        Node* p = dau;

        if (size == 1) {
            dau = NULL;
            cuoi = NULL;
        }
        else {
            dau = dau->next;
            dau->prev = NULL;
        }

        delete p;
        size--;
    }

    // Xoa cuoi
    void xoaCuoi() {
        if (size == 0) {
            return;
        }

        Node* p = cuoi;

        if (size == 1) {
            dau = NULL;
            cuoi = NULL;
        }
        else {
            cuoi = cuoi->prev;
            cuoi->next = NULL;
        }

        delete p;
        size--;
    }

    // Xoa tai vi tri i
    void xoaViTri(int i) {
        if (i < 0 || i >= size) {
            return;
        }

        if (i == 0) {
            xoaDau();
            return;
        }

        if (i == size - 1) {
            xoaCuoi();
            return;
        }

        Node* p = dau;

        for (int j = 0; j < i; j++) {
            p = p->next;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;

        size--;
    }

    // Duyet xuoi
    void duyetXuoi() {
        Node* p = dau;

        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }

    // Duyet nguoc
    void duyetNguoc() {
        Node* p = cuoi;

        while (p != NULL) {
            cout << p->data << " ";
            p = p->prev;
        }

        cout << endl;
    }

    // Ham huy
    ~DoublyLinkedList() {
        while (dau != NULL) {
            Node* p = dau;
            dau = dau->next;
            delete p;
        }
    }
};


int main() {
    DoublyLinkedList a;

    a.themCuoi(26);
    a.themCuoi(27);
    a.themCuoi(28);
    a.duyetXuoi();
    cout << endl;
    a.themDau(1);
    a.duyetXuoi();
    cout << endl;
    a.themViTri(2, 100);

    cout << "them 100 vao vi tri 2: ";
    a.duyetXuoi();
    cout << endl;
    a.xoaDau();
    a.duyetXuoi();
    cout << endl;
    a.xoaCuoi();
    a.duyetXuoi();
    cout << endl;
    a.xoaViTri(1);
    cout << "xoa vi tri 1: ";
    a.duyetXuoi();
    cout << endl;
    a.duyetXuoi();
    cout << endl;
    a.duyetNguoc();

    return 0;
}
