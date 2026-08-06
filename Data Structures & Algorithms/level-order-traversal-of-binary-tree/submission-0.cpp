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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tree;
        vector<vector<int>> levels;
        if (!root) return levels;
        tree.push(root);
        while (tree.size() > 0) {
            int size = tree.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* current = tree.front();
                if (current->left != nullptr) {
                    tree.push(current->left);
                } if (current->right != nullptr) {
                    tree.push(current->right);
                } 
                level.push_back(current->val);
                tree.pop();
            }
            levels.push_back(level);
        }
        return levels;
    }
};
