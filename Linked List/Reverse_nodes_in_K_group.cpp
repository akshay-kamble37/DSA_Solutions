//Problem : Reverse Nodes in a K Group
//Difficulty: Hard
//Platform: Leetcode/GFG


/*APPROACH :

step 1: Storing Node values in Vector.
step 2: Reversing node values in a K group (start = 0 and end = k)
step 3: increase value of start and end by K until k reaches to the size of the vector.
step 4: Store the reverse valued vector in the Linked list.
step 5: Return the head 

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
        if(head == NULL || k==0 || head->next == NULL|| k==1) return head;
        ListNode* runner = head;
        vector<int> answer;
        while(runner->next != NULL){
            answer.push_back(runner->val);
            runner = runner->next;
        }
        answer.push_back(runner->val);
        int start = 0;
        int end = k;
        while(end <= answer.size()){
            reverse(answer.begin()+start,answer.begin()+end);
            start+=k;
            end+=k;
        }
        runner = head;
        start =0;
        while(start < answer.size()){
            runner->val = answer[start];
            start++;
            runner = runner->next;
        }
        return head;

    }
};