// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>


int get_max(int arr[],int n){
    int i=0;
    int max = arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

void decimal_to_binary(int n){
    int arr[40];
    int i=0;
    printf("%d as binary : ",n);
    while(n>0){
        arr[i] = n % 2;
        n /= 2;
        i++;
    }
    // Printing them in a reversed order
    int counter[10]={0};
    int j;
    for(j=i-1;j>=0;j--){
        printf("%d",arr[j]);
        if(arr[j] == 0){
            for(int k=j+1;k<i;k++){
                if(arr[k] == 1)
                    counter[i]++;
                else
                    break;
            }
        }
    }
    printf("\nMax number of ones : %d",get_max(counter,10));

}
int main() {

    decimal_to_binary(14);



    return 0;
}
