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
		printf("*     ���� ���Ḯ��Ʈ �����ý���     *\n");
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� *\n");
		printf("**************************************\n");
		printf("������ ��ȣ�� �Է��ϼ���. : ");
		scanf("%d", &exeNum);
		printf("\n");
		switch (exeNum) {
		case 1:
			printf("�߰��� �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &addNum); printf("\n");
			hit = 0;
			addNode(addNum);
			break;
		case 2:
			printNode();
			break;
		case 3:
			printf("�˻��� �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum);
			break;
		case 4:
			printf("������ �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			delNode(delNum);
			break;
		case 5:
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �Է°��Դϴ�. 1~5�� �� ������ ��ȣ�� �Է����ּ���.\n");
			break;
		}
	}
}

void addNode(int num) {
	//printf("�߰��� �� �Լ�");
	LINK curr = NULL;
	if (head == NULL) { // 1) ������� ��
		head = (LINK)malloc(sizeof(NODE));
		head->data = num;
		curr = head;
		curr->next = curr;
		printf("�����Ͱ� �ԷµǾ����ϴ�.\n\n");
	}
	else { // 2) �� ����� ��
		curr = head;
		while (curr->next != head) { // �� ������ ��� �˻� �� �ż� �Ʒ��� �ѹ� �� �־�����. �� ���� ��� �������� ����.
			if (curr->data == num) {
				hit = 1; // �ߺ� ����.
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
			printf("�����Ͱ� �ԷµǾ����ϴ�.\n\n");
		}
		else {
			printf("�ߺ��� ���� �Է��� �� �����ϴ�.\n");
		}
	}
}

void printNode() {
	//printf("��¿� �� �Լ�");
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		printf("�����͸� ����մϴ�.\n");
		printf("������ : ");
		while (curr->next != head) { // �̷� ������ ���� �� ������ ��� �� �ż� �Ʒ��� �ѹ� �� �ֱ� �ߴµ�, �� ���� ��� ������ �����غ���.
			printf("%d -> ", curr->data);
			curr = curr->next;
		}
		printf("%d", curr->data);
		printf("\n\n");
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n");
	}
}

void searchNode(int num) {
	//printf("�˻��� �� �Լ�");
	LINK curr = NULL;
	if (head != NULL) {
		curr = head;
		while (curr->next != head) { // �̷� ������ ���� �� ������ �˻簡 �� �ż� �Ʒ��� �ѹ� �� �ֱ� �ߴµ�, �� ���� ��� ������ �����غ���.
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
		printf("����� �����Ͱ��� �����ϴ�.\n");
	}
}

void delNode(int num) {
	//printf("������ �� �Լ�");
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
				//ù ��� ����
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
				printf("�����Ͱ� �� %d��(��) �����Ͽ����ϴ�.\n", num);
			}
			else {
				//��
				while (pre->next != curr) {
					pre = pre->next;
				}
				pre->next = curr->next;
				free(curr);
				printf("�����Ͱ� �� %d��(��) �����Ͽ����ϴ�.\n", num);
			}
		}
		else {
			printf("������� ���� ���� ������ �� �����ϴ�.\n");
		}
	}
	else {
		printf("����� �����Ͱ��� �����ϴ�.\n");
	}
}