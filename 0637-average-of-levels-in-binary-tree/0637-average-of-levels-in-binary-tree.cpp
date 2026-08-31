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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        vector<double> ans;
        queue<TreeNode*> que;
        que.push(root);
        while( ! que.empty()){
            int size = que.size();
            double number = 0;
            for(int i=0;i<size;i++){
                root = que.front();
                que.pop();
                if(root->left != NULL) que.push(root->left);
                if(root->right != NULL) que.push(root->right);
                number += root->val;
            }
            ans.push_back(number/size);
        }
        return ans;
    }
};