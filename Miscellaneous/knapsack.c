/*
Karan Chawla
0-1 Knapsack Problem
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int *val, int *wt, int W, int n)
{	
	int i,w;

	int k[n+1][W+1];

	

	if(n==0||W==0)
	{
		return 0;
	}

	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0||w==0)
				k[i][w] = 0;
		
			else if(wt[i-1]<=w)
				k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w]);

			else 
				k[i][w] = k[i-1][w];
		}
	}

	return k[n][W];
}

//Driver program
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(val, wt, W, n));
    return 0;
}