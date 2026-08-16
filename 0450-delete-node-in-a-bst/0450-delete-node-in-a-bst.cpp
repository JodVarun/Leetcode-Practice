/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

    // 1. Search for the node to delete
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // 2. Node found! Handle the 3 cases:

        // Cases 1 & 2: 0 or 1 child
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        // Find Inorder Successor (min node in right subtree)
        TreeNode* curr = root->right;
        while (curr->left) {
            curr = curr->left;
        }

        // Copy successor value to current node
        root->val = curr->val;

        // Recursively delete the duplicate successor node
        root->right = deleteNode(root->right, curr->val);
    }
    return root;
        
    }
};