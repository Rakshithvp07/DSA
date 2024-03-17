#include <stdio.h>
#include <math.h>

int op1, op2, res, i, top = -1, s[10], ele, n;

void push(int ele) {
    top++;
    s[top] = ele;
}

int pop() {
    int ele;
    ele = s[top];
    top--;
    return ele;
}

void eval() {
    int e;
    char postfix[20], ch;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch))
            push(ch - '0');
        else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '^':
                    res = pow(op1, op2);
                    break;
            }
            push(res);
        }
    }
    printf("Result of postfix expression: %d\n", res);
}

void tow(int n, char s, char t, char d) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", s, d);
        return;
    }
    tow(n - 1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    tow(n - 1, t, s, d);
}

int main() {
    int ch;
    do {
        printf("1: Evaluation of postfix expression\n2: Tower of Hanoi\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                eval();
                break;
            case 2:
                // Assuming you have the number of disks 'n' as input
                printf("Enter the number of disks: ");
                scanf("%d", &n);
                tow(n, 'A', 'B', 'C');
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch <= 2);
    return 0;
}
