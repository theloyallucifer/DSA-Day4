#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *nextptr;
} *stnode;

void createNodeList(int n);
void displayList();
int countList();
void freeList();
void insertAtEnd(int num);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice, num, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Count nodes in the list\n");
        printf("4. Insert a node at the end\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input the number of nodes: ");
                scanf("%d", &n);
                createNodeList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Number of nodes: %d\n", countList());
                break;
            case 4:
                printf("Input data for new node: ");
                scanf("%d", &num);
                insertAtEnd(num);
                break;
            case 5:
                freeList();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void createNodeList(int n) {
    struct node *fnNode, *tmp;
    int num, i;

    // Allocate memory for the first node
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode == NULL) {
        printf("Memory cannot be allocated.");
        exit(1); 
    }

    printf("Input data for node 1: ");
    scanf("%d", &num);
    stnode->num = num;
    stnode->nextptr = NULL;
    tmp = stnode;

    for (i = 2; i <= n; i++) {
        // Allocate memory for the next node
        fnNode = (struct node *)malloc(sizeof(struct node));
        if (fnNode == NULL) {
            printf("Memory cannot be allocated.");
            break;
        }

        printf("Input data for node %d: ", i);
        scanf("%d", &num);
        fnNode->num = num;
        fnNode->nextptr = NULL;
        tmp->nextptr = fnNode;
        tmp = tmp->nextptr;
    }
}

int countList() {
    int ctr = 0;
    struct node *tmp = stnode;

    while (tmp != NULL) {
        ctr++;
        tmp = tmp->nextptr;
    }

    return ctr;
}

void displayList() {
    struct node *tmp = stnode;

    if (tmp == NULL) {
        printf("List is empty.");
    } else {
        printf("Linked List:\n");
        while (tmp != NULL) {
            printf("%d --> ", tmp->num);
            tmp = tmp->nextptr;
        }
        printf("NULL\n");
    }
}

void insertAtEnd(int num) {
    struct node *newNode, *tmp;

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory cannot be allocated.");
        return;
    }

    newNode->num = num;
    newNode->nextptr = NULL;

    if (stnode == NULL) {
        stnode = newNode;
    } else {
        tmp = stnode;
        while (tmp->nextptr != NULL) {
            tmp = tmp->nextptr;
        }
        tmp->nextptr = newNode;
    }
}

void freeList() {
    struct node *tmp;

    while (stnode != NULL) {
        tmp = stnode;
        stnode = stnode->nextptr;
        free(tmp);
    }
}

