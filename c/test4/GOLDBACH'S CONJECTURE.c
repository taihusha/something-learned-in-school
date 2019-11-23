#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
#define BEGIN 10
#define END 20
bool Prime(int n);
void Goldbach(int n);
/* GOLDBACH'S CONJECTURE:
Every even number n>=4 is the sum of two primes.
10=3+7
12=5+7
……
20=3+17
 */
int main(){
    int i;
    for(i=BEGIN;i<=END;i++)
    {
        if(i%2==0)
            Goldbach(i);    
    }
    system("pause");
    return 0;
}
bool Prime(int n) 
{ 
    bool p=true; 
    for(int i=2;i<=floor(sqrt(n));i++) 
    { 
        if(n%i==0) 
        {
            p=false; 
            exit;
        }
    } 
    return p; 
} 
void Goldbach(int n) 
{ 
    bool goldbach=false; 
    for(int i=2;i<=n/2;i++) 
    { 
        if(Prime(i)&&Prime(n-i)) 
           printf("%d=%d+%d\n",n,i,n-i);
    } 
} 