/*In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 */
#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place m balls with minimum distance = dist
int canPlace(int pos[], int n, int m, int dist) {
    int count = 1;  // first ball placed
    int last = pos[0];

    for(int i = 1; i < n; i++) {
        if(pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if(count >= m)
            return 1;
    }
    return 0;
}

int maxDistance(int pos[], int n, int m) {
    qsort(pos, n, sizeof(int), compare);

    int low = 1;
    int high = pos[n - 1] - pos[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(pos, n, m, mid)) {
            ans = mid;       // valid
            low = mid + 1;   // try bigger distance
        } else {
            high = mid - 1;  // reduce distance
        }
    }

    return ans;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int pos[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }

    printf("%d\n", maxDistance(pos, n, m));

    return 0;
}
