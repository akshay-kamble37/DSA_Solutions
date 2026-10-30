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
    void check(TreeNode* root,priority_queue<int,vector<int>,greater<int>> &pq,unordered_map<int,int> &mp){
        if(root == NULL) return;
        
        if(mp.find(root->val) == mp.end()){
            mp[root->val] = 1;
            pq.push(root->val);
        }

        check(root->left,pq,mp);
        check(root->right,pq,mp);
    }


    int findSecondMinimumValue(TreeNode* root) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> mp;

        pq.push(root->val);
        mp[root->val] = 1;

        check(root,pq,mp);

        pq.pop();

        if(pq.empty()) return -1;

        return pq.top();

    }
};