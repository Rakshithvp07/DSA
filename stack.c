#include <stdio.h>
#define MAX 4

int s[MAX], top = -1, ele, i;

void push(int ele) {
    if (top == MAX - 1) {
        printf("Stack Overflow");
        return;
    }
    top++;
    s[top] = ele;
}
int pop() {
    int ele;
    if (top == -1) {
        printf("Stack underflow");
        return -1;
    }
    ele = s[top];
    top--;
    return ele;
}
void display() {
    if (top == -1) {
        printf("Stack underflow");
        return;
    }
    printf("Stack Contents are:\n");
    for (i = top; i >= 0; i--)
        printf("%d\n", s[i]);
}
void pal() {
    int i = 1, len = 0, rev = 0, digit, temp, n;
    printf("Enter a Number: ");
    scanf("%d", &n);
    temp = n;
    while (n != 0) {
        digit = n % 10;
        n = n / 10;
        push(digit);
        len++;
    }
    while (len != 0) {
        digit = pop();
        rev = rev + (digit * i);
        len--;
        i = i * 10;
    }
    if (temp == rev)
        printf("Number is a palindrome");
    else
        printf("Number is not a palindrome");
}

int main() {
    int ch;
    while(1) {
        printf("1: Push\n2: Pop\n3: Display\n4: Palindrome\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                ele = pop();
                if (ele != -1)
                    printf("Element deleted is %d\n", ele);
                break;
            case 3:
                display();
                break;
            case 4:
                pal();
                break;
            default:
                printf("Invalid choice\n");
        }
    } 
}
