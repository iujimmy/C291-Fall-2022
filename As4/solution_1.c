#include <stdio.h>
#include <math.h>

int Factorial(int x)
{
	if(x < 1) return 0;
	for(int i = x; i > 1; i--)
	{
		x *= (i - 1);
	}
	return x;
}

int main()
{
	float k, n, p = 0;

	printf("Enter k value: ");
	scanf("%e", &k);
	printf("Enter n value: ");
	scanf("%e", &n);
	printf("Enter p value: ");
	scanf("%e", &p);

	double fKNP = pow((double)(p),(double)(k));
	fKNP = fKNP * pow((double)(1-p),(double)(n-k));
	
	double fact = Factorial(n) / (Factorial(k)*(Factorial(n-k)));
	fKNP = fKNP * fact;

	printf("The answer is: %f \n", fKNP);

}
