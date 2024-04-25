#include<stdio.h>
void print(int n){
    if (n==0){
        return;
    }
    printf("%d\t", n);
    print(n-1);
}
int main(){
    int n;
    printf("Enter the number you want to print: ");
    scanf("%d", &n);
    print(n);
    return 0;
}
