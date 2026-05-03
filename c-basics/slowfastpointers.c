#include <stdio.h>

typedef struct Node {
    int data;
    Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}
int main() {
    Node *n1 = createNode(1);
    Node *n2 = createNode(2);
    n1->next = n2;
    Node *head = n1;
    while(head->next) {
        printf("")
    }
}