#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct phone {
char name[10];
char number[11];
char kategorie[2];
char cation[50];
struct phone *point;
};
typedef struct phone phone1;
void Insert(phone1*);
void Search(phone1*);
void Delete(phone1*);
void Display(phone1*);

int main(void){
	phone1 *p;
	int a;
	p=(phone1*)malloc(sizeof(phone1));
	p->point=NULL;
	do{
	printf("원하는 작업을 입력하시오.1)연락처 추가하기 2)연락처 조회 3)연락처 삭제 4)종료하기\n");
	a=getchar();
	fflush(stdin);

	switch (a){
	case '1':
		printf("연락처를 추가합니다. 정보를 입력하시오.\n");
		Insert(p);
		break;
	case '2':
		printf("연락처를 조회합니다. 조회하고자 하는 분 성함을 입력하시오.\n");
		Search(p);
		break;
	case '3':
		printf("연락처를 삭제합니다. 삭제하고자 하는 분 성함을 입력하시오:\n");
		Delete(p);
		break;
	case '4':
		printf("연락처 프로그램을 종료합니다.\n");
		break;
	default:
		printf("잘못 입력하셨습니다. 1)연락처 추가 2)연락처 조회 3)연락처 삭제 4)연락처 프로그램 종료\n");
	}
	}while (1<=a<5);
}
	void Insert(phone1 *p){
	int b;
	while (p->point!=NULL)
		p=p->point;
	do{
	p->point=(phone1*)malloc(sizeof(phone1));
	p=p->point;

	printf("이름:");
	gets(p->name);
	printf("전화번호:");
	gets(p->number);
	printf("카테고리 1)가족 2)친구 3)지인");
	gets(p->kategorie);
	printf("참고사항: (최대 25자)");
	gets(p->cation);
	printf("\n등록이 완료 되었습니다.\n");
	for (;;){
	printf("새로 등록하시겠습니까?(Y|N)");
	b=getchar();
	fflush(stdin);
	if (b!='Y' && b!='y' && b!='N' && b!='n'){
	printf("잘못 입력하셨습니다.\n 새로 등록하려면 Y를 눌러주세요.\n");
	continue;
	}
	else
		break;
	}
	}while (b!='n' && b!='N');
	
	p->point=NULL;
	printf("\n");
	}
	void Delete (phone1 *p){
	phone1 *temp;
	char _name[10];
	printf("삭제할 사람의 이름을 입력하시오:");
	gets(_name);
	while (p->point!=NULL){
	temp=p;
	p=p->point;
	if (strcmp(_name, p->name)==0){
	temp->point=p->point;
	free(p);
	break;
	}
	}
	}
	void Search(phone1 *p){
		char _name[10];
		printf("찾을 사람의 이름을 입력하시오:");
		gets(_name);
	printf("|주소록|\n");
	printf("%-10","이름:");
	printf("%-11","전화번호");
	printf("%-2","카테고리");
	printf("%-50","참고사항");
	
	while (p!=NULL){
	if (strcmp(_name,p->name)==0){
	printf("%-10s",p->name);
	printf("%-11s",p->number);
	printf("%-2s",p->kategorie);
	printf("%-50s",p->cation);
	printf("\n \n");
	}
	p=p->point;
	}
	}
