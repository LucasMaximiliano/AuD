/* PSEUDOCODE:
 * binomial_koeffizient(n,k)
 * 	if n==k || k==0
 * 		return 1
 * 	else
 * 		ergebnisse[n][k]
 * 		if ergebnisse[n][k] != 0
 * 			return ergebnisse[n][k]
 * 		else
 * 			return ergebnisse[n][k] = binomial_koeffizient(n-1,k-1) + binomial_koeffizient(n-1,k)
 */

#include <stdio.h>

long long binomial_koeffizient(const int n, const int k)
{
	if(n==k || k==0)
		return 1;
	else
	{
		static long long ergebnisse[1000][1000];	//[0] wird nicht benutzt
		if(ergebnisse[n][k]!=0)
			return ergebnisse[n][k];
		else
			return ergebnisse[n][k] = binomial_koeffizient(n-1,k-1) + binomial_koeffizient(n-1,k);
	}
}

int main()
{
	printf("%d", binomial_koeffizient(5,3) );	//Testlauf
	return 0;
}
