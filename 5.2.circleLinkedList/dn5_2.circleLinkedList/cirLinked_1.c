#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int data;
	struct linked_list* next;
};
typedef struct linked_list NODE;
typedef NODE* LINK;

int hit = 0;
LINK head = NULL;
void addNode();
void printNode();
void searchNode();
void delNode();

void main() {
	int addNum, searchNum, delNum;
	for (int exeNum = 0; exeNum != 5;) {
		printf("**************************************\n");
		printf("*     원형 연결리스트 관리시스템     *\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.종료 *\n");
		printf("**************************************\n");
		printf("실행할 번호를 입력하세요. : ");
		scanf("%d", &exeNum);
		printf("\n");
		switch (exeNum) {
		case 1:
			printf("추가할 데이터값을 입력하세요. : ");
			scanf("%d", &addNum); printf("\n");
			hit = 0;
			addNode(addNum);
			break;
		case 2:
			printNode();
			break;
		case 3:
			printf("검색할 데이터값을 입력하세요. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum);
			break;
		case 4:
			printf("삭제할 데이터값을 입력하세요. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			delNode(delNum);
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 입력값입니다. 1~5번 중 실행할 번호를 입력해주세요.\n");
			break;
		}
	}
}

void addNode(int num) {
	//printf("추가에 쓸 함수");
	LINK curr = NULL;
	if (head == NULL) { // 1) 비어있을 때
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		curr = head;
		curr->next = curr;
		printf("데이터가 입력되었습니다.\n\n");
	}
	else { // 2) 안 비었을 때
		curr = head;
		while (curr->next != head) { // 맨 마지막 노드 검사 안 돼서 아래서 한번 더 넣어줬음. 더 좋은 방법 생각나면 수정.
			if (curr->data == num) {
				hit = 1; // 중복 있음.
			}
			curr = curr->next;
		}
		if (curr->data == num) {
			hit = 1;
		}
		if (hit == 0) {
			curr->next = (LINK)malloc(sizeof(NODE));
			curr = curr->next;
			curr->data = num;
			curr->next = head;
			printf("데이터가 입력되었습니다.\n\n");
		}
		else {
			printf("중복된 값은 입력할 수 없습니다.\n");
		}
	}
}

void printNode() {
	//printf("출력에 쓸 함수");
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("데이터를 출력합니다.\n");
		printf("데이터 : ");
		while (curr->next != head) { // 이런 식으로 돌면 맨 마지막 출력 안 돼서 아래서 한번 더 넣긴 했는데, 더 좋은 방법 없는지 생각해보자.
			printf("%d -> ", curr->data);
			curr = curr->next;
		}
		printf("%d", curr->data);
		printf("\n\n");
	}
	else {
		printf("출력할 데이터값이 없습니다.\n");
	}
}

void searchNode(int num) {
	//printf("검색에 쓸 함수");
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		while (curr->next != head) { // 이런 식으로 돌면 맨 마지막 검사가 안 돼서 아래서 한번 더 넣긴 했는데, 더 좋은 방법 없는지 생각해보자.
			if (curr->data == num) {
				hit = 1;
			}
			curr = curr->next;
		}
		if (curr->data == num) {
			hit = 1;
		}
		if (hit == 1) {
			printf("검색한 값인 %d은(는) 데이터 내에 있습니다.\n", num);
		}
		else {
			printf("검색한 값인 %d은(는) 데이터 내에 없습니다.\n", num);
		}
	}
	else {
		printf("저장된 데이터값이 없습니다.\n");
	}
}

void delNode(int num) {
	//printf("삭제에 쓸 함수");
	LINK curr = NULL;
	LINK pre = head;
	if (head != NULL) {
		curr = head;
		while (curr->next != head) {
			if (curr->data == num) {
				hit = 1;
			}
			curr = curr->next;
		}
		if (curr->data == num) {
			hit = 1;
		}
		curr = head;
		if (hit == 1) {
			while (curr->data != num) {
				curr = curr->next;
			}
			if (head == curr) {
				//첫 노드 삭제
				if (curr->next != curr) {
					while (pre->next != curr) {
						pre = pre->next;
					}
					head = head->next;
					pre->next = head;
					free(curr);
				}
				else {
					head = NULL;
					free(curr);
				}
				printf("데이터값 중 %d을(를) 삭제하였습니다.\n", num);
			}
			else {
				//외
				while (pre->next != curr) {
					pre = pre->next;
				}
				pre->next = curr->next;
				free(curr);
				printf("데이터값 중 %d을(를) 삭제하였습니다.\n", num);
			}
		}
		else {
			printf("저장되지 않은 값은 삭제할 수 없습니다.\n");
		}
	}
	else {
		printf("저장된 데이터값이 없습니다.\n");
	}
}