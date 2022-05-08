/*
SKIZZE:
a = [ a0 a1 a2 ... aN ]
sub = aI - aJ
Falls abs(aI - aJ) < sub --> sub = aI - aJ
PSEUDOCODE:
sub = a[0]-a[1];
for(i=0; i<n; i++)
    for(j=0; j<n; j++)
        if(i!=j && abs(a[i]-a[j]<sub))
            sub = a[i] - a[j]
*/

#include <stdio.h>
#include <math.h>

int abs_min_diff(const int* array, const int laenge)
{
    int sub = array[0] - array[1];
    for(int i=0; i<laenge; i++)
    {
        for(int j=0; j<laenge; j++)
        {
            if(i!=j && abs(array[i]-array[j]<sub))
                sub = array[i] - array[j];
        }
    }
    return sub;
}

int main()
{
    int a[5] = {0, 7, 12, 53, -40};      //Testlauf
    int x = abs_min_diff(a, 5);
    printf("%d", x);

    return 0;
}