#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int MAX = 100;

//void countingSort(int A[], int size);
//int getMax(int A[], int size);
void display(int *A, int size);
void getFrequencyArray(int *A, int size, int *frequency);

void display(int *A, int size){
    for(int i =0;i<size;i++){
        printf("%d ", *(A+i));
    }
    printf("\n");
}

/*int getMax(int A[], int size){
    int max = A[0];
    for(int i=1;i<size;i++){
        if (A[i]>max){
            max = A[i];
        }
    }
    return max;
}*/

void getFrequencyArray(int *A, int size, int *frequency){
    for (int i=0;i<MAX;i++){
        frequency[i]=0;
    }

    for (int i=0;i<size;i++){
        frequency[A[i]]++;
    }
    for (int i =0; i<MAX;i++){
       frequency[i] += frequency[i-1];
   }

}

int main() {

    int size;
    scanf("%d", &size);
    int A[size], i;
    for(i = 0; i < size; i++) { 
       scanf("%d", &A[i]); 
    }
    int frequency[MAX];
    getFrequencyArray(A,size,frequency);
    display(frequency,MAX);
    int temp[size];
    memset(temp,0,size);
    for(int i =size-1;i>=0;i--){
        temp[frequency[A[i]]-1] = A[i];
        frequency[A[i]]--;
    }
    display(temp,size);
    //countingSort(A,size);
    return 0;
}

