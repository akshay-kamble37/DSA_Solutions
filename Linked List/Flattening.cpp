//Problem : Flattening a Linked list
//Difficulty: Medium 
//Platform : GFG

/* APPROACH:

Reading a linked list and Sorting it by Manual Method.

step 1: Starting with a Head -

    if(Bottom is available at the standing position then read and Store value until Bottom is equal to NULL)

    else Move towards next pointer

step 2: Sort the value which is stored in the vector.
step 3: Creating a New Node every time for new value and link it to bottom.


*/


/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node *flatten(Node *root) {
        if(root == NULL) return root;
        vector<int> answer;
        while(root != NULL){
            answer.push_back(root->data);
            Node* Bot = root->bottom;
            while(Bot != NULL){
                answer.push_back(Bot->data);
                Bot = Bot->bottom ;
            }
            root = root->next;
        }
        sort(answer.begin(),answer.end());
        int point = 0 ;
        Node* result = new Node(0);
        Node* copy = result;
        while(point < answer.size()){
            Node* newone=new Node(answer[point]);
            copy->bottom = newone;
            copy = copy->bottom;
            point++;
        }
        return result->bottom;
    }
};