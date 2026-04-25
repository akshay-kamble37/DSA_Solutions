//Problem : Checking the linked list is palindrome or not 
//Platform : GFG , Leetcode 
//Difficulty: Medium

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        vector<int> checking;
        while(head != NULL){
            checking.push_back(head ->  data);
            head = head -> next;
        }
        if(checking.size() == 0) return true;
        int left=0;
        int right=checking.size()-1;
        while(left < right){
            if(checking[left] == checking[right]){
                left++;
                right--;
            }else return false;
        }
        return true;
    }
};