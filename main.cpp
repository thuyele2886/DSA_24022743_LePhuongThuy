#include <iostream>
#include "sort.h"
using namespace std;

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

void saoChep(int a[], int b[], int n) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int main() {
    int a[1000], b[1000];
    int n;
    cin >> n;

    if (n < 0 || n > 1000)
        return 0;

    nhap(a, n);

    saoChep(a, b, n);
    bubblesort(b, n);
    cout << "Bubble Sort: ";
    xuat(b, n);

    saoChep(a, b, n);
    selectionsort(b, n);
    cout << "Selection Sort: ";
    xuat(b, n);

    saoChep(a, b, n);
    insertionsort(b, n);
    cout << "Insertion Sort: ";
    xuat(b, n);

    saoChep(a, b, n);
    mergesort(b, 0, n - 1);
    cout << "Merge Sort: ";
    xuat(b, n);

    saoChep(a, b, n);
    quicksort(b, 0, n - 1);
    cout << "Quick Sort: ";
    xuat(b, n);



    return 0;
}
