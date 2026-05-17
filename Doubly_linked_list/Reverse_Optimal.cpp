//Problem : Reverse the element in the Doubly linked list
//Difficulty: Easy
//Platform: GFG

/* Approch

Two-pointer Approach
1. Create Node first and last
2.Travelled to the last node
3.swapping the values
4.increaments first and decreament last
5.Repeat step 3 until the break condition

*/



/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head == NULL) return NULL;
        Node* first=head;
        Node* last=head;
        while(last->next != NULL){
            last = last->next;
        }
        Node* lastvisit = head;
        while(lastvisit != last && first != last){
            int copy=first->data;
            first->data = last->data;
            last->data = copy;
            lastvisit = first;
            first = first->next;
            last = last->prev;
        }
        return head;
    }
};