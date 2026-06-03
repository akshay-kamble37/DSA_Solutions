//Problem: Flattening a Linked list
//Difficulty: Medium
//Platform: GFG

/*
APPROACH:

Using Recursion and Merge concepts

step 1: In Resursive Function, traverse upto last head of the linked list/
step 2: Merge the Two Linked list last and Second last in Recursive way and return new root head.

step 3: IN merge Function:

-- Merge Two Linked list by comparing the element of the each other.


Time Complexity : Big O (2*m*n) m(bottom length) n(horizontal length)

*/


/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge(Node* list1,Node* list2){
        Node* DummyAnswer = new Node(-1);
        Node* runner = DummyAnswer;
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                runner->bottom = list1;
                list1 = list1->bottom ;
                runner = runner->bottom ;
                runner->bottom = NULL;
            }else{
                runner->bottom = list2;
                list2 = list2->bottom;
                runner = runner->bottom ;
                runner->bottom = NULL;
            }
            runner->next = NULL;
        }
        if(list1 == NULL) runner->bottom=list2;
        else runner->bottom = list1;
        
        if(DummyAnswer->bottom) DummyAnswer->bottom->next = NULL;
        return DummyAnswer->bottom;

    }
    
    Node *flatten(Node *root) {
        if(root == NULL || root->next == NULL){
            return root;
        }
        Node* mergehead = flatten(root->next);
        root = merge(root , mergehead);
        
        return root;
    }
};