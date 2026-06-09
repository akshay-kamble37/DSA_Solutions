//Problem : Reverse a Stack using Recursion
//Difficulty: Medium
//Platform : Leetcode / GFG


/*Approach:

Step 1 : Remove the top element from the stack
Step 2 : Recursively call reverseStack() for the remaining stack
Step 3 : Insert the removed element at the bottom of the stack using reverse()

Step 4 : In reverse():
         - If stack is empty, push the element (this ensures it goes to bottom)
         - Else:
             -> Pop the top element
             -> Recursively call reverse() to reach bottom
             -> Push the popped element back

Step 5 : Repeat until all elements are reversed

Time Complexity :
- O(n^2)
- Because for each element, we traverse the entire stack to insert it at bottom

Space Complexity :
- O(n)
- Due to recursive call stack

*/



class Solution {
  public:
  
    void reverse(stack<int>& st,int &a){
        
        if(st.empty()){
            st.push(a);
            return ;
        }
        
        int b = st.top();
        st.pop();
        
        reverse(st,a);
        
        st.push(b);
    }
    
    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        
        int a = st.top();
        st.pop();
        
        reverseStack(st);
        
        reverse(st,a);
    }
    
};