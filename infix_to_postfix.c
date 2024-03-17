#include <stdio.h>
#include <ctype.h>

char infix[25], postfix[25],ch,s[25],ele;
int i,j=0, top = -1;

void push(char d) {
    top++;
    s[top] = d;
}
char pop() {
    char d;
    d = s[top];
    top--;
    return d;
}
int pri(char d) {
    switch (d) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
        case '#':
            return 0;
    }
}
void main() {
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    push('#');
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[j++] = pop();
            ele = pop();
        } else {
            while (pri(s[top]) >= pri(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix expression is: %s", postfix);
}
