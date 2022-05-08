/*
PSEUDOCODE:
reverse(array, laenge)
    for(i=0; i<laenge/2; i--)
        buff = array[laenge-i]
        array[laenge-i] = array[i]
        array[i] = buff
*/

#include <stdio.h>

void reverse_iterative(int* array, const int laenge)
{
    for(int i=0; i<(laenge/2); i++)
    {
        int buff = array[laenge-1-i];
        array[laenge-1-i] = array[i];
        array[i] = buff;
    }
}

void reverse_recursive(int* array, const int laenge)
{
    static int org_laenge = laenge;
    if(laenge == org_laenge/2)
        return;
    else
    {
        static int count = 0;
        int buff = array[laenge-1];
        array[laenge-1] = array[count];
        array[count] = buff;
        count++;
        reverse_recursive(array, laenge-1);
    }
}

int main()
{
    int a[5] = {0, 7, 12, 53, -40};         //Testlauf 1
    reverse_iterative(a, 5);
    for(int i=0; i<5; i++)
    {
        printf("%d ", a[i]);
    }

    int b[5] = {24, -30, -4, 75, 280};       //Testlauf 2
    reverse_recursive(b, 5);
    for(int i=0; i<5; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}