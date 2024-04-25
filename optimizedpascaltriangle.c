#include<stdio.h>
int main(){
    int r;
    printf("Enter the value of row: ");
    scanf("%d", &r);
    for(int i =0 ; i<=r; i++){
        for(int j = 0; j<=r-(i+1); j++){
            printf("  ");
        }
        for(int j = 0; j<=i; j++){
            printf(" %d ");
        }
        printf("\n");
    }
    return 0;

}