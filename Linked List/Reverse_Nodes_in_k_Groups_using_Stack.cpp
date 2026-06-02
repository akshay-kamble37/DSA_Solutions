//Problem : Reverse Nodes in K groups using Stack
//Difficulty: Hard
//Platform: Leetcode/GFG


/*
APPROACH:

USING STACK 

Step 1: Check base cases, if true return head
step 2: Store Node in stack upto k and maintain counter(start=0)
step 3: if(start == k) pop the node and maintain pointer in the reverse order (Popping).
step 4: Repeat step 2 until head is equal to NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL|| k==0 || head->next == NULL || k==1) return head;
        ListNode* answer = new ListNode(0);
        ListNode* copy = answer ; 
        ListNode* next_node=copy;
        stack<ListNode*> st;
        int start = 0;
        while(head != NULL){
            st.push(head);
            start++;
            head = head->next;
            if(start == k){
                while(! st.empty()){
                    copy->next = st.top();
                    copy = copy->next;
                    copy->next = NULL;
                    st.pop();
                }
                start = 0;
                next_node = head;
            }
        }
        if(start != 0){
            copy->next = next_node;
        }
        return answer->next;

    }
};