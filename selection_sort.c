#include<stdio.h>
void selectionSort(int a[], int n){
    for (int i = 0; i <= n-2; i++)                 
    {   
        int min = i;
        for (int j = i; j <= n-1; j++)
        {
            if(a[j]<a[min]){
                min = j;
            }
            
        }
            
                int temp = a[min];
                a[min] = a[i];
                a[i] = temp;
            
        }
        
    }
    

int main(){
    int a[10], i,n,j, temp;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element no %d: ", i+1);
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    for ( i = 0; i <n; i++)
    {
        printf(" %d\t", a[i]);
        
    }
    
    return 0;
    
}