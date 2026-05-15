//Problem : Merge two sorted linked list
//Difficulty: Medium 
//Platform : Leetcode/GFG

/*
APPROACH

step 1:traverse both the linked list simulataneously, compare each elements
step 2:append the samllest element first and moves to next within the same linked list
step 3:if one of the linked list pointer is NULL ,other remaining list is already sorted 
so, directly append it to the merged-sorted linked list

*/

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if(head1 == NULL && head2 != NULL)  return head2;
        if(head1 != NULL && head2== NULL)  return head1;
        Node* answer= new Node(0);
        Node* sorted = answer;
        while(head1 != NULL && head2!= NULL){
            if((head1->data) < (head2->data)){
                Node* newnode = new Node(head1->data);
                answer->next = newnode;
                answer= answer->next;
                answer->next = NULL;
                head1 = head1->next;
            }else{
                Node* newnode = new Node(head2->data);
                answer->next = newnode;
                answer= answer->next;
                answer->next = NULL;
                head2 = head2->next;
            }
        }
        if(head1 == NULL){
            answer->next = head2;
        }
        if(head2 == NULL){
            answer->next = head1;
        }
        return sorted->next;
    }
};