//Problem : Remove middle of the linked list
//Platform: GFG, Leetcode
//Difficulty : Medium

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
        // Your Code Here
        int count=1;
        Node* start=head;
        while(start != NULL){
            count++;
            start = start->next;
        }
        if(count == 2){
            return NULL;
        }else if(count == 3){
            head -> next = NULL;
            return head;
        }
        int value = 1;
        if( count%2 == 0){
            count = count/2-1;
        }else{
            count = count/2;
        }
        start = head;
        while(value < count){
            value++;
            start =start -> next;
        }
        start->next = start->next->next;
        return head;
    }
};