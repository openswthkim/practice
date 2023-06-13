#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node* left;
   struct Node* right;
}Node;

//스택
#define MAX_STACK_SIZE 20
Node* stack[MAX_STACK_SIZE];
int top = -1;

//큐
#define MAX_QUEUE_SIZE 20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;   
int rear = -1;

void insertNode(Node* h, int key);
void iterativeInorder(Node* h);
void levelOrder(Node* h);
void freeNode(Node* h);
void freeBST(Node* h);

//스택 팝, 푸시
Node* pop();
void push(Node* h);

//큐 인큐, 디큐
Node* deQueue();
void enQueue(Node* h);

int main() {
   int i;

   Node* head = (Node*)malloc(sizeof(Node));
   head->data = 0;
   head->left = NULL;
   head->right = head;

   do {
      scanf("%d", &i);
      /* Binary Search Tree에 노드 추가 */
      if (i == -1)
         break;

      insertNode(head, i);
   } while (i != -1);

   iterativeInorder(head->left);
   printf("\n");
   levelOrder(head->left);
   printf("\n");

   freeBST(head);

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
   Node* parent = NULL;

   while (ptr != NULL) {
      if (ptr->data == key) {
         free(newNode);
         return;
      }

      parent = ptr;
      if (ptr->data < key)
         ptr = ptr->right;
      else
         ptr = ptr->left;
   }

   if (parent->data < key)
      parent->right = newNode;
   else
      parent->left = newNode;
}
void iterativeInorder(Node* h) {
   while (1) {
      for (; h; h = h->left)
         push(h);            
      h = pop();            

      if (!h)
         break;
      printf(" [%d] ", h->data); 

      h = h->right; 
   }
}
void levelOrder(Node* h) {
   if (!h)
      return;

   enQueue(h);

   while (1) {
      h = deQueue();
      if (h) {
         printf(" [%d] ", h->data);

         if (h->left)         
            enQueue(h->left);   
         if (h->right)          
            enQueue(h->right); 
      }
      else
         break;
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

   freeNode(h->left);
   free(h);
}
Node* pop() {
   if (top < 0)
      return NULL;
   return stack[top--];
}
void push(Node* h) {
   stack[++top] = h;
}
Node* deQueue() {
   if (front == rear)
      return NULL;

   front = (front + 1) % MAX_QUEUE_SIZE;
   return queue[front];
}
void enQueue(Node* h) {
   rear = (rear + 1) % MAX_QUEUE_SIZE; 
   if (front == rear)            
      return;

   queue[rear] = h;
}