/* Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*/


#include <stdlib.h>

// Heap structure
typedef struct {
    int* arr;
    int size;
    int capacity;
} Heap;

// MedianFinder structure
typedef struct {
    Heap maxHeap; // left (max heap)
    Heap minHeap; // right (min heap)
} MedianFinder;

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Resize heap
void resizeHeap(Heap* h) {
    h->capacity *= 2;
    h->arr = (int*)realloc(h->arr, h->capacity * sizeof(int));
}

// Max Heapify Up
void maxHeapifyUp(Heap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent] < h->arr[i]) {
            swap(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else break;
    }
}

// Min Heapify Up
void minHeapifyUp(Heap* h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->arr[parent] > h->arr[i]) {
            swap(&h->arr[parent], &h->arr[i]);
            i = parent;
        } else break;
    }
}

// Max Heapify Down
void maxHeapifyDown(Heap* h, int i) {
    while (1) {
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < h->size && h->arr[l] > h->arr[largest])
            largest = l;
        if (r < h->size && h->arr[r] > h->arr[largest])
            largest = r;

        if (largest != i) {
            swap(&h->arr[i], &h->arr[largest]);
            i = largest;
        } else break;
    }
}

// Min Heapify Down
void minHeapifyDown(Heap* h, int i) {
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < h->size && h->arr[l] < h->arr[smallest])
            smallest = l;
        if (r < h->size && h->arr[r] < h->arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert into MaxHeap
void insertMax(Heap* h, int val) {
    if (h->size == h->capacity) {
        resizeHeap(h);
    }
    h->arr[h->size++] = val;
    maxHeapifyUp(h, h->size - 1);
}

// Insert into MinHeap
void insertMin(Heap* h, int val) {
    if (h->size == h->capacity) {
        resizeHeap(h);
    }
    h->arr[h->size++] = val;
    minHeapifyUp(h, h->size - 1);
}

// Extract Max
int extractMax(Heap* h) {
    int val = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    maxHeapifyDown(h, 0);
    return val;
}

// Extract Min
int extractMin(Heap* h) {
    int val = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    minHeapifyDown(h, 0);
    return val;
}

// Get top elements
int getMax(Heap* h) { return h->arr[0]; }
int getMin(Heap* h) { return h->arr[0]; }

// Create MedianFinder
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));

    obj->maxHeap.capacity = 100;
    obj->minHeap.capacity = 100;

    obj->maxHeap.arr = (int*)malloc(sizeof(int) * obj->maxHeap.capacity);
    obj->minHeap.arr = (int*)malloc(sizeof(int) * obj->minHeap.capacity);

    obj->maxHeap.size = 0;
    obj->minHeap.size = 0;

    return obj;
}

// Add number
void medianFinderAddNum(MedianFinder* obj, int num) {
    // Step 1: Insert into correct heap
    if (obj->maxHeap.size == 0 || num <= getMax(&obj->maxHeap)) {
        insertMax(&obj->maxHeap, num);
    } else {
        insertMin(&obj->minHeap, num);
    }

    // Step 2: Balance heaps
    if (obj->maxHeap.size > obj->minHeap.size + 1) {
        insertMin(&obj->minHeap, extractMax(&obj->maxHeap));
    } else if (obj->minHeap.size > obj->maxHeap.size) {
        insertMax(&obj->maxHeap, extractMin(&obj->minHeap));
    }
}

// Find median
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxHeap.size == obj->minHeap.size) {
        return (getMax(&obj->maxHeap) + getMin(&obj->minHeap)) / 2.0;
    }
    return getMax(&obj->maxHeap);
}

// Free memory
void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap.arr);
    free(obj->minHeap.arr);
    free(obj);
}
