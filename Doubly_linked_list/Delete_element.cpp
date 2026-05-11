//Problem : Delete element in the Doubly-linked list
//Platform: Leetcode,GFG
//Difficulty: Easy

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    void *deletemid(Node *current){
        current->prev->next=current->next;
        current->next->prev=current->prev;
    }
    void *deleteend(Node *current){
        current->prev->next=NULL;
        current->prev=NULL;
    }
    Node* delPos(Node* head, int x) {
        // code here
        if(x==1){
            if(head->next == NULL) return NULL;
            Node* current = head;
            current=current->next;
            current->prev->next= NULL;
            current->prev = NULL;
            return current;
        }
        int count=1;
        Node* current = head;
        while(count<x && current->next != NULL){
            count++;
            current= current->next;
        }
        if(current->next != NULL){
            deletemid(current);
        }else{
            deleteend(current);
        }
        return head;
    }
};