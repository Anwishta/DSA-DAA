#include<stdio.h>
void swap(int *p, int *q){
    int temp = *p; 
    *p = *q;
    *q = temp;
}
int partition(int a[], int low, int high){
    int i,j;
    int pivot = a[low];
    i = low;
    j = high;
    while(a[i]<a[pivot] && i<=high){
        i++;
    }while(a[j]>a[pivot] && j>=low ){
        j--;
    }if(i<j){swap(&a[i], &a[j]);}
    swap(&a[pivot], &a[j]);
    return j;

}
void quickSort(int a[], int low, int high){
    int pi = partition(a, low, high);
    quickSort(a, low, pi-1);
    quickSort(a, pi+1, high);
    
}
int main(){
    int a[10], n;
    printf("Enter the number of elements of array: ");
    scanf("%s", &n);
    for(int i=0; i<n; i++){
        printf("Enter element no %d", i+1);
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);

    }return 0;
}