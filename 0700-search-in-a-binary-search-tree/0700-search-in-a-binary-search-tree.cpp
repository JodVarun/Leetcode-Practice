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
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<int> ans;
        TreeNode* root1 = nullptr;
        search(root, val, root1);
        return root1;

        
        
    }
    void search(TreeNode* root, int val, TreeNode* &root1){
        if(!root) return;
        if(root->val == val) {
            root1 = root;
            return;
        }
        if(val>root->val) search(root->right,val,root1);
        else if(val<root->val) search(root->left,val,root1);
    }
};