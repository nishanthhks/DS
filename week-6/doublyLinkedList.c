#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNodeToLeft(struct Node* node, int newData) {
    if (node == NULL) {
        printf("Error: Cannot insert to the left of a NULL node.\n");
        return;
    }

    struct Node* newNode = createNode(newData);

    newNode->next = node;
    newNode->prev = node->prev;

    if (node->prev != NULL) {
        node->prev->next = newNode;
    } else {
        head = newNode;
    }

    node->prev = newNode;
}

void deleteNodeByValue(int value) {
    struct Node* current = head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void displayList() {
    struct Node* current = head;

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    insertNodeToLeft(second, 5);

    deleteNodeByValue(2);

    displayList();

    return 0;
}
