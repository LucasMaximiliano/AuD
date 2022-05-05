/*
PSEUDOCODE:
fakultaet(n)
    int x = 1
    for(i=n, i>1, i--)
        x *= i
    return x

binomial_koeffizient(n,k)
    n_fak = fakultaet(n)
    k_fak = fakultaet(k)
    n_minus_k_fak = fakultaet(n-k)
    return (n_fak)/(k_fak*n_minus_k_fak)
*/

#include<stdio.h>

int fakultaet(const int n)
{
    int x = 1;
    for(int i=n; i>1; i--)
        x *= i;
    return x;
}

int binomial_koeffizient(const int n, const int k)
{
    int n_fak = fakultaet(n);
    int k_fak = fakultaet(k);
    int n_minus_k_fak = fakultaet(n-k);
    return (n_fak)/(k_fak*n_minus_k_fak);
}

int main()
{
    int x = binomial_koeffizient(5,3);      //Testlauf
    printf("%d", x);

    return 0;
}