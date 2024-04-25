#include<stdio.h>
int power(int a, int b){
    int x;
    if(b==0) return 1;
    x = power(a, b/2);
    if(b%2==0){
        return x*x;
    }
    else{
        return x*x*a;
    }
}
int main(){
    int a, b;
    printf("Enter the base: ");
    scanf("%d", &a);
    printf("Enter the power: ");
    scanf("%d", &b);
    printf("The power of %d raised to power %d is : %d",a, b, power(a, b));
    return 0;
}