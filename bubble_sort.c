#include<stdio.h>
void bubbleSort(int a[], int n){
    int i,j,temp;
    for ( i = 0; i < n-1; i++)
    {
        for(j=0; j<n-i-1;j++){
            if (a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
            
        }
    }
    
}
int main(){
    int a[10], i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter the element no %d: ", i);
        scanf("%d", &a[i]);
    }
    bubbleSort(a,n);
    for ( i = 0; i < n; i++)
    {
       printf("%d\t", a[i]);
    }
    
}