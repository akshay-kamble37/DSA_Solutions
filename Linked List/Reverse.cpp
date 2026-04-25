//Problem : Reverse a linked list
//Platform : Leetcode, GFG
//Difficulty: Easy


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
    ListNode* reverseList(ListNode* head) {
        vector<int> value;
        ListNode* ptr  = head;
        while(ptr != NULL){
            value.push_back(ptr -> val);
            ptr = ptr -> next;
        }
        ptr = head;
        int point = value.size()-1;
        while(ptr != NULL){
            ptr -> val = value[point];
            ptr = ptr -> next;
            point--;
        }
        return head;
    }
};