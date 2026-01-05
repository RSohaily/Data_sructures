// Max, Min Heap

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMaxHeap(int value) {
    heap[size] = value;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertMinHeap(int value) {
    heap[size] = value;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insertMaxHeap(10);
    insertMaxHeap(20);
    insertMaxHeap(5);
    insertMaxHeap(30);
    printHeap();

    size = 0;
    insertMinHeap(10);
    insertMinHeap(20);
    insertMinHeap(5);
    insertMinHeap(30);
    printHeap();

    return 0;
}
