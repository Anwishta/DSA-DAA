#include<stdio.h>
int majority(int *nums, int numSize){
    int candidate = nums[0];
    int count = 1;
    for (int i = 0; i < numSize; i++)
    {
        if(nums[i]== candidate){
            count++;
        }else{
            count--;
            if(count == 0){
                candidate = nums[i];
                count =1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < numSize; i++)
    {
        if (nums[i]== candidate){
            count++;
        }
        
    }
   if(count>numSize/2){
    return count;
   }else{
    return -1;
   }
    
    
}

int main(){
    int a[10], n;
    printf("Enter number of elements of the array: ");
    scanf("%d", &n);
}