#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct binary_tree {
	int data;
	struct binary_tree* right;
	struct binary_tree* left;
};
typedef struct binary_tree NODE;

void addNode(int);
void printNode();
void prePrintNode(NODE*);
void inPrintNode(NODE*);
void postPrintNode(NODE*);
void searchNode(int, NODE*);
void delNode(int, NODE*, NODE*);
void degrZero();
void degrOne();
void degrTwo();
int hit = 0;

NODE* root = NULL;
NODE* temp = NULL;

void main() {
	int addNum, searchNum, delNum;

	for (int exeNum = 0; exeNum != 5;) {
		printf("**************************************\n");
		printf("*        ���� Ʈ�� �����ý���        *\n");
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
			if (root != NULL) {
				printNode();
			}
			else {
				printf("����� ���� �����ϴ�.\n\n");
			}
			break;
		case 3: //�˻�
			printf("�˻��� �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum, root);
			if (hit == 1) {
				printf("�˻��� ���� %d(��)�� ������ ���� �ֽ��ϴ�.\n\n", searchNum);
			}
			else {
				printf("�˻��� ���� %d(��)�� ������ ���� �����ϴ�.\n\n", searchNum);
			}
			break;
		case 4: //����
			printf("������ �����Ͱ��� �Է��ϼ���. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			NODE* curr = root;
			delNode(delNum, root, curr);
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
	NODE* curr = NULL;
	int leaf = 0;
	// �ƹ��͵� ���� �� �Է��̶� / ���� ���� �� �Է��� �ϴ� �и� => ��Ʈ ���η� �Ǵ��ؾ� �ϳ�
	if (root != NULL) { // �� ���� ��
		curr = root;
		while (leaf == 0) {
			if (curr->data > num) {
				if (curr->left != NULL) {
					curr = curr->left;
				}
				else {
					leaf = 1;
				}
			}
			else if (curr->data < num) {
				if (curr->right != NULL) {
					curr = curr->right;
				}
				else {
					leaf = 1;
				}
			}
			else {
				leaf = 1;
			}
		}
		if (curr->data > num) {
			curr->left = (NODE*)malloc(sizeof(NODE));
			curr->left->data = num;
			curr->left->right = NULL;
			curr->left->left = NULL;
			printf("�ԷµǾ����ϴ�.\n\n");
		}
		else if (curr->data < num) {
			curr->right = (NODE*)malloc(sizeof(NODE));
			curr->right->data = num;
			curr->right->left = NULL;
			curr->right->right = NULL;
			printf("�ԷµǾ����ϴ�.\n\n");
		}
		else {
			printf("�ߺ��� ���� �Է��� �� �����ϴ�.\n\n");
		}
	}
	else { // �� ���� ��
		root = (NODE*)malloc(sizeof(NODE));
		root->data = num;
		root->right = NULL;
		root->left = NULL;
		printf("�ԷµǾ����ϴ�.\n\n");
	}
}

void printNode() {
	printf("���� Ʈ�� ����� �����մϴ�.\n");
	printf("���� ��ȸ : ");
	prePrintNode(root);
	printf("\n");
	printf("���� ��ȸ : ");
	inPrintNode(root);
	printf("\n");
	printf("���� ��ȸ : ");
	postPrintNode(root);
	printf("\n");
}

void prePrintNode(NODE* start) {
	printf("%d ", start->data);
	if (start->left != NULL) {
		prePrintNode(start->left);
	}
	if (start->right != NULL) {
		prePrintNode(start->right);
	}
}

void inPrintNode(NODE* start) {
	if (start->left != NULL) {
		inPrintNode(start->left);
	}
	printf("%d ", start->data);
	if (start->right != NULL) {
		inPrintNode(start->right);
	}
}

void postPrintNode(NODE* start) {
	if (start->left != NULL) {
		postPrintNode(start->left);
	}
	if (start->right != NULL) {
		postPrintNode(start->right);
	}
	printf("%d ", start->data);
}

void searchNode(int num, NODE* start) {
	if (start->data == num) {
		hit = 1;
		temp = start;
	}
	if (start->left != NULL) {
		searchNode(num, start->left);
	}
	if (start->right != NULL) {
		searchNode(num, start->right);
	}
}

void delNode(int num, NODE* start) { // ���� ������ �� ���� �� �������� �ɷ� ����. (left �� ���� right ��) vs (right �� ���� left ��)
	// ��츦 �Ƹ�. 1) ��Ʈ�� ������ ��� / 2) ��Ʈ �ƴ� �� ������ ��� // ���� ������ ���� ������?
	hit = 0;
	int degree;
	searchNode(num, start);
	if (hit == 1) {
		if (temp->right == NULL && temp->left == NULL) {
			degree = 0;
		}
		else if (temp->right == NULL || temp->left == NULL) {
			degree = 1;
		}
		else {
			degree = 2;
		}

		if (degree == 0) {
			degrZero();
		}
		else if (degree == 1) {
			degrOne();
		}
		else if (degree == 2) {
			degrTwo();
		}
	}
	else {
		printf("����Ǿ� ���� ���� �������Դϴ�.\n\n");
	}
}

void degrZero() {
	int quit = 0;
	NODE* preTemp = NULL;

	if (root->data == temp->data) {
		root = NULL;
		free(temp);
	}
	else {
		preTemp = root;
		while (quit == 0) {
			if (preTemp->left != NULL && preTemp->right == NULL) {
				if (preTemp->left->data == temp->data) {
					quit = 1;
					preTemp->left = NULL;
					free(temp);
				}
				preTemp = preTemp->left;
			}
			else if (preTemp->right != NULL && preTemp->left == NULL) {
				if (preTemp->right->data == temp->data) {
					quit = 1;
					preTemp->right = NULL;
					(temp);
				}
				preTemp = preTemp->right;
			}
			else if (preTemp->right != NULL && preTemp->left != NULL) {
				if (preTemp->right->data == temp->data) {
					quit = 1;
					preTemp->right = NULL;
					free(temp);
				}
				else if (preTemp->left->data == temp->data) {
					quit = 1;
					preTemp->left = NULL;
					free(temp);
				}
				if (preTemp->data > temp->data) {
					preTemp = preTemp->left;
				}
				else if (preTemp->data < temp->data) {
					preTemp = preTemp->right;
				}
				else {
					printf("\n\n\n\n��� ���� ��찡 ������ �� �Ǵµ� �� ����. ������ ����.\n\n\n\n"); //Ȯ�ο�. ���߿��� ������.
				}
			}
		}
	}
}

void degrOne() {
	int quit = 0;
	NODE* preTemp = NULL;
	if (root->data == temp->data) {
		if (root->right == NULL) {
			root = root->left;
		}
		else {
			root = root->right;
		}
		free(temp);
	}
	else {
		preTemp = root;
		
		while (quit == 0) {
			if (preTemp->left != NULL && preTemp->right == NULL) {
				if (preTemp->left->data == temp->data) {
					quit = 1;
					if (temp->right == NULL) {
						preTemp->left = temp->left;
					}
					else {
						preTemp->left = temp->right;
					}
					free(temp);
				}
				preTemp = preTemp->left;
			}
			else if (preTemp->right != NULL && preTemp->left == NULL) {
				if (preTemp->right->data == temp->data) {
					quit = 1;
					if (temp->right == NULL) {
						preTemp->right = temp->left;
					}
					else {
						preTemp->right = temp->right;
					}
					free(temp);
				}
				preTemp = preTemp->right;
			}
			else if (preTemp->right != NULL && preTemp->left != NULL) {
				if (preTemp->right->data == temp->data) {
					quit = 1;
					if (temp->right == NULL) {
						preTemp->right = temp->left;
					}
					else {
						preTemp->right = temp->right;
					}
					free(temp);
				}
				else if (preTemp->left->data == temp->data) {
					quit = 1;
					if (temp->right == NULL) {
						preTemp->left = temp->left;
					}
					else {
						preTemp->left = temp->right;
					}
					free(temp);
				}
				if (preTemp->data > temp->data) {
					preTemp = preTemp->left;
				}
				else if (preTemp->data < temp->data) {
					preTemp = preTemp->right;
				}
				else {
					printf("\n\n\n\n��� ���� ��찡 ������ �� �Ǵµ� �� ����. ������ ����.\n\n\n\n"); //Ȯ�ο�. ���߿��� ������.
				}
			}

		}
	}
}

void degrTwo() {
	NODE* curr = NULL;
	NODE* pre = NULL;
	
	curr = temp->left;
	while (curr->right != NULL) {
		curr = curr->right;
	}

	pre = temp;
	if (pre->left->data != curr->data) {
		pre = pre->left;
		while (pre->right->data == curr->data) {
			pre = pre->right;
		}
	}

	if (root->data == temp->data) {

	}
	else {

	}
}