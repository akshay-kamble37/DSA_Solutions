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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> que;
        int read = 0;
        vector<vector<int>> ans;
        que.push(root);
        while(! que.empty()){
            int size = que.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* current = que.front();
                que.pop();
                level.push_back(current->val);
                if(current->left != NULL) que.push(current->left);
                if(current->right != NULL) que.push(current->right);
            }

            if(read == 1){
                read = 0;
                reverse(level.begin(),level.end());
            }else read = 1;
            ans.push_back(level);
        }
        return ans;
    }
};