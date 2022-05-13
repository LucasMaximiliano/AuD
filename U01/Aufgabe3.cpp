/*
* BSP.:
* a = [ 3 -2 5 ]
* max_subarray = a (sum = 6)
* b = [ -20 9 -1 10 ]
* max_subarray = [ 9 -1 10 ] (sum = 18)
*
* PSEUDOCODE:
* max_subarray(*a,l)
*       best = a[0]
*       for(i=0 i<l i++)
*           partial_sum = 0
*           for(size_subarray=1 size_subarray<l size_subarray++)
*               for(j=i j<size_subarray j++)
*                   partial_sum += a[j]
*               if partial_sum>best
*                   best = partial_sum
*/

#include <stdio.h>

int max_subarray(int* array, int laenge)
{
    int best = array[0];
    for(int i=0; i<laenge; i++)
    {
        for(int size_subarray=1; size_subarray<=laenge; size_subarray++)
        {
            int partial_sum = 0;
            for(int j=i; j<size_subarray; j++)
            {
                partial_sum +=  array[j];
            }
            if(partial_sum>best)
                best = partial_sum;
        }
    }
    return best;
}

int main()
{
    int a[3] = {3,-2,5};
    int b[4] = {-20,9,-1,10};

    printf("%d\n", max_subarray(a,3) );
    printf("%d\n", max_subarray(b,4) );
    
    return 0;
}