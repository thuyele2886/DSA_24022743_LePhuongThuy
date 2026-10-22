#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* dau;
    Node* cuoi;
    int size;

public:
// Khoi tao danh sach
    LinkedList() {
        dau = NULL;
        cuoi = NULL;
        size = 0;
    }

    // Them vao dau
    void themDau(int x) {
        Node* p = new Node;

        p->data = x;
        p->next = dau;

        dau = p;

        if (size == 0) {
            cuoi = p;
        }

        size++;
    }

    void themCuoi(int x) {
        Node* p = new Node;

        p->data = x;
        p->next = NULL;

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
        q->next = p->next;
        p->next = q;

        size++;
    }

    void xoaDau() {
        if (size == 0) {
            return;
        }

        Node* p = dau;

        dau = dau->next;

        delete p;

        size--;

        if (size == 0) {
            cuoi = NULL;
        }
    }


    void xoaCuoi() {
        if (size == 0) {
            return;
        }

        if (size == 1) {
            delete dau;
            dau = NULL;
            cuoi = NULL;
            size = 0;
            return;
        }

        Node* p = dau;

        while (p->next != cuoi) {
            p = p->next;
        }

        delete cuoi;

        cuoi = p;
        cuoi->next = NULL;

        size--;
    }

    // Xoa vi tri i
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

        for (int j = 0; j < i - 1; j++) {
            p = p->next;
        }

        Node* q = p->next;

        p->next = q->next;

        delete q;

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

    void duyetNguoc(Node* p) {
        if (p == NULL) {
            return;
        }

        duyetNguoc(p->next);

        cout << p->data << " ";
    }

    void duyetNguoc() {
        duyetNguoc(dau);
        cout << endl;
    }

    // Ham huy
    ~LinkedList() {
        while (dau != NULL) {
            Node* p = dau;
            dau = dau->next;
            delete p;
        }
    }
};


int main() {
    LinkedList a;

    a.themCuoi(10);
    cout<< endl;
    a.themCuoi(20);
    a.themCuoi(30);
    a.duyetXuoi();
     cout<< endl;
    a.themDau(5);
    a.duyetXuoi();
     cout<< endl;
    a.themViTri(2, 1);
    cout << "Them 1 vao vi tri 2 ";
    a.duyetXuoi();
     cout<< endl;
    a.xoaDau();
    a.duyetXuoi();
     cout<< endl;
    a.xoaCuoi();
    a.duyetXuoi();
     cout<< endl;
    a.xoaViTri(1);
    a.duyetXuoi();
     cout<< endl;
    a.duyetNguoc();
     cout<< endl;

    return 0;
}
