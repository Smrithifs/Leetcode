#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int stackTop = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/') {
            if (stackTop < 1) {
                return -1;  // Error, not enough operands
            }
            int b = stack[stackTop--];
            int a = stack[stackTop--];
            if (tokens[i][0] == '+') {
                stack[++stackTop] = a + b;
            } else if (tokens[i][0] == '-') {
                stack[++stackTop] = a - b;
            } else if (tokens[i][0] == '*') {
                stack[++stackTop] = a * b;
            } else if (tokens[i][0] == '/') {
                stack[++stackTop] = a / b;  /
            }
        } else {
            stack[++stackTop] = atoi(tokens[i]);  
        }
    }

    return stack[stackTop];  
}
