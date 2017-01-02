#include <stdio.h> 

int missingNumber(int *a, int size){
	int k;
	for(int i=1;i<=size;i++){
		if(a[i-1]!=i){
			return i;
		}		
	}
}


int main(void){

	int A1[] = {1, 2, 3, 4 ,5 ,6 ,7 ,8 ,10};
    int m = sizeof(A1)/sizeof(A1[0]);
    printf("%d\n", missingNumber(A1,m));

    return 0;
}
/*    
	int t;
	scanf("%d",&t);
	int size;
	int a[1000];
	while(t--){
		scanf("%d",&size);
		for(int i=0;i<size;i++) scanf("%d",&a[i]);
		printf("%d\n",missingNumber(a,size));
}*/