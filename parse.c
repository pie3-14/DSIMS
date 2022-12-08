#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "cmd.h"

//입력받은 명령어를 분해
char parser(char *com) {
    // 명령어 분해해서 배열에 저장
    char* token[100];
    char deli[2] = " ";
    char *result;
    int i = 0;

    result = strtok(com, deli);

    while ( result != NULL ) {
        strcpy(token[i++], result);
        result =strtok(NULL, deli);
    }

    // 만약 토큰의 0번 째 값이 exit라면
    if (strcmp(token[0], "exit") == 0) {
            return token[0];
    }
    
    command(token, sizeof(token)/sizeof(char));
}