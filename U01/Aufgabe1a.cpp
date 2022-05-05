/*
PSEUDOCODE:
function(n)
    if(n=1)
        printf(1)
    else
        function(n-1)
        printf(n)
*/

#include<stdio.h>

void function(const int n)
{
    if(n==1)
        printf("%d", 1);
    else
    {
        function(n-1);
        printf("%d", n);
    }
}

int main()
{
    function(5);     //Testlauf
    
    return 0;
}