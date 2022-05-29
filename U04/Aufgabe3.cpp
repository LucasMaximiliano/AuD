/*
* SKIZZE:
* 1) kleinster Element suchen;
* 2) zu pos 0 schieben (vertauschen von Elementen);
* 3) rekursiv wiederholen (mit verbleibenden array der Groesse n-1);
* 
* PSEUDOCODE:
* void selectionSort(*a,n)
*       if(n==0)
*           return
*       else
*           //Nach kleinster Element suchen:
*           smallestPos = 0
*           smallest = a[0]
*           for(i=1;i<n;i++)
*               if(a[i]<smallest)
*                   smallestPos = i
*                   smallest = a[i]
*           // Elemente tasuchen:
*           buff = a[0]
*           a[0] = smallest
*           a[i] = buff
*           // Rekursionsaufruf:
*           selectionSort(a+1,n-1)  
*/

#include <stdio.h>

void print(const int* a, const int n)
{
    printf("[ ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void selectionSort(int* a, const int n)
{
    if(n==0)
        return;
    else
    {
        //Nach kleinster Element suchen:
        int smallestPos = 0;
        int smallest = a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i]<smallest)
            {
                smallestPos = i;
                smallest = a[i];
            }
        }
        // Elemente tasuchen:
        int buff = a[0];
        a[0] = smallest;
        a[smallestPos] = buff;
        // Rekursionsaufruf:
        selectionSort(a+1,n-1);
    }
}

int main()
{
    int arr[] = {5, 7, 4, 3, 2, 9, 1, 6};
    selectionSort(arr,8);
    print(arr,8);
    return 0;
}