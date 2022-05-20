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
 * 	...direkt in Code geschriben...
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

void loeschen(PolynomNode* &ptr, const int n)
{
    //...
}

void print(PolynomNode* &ptr)
{
    if(ptr==NULL)
        printf("NULL\n");
    else if(ptr->next==NULL)
        printf("%dx^%d\n", ptr->koeff, ptr->exp);
    else
    {
        printf("%dx^%d + ", ptr->koeff, ptr->exp);
        print(ptr->next);
    }
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
    //Ende der Liste:
    if(ptr1==NULL && ptr2==NULL)
        return NULL;
    else
    {
        //Beide ptr existieren:
        if(ptr1!=NULL && ptr2!=NULL)
        {
            //exp sind gleich:
            if(ptr1->exp==ptr2->exp)
            {
                PolynomNode* new_p = new PolynomNode(ptr1->koeff + ptr2->koeff, ptr1->exp, NULL);
                return new_p->next = sum(ptr1->next,ptr2->next);
            }
            //Kleineres exp kommt zuerst:
            else if(ptr1->exp < ptr2->exp)
            {
                //Kleineres ptr wird verschoeben; anderer bleibt:
                PolynomNode* new_p = new PolynomNode(ptr1->koeff, ptr1->exp, NULL);
                return new_p->next = sum(ptr1->next,ptr2);
            }
            else
            {
                //Kleineres ptr wird verschoeben; anderer bleibt:
                PolynomNode* new_p = new PolynomNode(ptr2->koeff, ptr2->exp, NULL);
                return new_p->next = sum(ptr1,ptr2->next);
            }
        }
        //ptr1 existiert:
        else if(ptr1!=NULL)
        {
            //Restliste von ptr1 kopieren:
            PolynomNode* new_p = new PolynomNode(ptr1->koeff, ptr1->exp, NULL);
            return new_p->next = sum(ptr1->next,ptr2);
        }
        //ptr2 existiert:
        else
        {
            //Restliste von ptr2 kopieren:
            PolynomNode* new_p = new PolynomNode(ptr2->koeff, ptr2->exp, NULL);
            return new_p->next = sum(ptr1,ptr2->next);
        }
    }
}

PolynomNode* add(PolynomNode* &ptr1, PolynomNode* &ptr2)
{
    //Nullelemente loeschen:
    return loeschen(sum(ptr1,ptr2), 0);
}


//MAIN:
int main()
{
    struct PolynomNode p1(1,1,NULL);
    struct PolynomNode p2(2,2,&p1);
    struct PolynomNode p3(3,3,&p2);
    struct PolynomNode *pol1 = &p3;     //Polynom: pol1 = 3x³ + 2x² + x

    printf("%d\n", get(pol1,2) );


    struct PolynomNode p4(1,1,NULL);
    struct PolynomNode p5(2,2,&p4);
    struct PolynomNode p6(3,3,&p5);
    struct PolynomNode *pol2 = &p6;     //pol1 == pol2
    printf("%d\n", equal(pol1,pol2) );

    struct PolynomNode p7(4,1,NULL);
    struct PolynomNode p8(5,2,&p7);
    struct PolynomNode p9(6,3,&p8);
    struct PolynomNode *pol3 = &p9;     //pol1 != pol3 (6x³ + 5x² + 4x)
    printf("%d\n", equal(pol1,pol3) );
    
    struct PolynomNode p10(10,1,NULL);
    struct PolynomNode *pol4 = &p10;     //pol1 != pol4 (10x)
    printf("%d\n", equal(pol1,pol4) );
    

    struct PolynomNode *pol5 = sum(pol3,pol4);      //pol5 = pol3 + pol4 (14x)
    print(pol5);

    struct PolynomNode p11(-4,1,NULL);
    struct PolynomNode p12(-5,2,&p11);
    struct PolynomNode p13(-6,3,&p12);
    struct PolynomNode *pol6 = &p13;     //pol6 = -pol3
    struct PolynomNode *pol7 = sum(pol3,pol6);      //pol7 = pol3 + pol6 (NULL)
    print(pol7);

    return 0;
}
//marco.nanka