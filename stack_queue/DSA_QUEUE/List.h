#ifndef LIST_H
#define LIST_H

class List {
private:
    int* a;
    int size;
    int onho;

public:
    List(int n = 5);
    ~List();

    void themCuoi(int x);
    void themDau(int x);
    void themViTri(int i, int x);

    void xoaDau();
    void xoaCuoi();
    void xoaViTri(int i);

    void duyetXuoi();
    void duyetNguoc();

    int layViTri(int i);
    int getSize();
};

#endif
