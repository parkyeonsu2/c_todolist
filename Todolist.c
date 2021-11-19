#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char list[10][100] = { 0, };	
	int sum = 0, a, end;
	do {
		printf_s("어떤 작업을 실행하시겠습니까? 1) todolist 작성 2) 완료된 일 삭제 3) list확인 4) 종료 >>");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf_s("할 일을 입력해주세요.(최대 10개. ';'을 입력하면 저장이 중지됩니다.)>>");
			for (int i = 0; i < 10; i++) {
				scanf_s("%s", list[i], 100);	
				if (list[i][0] == ';') {		
					printf_s("입력을 중단합니다.\n");
					break;

				}
				printf_s("%d) %s\n", i+1, list[i]);
			}
			break;
		case 2:
			printf_s("어떤 일을 완료하셨습니까?");
			scanf_s("%d", &end);
			list[end][0] = NULL;	
			sum += 1;
			break;
		case 3:
			printf_s("현재 남은 일을 출력합니다.\n");
			for (int i = 0; i < 10; i++) {
				printf_s("%d)%s\n", i+1, list[i]);	
			}
			break;
		case 4:
			printf_s("프로그램을 종료합니다.\n");
			printf_s("당신의 포인트는:%d\n", sum);
			int con;
			printf_s("지뢰찾기 게임을 진행하시겠습니까?(1.Y/2.N)>>");
			scanf_s("%d", &con);
			if (con == 1) {
				printf_s("지뢰찾기 게임을 시작하겠습니다.(소요 포인트: 5pt)\n");
			}
			else if(con==2) {
				printf_s("오늘도 수고하셨습니다.\n");
			}
			return 0;
		default:
			printf_s("다시 입력해주세요.\n");
			break;
		}
	} while (1 <= a < 5);
	
	return 0;
}