//Problem : Sort linked list by 0,1 and 2
//Difficulty : Medium
//platform : GFG


/*APPROACH 

step 1: create a 6 diffenrent node (3 for the sorting and 3 for storing starting address)
step 2: Traverse the linked list 
step 3: check the each value and append to the node differently
step 4: at the end , connect each different node properly in sorted order

*/

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zero = NULL;
        Node* one = NULL;
        Node* two=NULL;
        Node* zero_copy = NULL;
        Node* one_copy = NULL;
        Node* two_copy=NULL;
        while(head != NULL){
            Node* first = head->next;
            if(head->data == 0){
                if(zero == NULL){
                    zero = head;
                    zero_copy = head;
                    zero->next = NULL;
                }else{
                    zero->next = head;
                    zero = zero->next;
                    zero->next=NULL;
                    
                }
            }
            else if(head->data == 1){
                if(one == NULL){
                    one = head;
                    one_copy = head;
                    one->next = NULL;
                }else{
                    one->next = head;
                    one = one->next;
                    one->next = NULL;
                }
            }else{
                if(two == NULL){
                    two = head;
                    two_copy = head;
                    two -> next = NULL;
                }else{
                    two->next = head;
                    two = two->next;
                    two ->next = NULL;
                }
            }
            head = first;
        }
        Node* newhead = NULL;
        if(zero != NULL){
            zero->next = one_copy;
            newhead = zero_copy;
        }else{
            newhead = one_copy;
        }
        
        if(one != NULL){
            one->next = two_copy;
        }else if(zero != NULL){
            zero->next = two_copy;
        }
        if(newhead == NULL){
            newhead = two_copy;
        }
        
        return newhead;
    }
};