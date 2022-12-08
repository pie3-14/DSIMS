#include <stdio.h>
#include <uchar.h>
#include <string.h>
#include "parse.h"

int main() {
    char cmd[1000];
    printf("**********Dart Spending Income Management System**********");

    //커맨드 입력받기
    while (1) {
        printf(">>");
        gets(cmd);
        paser(cmd);
        //만약 명령어가 exit라면 종료
        if (strcmp(parse(cmd), "exit") == 0) {
            break;
        }
    }

    return 0;
}