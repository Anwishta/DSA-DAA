#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1], r[n2];

    for (int i = 0; i < n1; i++) {
        l[i] = a[low + i];
    }

    for (int j = 0; j < n2; j++) {
        r[j] = a[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[10], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element no %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}
