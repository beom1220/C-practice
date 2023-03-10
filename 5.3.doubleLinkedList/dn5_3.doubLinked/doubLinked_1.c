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
		printf("*     ���� ���Ḯ��Ʈ �����ý���     *\n");
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� *\n");
		printf("**************************************\n");
		printf("������ ��ȣ�� �Է��ϼ���. : ");
		scanf("%d", &exeNum);
		printf("\n");
		switch (exeNum) {
		case 1: //�Է�
			printf("�߰��� �����Ͱ��� �Է��ϼ���. : ");
			hit = 0;
			scanf("%d", &addNum); printf("\n");
			addNode(addNum);
			break;
		case 2: //���
			printNode();
			break;
		case 3: //�˻�
			printf("�˻��� �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum);
			break;
		case 4: //����
			printf("������ �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			delNode(delNum);
			break;
		case 5: //����
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �Է°��Դϴ�. 1~5�� �� ������ ��ȣ�� �Է����ּ���.\n");
			break;
		}
	}
}

void addNode(int num) {
	LINK curr = NULL;
	if (head == NULL) { // 1) ������� ��
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		head->next = NULL;
		head->pre = NULL;
		printf("�����Ͱ� �ԷµǾ����ϴ�.\n\n");
	}
	else { // 2) �� ��
		curr = head;
		while (curr->next != NULL) {
			if (curr->data == num) {
				hit = 1; // �ߺ� �ִ�
			}
			curr = curr->next;
		}
		if (curr->data == num) {
			hit = 1; // ������ ��尡 �ߺ�
		}
		if (hit == 0) {
			curr->next = (LINK)malloc(sizeof(NODE));
			curr->next->data = num;
			curr->next->next = NULL;
			curr->next->pre = curr;
		}
		else {
			printf("�ߺ��� ���� �Է��� �� �����ϴ�.\n");
		}
	}
}

void printNode() {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("�����͸� ����մϴ�.\n");
		printf("������ : ");
		while (curr->next != NULL) {
			printf("%d <-> ", curr->data);
			curr = curr->next;
		}
		printf("%d\n\n", curr->data);
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n\n");
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
			printf("�˻��� ���� %d��(��) ������ ���� �ֽ��ϴ�.\n", num);
		}
		else {
			printf("�˻��� ���� %d��(��) ������ ���� �����ϴ�.\n", num);
		}
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n\n");
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
			if (head == curr) { // ù ��� ����
				if (head->next == NULL) { // ��尡 �� �ϳ�
					head = NULL;
					free(curr);
				}
				else { // ��尡 ������
					head = curr->next;
					curr->next->pre = NULL;
					free(curr);
				}
			}
			else if (curr->next == NULL) { // �� ��� ����
				curr->pre->next = NULL;
				free(curr);
			}
			else { // �߰� ��� ����
				curr->pre->next = curr->next;
				curr->next->pre = curr->pre;
				free(curr);
			}
		}
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n\n");
	}
}