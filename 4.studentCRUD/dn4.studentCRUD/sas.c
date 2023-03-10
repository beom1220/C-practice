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
        printf("* 1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료 *\n");
        printf("****************************************************\n");
        printf("실행할 번호를 입력하세요. : ");
        scanf("%d", &exeNum);
        printf("\n");
        switch (exeNum) {
        case 1: //입력
            printf("학번을 입력하세요. : ");
            overlap = 0;
            scanf("%d", &studentID); printf("\n");
            //printf("\n\n%d\n\n", studentID);

            for (stId = 0; stId <= 1000; stId++) {
                if (std[stId].stNum == studentID) {
                    overlap = 1;
                }
            } // 중복 있으면 중복확인변수 1로.

            for (stId = 0; std[stId].stNum != 0;) { stId++; }
            if (overlap == 0) {
                std[stId] = pushData(studentID);
                stId++;
                //printf("\n\ncheck!\n\n");
                //printf("\n\n%d\n\n", std[stId-1].stNum);
            }
            else {
                printf("이미 저장되어 있는 학번입니다.\n\n");
            }
            break;

        case 2: //출력
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
                printf("출력할 학생 정보가 없습니다.\n\n");
            }
            break;

        case 3: //검색
            printf("검색할 학생의 학번을 입력하세요. : ");
            scanf("%d", &searchNum);
            printf("\n");
            srchErr = 0;
            for (stId = 0; searchNum != std[stId].stNum && stId != 1000;) {
                stId++;
                if (stId == 1000) {
                    printf("검색한 정보를 찾을 수 없습니다.\n\n");
                    srchErr = 1;
                }
            }
            if (srchErr == 0) {
                printf("검색한 학생의 정보는 다음과 같습니다.\n");
                printData(std[stId]);
            }
            break;

        case 4: //삭제
            printf("검색할 학생의 학번을 입력하세요. : ");
            scanf("%d", &searchNum);
            printf("\n");
            srchErr = 0;
            for (stId = 0; searchNum != std[stId].stNum && stId != 1000;) {
                stId++;
                if (stId == 1000) {
                    printf("검색한 정보를 찾을 수 없습니다.\n\n");
                    srchErr = 1;
                }
            }
            if (srchErr == 0) {
                printf("검색한 학생의 정보를 삭제했습니다.\n");
                std[stId].stNum = 0;
            }
            break;

        case 5: //저장
            if ((f = fopen(fname, "w")) == NULL) {
                printf("파일이 열리지 않습니다.\n");
                exit(1);
            };
            fprintf(f, "");
            count = 0;
            fclose(f);

            if ((f = fopen(fname, "a")) == NULL) {
                printf("파일이 열리지 않습니다.\n");
                exit(1);
            };

           for (stId = 0; stId <= 1000; stId++) {
                if (std[stId].stNum != 0) {
                    saveData(std[stId]);
                }
            }
           printf("학생 리스트를 저장하였습니다. \"students.txt\"에서 확인하실 수 있습니다.\n\n");
           fclose(f);
           break;

        case 6: //로드
            if ((f = fopen(fname, "r")) == NULL) {
                printf("파일을 열지 못했습니다.\n");
                exit(1);
            }
            stId = 0;
            do {
                std[stId] = loadData();
                stId++;
            } while (std[stId - 1].cnt != std[stId - 2].cnt);
            // 일단 여기서 txt 파일에 있는 앞의 count를 활용해서 for문을 돌려서 넣는 방식으로 시도해볼까 함. 수업 때문에 여기까지.
            printf("\"students.txt\"에서 학생 리스트를 로드하였습니다.\n\n");
            fclose(f);
            break;

        case 7: //종료
            printf("시스템을 종료합니다.\n");
            break;

        default:
            printf("잘못된 입력값입니다.\n");
            break;
        }
    }
}

struct student pushData(int stduentID) //입력에 쓸 함수
{
    student std;
    std.stNum = studentID;
    printf("이름을 입력하세요. : ");
    scanf("%s", std.name); printf("\n");
    for (std.kor = 101; std.kor > 100;) {
        printf("국어점수를 입력하세요. : ");
        scanf("%d", &std.kor); printf("\n");
        if (std.kor > 100) {
            printf("점수에는 100점을 넘기지 않는 값을 입력해주세요.\n\n");
        }
    }

    for (std.math = 101; std.math > 100;) {
        printf("수학점수를 입력하세요. : ");
        scanf("%d", &std.math); printf("\n");
        if (std.math > 100) {
            printf("점수에는 100점을 넘기지 않는 값을 입력해주세요.\n\n");
        }
    }

    for (std.eng= 101; std.eng > 100;) {
        printf("영어점수를 입력하세요. : ");
        scanf("%d", &std.eng); printf("\n");
        if (std.eng > 100) {
            printf("점수에는 100점을 넘기지 않는 값을 입력해주세요.\n\n");
        }
    }
    std.sum = (std.kor + std.math + std.eng);
    std.aver = ((std.kor + std.math + std.eng) / 3);
    //struct student std = { stName, stNum, korSco, mathSco, engSco, (korSco + mathSco + engSco), ((korSco + mathSco + engSco) / 3) }; 이건 왜 안 되는 거지..? 문자열 파트가 문젠가. 일단 위에껄로 하면 되니까 해결은 됐음.
    return std;
}

void printData(student std) //출력에 쓸 함수
{
    printf("학번 : %8d | 이름 : %5s | 국어점수 : %3d | 수학점수 : %3d | 영어점수 : %3d | 총합점수 : %3d | 평균점수 : %3d\n", std.stNum, std.name, std.kor, std.math, std.eng, std.sum, std.aver);
    printf("\n");
}


void saveData(student std) //저장에 쓸 함수
{
    fprintf(f, "%d %d %s %d %d %d %d %d\n", ++count, std.stNum, std.name, std.kor, std.math, std.eng, std.sum, std.aver);
}


struct student loadData() //로드에 쓸 함수
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