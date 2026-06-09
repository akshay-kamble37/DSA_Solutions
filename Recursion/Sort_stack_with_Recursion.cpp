//Problem : Sort a Stack using Recursion
//Difficulty: Medium
//Platform : Leetcode / GFG


/*Approach:

Step 1 : Remove the top element from the stack
Step 2 : Recursively call sortStack() for the remaining stack
Step 3 : Insert the removed element back into the stack in sorted order using sorting()

Step 4 : In sorting():
         - If stack is empty, push the element
         - If top element is greater than current element:
             -> Pop the top
             -> Recursively call sorting()
             -> Push the popped element back
         - Else push the element directly

Step 5 : Repeat until all elements are placed in sorted order


Time Complexity :
- O(n^2)
- Because for each element, we may traverse the entire stack in worst case

Space Complexity :
- O(n)
- Due to recursive function call stack

*/



class Solution {
  public:
  
    void sorting(stack<int> &st,int a){
        if(st.empty()){
            st.push(a);
            return;
        }
        
        int b = st.top();
        
        if(b > a){
            st.pop();
            sorting(st,a);
            st.push(b);
        }else{
            st.push(a);
        }
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()){
            return ;
        }
        
        int a = st.top();
        st.pop();
        
        sortStack(st);
        
        sorting(st,a);
    }
};