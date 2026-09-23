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
    void add(TreeNode* root, int k,set<int> &st){
        if(root == NULL) return ;
        st.insert(root->val);
        add(root->left,k,st);
        add(root->right,k,st);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root== NULL ) return 0;
        set<int> st;
        add(root,k,st);
        int point = 1;
        for(auto it:st){
            if(point == k){
                return it;
            }
            point++;
        }
        return 0;
    }
};