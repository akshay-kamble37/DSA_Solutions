/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void BFS(Node* root){
        queue<Node*> que;
        que.push(root);
        while(! que.empty()){
            int size = que.size();
            vector<Node*> vec;
            for(int i=0;i<size;i++){
                Node* current = que.front();
                vec.push_back(current);
                que.pop();
                if(current->left != NULL)  que.push(current->left);
                if(current->right != NULL)  que.push(current->right);
            }
            for(int i=0;i<size-1;i++){
                Node* append = vec[i];
                Node* next_append = vec[i+1];
                append->next = next_append;
            }
        }
    }
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* copy = root;
        BFS(root);
        return copy;
    }
};