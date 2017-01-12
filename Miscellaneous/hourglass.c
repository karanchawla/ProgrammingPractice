//Kran Chawla
//Hackkerank challenge to 
//calculate maximum sum 
//from all the hourglass shapes
//in a 2D array

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//driver function
int main(void)
{
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++)
    {
        for(int arr_j = 0; arr_j < 6; arr_j++)
        {

            scanf("%d",&arr[arr_i][arr_j]);
        }
    }

    int sum = -100;

    for(int i=0 ; i<=3 ; i++)
    {   
        for(int j=0 ; j<=3 ; j++)
        {
            int temp = 0;
            for(int k = j; k < j+3; k++)
            {
                temp += arr[i][k];
            }
            temp += arr[i+1][j+1];
            for(int k = j; k < j+3; k++)
            {
                temp+= arr[i+2][k];
            }
            if(sum < temp)
            {
                sum = temp;
            }
        }
    }
    
        printf("%d\n", sum); 
    
    return 0;
}