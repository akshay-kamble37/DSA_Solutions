/**
 * Definition for singly-linked vec.
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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* start = head;
        while(start != NULL){
            vec.push_back(start);
            start = start->next ;
        }

        int left = 0;
        int right = vec.size()-1;

        while(left < right ){
            auto current = vec[left];
            auto next_node = vec[right];
            
            current -> next = next_node;

            left++;

            auto next_one = vec[left];
            next_node -> next = next_one;

            right--;
        }

        vec[left]->next = nullptr;
        
    }
};



/* APPROACH - 

step 1 : Store all the node in the vector
step 2 : for each iteration change the poiter of the node according to the condition requirement
step 3 : After the complition of the iteration make the last node null

*/