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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        vector<int> finalans;
        while(! que.empty()){
            vector<int> level;
            int size = que.size();
            for(int i=0;i<size;i++){
                root = que.front();
                if(root->left != NULL) que.push(root->left);
                if(root->right != NULL) que.push(root->right);
                level.push_back(root->val);
                que.pop();
            }
            ans.push_back(level);
        }
        for(int i=0;i<ans.size();i++){
            finalans.push_back(ans[i].back());
        }
        return finalans;
    }
};