#include <stdio.h>

int main()
{
	char letter1 = 'a';
	char letter2 = 'a';

	for(int i = 0; i <26; i++)
	{
		for(int j = 0; j <26; j++){
			printf("www.%c%c.com\n",letter1,letter2);
			letter2 += 1;
		}
		letter1 += 1;
		letter2 = 'a';
	}
	return 1;
}
