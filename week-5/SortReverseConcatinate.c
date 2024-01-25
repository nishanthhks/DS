#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* first, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL) {
        return newNode;
    }

    struct Node* ptr = first;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    return first;
}

void sort(struct Node* first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr;
    struct Node* p;

    for (ptr = first; ptr != NULL; ptr = ptr->next) {
        bool swapped = false;
        for (p = first; p->next != NULL; p = p->next) {
            if (p->data > (p->next)->data) {
                int temp = p->data;
                p->data = (p->next)->data;
                (p->next)->data = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    struct Node* p1 = first;
    while (p1 != NULL) {
        printf(" Element: %d", p1->data);
        p1 = p1->next;
    }
    printf("\n");
}

void display(struct Node* first) {
    struct Node* p1 = first;
    while (p1 != NULL) {
        printf(" Element: %d", p1->data);
        p1 = p1->next;
    }
    printf("\n");
}

struct Node* reverse(struct Node* first) {
    struct Node* prev = NULL;
    struct Node* current = first;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node* concatenate(struct Node* first1, struct Node* first2) {
    if (first1 == NULL) {
        return first2;
    }

    struct Node* ptr = first1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = first2;
    return first1;
}

int main() {
    struct Node* first1 = NULL;
    struct Node* first2 = NULL;
    int n, ele;

    do {
        printf("\n1. Add Element to List 1\n2. Sort List 1\n3. Reverse List 1\n4. Display List 1\n");
        printf("5. Add Element to List 2\n6. Sort List 2\n7. Reverse List 2\n8. Display List 2\n");
        printf("9. Concatenate Lists\n10. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter the data for List 1:\n");
                scanf("%d", &ele);
                first1 = insert(first1, ele);
                break;
            case 2:
                sort(first1);
                break;
            case 3:
                first1 = reverse(first1);
                printf("List 1 reversed.\n");
                break;
            case 4:
                display(first1);
                break;
            case 5:
                printf("Enter the data for List 2:\n");
                scanf("%d", &ele);
                first2 = insert(first2, ele);
                break;
            case 6:
                sort(first2);
                break;
            case 7:
                first2 = reverse(first2);
                printf("List 2 reversed.\n");
                break;
            case 8:
                display(first2);
                break;
            case 9:
                first1 = concatenate(first1, first2);
                printf("Lists concatenated.\n");
                break;
            case 10:
                exit(0);
            default:
                printf("Enter correct choice\n");
        }
    } while (1);

    return 0;
}
