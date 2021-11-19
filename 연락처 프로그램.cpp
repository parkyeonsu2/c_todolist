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
	printf("���ϴ� �۾��� �Է��Ͻÿ�.1)����ó �߰��ϱ� 2)����ó ��ȸ 3)����ó ���� 4)�����ϱ�\n");
	a=getchar();
	fflush(stdin);

	switch (a){
	case '1':
		printf("����ó�� �߰��մϴ�. ������ �Է��Ͻÿ�.\n");
		Insert(p);
		break;
	case '2':
		printf("����ó�� ��ȸ�մϴ�. ��ȸ�ϰ��� �ϴ� �� ������ �Է��Ͻÿ�.\n");
		Search(p);
		break;
	case '3':
		printf("����ó�� �����մϴ�. �����ϰ��� �ϴ� �� ������ �Է��Ͻÿ�:\n");
		Delete(p);
		break;
	case '4':
		printf("����ó ���α׷��� �����մϴ�.\n");
		break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�. 1)����ó �߰� 2)����ó ��ȸ 3)����ó ���� 4)����ó ���α׷� ����\n");
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

	printf("�̸�:");
	gets(p->name);
	printf("��ȭ��ȣ:");
	gets(p->number);
	printf("ī�װ� 1)���� 2)ģ�� 3)����");
	gets(p->kategorie);
	printf("�������: (�ִ� 25��)");
	gets(p->cation);
	printf("\n����� �Ϸ� �Ǿ����ϴ�.\n");
	for (;;){
	printf("���� ����Ͻðڽ��ϱ�?(Y|N)");
	b=getchar();
	fflush(stdin);
	if (b!='Y' && b!='y' && b!='N' && b!='n'){
	printf("�߸� �Է��ϼ̽��ϴ�.\n ���� ����Ϸ��� Y�� �����ּ���.\n");
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
	printf("������ ����� �̸��� �Է��Ͻÿ�:");
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
		printf("ã�� ����� �̸��� �Է��Ͻÿ�:");
		gets(_name);
	printf("|�ּҷ�|\n");
	printf("%-10","�̸�:");
	printf("%-11","��ȭ��ȣ");
	printf("%-2","ī�װ�");
	printf("%-50","�������");
	
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
