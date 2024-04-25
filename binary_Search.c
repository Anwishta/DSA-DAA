#include <stdio.h>

int swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int binarySearch(int a[], int low, int high, int n) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (n == a[mid]) {
            return mid;
        } else if (n > a[mid]) {
            return binarySearch(a, mid + 1, high, n);
        } else {
            return binarySearch(a, low, mid - 1, n);
        }
    }
    return -1;
}

int main() {
    int a[10], s, n, i;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    printf("Enter the element you want to search: ");
    scanf("%d", &s);
    int result = binarySearch(a, 0, n - 1, s);
    if (result == -1) {
        printf("Element not found...");
    } else {
        printf("Element found at index %d", result);
    }
    return 0;
}
