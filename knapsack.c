#include <stdio.h>
#include <stdlib.h>

struct item{
    float weight;
    float value;
    float ratio; 
    int item_n;
};

void merge(struct item *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct item L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].ratio >= R[j].ratio) {
            arr[k]= L[i];
            i++;
        } else {
            arr[k]= R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct item *arr, int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void knapsack(struct item *arr,int n, float capacity)
{
     float Totalvalue = 0;
     int i,j;
     
     printf("Knapsack problems using Greedy Algorithm:\n");
     for (i = 0; i < n; i++) 
     {
      if (arr[i].weight > capacity)
          break;
       else 
      {
          Totalvalue = Totalvalue + arr[i].value;
          capacity = capacity - arr[i].weight;
       }
     } 
       if (i < n)
       Totalvalue = Totalvalue + (arr[i].ratio*capacity);
     printf("\nThe maximum value is :%.2f\n",Totalvalue);     

}

void main(){
    int n;
    printf("Enter no of Items :");
    scanf("%d",&n);
    struct item *rec = (struct item*) malloc(n *sizeof(struct item));
   
    printf("Enter details:");
    for(int i=0; i<n; i++){
        printf("Enter item no: ");
        scanf("%d", &rec[i].item_n);
        printf("\nEnter Weight:");
        scanf("%f",&rec[i].weight);
       
        printf("Enter Profit:");
        scanf("%f",&rec[i].value);
       
        rec[i].ratio = rec[i].value/rec[i].weight;
    }
    printf("Recorded Items:\n");
    printf("Weight \t Value \t PVRatio\n");
    for(int i=0; i<n; i++){
        printf("%d\t %.1f \t %.1f \t %.1f \n",rec[i].item_n, rec[i].weight, rec[i].value, rec[i].ratio);
    }
    mergeSort(rec, 0, n-1);
    printf("Recorded Items after sorting:\n");
    printf("Item\tWeight \t Value \t PVRatio\n");
    for(int i=0; i<n; i++){
        printf("%d\t %.1f \t %.1f \t %.1f \n",rec[i].item_n, rec[i].weight, rec[i].value, rec[i].ratio);
    }
   knapsack(rec, n,90);
}


