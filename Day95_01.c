/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list in each bucket
struct Node {
    float data;
    struct Node* next;
};

// Function to sort individual buckets using Insertion Sort
struct Node* InsertionSort(struct Node* list) {
    if (!list || !list->next) return list;

    struct Node* sorted = NULL;
    struct Node* current = list;

    while (current != NULL) {
        struct Node* next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void BucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    // 1. Initialize empty buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        int bucketIdx = n * arr[i]; // Indexing logic
        newNode->next = buckets[bucketIdx];
        buckets[bucketIdx] = newNode;
    }

    // 3. Sort each bucket and 4. Concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = InsertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Free memory as we go
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    BucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}
