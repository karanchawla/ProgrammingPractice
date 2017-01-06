/*
 Karan Chawla
 Algorithm: Karatsuba Multiplication
 Source: Wikipedia
*/

#include <stdio.h>             
#include <string.h>            
#include <math.h>              

long long int karatsuba(long long int , long long int , int );

long long int karatsuba(long long int x, long long int y, int b ){

    if (x <1000 || y <1000){   
        return x*y;            
    }
    else{
  
        char x1[100000];
        sprintf(x1,"%lld", x);
        char y1[100000];
        sprintf(y1,"%lld", y);
        long long int m;
        if (strlen(x1)>strlen(y1)){     
            m = strlen(x1);
        }else {
            m = strlen(y1);
        }
        long long int m2 = m/2;   
        long long int bm = pow(b, m2);  
        long long int high1 = x/bm;     
        long long int high2 = y/bm;     
        long long int low1 = x%bm;      
        long long int low2 = y%bm;        
        long long int z0 = karatsuba(low1,low2, 10);
        long long int z1 = karatsuba(low1+high1,low2+high2, 10);
        long long int z2 = karatsuba(high1,high2, 10);   
        long long int temp = pow(10, m2);
        long long int temp2 = pow(10, 2*m2); 
        return (z2*temp2)+((z1-z2-z0)*temp)+(z0);
    }

}

int main(){
	long long int ans = karatsuba(106546,256364,10);
	printf("%lld\n", ans);
}   
