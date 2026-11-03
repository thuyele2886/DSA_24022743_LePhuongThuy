#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> a;

    void doiCho(int &x, int &y) {
        int tam = x;
        x = y;
        y = tam;
    }

    void dayLen(int i) {
        while (i > 0) {
            int cha = (i - 1) / 2;

            if (a[cha] >= a[i])
                break;

            doiCho(a[cha], a[i]);
            i = cha;
        }
    }

    void dayXuong(int i) {
        int n = dem();

        while (2 * i + 1 < n) {
            int trai = 2 * i + 1;
            int phai = 2 * i + 2;
            int lonNhat = trai;

            if (phai < n && a[phai] > a[trai])
                lonNhat = phai;

            if (a[i] >= a[lonNhat])
                break;

            doiCho(a[i], a[lonNhat]);
            i = lonNhat;
        }
    }

public:
    bool rong() {
        return a.empty();
    }

    int dem() {
        return a.size();
    }

    void them(int x) {
        a.push_back(x);
        dayLen(dem() - 1);
    }

    bool layRa(int &x) {
        if (rong())
            return false;

        x = a[0];
        a[0] = a[dem() - 1];
        a.pop_back();

        if (!rong())
            dayXuong(0);

        return true;
    }

    void nhap(int n) {
        int x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            them(x);
        }
    }

    void xuat() {
        for (int i = 0; i < dem(); i++)
            cout << a[i] << " ";

        cout << endl;
    }
};

// Dung Priority Queue de sap xep tang dan.
void heapSort(PriorityQueue q, vector<int> &a) {
    int n = q.dem();
    a.resize(n);

    for (int i = n - 1; i >= 0; i--)
        q.layRa(a[i]);
}

int main() {
    PriorityQueue q;
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n < 0)
        return 0;

    cout << "Nhap cac phan tu: ";
    q.nhap(n);

    cout << "Priority Queue: ";
    q.xuat();

    cout << "So phan tu: " << q.dem() << endl;

    vector<int> a;
    heapSort(q, a);

    cout << "Sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    int x;
    if (q.layRa(x))
        cout << "Phan tu lay ra khoi queue: " << x << endl;
    else
        cout << "Queue rong" << endl;

    cout << "So phan tu con lai: " << q.dem() << endl;

    return 0;
}
