#include <stdio.h>
#include <string.h>
char * searchEngine(char ** documents, char * query, int S)
{
 	static char info[225] = {};	
	for(int i = 0; i < S; i++)
	{
		*(info + i) = *(*documents + i);
	}
	return info;
}
int main()
{
	char * documents[4] = {"Located in Bloomington, Indiana, the campus of IU Bloomington is home to an extensive student life program. The university campus is 1937 acres, the largest of any university in Indiana. The university has a student count of over 45000. The campus is where a student takes classes, just like any other campus.",
"The  campus  rests  on  a  bed  of  Indiana  limestone,  along  with  the  rest  of Bloomington and southern Indiana. The Bryan house is the campus home of the university president. To a student and a faculty member alike, Indiana University has a campus that is rich with green space and historic buildings. Bloomington, Indiana is located in Southern Indiana.",
"The  Indiana  Memorial  Union  in  Bloomington  is  the  second  largest  student union in the world. It features a student activities tower, which houses a variety of student  organizations.  The  University  campus  is  centered  around  this  student union. The Campus has an extensive bus system.",
"The  Luddy  School  of  Informatics,  Computing,  and  Engineering  is  a  school within Indiana University. A student can major in fields such as Informatics and Computer Science. The student count has grown greatly in the past few years, and  LuddyHall  was  built  on  Indiana  University  campus  in  2018.  Indiana University does not have a mascot. The university is known for its Sample Gates."};

	printf("Query: ");
	char query[225] = {"0"};
	fgets(query, 225, stdin);
	printf("Enter the number of chars to return: ");
	int S;
	scanf("%d", &S);

	char * results = searchEngine(documents, query, S);
	printf("%s\n", results);
}
