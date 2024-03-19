#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double compute(double operand1, char operator, double operand2) {
 switch (operator) {
 case '+': return operand1 + operand2;
 case '-': return operand1 - operand2;
 case '*': return operand1 * operand2;
 case '/': return operand1 / operand2;
 case '%': return fmod(operand1, operand2);
 case '^': return pow(operand1, operand2);
 default:
 exit(0);
 }
}
double evaluate(char postfix[]) {
 int i, top = -1;
 double stack[20], operand1, operand2;
 for (i = 0; postfix[i] != '\0'; i++) {
 if (postfix[i] >= '0' && postfix[i] <= '9') {
 stack[++top] = postfix[i] - '0';
 } else {
 operand2 = stack[top--];
 operand1 = stack[top--];
 stack[++top] = compute(operand1, postfix[i], operand2);
 }
 }
 return stack[top--];
}
int main() {
 char postfix[20];
 double result;
 printf("Enter Postfix expression: ");
 scanf("%s", postfix);
 result = evaluate(postfix);
 printf("Result = %lf\n", result);
 return 0;
}
#TOWER OF HANOI
#include <stdio.h>
void Transfer(int n, char source, char temp, char dest)
{
 if (n == 0) return;

 Transfer(n - 1, source, dest, temp);

 printf("Move disk %d from %c to %c\n", n, source, dest);

 Transfer(n - 1, temp, source, dest);
}
void main()
{
 int n;

 printf("Enter number of disks : ");
 scanf("%d", &n);

 Transfer(n, 'A', 'B', 'C');
}
