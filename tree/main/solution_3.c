#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * replaceAll(char * str, const char * target, char * replace)
{
	if(!str) return NULL;
	if(!target) return str;

	static char replaced[225] = {"0"};
	int strDelta = 0;	
	for(int i = 0; i < strlen(str) - 1; i++){
		for(int j = 0; j < strlen(target) - 1; j++)
		{
			if((*(str + i + j)) != (*(target + j))){
				break;
			}else if(j == (strlen(target) - 2)){
				//printf("Found one!\n");
				for(int k = 0; k < strlen(replace)-1; k++)
				{
					replaced[i+k] = *(replace + k);
				}
				i += strlen(replace);
				strDelta += (strlen(replace) - strlen(target));
			}
		}
		replaced[i] = *(str + i - strDelta);
	}
	return replaced;
}

int main(){
	printf("Enter a string: ");
	char input[225] = {"0"};
	fgets(input, 225, stdin);
	printf("Enter the target: ");
	char target[225] = {"0"};
	fgets(target, 225, stdin);	
	printf("Enter replacement: ");
	char replace[225] = {"0"};
	fgets(replace, 225, stdin);
	
	char * replaced = replaceAll(input, target, replace);
	printf("%s\n", replaced);
}
