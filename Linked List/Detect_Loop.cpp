//Problem : Detect loop in the linked list
//Platform: Leetcode,GFG
//Difficulty: Medium

/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        map<Node*,int> address;
        while(head != NULL){
            if(address.find(head) != address.end()){
                return true;
            }
            address[head]=1;
            head = head->next;
        }
        return false;
    }
};