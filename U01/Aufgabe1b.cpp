/*
PSEUDOCODE:
function(n)
    if(n=1)
        printf(1)
    else
        printf(n)
        function(n-1)
*/

#include<stdio.h>

void function(const int n)
{
    if(n==1)
        printf("%d", 1);
    else
    {
        printf("%d", n);
        function(n-1);
    }
}

int main()
{
    function(5);     //Testlauf
    
    return 0;
}