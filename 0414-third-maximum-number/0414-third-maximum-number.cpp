class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        map<int,int> mp;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
                pq.push(nums[i]);
                if(pq.size() > 3){
                    pq.pop();
                }
            }
        }
        if(pq.size() < 3){
            while(pq.size() != 1){
                pq.pop();
            }
        }
        return pq.top();
    }
};