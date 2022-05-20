#include <stdio.h>
#include <math.h>

//FUNKTION DEFINITIONEN:
int g_tailrec(int x, int y, int sum);
int g_tailrec(int x, int y);
int g_iterativ(int x, int y);

//FUNKTION IMPLEMENTIERUNGEN:
int g_tailrec(int x, int y, int sum)
{
    if(x<10)
        return sum + pow(x,y);
    else
        return g_tailrec(x/10,y+1,sum+pow(x%10,y) );
}

int g_tailrec(int x, int y)
{
    return g_tailrec(x,y,0);
}

int g_iterativ(int x, int y)
{
    int sum = 0;
    while(x>=0)
    {
        sum += pow(x%10,y);
        y++;
        x/10;
    }
    sum += pow(x,y);
    return sum;
}

int main()
{
    printf("%d, %d, %d\n", g_tailrec(11,1), g_tailrec(20,2), g_tailrec(15,5));      //Testlaeufe
    printf("%d, %d, %d\n", g_iterativ(11,1), g_iterativ(20,2), g_iterativ(15,5));
    return 0;
}