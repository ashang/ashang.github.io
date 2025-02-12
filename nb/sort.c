#include <stdio.h>

//void insertion_sort(int arr[], int len){
void insertion_sort(int arr[], int len){
    int i,j;
    for (i=1;i!=len; ++i){

    printf("\n");
    printf("Round %d \n", i);

        int key = arr[i];
        j=i-1;

    for (int idx=0; idx<len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");

        while((j>=0) && (arr[j]> key)) {

    printf("i: %d, j: %d, key: %d, arr[j]: %d \n", i, j, key, arr[j]);

            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    printf("After Round %d \n", i);
    for (int idx=0; idx<len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");

    }
}

int main(){

// get len
    int len = 6;
// get len

    int arr[] = {5, 2, 4, 6, 1, 3};

    for (int idx=0; idx<len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");

    insertion_sort(arr, len);

    for (int idx=0; idx<len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");

    return 0;
}

