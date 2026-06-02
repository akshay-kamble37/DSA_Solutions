//Problem : Remove Duplicates from the Sorted DLL
//Difficulty: Medium/Easy
//Platform : Leetcode / GFG

/*Approach:

Step 1 : Create a New Doubly linked list and Store -1 value, beacuse sorted DLL range start from 1
Step 2 : Keep record of the previous stored value
step 3 : Traverse the DLL and if the new value apprears change the prev and next of the Struct
Step 4 : Repeat Step 2 until head is equal to NULL

*/



/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
        
        Node* runner = new Node(-1);
        Node* answer = runner;
        int value = -1;
        while(head != NULL){
            if(head->data != value){
                value = head->data;
                answer->next = head;
                answer->next->prev = answer;
                answer=answer->next;
                head = head->next;
                answer->next = NULL;
            }else{
                head = head ->next;
            }
        }
        return runner->next;
    }
};