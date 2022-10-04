#include <stdio.h>

#define NCOLS 4
void filterStudents(int students[][NCOLS], int minAge, int minYear, int minGrade)
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < NCOLS; j++)
		{
			if(students[i][1] <= minAge && minAge != -1) break;
			if(students[i][2] <= minYear && minYear != -1) break;
			if(students[i][3] <= minGrade && minGrade != -1) break;
			printf("%d\n", i+1);
			break;
		}
	}
}

void main()
{
	int students[5][NCOLS];
	int filters[3] = {0};

	students[0][0] = 1;
	students[0][1] = 18;
	students[0][2] = 11;
	students[0][3] = 90;
	students[1][0] = 2;
	students[1][1] = 16;
	students[1][2] = 10;
	students[1][3] = 75;
	students[2][0] = 3;
	students[2][1] = 15;
	students[2][2] = 9;
	students[2][3] = 85;
	students[3][0] = 4;
	students[3][1] = 10;
	students[3][2] = 10;
	students[3][3] = 60;
	students[4][0] = 5;
	students[4][1] = 11;
	students[4][2] = 9;
	students[4][3] = 60;

	printf("Please enter filters: \n");
	scanf("%d %d %d", &filters[0], &filters[1], &filters[2]);

	filterStudents(students, filters[0], filters[1], filters[2]);
}
