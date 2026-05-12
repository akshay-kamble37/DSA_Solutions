//Problem: Intersection of the two linked list
//Platform : GFG
//Difficulty: easy

/*APPROACH

step 1: check base case if one the linked list is empty then return NULL
step 2: travell the linked list 2 and store the value in map
step 3: travell the linked list 1 and store the value with pointer in new linked list
*/


/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        if(head1 == NULL || head2 == NULL){
            return NULL;
        }
        map<int,int> check;
        while(head2 != NULL){
            check[head2->data] = 1;
            head2 = head2->next;
        }
        Node* answer=NULL;
        Node* copy_ans=NULL;
        while(head1 != NULL){
            Node* nextnode = head1->next;
            if(check.find(head1->data) != check.end()){
                if(answer == NULL){
                    answer=head1;
                    answer->next = NULL;
                    copy_ans=head1;
                }else{
                    answer->next=head1;
                    answer = answer->next;
                    answer->next = NULL;
                }
            }
            head1 = nextnode;
        }
        if(answer != NULL) return copy_ans;
        return answer;
    }
};