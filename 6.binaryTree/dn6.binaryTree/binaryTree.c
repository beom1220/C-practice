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
		printf("*        이진 트리 관리시스템        *\n");
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
			if (root != NULL) {
				printNode();
			}
			else {
				printf("출력할 값이 없습니다.\n\n");
			}
			break;
		case 3: //검색
			printf("검색할 데이터값을 입력하세요. : ");
			scanf("%d", &searchNum); printf("\n");
			hit = 0;
			searchNode(searchNum, root);
			if (hit == 1) {
				printf("검색한 값인 %d(이)가 데이터 내에 있습니다.\n\n", searchNum);
			}
			else {
				printf("검색한 값인 %d(이)가 데이터 내에 없습니다.\n\n", searchNum);
			}
			break;
		case 4: //삭제
			printf("삭제할 데이터값을 입력하세요. : ");
			scanf("%d", &delNum); printf("\n");
			hit = 0;
			NODE* curr = root;
			delNode(delNum, root, curr);
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
	NODE* curr = NULL;
	int leaf = 0;
	// 아무것도 없을 때 입력이랑 / 뭐라도 있을 때 입력을 일단 분리 => 루트 여부로 판단해야 하나
	if (root != NULL) { // 뭐 있을 때
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
			printf("입력되었습니다.\n\n");
		}
		else if (curr->data < num) {
			curr->right = (NODE*)malloc(sizeof(NODE));
			curr->right->data = num;
			curr->right->left = NULL;
			curr->right->right = NULL;
			printf("입력되었습니다.\n\n");
		}
		else {
			printf("중복된 값은 입력할 수 없습니다.\n\n");
		}
	}
	else { // 뭐 없을 때
		root = (NODE*)malloc(sizeof(NODE));
		root->data = num;
		root->right = NULL;
		root->left = NULL;
		printf("입력되었습니다.\n\n");
	}
}

void printNode() {
	printf("이진 트리 출력을 시작합니다.\n");
	printf("전위 순회 : ");
	prePrintNode(root);
	printf("\n");
	printf("중위 순회 : ");
	inPrintNode(root);
	printf("\n");
	printf("후위 순회 : ");
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

void delNode(int num, NODE* start) { // 차이 같으면 더 작은 애 데려오는 걸로 하자. (left 중 가장 right 값) vs (right 중 가장 left 값)
	// 경우를 아마. 1) 루트가 지워진 경우 / 2) 루트 아닌 거 지워진 경우 // 이케 나눠야 하지 않을까?
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
		printf("저장되어 있지 않은 데이터입니다.\n\n");
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
					printf("\n\n\n\n어라 같은 경우가 나오면 안 되는데 왜 나와. 에러임 에러.\n\n\n\n"); //확인용. 나중에는 지워야.
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
					printf("\n\n\n\n어라 같은 경우가 나오면 안 되는데 왜 나와. 에러임 에러.\n\n\n\n"); //확인용. 나중에는 지워야.
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