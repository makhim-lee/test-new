#include<stdio.h>

typedef struct /*student*/{
	char name[21];
	int kor;
	int eng;
	int mat;
	int sum;
	double ave;
	int rank;
} Student;

int main(void)
{

	FILE * fin, *fout;
	fin = fopen("score.dat", "r");
	fout = fopen("score.out", "w");
	//struct student students[10];
	Student students[10];
	Student table[10];
	
	for (int i = 0; i < 10; ++i){
		fscanf(fin, "%s %d %d %d", 
			students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
		
		students[i].sum = students[i].kor + students[i].eng + students[i].mat;
		students[i].ave = (double)students[i].sum / 3.0;
		students[i].rank = 1;
	}
	//rank
	for (int i = 0; i <= 10; ++i){
		for (int j = 0; j <= 10; ++j){
			if (students[i].ave < students[j].ave){
				++students[i].rank;
			}
		} 
	}

	//sorting

	table[i] = &students[i];


	for (int i = 0; i < 10 - 1; ++i){
		for (int j = i + 1; j < 10; ++j){
			if (strcmp(table[i] -> name, table[j] -> name) > 0){
				Student *tem = table[i];
				table[j] = table[i];
				table[i] = tem;
			}
		} 
	}
			//	char tem = *students[j].name;
			//	*students[j].name = *students[i].name;
			//	*students[i].name = tem;     //배열의 선택한 엘리먼트만 바꿔짐 
	
	
	
	for (int i = 0; i < 10; ++i){
		fprintf(fout, "%-10s %3d %3d %3d %3d %6.2f %3d\n", table[i]->name, 
			table[i]->kor, table[i]->eng, table[i]->mat, table[i]->sum, 
			table[i]->ave, table[i]->rank);
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
