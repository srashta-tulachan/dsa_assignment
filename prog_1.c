#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push into stack
void push(char c) {
    top++;
    stack[top] = c;
}

// pop from stack
char pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i;
    char last;

    printf("Enter expression: ");
    gets(exp);

    for (i = 0; exp[i] != '\0'; i++) {

        // opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        // closing brackets
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            // if stack empty
            if (top == -1) {
                printf("NOT BALANCED\n");
                return 0;
            }

            last = pop();

            // check matching
            if (
                (last == '(' && exp[i] != ')') ||
                (last == '{' && exp[i] != '}') ||
                (last == '[' && exp[i] != ']')
            ) {
                printf("NOT BALANCED\n");
                return 0;
            }
        }
    }

    // after checking whole expression
    if (top == -1)
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;
}
