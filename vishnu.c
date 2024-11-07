#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heapSize = 0;
int heap[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left] > heap[largest])
        largest = left;
    if (right < heapSize && heap[right] > heap[largest])
        largest = right;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}

void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

void insert(int key) {
    if (heapSize >= MAX) {
        printf("Heap overflow\n");
        return;
    }
    heap[heapSize] = key;
    int i = heapSize;
    heapSize++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteElement(int i) {
    if (i < 0 || i >= heapSize) {
        printf("Invalid index\n");
        return;
    }
    heap[i] = heap[heapSize - 1];
    heapSize--;
    maxHeapify(i);
}

void displayHeap() {
    if (heapSize == 0) {
        printf("Heap is empty\n");
        return;
    }
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, element, index;
    while (1) {
        printf("\n1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                printf("Enter index of element to delete: ");
                scanf("%d", &index);
                deleteElement(index);
                break;
            case 3:
                printf("Heap content: ");
                displayHeap();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
