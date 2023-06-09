#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node* h, int key);
void printNode(Node* h);
void freeNode(Node* h);
void freeBST(Node* h);
void inorder(Node* h);

int main() {
    int size, i;
    int* input;

    scanf("%d", &size);
    input = (int*)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
        scanf("%d", &input[i]);

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->left = NULL;
    head->right = head;

    for (i = 0; i < size; i++)
        insertNode(head, input[i]);

    printNode(head->left);

    freeBST(head);
    free(input);

    return 0;
}

void insertNode(Node* h, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key; 
    newNode->left = NULL; 
    newNode->right = NULL; 

    if (h->left == NULL) {
        h->left = newNode;
        return;
    }

    Node* ptr = h->left;

    Node* parentNode = NULL;

    while (ptr != NULL) {
        if (ptr->data == key) {
            free(newNode);
            return;
        }
        parentNode = ptr;

        if (ptr->data < key)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }

    if (parentNode->data > key) 
        parentNode->left = newNode;
    else
        parentNode->right = newNode;
}

void printNode(Node* h) {
    if (h) {
        printNode(h->left);
        printf(" [%d] ", h->data);
        printNode(h->right);
    }
}

void inorder(Node* h) {
    if (h) {
        inorder(h->left);
        printf(" [%d] ", h->data);
        inorder(h->right);
    }
}

void freeNode(Node* h) {
    if (h) {
        freeNode(h->left);
        freeNode(h->right);
        free(h);
    }
}

void freeBST(Node* h) {
    if (h->right == h) {
        free(h);
        return;
    }

    Node* p = h->left;

    freeNode(p);

    free(h);
}