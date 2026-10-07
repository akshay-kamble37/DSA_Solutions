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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;
        while(! que.empty()){
            int size = que.size();
            int max_value = -INT_MAX-1;
            for(int i=0;i<size;i++){
                TreeNode* value = que.front();
                que.pop();
                max_value = max(max_value,value->val);
                if(value -> left != NULL) que.push(value->left);
                if(value -> right != NULL) que.push(value->right);
            }
            ans.push_back(max_value);
        }
        return ans;
    }
};

/* APPROACH 

using BFS we find maximum value at each level.

step 1 : if root is already NULL return empty array.
step 2 : if not create a queue and push root value in it.
step 3 : at each level keep the maximum value 
step 4 : at the end of the level add the value in vector
step 5 : return vector

*/