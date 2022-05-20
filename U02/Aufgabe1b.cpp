/*PSEUDOCODE:
 *pi(n)
 *	if(n==0)
 *		return 0
 *	else if(n%2==0)
 *		return 4/(2*n+1) + pi(n-1)
 *	else
 *		return -4/(2*n+1) + pi(n-1)
 */

#include <stdio.h>
#include <math.h>

/*
MEINE LOESUNG (NICHT OPTIMAL):
float pi(const int n)
{
	if(n==0)
		return 4;
	else if(n%2==0)
		return 4.0/(2*n+1) + pi(n-1);
	else
		return -4.0/(2*n+1) + pi(n-1);
}
*/

float pi(const int n)
{
	if(n==0)
		return 4;
	else
		return pow(-1,n) * 4.0/(2*n+1) + pi(n-1);
}

int main()
{
	printf("%f, %f, %f\n", pi(5.0), pi(10.0), pi(100.0) );	//Testlaeufe
	
	return 0;
}
