/*
PSEUDOCODE:
reverse(array, laenge)
    for(i=0; i<laenge/2; i--)
        buff = array[laenge-i]
        array[laenge-i] = array[i]
        array[i] = buff
*/

#include <stdio.h>

void reverse(int* array, const int laenge)
{
    for(int i=0; i<(laenge/2); i++)
    {
        int buff = array[laenge-1-i];
        array[laenge-1-i] = array[i];
        array[i] = buff;
    }
}

int main()
{
    int a[5] = {0, 7, 12, 53, -40};      //Testlauf
    reverse(a, 5);
    for(int i=0; i<5; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}