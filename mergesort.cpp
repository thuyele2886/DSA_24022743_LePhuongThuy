#include "Sort.h"

void merge(int a[], int left, int mid, int right) {
    int n = right - left + 1;
    int *tam = new int[n];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tam[k] = a[i];
            i++;
        } else {
            tam[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        tam[k] = a[i];
        i++;
        k++;
    }

    while (j <= right) {
        tam[k] = a[j];
        j++;
        k++;
    }

    for (int t = 0; t < n; t++)
        a[left + t] = tam[t];

    delete[] tam;
}

void mergesort(int a[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);

    merge(a, left, mid, right);
}
