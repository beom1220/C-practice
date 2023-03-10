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
			//�ߺ��� �˻��ؼ� �� �ְ� �ؾ� ��. Ž�� �ʿ�.
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
};

void addNode(int num) {
	LINK curr = NULL;
	if (head == NULL) { //1. ������� �� = head�� NULL�� ��
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		curr = head;
		curr->next = NULL;
		printf("�����Ͱ� �ԷµǾ����ϴ�.\n\n");
	}
	else { //2. �� ������� ��
		curr = head;
		nodeEnd = 0;
		while (nodeEnd == 0) {
			if (curr->data == num) {
				hit = 1; // �ߺ� �ִ�.
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
			printf("�����Ͱ� �ԷµǾ����ϴ�.\n\n");
		}
		else if (hit == 1) {
			printf("�ߺ��� ���� �Է��� �� �����ϴ�.\n");
		}
	}
};

void printNode() {
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("�����͸� ����մϴ�.\n");
		printf("������ : ");
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
		printf("����� �����Ͱ��� �����ϴ�.\n");
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
			printf("�˻��� ���� %d��(��) ������ ���� �ֽ��ϴ�.\n", num);
		}
		else if (hit == 0) {
			printf("�˻��� ���� %d��(��)������ ���� �����ϴ�.\n", num);
		}
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n");
	}
}

void delNode(int num) { // ���࿡ ��尡 �� �ϳ���? ���� ������.
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
			if (head == curr) { // ù ��� ����
				head = head->next;
				free(curr);
				printf("�����Ͱ� �� %d��(��) �����Ͽ����ϴ�.\n", num);
			}
			else if (curr->next == NULL) { // ������ ��� ����
				while (pre->next != curr) {
					pre = pre->next;
				}
				free(curr);
				pre->next = NULL;
				printf("�����Ͱ� �� %d��(��) �����Ͽ����ϴ�.\n", num);
			}
			else {
				while (pre->next != curr) { // �߰� ��� ����
					pre = pre->next;
				}
				pre->next = curr->next;
				free(curr);
				printf("�����Ͱ� �� %d��(��) �����Ͽ����ϴ�.\n", num);
			}
		}
		else if (hit == 0) {
			printf("������� ���� ���� ������ �� �����ϴ�.\n");
		}
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n");
	}
}