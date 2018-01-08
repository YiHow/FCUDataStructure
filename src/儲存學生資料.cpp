/*
�m�W : ������ 
�Ǹ� : D0542487 
���g��� : 2017/10/13
dev-cpp version : 5.11 
*/ 
#include <stdio.h>
#include <stdlib.h>
//student���c �m�W �Ǹ� ���Z 
typedef struct student{
	char name[10];
	char id[10];
	int grade;
}stu;
//�s�W�ǥ͸�� 
void add(stu* s){
	printf("�п�J�ǥͩm�W : \n");
	scanf("%s", s->name);
	fflush(stdin);
	printf("�п�J�ǥ;Ǹ� : \n");
	scanf("%s", s->id);
	fflush(stdin);
	printf("�п�J�ǥͦ��Z : \n");
	scanf("%d", &s->grade);
	fflush(stdin);
	while(s->grade < 0 || s->grade > 100){
		printf("��J���~!!\n");
		printf("�п�J�ǥͦ��Z : \n");
		scanf("%d", &s->grade);
		fflush(stdin);
	}
	printf("\n");
}
//�L�X�Ҧ��ǥ� �m�W+���Z 
void print(stu s[], int sum){
	int i;
	for(i = 0 ; i < sum ; i++){
		printf("�m�W : %s\n", s[i].name);
		printf("���Z : %d\n\n", s[i].grade);
	}
}
//�L�X�������� 
void printavg(stu s[], int sum){
	int i, gradeSum = 0;
	if(sum == 0){
		printf("�ثe�L�ǥ͸��!!\n\n");
	}
	else{
		for(i = 0 ; i < sum ; i++){
			gradeSum += s[i].grade;
		}
		printf("�������Z : %.1f\n\n", (float)gradeSum/sum);
	}
}
int main(){
	int flag = 0, stuSum = 0, i;
	stu *studentList;
	studentList = (stu*)malloc(stuSum*sizeof(stu));
	while(flag != 3){
		printf("�п�J���O : \n1.�s�W�ǥͦ��Z\n2.�L�X�Ҧ��ǥͦ��Z�Υ�������\n3.���}�{��\n");
		scanf("%d", &flag);
		fflush(stdin);
		switch (flag){
			case 1 : //�ʺA�W�[�}�C�j�p 
				if(stuSum >= 100){
					printf("�F��100�W�ǥͤW��!!\n\n");
					break;
				}
				stuSum++;
				studentList = (stu*)realloc(studentList, stuSum*sizeof(stu));
				add(&studentList[stuSum-1]);
				break;
			case 2 : //�L�X���Z�Υ������� 
				print(studentList, stuSum);
				printavg(studentList, stuSum);
				break;
			case 3 : //����O����, ���} 
				free(studentList);
				return 0;
			default :  
				printf("���~���O ! \n\n");
		}
	}
	return 0;
}

