#include <stdio.h>
#include <malloc.h>

typedef struct node {
    char usn[11];
    char name[20];
    char sem[10];
    char branch[10];
    char phno[10];
    struct node *link;
} NODE;

NODE *first = NULL;

void create() {
    int i, n;
    NODE *nn;
    printf("\nEnter value of n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        nn = (NODE *)malloc(sizeof(NODE));
        printf("Enter Details\n");
        printf("Enter usn, name, branch, sem, phno: ");
        scanf("%s%s%s%s%s", nn->usn, nn->name, nn->branch, nn->sem, nn->phno);
        nn->link = first;
        first = nn;
    }
}

void insert_front() {
    NODE *nn;
    nn = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Details\n");
    printf("Enter usn, name, branch, sem, phno: ");
    scanf("%s%s%s%s%s", nn->usn, nn->name, nn->branch, nn->sem, nn->phno);
    nn->link = first;
    first = nn;
}

void delete_front() {
    NODE *temp;
    if (first == NULL) {
        printf("\nList is empty");
        return;
    }
    temp = first;
    first = first->link;
    free(temp);
}

void display() {
    int c = 0;
    NODE *temp;
    if (first == NULL) {
        printf("\nList is empty");
        return;
    }
    temp = first;
    printf("\nContents are:\n");
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->link;
        c++;
    }
    printf("No. of nodes = %d\n", c);
}

void stack() {
    int ch;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_front();
                break;
            case 2:
                delete_front();
                break;
            case 3:
                display();
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (ch <= 3);
}

int main() {
    int ch;
    do {
        printf("\n1. Create\n2. Display\n3. Stack\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                stack();
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (ch <= 3);
    return 0;
}
