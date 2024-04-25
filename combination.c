#include<stdio.h>
int factorial(int n){
    int fact =1;
    if(n == 0 || n == 1)
    return 1;
    fact = n * factorial(n-1);
    return fact;
}
int combination(int n, int r){
    int s = 1;
    s = factorial(n)/(factorial(r)*factorial(n-r));
    return s;
}
int main(){
    int r, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);
    printf("%d", combination(n,r));
    return 0;

}