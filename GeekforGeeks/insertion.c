#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int ar_size, int *  ar) {
    for(int i =0;i<ar_size;i++){
        int j = i;
        int temp;
        while (j>0 && ar[j-1]>ar[j]){
            temp = ar[j];
            ar[j] = ar[j-1];
            ar[j-1] = temp;
            j = j-1;
        }
        for(int k=0;k<ar_size;k++)    printf("%d\t", ar[k]);
        printf("\n");
    }
}

int main(void) {
    int _ar_size;
    /*scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }*/
    _ar_size = 5;
    int _ar[] = {2, 4, 6, 8, 3};
    
    insertionSort(_ar_size, _ar);
    return 0;
}