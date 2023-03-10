#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student
{
    int cnt;
    char name[10];
    int stNum;
    int kor;
    int math;
    int eng;
    int sum;
    int aver;
}student;

struct student pushData(int studentID);
void printData(student std);
void saveData(student std);
struct student loadData();
student std[1000];
int stId = 0, studentID;
int count = 0;
char fname[] = "students.txt";
FILE* f;

int main(void)
{
    int averCheck, searchNum, srchErr, overlap;
    for (int exeNum = 0; exeNum != 7;) {
        printf("****************************************************\n");
        printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.�ε� 7.���� *\n");
        printf("****************************************************\n");
        printf("������ ��ȣ�� �Է��ϼ���. : ");
        scanf("%d", &exeNum);
        printf("\n");
        switch (exeNum) {
        case 1: //�Է�
            printf("�й��� �Է��ϼ���. : ");
            overlap = 0;
            scanf("%d", &studentID); printf("\n");
            //printf("\n\n%d\n\n", studentID);

            for (stId = 0; stId <= 1000; stId++) {
                if (std[stId].stNum == studentID) {
                    overlap = 1;
                }
            } // �ߺ� ������ �ߺ�Ȯ�κ��� 1��.

            for (stId = 0; std[stId].stNum != 0;) { stId++; }
            if (overlap == 0) {
                std[stId] = pushData(studentID);
                stId++;
                //printf("\n\ncheck!\n\n");
                //printf("\n\n%d\n\n", std[stId-1].stNum);
            }
            else {
                printf("�̹� ����Ǿ� �ִ� �й��Դϴ�.\n\n");
            }
            break;

        case 2: //���
            int empty = 0;
            for (averCheck = 100; averCheck >= 0; averCheck--) {
                for (stId = 0; stId <= 1000; stId++) {
                    if (std[stId].aver == averCheck && std[stId].stNum != 0) {
                        printData(std[stId]);
                    }
                    else {
                        empty++;
                    }
                }
            }
            if (empty == 101101) { // 1001 X 101 = 101101
                printf("����� �л� ������ �����ϴ�.\n\n");
            }
            break;

        case 3: //�˻�
            printf("�˻��� �л��� �й��� �Է��ϼ���. : ");
            scanf("%d", &searchNum);
            printf("\n");
            srchErr = 0;
            for (stId = 0; searchNum != std[stId].stNum && stId != 1000;) {
                stId++;
                if (stId == 1000) {
                    printf("�˻��� ������ ã�� �� �����ϴ�.\n\n");
                    srchErr = 1;
                }
            }
            if (srchErr == 0) {
                printf("�˻��� �л��� ������ ������ �����ϴ�.\n");
                printData(std[stId]);
            }
            break;

        case 4: //����
            printf("�˻��� �л��� �й��� �Է��ϼ���. : ");
            scanf("%d", &searchNum);
            printf("\n");
            srchErr = 0;
            for (stId = 0; searchNum != std[stId].stNum && stId != 1000;) {
                stId++;
                if (stId == 1000) {
                    printf("�˻��� ������ ã�� �� �����ϴ�.\n\n");
                    srchErr = 1;
                }
            }
            if (srchErr == 0) {
                printf("�˻��� �л��� ������ �����߽��ϴ�.\n");
                std[stId].stNum = 0;
            }
            break;

        case 5: //����
            if ((f = fopen(fname, "w")) == NULL) {
                printf("������ ������ �ʽ��ϴ�.\n");
                exit(1);
            };
            fprintf(f, "");
            count = 0;
            fclose(f);

            if ((f = fopen(fname, "a")) == NULL) {
                printf("������ ������ �ʽ��ϴ�.\n");
                exit(1);
            };

           for (stId = 0; stId <= 1000; stId++) {
                if (std[stId].stNum != 0) {
                    saveData(std[stId]);
                }
            }
           printf("�л� ����Ʈ�� �����Ͽ����ϴ�. \"students.txt\"���� Ȯ���Ͻ� �� �ֽ��ϴ�.\n\n");
           fclose(f);
           break;

        case 6: //�ε�
            if ((f = fopen(fname, "r")) == NULL) {
                printf("������ ���� ���߽��ϴ�.\n");
                exit(1);
            }
            stId = 0;
            do {
                std[stId] = loadData();
                stId++;
            } while (std[stId - 1].cnt != std[stId - 2].cnt);
            // �ϴ� ���⼭ txt ���Ͽ� �ִ� ���� count�� Ȱ���ؼ� for���� ������ �ִ� ������� �õ��غ��� ��. ���� ������ �������.
            printf("\"students.txt\"���� �л� ����Ʈ�� �ε��Ͽ����ϴ�.\n\n");
            fclose(f);
            break;

        case 7: //����
            printf("�ý����� �����մϴ�.\n");
            break;

        default:
            printf("�߸��� �Է°��Դϴ�.\n");
            break;
        }
    }
}

struct student pushData(int stduentID) //�Է¿� �� �Լ�
{
    student std;
    std.stNum = studentID;
    printf("�̸��� �Է��ϼ���. : ");
    scanf("%s", std.name); printf("\n");
    for (std.kor = 101; std.kor > 100;) {
        printf("���������� �Է��ϼ���. : ");
        scanf("%d", &std.kor); printf("\n");
        if (std.kor > 100) {
            printf("�������� 100���� �ѱ��� �ʴ� ���� �Է����ּ���.\n\n");
        }
    }

    for (std.math = 101; std.math > 100;) {
        printf("���������� �Է��ϼ���. : ");
        scanf("%d", &std.math); printf("\n");
        if (std.math > 100) {
            printf("�������� 100���� �ѱ��� �ʴ� ���� �Է����ּ���.\n\n");
        }
    }

    for (std.eng= 101; std.eng > 100;) {
        printf("���������� �Է��ϼ���. : ");
        scanf("%d", &std.eng); printf("\n");
        if (std.eng > 100) {
            printf("�������� 100���� �ѱ��� �ʴ� ���� �Է����ּ���.\n\n");
        }
    }
    std.sum = (std.kor + std.math + std.eng);
    std.aver = ((std.kor + std.math + std.eng) / 3);
    //struct student std = { stName, stNum, korSco, mathSco, engSco, (korSco + mathSco + engSco), ((korSco + mathSco + engSco) / 3) }; �̰� �� �� �Ǵ� ����..? ���ڿ� ��Ʈ�� ������. �ϴ� �������� �ϸ� �Ǵϱ� �ذ��� ����.
    return std;
}

void printData(student std) //��¿� �� �Լ�
{
    printf("�й� : %8d | �̸� : %5s | �������� : %3d | �������� : %3d | �������� : %3d | �������� : %3d | ������� : %3d\n", std.stNum, std.name, std.kor, std.math, std.eng, std.sum, std.aver);
    printf("\n");
}


void saveData(student std) //���忡 �� �Լ�
{
    fprintf(f, "%d %d %s %d %d %d %d %d\n", ++count, std.stNum, std.name, std.kor, std.math, std.eng, std.sum, std.aver);
}


struct student loadData() //�ε忡 �� �Լ�
{
    student std;
    char name[10];
    int cnt, stNum, kor, math, eng, sum, aver;
    fscanf(f, "%d %d %s %d %d %d %d %d", &cnt, &stNum, name, &kor, &math, &eng, &sum, &aver);
    std.cnt = cnt;
    std.stNum = stNum;
    std.kor = kor;
    std.math = math;
    std.eng = eng;
    std.sum = sum;
    std.aver = aver;
    strcpy(std.name, name);
    return std;
}