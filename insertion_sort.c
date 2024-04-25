#include<stdio.h>
void insertionSort(int a[], int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        j=i;
        while (j>0 && a[j-1]>a[j])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
}
int main(){
    int a[10],n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter element number %d", i+1);
        scanf("%d", &a[i]);
    }
    insertionSort(a,n);
    for(i=0;i<n;i++){
        printf("%d\t", a[i]);
        
    }
    return 0;
}