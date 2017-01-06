/*
 Karan Chawla
 Algorithm: Counting Sort
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int MAX = 100;

void display(int *A, int size);
void getFrequencyArray(int *A, int size, int *frequency);

void display(int *A, int size){
    for(int i =0;i<size;i++){
        printf("%d ", *(A+i));
    }
    printf("\n");
}

//Function to get frequency of each number
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

//Driver function
int main(void) {
    int size = 100;
    int A[100] = {63, 25, 73, 1, 98, 73, 56, 84 ,86 ,57 ,16 ,83 ,8 ,25 ,81 ,56 ,9 ,53 ,98 ,67 ,99 ,12 ,83 ,89 ,80 ,91 ,39 ,86 ,76 ,85 ,74 ,39 ,25 ,90 ,59 ,10 ,94 ,32 ,44 ,3 ,89 ,30 ,27 ,79 ,46 ,96 ,27 ,32 ,18 ,21, 92 ,69 ,81 ,40 ,40 ,34 ,68 ,78 ,24 ,87 ,42 ,69 ,23 ,41 ,78 ,22, 6, 90, 99, 89, 50, 30 ,20 ,1 ,43 ,3 ,70 ,95 ,33 ,46 ,44, 9 ,69 ,48 ,33 ,60 ,65 ,16, 82, 67, 61 ,32, 21 ,79 ,75, 75, 13, 87, 70, 33};
    
    int frequency[MAX];
    getFrequencyArray(A,size,frequency);
    
    int temp[size];
    memset(temp,0,size);
    
    for(int i =size-1;i>=0;i--){
        temp[frequency[A[i]]-1] = A[i];
        frequency[A[i]]--;
    }

    display(temp,size);
    return 0;
}

