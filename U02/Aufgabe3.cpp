/* PSEUDOCODE:
 * g_tailrec(x,y)
 *      if x<10
 *          return pow(x,y)
 *      else
 *          static sum
 *          return helper(x,y,sum)
 * 
 * helper(x,y,sum)
 *      return sum = pow(x%10,y) + g_tailrec(x/10,y+1)
 */

#include <stdio.h>
#include <math.h>

//FUNKTION DEFINITIONEN:
int helper(int x, int y, int sum);
int g_tailrec(int x, int y);

//FUNKTION IMPLEMENTIERUNGEN:
int helper(int x, int y, int sum)
{
    return sum = pow(x%10,y) + g_tailrec(x/10,y+1);
}

int g_tailrec(int x, int y)
{
    if(x<10)
        return pow(x,y);
    else
    {
        static int sum;
        return helper(x,y,sum);
    }
}

int main()
{
    printf("%d, %d, %d\n", g_tailrec(11,1), g_tailrec(20,2), g_tailrec(15,5));      //Testlaeufe
    return 0;
}