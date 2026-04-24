//Problem: Remove loop in the linked list
//Platform : GFG,Leetcode
//Difficulty : Medium

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        map<Node*,int> check;
        Node* past = NULL;
        while(head != NULL){
            if(check.find(head) != check.end()){
                past -> next =NULL;
                return;
            }
            check[head]=1;
            past=head;
            head = head -> next;
        }
        return;
    }
};