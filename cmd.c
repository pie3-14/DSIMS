#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "cmd.h"

// txt 파일 정보 담을 구조체
typedef struct Information {
    /* data */
    int idx_num; //순번
    char date[30]; //날짜
    char goal[3]; // 지출인지 수입인지
    int money; //얼마를 넣었는지
    char check[3]; //계좌인지 현금인지
} info;

// 명령어
typedef struct Command {
    /* data */
    char arg0[10];
    char arg1[10];
    char arg2[10];
    char arg3[10];
    char arg4[10];
} comm;

// 지출 수입 리스트 출력
static void list() {
    // 파일 열어서 읽기
    const int MAX = 1000;
    FILE *fi = fdopen("acc.txt", "r");
    char buffer[MAX];
    fread(buffer, 1, MAX, fi);
    if (buffer == NULL) { //텍스트 파일이 비어있으면 
        printf("자료가 없습니다.");
        return 0;
    } else {
        //한 줄씩 읽어서 출력
        const int max = 1024;
        char line[max];
        char *pLine;
        printf("번호    시간    금액    지출/수입   계좌/현금\n");
        printf("--------------------------------------------\n");
        while (!feof(fi)) {
            char* li[100];
            char deli[2] = ",";
            char *result;
            int i = 0;

            result = strtok(pLine, deli);

            while ( result != NULL ) {
                strcpy(li[i++], result);
                result =strtok(NULL, deli);
            }
            info g;
            strcpy(g.idx_num, li[0]);
            strcpy(g.date, li[1]);
            strcpy(g.money, li[2]);
            strcpy(g.goal, li[3]);
            strcpy(g.check, li[4]);
            pLine = fgets(line, max, fi);
            printf("%s  %d  %s  %d  %d", g.idx_num, g.date, g.money, g.goal, g.check );
        }
        fclose(fi);
        printf("--------------------------------------------\n");
    }
    return ;
}

//새로운 거 추가
/*static void add(char com[], ...) {
    // info 구조체에 하나씩 저장
    info input, output;
    va_list ap;
    va_start(ap, com);
    char* arr[5];
    for (int i = 0; i < com; i++) {
        arr[i] = va_arg(ap, char);
    }
    va_end(ap);
    input.idx_num = output.idx_num++;
}*/

// 삭제
/*static void delete() {

}*/

// 검색 
/*static void find() {

}*/

//분해한 명령어를 해석해서 명령어 실행
void command(char * token[], int len) {
    // 구조체에 저장
    comm comm1 = {token[0], token[1], token[2], token[3], token[4]};

    //뭐가 명령어일까요
    if ( strcmp(comm1.arg0, "list")==0 ) {
        list();
    } else if (strcmp(comm1.arg0, "add")==0) {
        add(comm1.arg1, comm1.arg2, comm1.arg3, comm1.arg4);
   // } else if (strcmp(comm1.arg0, "delete")==0) {
   //     delete();
    //} else if (strcmp(comm1.arg0, "find")==0) {
    //    find();
    }
}