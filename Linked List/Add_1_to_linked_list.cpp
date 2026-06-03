//Problem  : Add 1 to a linked list
//Difficulty: Medium
//Platform: GFG

/*
APPROACH:

Using STACK

step 1: Traverse to the end of the linked list and store the Node(address) in the stack
step 2: As the pointer reaches to end , start Poping and add 1 to the first element
step 3: As the Nodes pop from the stack,it will be in reverse order
step 4: Check the element (data) and perform additon according to the carry.
step 5: At the last(if still carry is present) create a New Node with data = 1 , and linked it with previous head
step 6: return head

*/

/* Structure of linked list Node
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
    Node* addOne(Node* head) {
        if(head == NULL){
            Node* Answer = new Node(1);
            return Answer;
        }
        Node* copyhead = head;
        stack<Node*> Record;
        while(head != NULL){
            Record.push(head);
            head = head->next;
        }
        int first=1;
        int count =0;
        while( ! Record.empty()){
            Node* copy = Record.top();
            if(first == 1 || count == 1){
                copy->data+=1;
                if(copy->data > 9){
                    count=1;
                    copy->data %= 10;
                }else count=0;
                first--;
            }
            Record.pop();
        }
        if(count==1){
            Node* newHead = new Node(1);
            newHead->next = copyhead;
            return newHead;
        }
        return copyhead;
    }
};