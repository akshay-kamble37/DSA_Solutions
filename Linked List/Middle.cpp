//Problem : find the middle of the linked list and the node
//Platform : GFG
//Difficulty : Easy


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
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode* check=head;
        while( check != NULL){
            count++;
            check = check -> next;
        }
        count = count/2 + 1;
        check = head ;
        int run=1;
        while( run < count){
            check = check -> next;
            run++;
        }
        return check;
    }
};