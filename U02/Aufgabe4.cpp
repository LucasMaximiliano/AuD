/* PSEUDOCODE:
 * a)
 * get(ptr,x)
 *      if(ptr->next==NULL)
 *          return (ptr->koeff)*pow(x,ptr->exp)
 *      else
 *          return (ptr->koeff)*pow(x,ptr->exp) + get(ptr->next,x)
 * b)
 * equal(ptr1,ptr2)                         //Liste nach aufsteigender exp geordnet
 *      if(length(ptr1)!=length(ptr2) )     //Unterschieldich gross
 *          return false
 *      if(ptr1->koeff!=ptr2->koeff)        //Unterschiedliche Koeffizienten
 *          return false
 *      if(ptr1->koeff==ptr2->koeff)
 *          equal(ptr1->next,ptr2->next)
 *      else
 *          return true
 * c)
 * sum(p1,p2)
 */

#include <stdio.h>
#include <math.h>

//DATENTYP DEFINITIONEN:
struct PolynomNode
{
    int koeff;
    int exp;
    struct PolynomNode* next;
    
    PolynomNode(int koeff_val, int exp_val, struct PolynomNode* next_val)
    {
        koeff = koeff_val; exp = exp_val; next = next_val;
    }
};

//FUNKTION IMPLEMENTIERUNGEN:
int get(PolynomNode* &ptr, const int x)
{
    if(ptr->next==NULL)
        return (ptr->koeff)*pow(x,ptr->exp);
    else
        return (ptr->koeff)*pow(x,ptr->exp) + get(ptr->next,x);
}

//HILFSFUNKTION IMPLEMENTIERUNGEN:


int main()
{
    struct PolynomNode p3(3,3,NULL);
    struct PolynomNode p2(2,2,&p3);
    struct PolynomNode p1(1,1,&p2);
    struct PolynomNode *p = &p1;     //Polynom: p = x + 2x² + 3x³

    printf("%d\n", get(p,2) );

    return 0;
}