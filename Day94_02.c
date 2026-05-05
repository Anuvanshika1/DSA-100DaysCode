/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    // 1. Initialize a frequency array for elements 0-1000
    int count[1001] = {0};
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    // 2. Allocate memory for the result array
    int* result = (int*)malloc(sizeof(int) * arr1Size);
    int index = 0;

    // 3. Fill result with elements from arr2 in the correct order
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // 4. Fill remaining elements in ascending order
    for (int i = 0; i < 1001; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return result;
}
