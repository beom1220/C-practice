#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int data;
	struct linked_list* next;
};
typedef struct linked_list NODE;
typedef NODE* LINK;

void addNode(int);
void printNode();
void searchNode(int);
void delNode(int);
int hit = 0;
int nodeEnd = 0;

LINK head = NULL;

void main() {
	int addNum, searchNum, delNum;

	//printf("%d, %d", head->next->data, head->next->next->data);
	for (int exeNum = 0; exeNum != 5;) {
		printf("**************************************\n");
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.종료 *\n");
		printf("**************************************\n");
		printf("실행할 번호를 입력하세요. : ");
		scanf("%d", &exeNum);
		printf("\n");
		switch (exeNum) {
		case 1: //입력
			printf("추가할 데이터값을 입력하세요. : ");
			hit = 0;
			scanf("%d", &addNum); printf("\n");
			addNode(addNum);
			//중복값 검사해서 못 넣게 해야 됨. 탐색 필요.
			break;
		case 2: //출력
			printNode();
			break;
		case 3: //검색
			printf("검색할 데이터값을 입력하세요. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum);
			break;
		case 4: //삭제
			printf("삭제할 데이터값을 입력하세요. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			delNode(delNum);
			break;
		case 5: //종료
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 입력값입니다. 1~5번 중 실행할 번호를 입력해주세요.\n");
			break;
		}
	}
};

void addNode(int num) {
	LINK curr = NULL;
	if (head == NULL) { //1. 비어있을 때 = head가 NULL일 때
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		curr = head;
		curr->next = NULL;
		printf("데이터가 입력되었습니다.\n\n");
	}
	else { //2. 안 비어있을 때
		curr = head;
		nodeEnd = 0;
		while (nodeEnd == 0) {
			if (curr->data == num) {
				hit = 1; // 중복 있다.
			}
			if (curr->next != NULL) {
				curr = curr->next;
			}
			else {
				nodeEnd = 1;
			}
		}
		if (hit == 0) {
			curr->next = (LINK)malloc(sizeof(NODE));
			curr = curr->next;
			curr->data = num;
			curr->next = NULL;
			printf("데이터가 입력되었습니다.\n\n");
		}
		else if (hit == 1) {
			printf("중복된 값은 입력할 수 없습니다.\n");
		}
	}
};

void printNode() {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("데이터를 출력합니다.\n");
		printf("데이터 : ");
		nodeEnd = 0;
		while (nodeEnd == 0) {
			printf("%d ", curr->data);
			if (curr->next != NULL) {
				curr = curr->next;
			}
			else {
				nodeEnd = 1;
			}
		} printf("\n\n");
	}
	else {
		printf("출력할 데이터값이 없습니다.\n");
	}
}

void searchNode(int num) {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		nodeEnd = 0;
		while (nodeEnd == 0) {
			if (curr->data == num) {
				hit = 1;
			}
			if (curr->next != NULL) {
				curr = curr->next;
			}
			else {
				nodeEnd = 1;
			}

		}
		if (hit == 1) {
			printf("검색한 값인 %d은(는) 데이터 내에 있습니다.\n", num);
		}
		else if (hit == 0) {
			printf("검색한 값인 %d은(는)데이터 내에 없습니다.\n", num);
		}
	}
	else {
		printf("저장된 데이터값이 없습니다.\n");
	}
}

void delNode(int num) { // 만약에 노드가 딱 하나면? 문제 없구나.
	LINK curr = NULL;
	LINK pre = head;
	if (head != NULL) {
		curr = head;
		nodeEnd = 0;
		while (nodeEnd == 0) {
			if (curr->data == num) {
				hit = 1;
			}
			if (curr->next != NULL) {
				curr = curr->next;
			}
			else {
				nodeEnd = 1;
				curr = head;
			}
		}
		if (hit == 1) {
			while (curr->data != num) {
				curr = curr->next;
			}
			if (head == curr) { // 첫 노드 삭제
				head = head->next;
				free(curr);
				printf("데이터값 중 %d을(를) 삭제하였습니다.\n", num);
			}
			else if (curr->next == NULL) { // 마지막 노드 삭제
				while (pre->next != curr) {
					pre = pre->next;
				}
				free(curr);
				pre->next = NULL;
				printf("데이터값 중 %d을(를) 삭제하였습니다.\n", num);
			}
			else {
				while (pre->next != curr) { // 중간 노드 삭제
					pre = pre->next;
				}
				pre->next = curr->next;
				free(curr);
				printf("데이터값 중 %d을(를) 삭제하였습니다.\n", num);
			}
		}
		else if (hit == 0) {
			printf("저장되지 않은 값은 삭제할 수 없습니다.\n");
		}
	}
	else {
		printf("저장된 데이터값이 없습니다.\n");
	}
}