//Problem : Find the intersection point on Linked list
//difficulty: Easy
//Platform: GFG,Leetcode

/*APPROACH

step1: create a map
step2: travel the first linked list and store the pointer or memory address
step3: travel the second linked list and check the memory address in the map 
step4: if found return the address, else return NULL
*/



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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> check;
        while(headA != NULL){
            check[headA] = 1;
            headA= headA ->next;
        }
        while(headB != NULL){
            if(check.find(headB) != check.end()){
                return headB;
            }
            headB = headB ->next;
        }
        return NULL;
    }
};