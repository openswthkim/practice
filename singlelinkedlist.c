#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* nextNode;
} Node;

int insertNode(Node* h, int key);
int freeNode(Node* h);
void printNode(Node* h);

int main() {
    int n;
    scanf("%d", &n);

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->nextNode = NULL;

   for (int i = 1; i <= n; i++)
      insertNode(head, i);

   printNode(head);

   freeNode(head);

    return 0;
}

int insertNode(Node* h, int key) {   
   Node* node = (Node*)malloc(sizeof(Node));   
   node->data = key;   
   node->nextNode = NULL;

   if (h->nextNode == NULL)
   {
      h->nextNode = node;
      return 0;
   }

   Node* n = h->nextNode;   
   while (n->nextNode != NULL) {   
      n = n->nextNode;   
   }
   n->nextNode = node;   

   return 0;
}

int freeNode(Node* h) {
   Node* p = h->nextNode;

   Node* prev = NULL; 
   while (p != NULL) {
      prev = p;
      p = p->nextNode;
      free(prev);
   }
   free(h);

   return 0;
}

void printNode(Node* h) {
   Node* p;

   p = h->nextNode;

   while (p != NULL) {
      printf("%d ", p->data);
      p = p->nextNode;
   }
}