
#include <iostream>
using namespace std;

class List {
private:
    int* a;
    int size;
    int onho;

public:

    // Constructor - ham khoi tao
    List(int n = 5) {
        onho = n;
        size = 0;
        a = new int[onho];
    }

    // Destructor - ham huy
    ~List() {
        delete[] a;
    }

    //Them vao cuoi
    void themCuoi(int x) {
        if (size == onho) {
            onho = onho +1;
            int* b = new int[onho]; // tao mang moi de cho du lieu sang neu mang cu day
            for (int i = 0; i < size; i++) {
                b[i] = a[i];
            }

            delete[] a;
            a = b;
        }

        a[size] = x;
        size++;
    }

    void themDau(int x) {
    if (size == onho) {
        onho = onho + 1;

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

    // Them vao vi tri i
    void themViTri(int i, int x) {
        if (i < 0 || i > size) {
            return;
        }

        // Neu mang day
        if (size == onho) {
            onho = onho +1 ;

            int* b = new int[onho];

            for (int j = 0; j < size; j++) {
                b[j] = a[j];
            }

            delete[] a;
            a = b;
        }

        // Dich cac phan tu tu i sang phai
        for (int j = size; j > i; j--) {
            a[j] = a[j - 1];
        }

        a[i] = x;
        size++;
    }

    // Xoa dau
    void xoaDau() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            a[i] = a[i + 1];
        }

        size--;
    }

    // Xoa cuoi
    void xoaCuoi() {
        if (size == 0) {
            return;
        }

        size--;
    }

    // Xoa tai vi tri i
    void xoaViTri(int i) {
        if (i < 0 || i >= size) {
            return;
        }

        for (int j = i; j < size - 1; j++) {
            a[j] = a[j + 1];
        }

        size--;
    }

    // Duyet xuoi
    void duyetXuoi() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    // Duyet nguoc
    void duyetNguoc() {
        for (int i = size - 1; i >= 0; i--) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
};


int main() {

    List a;

    // Them vao cuoi
    a.themCuoi(1);
    a.themCuoi(2);
    a.themCuoi(3);

    a.duyetXuoi();
     cout << endl;

    a.themDau(5);
    a.duyetXuoi();
      cout << endl;


    a.themViTri(2, 5);

    cout << "them 5 vao vi tri 2 duoc ";
     a.duyetXuoi();
      cout << endl;


    // Xoa dau
    a.xoaDau();

    a.duyetXuoi();
     cout << endl;


    a.xoaCuoi();

    a.xoaViTri(1);

    cout << "xoa vi tri 1 " ;
    a.duyetXuoi();
    cout << endl;


     a.duyetNguoc();



    return 0;
}

