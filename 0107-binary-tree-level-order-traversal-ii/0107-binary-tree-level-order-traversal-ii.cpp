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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while( ! que.empty()){
            vector<int> add;
            int size = que.size();
            for(int i=0;i<size;i++){
                root = que.front();
                que.pop();
                if(root -> left != NULL) que.push(root->left);
                if(root -> right != NULL) que.push(root->right);
                add.push_back(root->val);
            }
            ans.push_back(add);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};