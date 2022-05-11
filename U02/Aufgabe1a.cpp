/*PSEUDOCODE:
 *berechne_C(n)
 *	if n==1
 *		return 1
 *	else
 *		return ( (4*n-2)/(n+1) ) * berechne_Cn(n-1)
 */

#include <stdio.h>

int berechne_Cn(const int n)
{
	if(n==1)
		return 1;
	else
		return ( (4*n-2)/(n+1) ) * berechne_Cn(n-1);
}

int main()
{
	printf("%d", berechne_Cn(5) );		//Testlauf
	return 0;
}

