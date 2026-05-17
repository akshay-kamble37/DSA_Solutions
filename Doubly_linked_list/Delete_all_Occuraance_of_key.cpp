//Problem: Delete all Occurance of the key in the Doubly linked list
//Difficulty: Medium
//Platform : GFG


/* APPROACH:

step 1: traverse the linked list and serach for the key
step 2: if the element not found append in the linked list
step 3: if element found mover forward
step 4: At the end , return the head of the Linked list
*/


/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {
        if(head == NULL) return NULL;
        if(head->next == NULL && head->data == x) return NULL;
        Node* answer = new Node(0);
        Node* copy = answer;
        while(head != NULL){
            if(head->data != x){
                Node* newnode = new Node(head->data);
                answer->next = newnode;
                newnode->prev = answer;
                answer = answer->next;
                newnode->next = NULL;
            }
            head = head->next;
        }
        copy = copy->next ;
        copy->prev = NULL;
        return copy;
    }
};