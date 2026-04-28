//Problem : Remove node from the end of the linked list
//Platform : GFG, Leetcode
//Difficulty : Medium

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* check = head;
        while(check != NULL){
            count++;
            check = check->next;
        }
        if(count == 0){
            return NULL;
        }else if( count == 1 && n==1){
            return NULL;
        }else if(count-n == 0){
            return head->next;
        }else if(n==1){
            check = head;
            count=count-1;
            int last=0;
            while(last < count-1){
                check = check->next;
                last++;
            }
            check->next = NULL;
            return head;
        }else{
            check = head;
            count = count - n-1;
            int last=0;
            while(last < count){
                check = check->next;
                last++;
            }
            check->next = check->next->next;
            return head;
        }
        return head;
    }
};