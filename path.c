#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    char* stack[3000];
    int stackTop = -1;
    char temp[3000];
    int tempIndex = 0;

    for (int i = 0; i <= strlen(path); i++) {
        if (path[i] == '/' || path[i] == '\0') {
            if (tempIndex > 0) {
                temp[tempIndex] = '\0';
                if (strcmp(temp, "..") == 0) {
                    if (stackTop >= 0) {
                        stackTop--;
                    }
                } else if (strcmp(temp, ".") != 0) {
                    stack[++stackTop] = strdup(temp);
                }
                tempIndex = 0;
            }
            continue;
        } else {
            temp[tempIndex++] = path[i];
        }
    }

    char* result = (char*)malloc(3000 * sizeof(char));
    int index = 0;

    if (stackTop == -1) {
        result[index++] = '/';
        result[index] = '\0';
        return result;
    }

    for (int i = 0; i <= stackTop; i++) {
        result[index++] = '/';
        strcpy(result + index, stack[i]);
        index += strlen(stack[i]);
    }
    result[index] = '\0';

    return result;
}

