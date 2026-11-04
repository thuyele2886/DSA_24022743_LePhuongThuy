#include "sort.h"

void selectionsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int viTriMin = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[viTriMin])
                viTriMin = j;
        }

        int tam = a[i];
        a[i] = a[viTriMin];
        a[viTriMin] = tam;
    }
}
