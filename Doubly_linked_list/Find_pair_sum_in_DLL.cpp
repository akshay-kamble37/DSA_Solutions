//Problem : Find Pairs which sums is equal to the target in DLL
//Difficulty : Easy
//Platform : GFG


/*APPROACH:

Optimal Solution : Two-pointer Approach

step 1: check base case, if head is already null return empty vector.
step 2: create a new Node , store last element address in it.
step 3: Apply two pointer Approach--
        
    A) check both value with head and back node - 
    if equals to the target add in the vector in form of pair

    B) if sum is greater than target-
    Move back to the previous node

    C)if sum is smaller than target
    Move head to the previous node

*/

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(head == NULL) return {};
        vector<pair<int,int>> answer;
        pair<int,int> ans;
        Node* back = head;
        while(back->next != NULL) back = back->next;
        while(head != back && head != NULL && back != NULL){
            int a=head->data;
            int b=back->data;
            if( a+b == target){
                ans.first=a;
                ans.second=b;
                answer.push_back(ans);
                if(head->next != back){
                    head=head->next;
                    back=back->prev;
                }
                else break;
                
            }else if( a+b > target){
                back = back->prev;
            }else{
                head = head->next;
            }
        }
        return answer;
        
    }
};