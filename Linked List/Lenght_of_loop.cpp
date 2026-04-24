//Problem: Find the length of the loop
//Platform: GFG, Leetcode
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
    int lengthOfLoop(Node *head) {
        // code here
        map<Node*,int> check;
        int count=1;
        while(head != NULL){
            if(check.find(head) != check.end()){
                return count - check[head];
            }
            check[head] = count;
            head = head -> next;
            count++;
        }
        return 0;
    }
};