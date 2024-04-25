#include<stdio.h>
int maze(int sr,int sc, int er, int ec){
    int rightways = 0, downways = 0;
    if(sr==er && sc==ec){
        return 1;
    }if (sr == er){
        rightways += maze(sr, sc+1, er, ec);
    }if (sc == ec){
        downways += maze(sr+1, sc, er, ec);
    }
    if(sr <er && sc<ec){
        rightways += maze(sr, sc+1, er, ec);
        downways += maze(sr+1, sc, er, ec);
    }
    int totalways = rightways + downways;
    return totalways;
}
int main(){
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    int result = maze(1, 1, r, c);
    printf("Total number of ways are: %d", result);
    return 0;
}