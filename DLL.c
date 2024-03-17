#include<stdio.h>
#include<malloc.h>

typedef struct node {
    char ssn[10];
    char name[20];
    char dept[10];
    char desg[10];
    char sal[10];
    char phno[11];
    struct node *llink;
    struct node *rlink;
} NODE;

NODE *first = NULL;

void create() {
    NODE *temp, *nn;
    int i, n;
    printf("enter the value of n\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        nn = (NODE*)malloc(sizeof(NODE));
        printf("enter the ssn, name, dept, designation, salary, phno\n");
        scanf("%s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
        if(first == NULL) {
            nn->rlink = NULL;
            nn->llink = NULL;
            first = nn;
        } else {
            temp = first;
            while(temp->rlink != NULL) {
                temp = temp->rlink;
            }
            temp->rlink = nn;
            nn->llink = temp;
            nn->rlink = NULL;
        }
    }
}

void insert_end() {
    NODE *temp, *nn;
    nn = (NODE*)malloc(sizeof(NODE));
    printf("enter the ssn, name, dept, designation, salary, phno\n");
    scanf("%s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
    if(first == NULL) {
        nn->rlink = NULL;
        nn->llink = NULL;
        first = nn;
        return;
    }
    temp = first;
    while(temp->rlink != NULL) {
        temp = temp->rlink;
    }
    temp->rlink = nn;
    nn->llink = temp;
    nn->rlink = NULL;
}

void insert_front() {
    NODE *nn;
    nn = (NODE*)malloc(sizeof(NODE));
    printf("enter ssn, name, dept, designation, salary, phno\n");
    scanf(" %s%s%s%s%s%s", nn->ssn, nn->name, nn->dept, nn->desg, nn->sal, nn->phno);
    nn->rlink = first;
    first->llink = NULL;
    first = nn;
}

void delete_front() {
    NODE *temp;
    if(first == NULL) {
        printf("list is empty\n");
        return;
    }
    temp = first;
    if(first->rlink == NULL) {
        first = NULL;
        free(temp);
        return;
    }
    first = first->rlink;
    first->llink = NULL;
    free(temp);
}

void delete_end() {
    NODE *temp, *prev;
    if(first == NULL) {
        printf("list is empty\n");
        return;
    }
    prev = NULL;
    temp = first;
    if(first->rlink == NULL) {
        first = NULL;
        free(temp);
        return;
    }
    while(temp->rlink != NULL) {
        prev = temp;
        temp = temp->rlink;
    }
    prev->rlink = NULL;
    free(temp);
}

void display() {
    NODE *temp;
    temp = first;
    if(first == NULL) {
        printf("list is empty\n");
        return;
    }
    printf("contents are \n");
    while(temp != NULL) {
        printf("%s\t%s\t%s\t%s\t%s%s\n", temp->ssn, temp->name, temp->desg, temp->dept, temp->sal, temp->phno);
        temp = temp->rlink;
    }
}

void dequeue() {
    int ch;
    do {
        printf("1:insert-front 2:insert-rear 3:delete front 4:delete rear,5display\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert_front();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            default:
                printf("invalid choice");
        }
    } while(ch <= 5);
}

void main() {
    int ch;
    do {
        printf("1.create 2.display 3.dequeue\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            default:
                printf("invalid choice");
        }
    } while(ch <= 3);
}
