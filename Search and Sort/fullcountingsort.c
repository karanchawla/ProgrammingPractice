#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void display(int *A, int size);

void display(int *A, int size){
    for(int i =0;i<size;i++){
        printf("%d ", *(A+i));
    }
    printf("\n");
}

int main() {
    int size=100;
    int lim;
    scanf("%d",&lim);
    int A[lim];
    char *str[lim];
    
    int counter[size];
    for (int i=0; i<size;i++){
        counter[i]=0;
    }
    for(int i = 0; i < lim; i++) { 
       scanf("%d", &A[i]);
       counter[A[i]]++;
       fgets(str[i],10,stdin);
    }

    int temp[lim];
    memset(temp,0,lim);
    for(int i =lim-1;i>=0;i--){
        temp[counter[A[i]]-1] = A[i];
        counter[A[i]]--;
    }
    display(temp,lim);

    
    return 0;
}
