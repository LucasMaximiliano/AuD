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
 *      else
 *          if(ptr1->next!=NULL && ptr2->next!=NULL)
 *          	equal(ptr1->next,ptr2->next)
 *	    else
 *	    	return true
 * c)
 * sum(ptr1,ptr2)
 * 	if(ptr1->next!=NULL && ptr2->next!=NULL)
 * 		if(ptr1->koeff + ptr2->koeff != 0)
 * 			new_p = new PolynomNode(ptr1->koeff + ptr2->koeff, ptr1->exp, NULL)
 * 			append(p_head,new_p)
 * 			sum(ptr1->next, ptr2->next)
 * 	else
 * 		
 * 		new_p = new PolynomNode(ptr1->koeff + ptr2->koeff, ptr1->exp, NULL)
 * 		append(p_head,new_p)
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

//HILFSFUNKTIONEN IMPLEMENTIEREN:
int length(PolynomNode* &ptr)
{
	if(ptr->next==NULL)
		return 1;
	else
		return 1+length(ptr->next);
}

//FUNKTION IMPLEMENTIERUNGEN:
int get(PolynomNode* &ptr, const int x)
{
    if(ptr->next==NULL)
        return (ptr->koeff)*pow(x,ptr->exp);
    else
        return (ptr->koeff)*pow(x,ptr->exp) + get(ptr->next,x);
}

bool equal(PolynomNode* &ptr1, PolynomNode* &ptr2)
{
	if(length(ptr1)!=length(ptr2) )
		return false;
	if(ptr1->koeff!=ptr2->koeff)
		return false;
	else
	{
		if(ptr1->next!=NULL && ptr2->next!=NULL)
		{
			return equal(ptr1->next,ptr2->next);	//Endrekursion
		}
		else
			return true;
	}
}


PolynomNode* sum(PolynomNode* &ptr1, PolynomNode* &ptr2)
{
	if(ptr1->next!=NULL && ptr2->next!=NULL)
	{
 		if(ptr1->koeff + ptr2->koeff != 0)
		{
 			PolyomNode* new_p = new PolynomNode(ptr1->koeff + ptr2->koeff, ptr1->exp, NULL);
 			//...
			help_sum(ptr1->next, ptr2->next, &new_p);
		}
	}
	else 		
		

	return &new_p;
}

//MAIN:
int main()
{
    struct PolynomNode p3(3,3,NULL);
    struct PolynomNode p2(2,2,&p3);
    struct PolynomNode p1(1,1,&p2);
    struct PolynomNode *pol1 = &p1;     //Polynom: p = x + 2x² + 3x³

    printf("%d\n", get(pol1,2) );


    struct PolynomNode p6(3,3,NULL);
    struct PolynomNode p5(2,2,&p6);
    struct PolynomNode p4(1,1,&p5);
    struct PolynomNode *pol2 = &p4;     //pol1 == pol2
    printf("%d\n", equal(pol1,pol2) );

    struct PolynomNode p9(6,3,NULL);
    struct PolynomNode p8(5,2,&p9);
    struct PolynomNode p7(4,1,&p8);
    struct PolynomNode *pol3 = &p7;     //pol1 != pol3
    printf("%d\n", equal(pol1,pol3) );
    
    struct PolynomNode p10(10,1,NULL);
    struct PolynomNode *pol4 = &p10;     //pol1 != pol4
    printf("%d\n", equal(pol1,pol4) );
    
    

    return 0;
}
