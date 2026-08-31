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
        if(root == NULL) return {};
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        que.push(root);
        while(! que.empty()){    // while queue is not empty check 
            vector<int> add;     // create array for reading the element on the same level
            int size = que.size();      
            for(int i=0;i<size;i++){        
                root = que.front();
                que.pop();
                if(root->left != NULL) que.push(root->left);        //add element of the next level
                if(root->right != NULL) que.push(root->right);
                add.push_back(root->val); 
            }
            ans.push_back(add);         // add particular level element to the array
        }
        return ans;
    }
};