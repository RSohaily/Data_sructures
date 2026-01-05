6.  Çembersel Linked list silme kodu, araya ekleme, traversal

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
}

void insertAtPosition(int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    if (head == NULL) return;
    struct Node* temp = head;
    if (pos == 1) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }
        struct Node* last = head->prev;
        head = head->next;
        last->next = head;
        head->prev = last;
        free(temp);
        return;
    }
    for (int i = 1; temp->next != head && i < pos; i++) {
        temp = temp->next;
    }
    if (temp->next == head && pos > 1) return;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void traverse() {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    traverse();
    insertAtPosition(15, 2);
    traverse();
    deleteAtPosition(3);
    traverse();
    return 0;
}
