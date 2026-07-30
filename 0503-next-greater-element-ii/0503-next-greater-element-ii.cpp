class Solution {
public:
    int call(vector<int> &nums,int n){
        for(int i=0;i<n;i++){
            if(nums[i] > nums[n]){
                return nums[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElements(vector<int> nums) {
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                int num = call(nums,i);
                st.push(nums[i]);
                nums[i] = num;
            }else{
                while( ! st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    int num = call(nums,i);
                    st.push(nums[i]);
                    nums[i] = num;
                }else{
                    int num = st.top();
                    st.push(nums[i]);
                    nums[i] = num;
                }
            }
        }
        return nums;
    }
};