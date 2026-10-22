
#include <iostream>
#include <stdexcept>
#include "C:/DSA_BTVN/List.h"

using namespace std;

List::List(int n) {
    onho = n;
    size = 0;
    a = new int[onho];
}

List::~List() {
    delete[] a;
}

void List::themCuoi(int x) {
    if (size == onho) {
        onho++;

        int* b = new int[onho];

        for (int i = 0; i < size; i++) {
            b[i] = a[i];
        }

        delete[] a;
        a = b;
    }

    a[size] = x;
    size++;
}

void List::themDau(int x) {
    if (size == onho) {
        onho++;

        int* b = new int[onho];
        b[0] = x;

        for (int i = 0; i < size; i++) {
            b[i + 1] = a[i];
        }

        delete[] a;
        a = b;
    }
    else {
        for (int i = size; i > 0; i--) {
            a[i] = a[i - 1];
        }

        a[0] = x;
    }

    size++;
}

void List::themViTri(int i, int x) {
    if (i < 0 || i > size) {
        return;
    }

    if (size == onho) {
        onho++;

        int* b = new int[onho];

        for (int j = 0; j < size; j++) {
            b[j] = a[j];
        }

        delete[] a;
        a = b;
    }

    for (int j = size; j > i; j--) {
        a[j] = a[j - 1];
    }

    a[i] = x;
    size++;
}

void List::xoaDau() {
    if (size == 0) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        a[i] = a[i + 1];
    }

    size--;
}

void List::xoaCuoi() {
    if (size == 0) {
        return;
    }

    size--;
}

void List::xoaViTri(int i) {
    if (i < 0 || i >= size) {
        return;
    }

    for (int j = i; j < size - 1; j++) {
        a[j] = a[j + 1];
    }

    size--;
}

void List::duyetXuoi() {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

void List::duyetNguoc() {
    for (int i = size - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    cout << endl;
}

int List::layViTri(int i) {
    if (i < 0 || i >= size) {
        throw out_of_range("Vi tri khong hop le");
    }

    return a[i];
}

int List::getSize() {
    return size;
}
