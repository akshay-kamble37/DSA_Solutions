//Problem : Search element in the Linked list
//Platform : GFG
//Difficulty : Easy

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        while(head != NULL){
            if(head -> data == key){
                return true;
            }
            head = head -> next;
        }
        return false;
    }
};
