#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    top++;
    stack[top] = c;
}


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

        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            
            if (top == -1) {
                printf("NOT BALANCED\n");
                return 0;
            }

            last = pop();

            
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

    
    if (top == -1)
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;// the endddd//
}
