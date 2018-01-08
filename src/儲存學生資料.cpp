/*
姓名 : 黃羿豪 
學號 : D0542487 
撰寫日期 : 2017/10/13
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>
//student結構 姓名 學號 成績 
typedef struct student{
	char name[10];
	char id[10];
	int grade;
}stu;
//新增學生資料 
void add(stu* s){
	printf("請輸入學生姓名 : \n");
	scanf("%s", s->name);
	fflush(stdin);
	printf("請輸入學生學號 : \n");
	scanf("%s", s->id);
	fflush(stdin);
	printf("請輸入學生成績 : \n");
	scanf("%d", &s->grade);
	fflush(stdin);
	while(s->grade < 0 || s->grade > 100){
		printf("輸入錯誤!!\n");
		printf("請輸入學生成績 : \n");
		scanf("%d", &s->grade);
		fflush(stdin);
	}
	printf("\n");
}
//印出所有學生 姓名+成績 
void print(stu s[], int sum){
	int i;
	for(i = 0 ; i < sum ; i++){
		printf("姓名 : %s\n", s[i].name);
		printf("成績 : %d\n\n", s[i].grade);
	}
}
//印出平均分數 
void printavg(stu s[], int sum){
	int i, gradeSum = 0;
	if(sum == 0){
		printf("目前無學生資料!!\n\n");
	}
	else{
		for(i = 0 ; i < sum ; i++){
			gradeSum += s[i].grade;
		}
		printf("平均成績 : %.1f\n\n", (float)gradeSum/sum);
	}
}
int main(){
	int flag = 0, stuSum = 0, i;
	stu *studentList;
	studentList = (stu*)malloc(stuSum*sizeof(stu));
	while(flag != 3){
		printf("請輸入指令 : \n1.新增學生成績\n2.印出所有學生成績及平均分數\n3.離開程式\n");
		scanf("%d", &flag);
		fflush(stdin);
		switch (flag){
			case 1 : //動態增加陣列大小 
				if(stuSum >= 100){
					printf("達到100名學生上限!!\n\n");
					break;
				}
				stuSum++;
				studentList = (stu*)realloc(studentList, stuSum*sizeof(stu));
				add(&studentList[stuSum-1]);
				break;
			case 2 : //印出成績及平均分數 
				print(studentList, stuSum);
				printavg(studentList, stuSum);
				break;
			case 3 : //釋放記憶體, 離開 
				free(studentList);
				return 0;
			default :  
				printf("錯誤指令 ! \n\n");
		}
	}
	return 0;
}

