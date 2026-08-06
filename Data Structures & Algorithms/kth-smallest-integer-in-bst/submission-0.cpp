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
    int kthSmallest(TreeNode* root, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        while (nodes.size() > 0) {
            for (int i = 0; i < nodes.size(); i++) {
                TreeNode* current = nodes.front();
                minHeap.push(current->val);
                if (current->right) {
                    nodes.push(current->right);
                }
                if (current->left) {
                    nodes.push(current->left);
                }
                nodes.pop();
            }
        }
        for (int i = 0; i < k - 1; i++) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
