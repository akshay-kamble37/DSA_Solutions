class Solution {
public:
    long long largestRectangleArea(vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i < nums.size() ;i++){
            int count = 1;
            if(st.empty()){
                st.push({nums[i],count});
                vec[i] = count;
            }else{
                while(! st.empty() && st.top().first >= nums[i]){
                    count += st.top().second;
                    st.pop();
                }
                st.push({nums[i],count});
                vec[i] = count;
            }
        }
        while(! st.empty()){
            st.pop();
        }

        for(int i=nums.size()-1;i >= 0 ;i--){
            int count = 1;
            if(st.empty()){
                st.push({nums[i],count});
                vec[i] += count;
            }else{
                while(! st.empty() && st.top().first >= nums[i]){
                    count += st.top().second;
                    st.pop();
                }
                st.push({nums[i],count});
                vec[i] += count;
            }
        }
        long long maxi = 0;
        for(int i=0;i<vec.size();i++){
            maxi = max(1LL * maxi,1LL * nums[i]);

            maxi = max(1LL * (vec[i]-1) * nums[i],maxi);
        }
        return maxi;
    }
};



// ============ BRUTE FORCE ==============



// if(nums.size() == 0 ) return 0;

//         long long maxi = 0 ;
//         for(int i=0;i < nums.size() ;i++){
//             if(nums[i] == 0) continue;
//             long long value = nums[i];
//             maxi = max(value,maxi);
//             int left = i;
//             int right  = i;
//             while(left >= 0 && right < nums.size() && nums[left]>= value && nums[right]>= value){
//                 long long val = (right - left + 1 ) * value;
//                 maxi = max(val,maxi);
//                 left--;
//                 right++;
//             } 
//             while(left >= 0 && nums[left] >= value ){
//                 long long val = (right - left) * value;
//                 maxi = max(val,maxi);
//                 left--;
//             }
//             while(right < nums.size() && nums[right]>= value){
//                 long long val = (right - left) * value;
//                 maxi = max(val,maxi);
//                 right++;
//             } 
//         }
//         return maxi;