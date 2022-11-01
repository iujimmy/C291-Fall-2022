#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * myTokenizer(char * str, const char * delim)
{
	if(!str) return NULL;
	if(!delim) return str;

	static char token[225] = {"0"};	
	
//	printf("str len = %ld, and %ld\n", strlen(str), strlen(delim) - 1);
//	printf("with string = %s ", str);
	for(int i = 0; i < strlen(str) - 1; i++){
		for(int j = 0; j < strlen(delim) - 1; j++)
		{
			//printf("Checking %c = %c\n", *(str + i + j), *(delim + j));
			if(tolower(*(str + i + j)) != tolower(*(delim + j))){
				break;
			}else if(j == (strlen(delim) - 2)){
				//printf("Found one!\n");
				memcpy(token,str, i);
				printf("%s\n", token);
				return token;
			}
		}
		if(i == strlen(str) - 2)
		{		
			memcpy(token,str,i+1);
			printf("%s\n", token);
			return token;
		}

	}
	return token;
}

int main(){
	char input[225] = {"0"};
	printf("Please input string: ");
	fgets(input, 225, stdin);
	printf("Please input delimiter: ");	
	char delim[225] = {"0"};
	fgets(delim, 225, stdin);	
	
	char *token  = 0;
	token = myTokenizer(input, delim);
	int nextIndex = strlen(token) + strlen(delim) - 1;
	while(*(input + nextIndex) != 0)
	{
		token = myTokenizer(input + nextIndex, delim);
		nextIndex += strlen(token) + strlen(delim) - 1;
	}
	
}
