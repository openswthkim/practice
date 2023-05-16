#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* llink;
    struct Node* rlink;
}Node;

int insertNode(Node* h, int key);
int freeNode(Node* h);
void printNode(Node* h);

int main(){
    int n;
    scanf("%d", &n);

    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->llink=NULL;
    head->rlink=NULL;

    for(int i=1;i<=n;i++){
        insertNode(head,i);
    }

    printNode(head);

    freeNode(head);
    return 0;
}

int insertNode(Node* h, int key){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=key;
    node->llink=NULL;
    node->rlink=NULL;

    if(h->rlink==NULL){
        h->rlink=node;
        return 0;
    }
    Node* n=h->rlink;
    while(n->rlink!=NULL){
        n=n->rlink;
    }
    n->rlink=node;
    node->llink=n;

    return 0;
}

int freeNode(Node* h){
    Node* p=h->rlink;

    Node* prev=NULL;

    while(p!=NULL){
        prev=p;
        p=p->rlink;
        free(prev);
    }
    free(h);
    return 0;
}

void printNode(Node* h){
    Node* p=h->rlink;

    while(p!=NULL){
        printf("%d",p->data);
        p=p->rlink;
    }
}