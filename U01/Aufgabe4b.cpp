/*
PSEUDOCODE:
binomial_koeffizient(n,k)
    if(n==k || k==0)
        return 1;
    else
        return binomial_koeffizient(n-1,k-1) + binomial_koeffizient(n-1,k)
*/

#include<stdio.h>

int binomial_koeffizient(const int n, const int k)
{
    if(n==k || k==0)
        return 1;
    else
        return binomial_koeffizient(n-1,k-1) + binomial_koeffizient(n-1,k);
}

int main()
{
    int x = binomial_koeffizient(5,3);
    printf("%d", x);

    return 0;
}