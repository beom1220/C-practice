#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int data;
	struct linked_list* next;
	struct linked_list* pre;

};
typedef struct linked_list NODE;
typedef NODE* LINK;

void addNode(int);
void printNode();
void searchNode(int);
void delNode(int);
int hit = 0;

LINK head = NULL;

void main() {
	int addNum, searchNum, delNum;

	for (int exeNum = 0; exeNum != 5;) {
		printf("**************************************\n");
		printf("*     이중 연결리스트 관리시스템     *\n");
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
}

void addNode(int num) {
	LINK curr = NULL;
	if (head == NULL) { // 1) 비어있을 때
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		head->next = NULL;
		head->pre = NULL;
		printf("데이터가 입력되었습니다.\n\n");
	}
	else { // 2) 안 빔
		curr = head;
		while (curr->next != NULL) {
			if (curr->data == num) {
				hit = 1; // 중복 있다
			}
			curr = curr->next;
		}
		if (curr->data == num) {
			hit = 1; // 마지막 노드가 중복
		}
		if (hit == 0) {
			curr->next = (LINK)malloc(sizeof(NODE));
			curr->next->data = num;
			curr->next->next = NULL;
			curr->next->pre = curr;
		}
		else {
			printf("중복된 값은 입력할 수 없습니다.\n");
		}
	}
}

void printNode() {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("데이터를 출력합니다.\n");
		printf("데이터 : ");
		while (curr->next != NULL) {
			printf("%d <-> ", curr->data);
			curr = curr->next;
		}
		printf("%d\n\n", curr->data);
	}
	else {
		printf("출력할 데이터값이 없습니다.\n\n");
	}
}

void searchNode(int num) {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
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
		printf("저장된 데이터값이 없습니다.\n\n");
	}
}

void delNode(int num) {
	LINK curr = head;
	if (head != NULL) {
		while (curr->next != NULL) {
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
			if (head == curr) { // 첫 노드 삭제
				if (head->next == NULL) { // 노드가 딱 하나
					head = NULL;
					free(curr);
				}
				else { // 노드가 여러개
					head = curr->next;
					curr->next->pre = NULL;
					free(curr);
				}
			}
			else if (curr->next == NULL) { // 끝 노드 삭제
				curr->pre->next = NULL;
				free(curr);
			}
			else { // 중간 노드 삭제
				curr->pre->next = curr->next;
				curr->next->pre = curr->pre;
				free(curr);
			}
		}
	}
	else {
		printf("저장된 데이터값이 없습니다.\n\n");
	}
}