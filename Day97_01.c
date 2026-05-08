/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int heap[], int size, int index) {
    while(1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, (*size)-1);
}

int removeMin(int heap[], int *size) {
    int min = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);

    return min;
}

int main() {
    Meeting meetings[] = {{0,30}, {5,10}, {15,20}};
    int n = 3;

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[100];
    int heapSize = 0;

    insertHeap(heap, &heapSize, meetings[0].end);

    for(int i = 1; i < n; i++) {

        if(meetings[i].start >= heap[0]) {
            removeMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, meetings[i].end);
    }

    printf("Minimum meeting rooms required = %d\n", heapSize);

    return 0;
}
