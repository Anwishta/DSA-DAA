#include<stdio.h>
int factorial(int n){
    int fact = 1;
    for(int i =2; i<=n; i++){
        fact = fact*i;
    }
    return fact;
}
int permutation(int n, int r){
    int result = factorial(n)/factorial(n-r);
    return result;
}
int main(){
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);
    if(n>=r){
    int value = permutation(n, r);
    printf("The valur of nPr is: %d", value);}
    else{
        printf("n must be greater than r...");
    }
    return 0;
}