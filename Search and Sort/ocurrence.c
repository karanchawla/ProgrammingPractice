#include <stdio.h>

int count(int *a,int size, int x){
	int ans=0;
	for(int i=0;i<size,i++){
		if(a[i]==x){
			ans++;
		}
	}
	if(ans==0){
		return -1;
	}else 
		return ans;
}


int mian(void){
	int t;
	scanf("%d",&t);
	int size, int x;
	int a[500];
	while(t--){
		scanf("%d %d", &size,&x);
		for(int i=0;i<size;i++){
			scanf("%d".&a[i]);
		}
		printf("%d\n", count(a,size,x));
	}
	return 0;
}