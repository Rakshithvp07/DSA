#include <stdio.h>
#define MAX 3

int cq[MAX], f = 0, r = -1, i, j, c = 0, n, ele;
void insert() {
    if (c == MAX) {
        printf("CIRCULAR QUEUE OVERFLOW\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &ele);
    r = (r + 1) % MAX;
    cq[r] = ele;
    c++;
}
void delete_ele() {
    if (c == 0) {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
        return;
    }
    printf("Element deleted is %d\n", cq[f]);
    f = (f + 1) % MAX;
    c--;
}
void display() {
    j = f;
    if (c == 0) {
        printf("CIRCULAR QUEUE UNDERFLOW\n");
        return;
    }
    printf("Contents of CQ are:\n");
    for (i = 1; i <= c; i++) {
        printf("%d\t", cq[j]);
        j = (j + 1) % MAX;
    }
}
int main() {
    int ch;
    do {
        printf("1: Insert 2: Delete 3: Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete_ele();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch <= 3);
    return 0;
}
