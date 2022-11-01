#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char * parsedPart(char * xml, char * part)
{
	static char info[225] = {};
	int startIndex = 0;
	int endIndex = 0;
	bool startFound = false;
	bool endFound = false;
	for(int i = 0; i < strlen(xml) - 1; i++){
		for(int j = 0; j < strlen(part) - 1; j++)
		{
			if((*(xml + i + j)) != (*(part + j))){
				break;
			}else if(j == (strlen(part) - 2)){
				startIndex = i + j + 3;
				startFound = true;	
			}
		}
		if(startFound) break;
	}
	for(int i = startIndex; i < strlen(xml) - 1; i++){
		for(int j = 0; j < strlen(part) - 1; j++)
		{
			if((*(xml + i + j)) != (*(part + j))){
				break;
			}else if(j == (strlen(part) - 2)){
				endIndex = i - 2;	
				endFound = true;
			}
		}
		if(endFound) break;
	}
	for(int k = 0; k < endIndex-startIndex; k++)
	{
		printf("%c", *(xml + startIndex + k));
		*(info + k) = *(xml + startIndex + k);
	}
	return info;
}

void parseXML(char * xml, char * bookID)
{
	char * authorInfo = parsedPart(xml, "author");
	printf("%s", authorInfo);
}

int main(){
  char * xml = 
  "<?xml version=\"1.0\"?>\n<catalog>\n"
  "<book id=\"bk101\">\n"
     "<author>Gambardella, Matthew</author>\n"
     "<title>XML Developer's Guide</title>\n"
     "<genre>Computer</genre>\n"
     "<price>44.95</price>\n"
     "<publish_date>2000-10-01</publish_date>\n"
     "<description>An in-depth look at creating applications with XML.</description>\n"
  "</book>\n"
  "<book id=\"bk102\">\n"
     "<author>Cormen, Stein</author>\n"
     "<title>Introduction of Algorithm, fourth edition</title>\n"
     "<genre>Computer</genre>\n"
     "<price>84.89</price>\n"
     "<publish_date>2022-04-05</publish_date>\n"
     "<description>A comprehensive update of the leading algorithms text, with new material on matchings in bipartite graphs, online algorithms, machine learning, and other topics.</description>\n"
  "</book>\n"
  "<book id=\"bk103\">\n"
     "<author>Ryan, Carl</author>\n"
     "<title>Python Programming for beginners: A Crash Course</title>\n"
     "<genre>Computer</genre>\n"
     "<price>7.11</price>\n"
     "<publish_date>2022-01-19</publish_date>\n"
     "<description>The Ultimate Python guide for beginners!</description>\n"
  "</book>\n"
  "</catalog>"; 
 
//  for(int i=0; xmlString[i] != '\0'; i++)
//   printf("%c", xmlString[i]);
	char * id = "bk101";
	parseXML(xml, id);
}
