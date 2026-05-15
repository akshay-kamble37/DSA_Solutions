//Problem : Add two linked list numbers and return the head
//Difficulty: Medium
//Platform: Leetcode/GFG

/*
APPROACH:

step 1:traverse in both linked list simultaneously and move with carry if generated
step 2:every time checks carry generated or not 
step 3:if one of the list reached NULL , traverse another list 
step 4:at the end check for the carry , if carry is present creates extra node and push value 1 to it
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0);
        ListNode* copy = answer;
        int data =0;
        int count=0;
        while(l1 != NULL && l2 != NULL){
            data = l1->val + l2->val;
            if(count == 1) data++;
            if(data > 9){
                data=data%10;
                count=1;
            }else{
                count=0;
            }
            ListNode* create = new ListNode(data);
            copy->next = create;
            copy = copy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            data = l1->val;
            if(count == 1) data++;
            if(data > 9){
                data=data%10;
                count=1;
            }else{
                count=0;
            }
            ListNode* create = new ListNode(data);
            copy->next = create;
            copy = copy->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            data =  l2->val;
            if(count == 1) data++;
            if(data > 9){
                data=data%10;
                count=1;
            }else{
                count=0;
            }
            ListNode* create = new ListNode(data);
            copy->next = create;
            copy = copy->next;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 == NULL && count==1){
            ListNode* create = new ListNode(1);
            copy->next = create;
            copy = copy->next;
        }
        return answer->next;
    }
};