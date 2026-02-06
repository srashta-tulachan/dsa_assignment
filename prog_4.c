#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* insertAtBeginning(struct Node* head, int data)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data= data;
  newNode->prev=NULL;
  newNode->next=head;

  if(head!= NULL)
      head->prev = newNode;

      return newNode;
}

void insertAfter(struct Node* givenNode, int data) {
    if (givenNode == NULL) {
        printf("Given node is NULL\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = givenNode->next;
    newNode->prev = givenNode;

    if (givenNode->next != NULL)
        givenNode->next->prev = newNode;

    givenNode->next = newNode;
}


struct Node* deleteNode(struct Node* head, struct Node* delNode) {
    if (head == NULL || delNode == NULL)
        return head;

    if (head == delNode)
        head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Initial list:\n");
    display(head);

    insertAfter(head->next, 25);
    printf("After inserting 25 after second node:\n");
    display(head);

    head = deleteNode(head, head->next);
    printf("After deleting second node:\n");
    display(head);

    return 0;
}