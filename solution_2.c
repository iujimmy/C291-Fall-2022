
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
			printf("The needle cannot be found in the haystack.");
			memcpy(token,str,i+1);
			return token;
		}

	}
	return token;
}

int main(){
	printf("Haystack: ");
	char input[225] = {"0"};
	fgets(input, 225, stdin);
	printf("Needle: ");
	char delim[225] = {"0"};
	fgets(delim, 225, stdin);	
	
	char *tokenBefore  = 0;
	tokenBefore = myTokenizer(input, delim);
	int nextIndex = strlen(tokenBefore);
	printf("From Index: %d\n", nextIndex);
}
