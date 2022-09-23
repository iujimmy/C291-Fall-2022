#include <stdio.h>
#include <math.h>


int findNextPrime(int L, int R)
{
	for(int i = L; i <= R; i++)
	{
		for(int j = 2; j < 99; j++)
		{
			if(i % j != 0 && j != L)
			{
break;
			}
				return i;
		}
	}}

int factorial(int n)
{
	int total = 1;
	for(int i = 0; i < n; n++)
	{
		total = total * (n-i);
	}
	return total;
}

double computeSeries(int n,int L,int R, double seriesTotal)
{
	seriesTotal = 0;
	L = findNextPrime(L, R);
	
 	int pPart = (pow(n,n));
	seriesTotal += L;
	seriesTotal += pPart;

	computeSeries(n-1, L, R, seriesTotal);
	if(n == 0){
		return seriesTotal;
	}

}

void main()
{
	int X,n,L,R;

	printf("Enter value for X: ");
	scanf("%d",&X);
	printf("Enter value for n: ");
	scanf("%d",&n);
	printf("Enter value for L: ");
	scanf("%d",&L);
	printf("Enter value for R: ");
	scanf("%d",&R);

	double sumOfSeries = X;
	
	sumOfSeries += computeSeries(n,L,R, 0);

	printf("Sum of Series: %f", sumOfSeries);
}	
