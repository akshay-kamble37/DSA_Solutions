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

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* current  = lists[i];
            while(current != NULL){
                pq.push(current);
                current = current->next;
            }
        }
        ListNode* head  = new ListNode(0);
        ListNode* copy = head;
        while( ! pq.empty()){
            head->next = pq.top();
            pq.pop();

            head = head->next;
            head->next = NULL;
        }
        return copy->next;
    }
};


/* APPROACH : 

step 1: Traversing the array of the linked list head.
step 2: Reading all the elements of the linked.
step 3: Adding the Linked list node in the priority queue
step 4: Priority queue is in min-heap (min heapify)
step 5: Reading all the element in the prority and add it to the linked list.
step 6: Return linked list 

*/