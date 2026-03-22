/* Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[*index] = root->val;
    (*index)++;

    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int totalNodes = countNodes(root);

    int* result = (int*)malloc(sizeof(int) * totalNodes);

    int index = 0;

    preorder(root, result, &index);

    *returnSize = totalNodes;

    return result;
}
