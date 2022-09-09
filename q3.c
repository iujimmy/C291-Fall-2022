#include <stdio.h>

#include <math.h>
int main()
{
	int num1, num2;
	char space1, space2, operator;
	scanf("%d%c%c%c%d",&num1,&space1,&operator,&space2,&num2);


	if(operator == '+'){
	       	printf("%d\n", num1 + num2);
}
	if(operator == '-'){
	       	printf("%d\n", num1 - num2);}
	if(operator == '*'){ printf("%d\n", num1 * num2);}
	if(operator == '/'){ printf("%d\n", num1 / num2);}
	if(operator == '%'){ printf("%d\n", num1 % num2);}
	if(operator == '^'){ printf("%f\n", pow(num1,num2));}
	
	if(operator == 'r'){ printf("%f\n",pow(num2, 1/num1));
	}
}
