class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) return {};
        stack<int> first;
        stack<int> helper;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            if(first.empty()){
                mp[nums2[i]] = -1;
            }else if(nums2[i] <= first.top()){
                mp[nums2[i]] = first.top();
            }else{
                while(! first.empty() && nums2[i] > first.top()){
                    helper.push(first.top());
                    first.pop();
                }
                if(! first.empty() && nums2[i] < first.top()){
                    mp[nums2[i]] = first.top();
                }else mp[nums2[i]] = -1;

                while(! helper.empty()){
                    first.push(helper.top());
                    helper.pop();
                }
            }
            first.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;

    }
};