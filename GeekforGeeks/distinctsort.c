#include <stdio.h>
#include <stdlib.h> 

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int findMax(int *a, int size){
	int max = -1;
	for (int i=0;i<size;i++){
		if(a[i]>max){
			max = a[i];
		}
	}
	return max;
}

void count(int *a, int size, int e, int *output){
	int i;
	int count[10]={0};

	for(int i=0;i<size;i++){
		count[(a[i]/e)%10]++;
	}
	
	for(int i=0;i<10;i++) {
		if(count[i]>0){
			output[i] = i;
		}
	}
}

int main(void){
	int temp[] = {131 ,20,11, 455};
	int size = sizeof(temp)/sizeof(*temp);
	int output[10];
	for(int i=0;i<10;i++) output[i] = -1;
	/*qsort (temp, sizeof(temp)/sizeof(*temp), sizeof(*temp), comp);
	int i, j;
	int NewLength = 1;
	for(i=1; i< size; i++){

   		for(j=0; j< NewLength ; j++)
   		{

      		if(temp[i] == temp[j])
    		  	break;
   		}

     	if (j==NewLength )
      	temp[NewLength++] = temp[i];
	}
	for (int i=0;i<NewLength;i++) printf("%d ",temp[i]);*/
	int max = findMax(temp,size);
	for(int e=1; max/e > 0; e*=10){
		count(temp, size, e, output);
	}
	qsort (output, 10, sizeof(*output), comp);

	for(int i=1;i<10;i++){
		if (output[i]>-1)
			printf("--%d", output[i]); 
	}
return 0;
}