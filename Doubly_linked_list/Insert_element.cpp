//Problem : Insert element in the Doubly-linked list
//Platform: Leetcode,GFG
//Difficulty: Easy

/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    void *insert(Node *current,int value){
        Node* newNode =new Node(value);
        newNode -> next = current ->next;
        current->next->prev = newNode;
        newNode->prev = current;
        current->next = newNode;
    }
    
    void *insertend(Node *current,int value){
        Node* newnode = new Node(value);
        newnode -> prev = current;
        current->next = newnode;
        newnode->next = NULL;
    }
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        int count=0;
        Node* current = head;
        while(count < p && current->next != NULL){
            count++;
            current = current ->next;
        }
        if(current -> next != NULL){
            insert(current,x);
        }else{
            insertend(current,x);
        }
        return head;
    }
};