/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int point=0;
        map<ListNode*,int> store;
        while(head != NULL){
            if(store.find(head) != store.end()){
                return head;
            }
            store[head] = point;
            head = head -> next;
        }
        return NULL;
    }
};