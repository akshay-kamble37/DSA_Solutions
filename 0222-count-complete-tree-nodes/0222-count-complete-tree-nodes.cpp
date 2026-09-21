#define ULL unsigned long long
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
    int countleft(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int countright(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = countleft(root->left);
        int rh = countright(root->right);

        // Perfect binary tree
        if (lh == rh)
            return (1 << (lh + 1)) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};

/* BFS


void rightside(TreeNode* root,int level,ULL &count,ULL value,vector<ULL> &rightvec,bool &completed){
        if(root == NULL) return;
        if(completed == true) return;
        if (level == rightvec.size() && ((value & (value - 1)) == 0)) {
            rightvec.push_back(1);
            count += value;
        }else{
            count += value;
            completed = true;
        }
        rightside(root->right,level+1,count,value*2,rightvec,completed);
        rightside(root->left,level+1,count,value*2-1,rightvec,completed);
    }
    ULL countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        ULL count = 0 ;
        vector<ULL> rightvec;
        bool completed = false;
        rightside(root,0,count,1,rightvec,completed);
        return count;

    }

BFS - BREADTH FIRST SEARCH

if(root == NULL) return 0;
        queue<TreeNode*> que;
        que.push(root);
        long long count = 0;
        while(! que.empty()){
            long long size = que.size();
            count += size;
            for(long long i=0;i<size;i++){
                TreeNode* current = que.front();
                que.pop();
                if(current->left != NULL) que.push(current->left);
                if(current->right != NULL) que.push(current->right); 
            }
        }
        return count;

step 1 : COUNTING THE NODE ON EACH LEVEL
step 2 : ADDING COUNT TO THE VARIABLE COUNT
step 3 : RETURNING COUNT 

*/