/*
 Karan Chawla
 Algorithm: Maximum and Minimum product in an array. 
 Array may have -ve, 0 and +ve integers
*/

#include <stdio.h> 
#include <math.h> 

int min (int x, int y) {return x < y? x : y; } 
int max (int x, int y) {return x > y? x : y; }

void maxMinProduct(int *a, int size, int *maxProduct, int *minProduct)
{
	int prevMaxProduct = a[0];
	int prevMinProduct = a[0];
	int currMaxProduct = a[0];
	int currMinProduct = a[0];

	for(int i=0;i<size;i++)
	{
		currMaxProduct = max(currMaxProduct*a[i],max(currMinProduct*a[i],a[i]));
		currMaxProduct = max(currMaxProduct, prevMaxProduct);

		currMinProduct = min(currMinProduct*a[i],min(currMaxProduct*a[i],a[i]));
		currMinProduct = min(currMinProduct,prevMinProduct);

		maxProduct = max(maxProduct,currMaxProduct);
		minProduct = max(minProduct,currMinProduct);

		prevMinProduct = currMinProduct;
		prevMaxProduct = prevMaxProduct;
	}
	return 0;
}

//Driver program
int main(void)
{
	int arr[] = {-4, -2, 3, 7, 5, 0, 1};
	int size = sizeof(arr)/sizeof(*arr);
	int maxp = NULL;
	int minp = NULL;
	maxMinProduct(arr,size,&maxp,&minp);
}
