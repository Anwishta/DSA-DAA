// #include<stdio.h>
// int factorial(int n){
//     int fact =1;
//     if(n == 0 || n == 1)
//     return 1;
//     fact = n * factorial(n-1);
//     return fact;
// }
// int combination(int n, int r){
//     int s = 1;
//     s = factorial(n)/(factorial(r)*factorial(n-r));
//     return s;
// }
int main(){
    int r;
    printf("Enter the value of row: ");
    scanf("%d", &r);
    for(int i =0 ; i<=r; i++){
        for(int j = 0; j<=r-(i+1); j++){
            printf("  ");
        }
        for(int j = 0; j<=i; j++){
            printf(" %d ", combination(i,j));
        }
        printf("\n");
    }
    return 0;

}