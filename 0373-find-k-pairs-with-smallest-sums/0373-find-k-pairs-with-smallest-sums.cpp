class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<nums1.size() && i<k;i++){
            pq.push({nums1[i] + nums2[0],i,0});
        }
        vector<vector<int>> ans;
        
        while(! pq.empty() && ans.size() < k){
            auto top = pq.top();
            pq.pop();

            int sum = top[0];
            int i = top[1];
            int j = top[2];

            ans.push_back({nums1[i],nums2[j]});

            if(j + 1 < nums2.size()){
                pq.push({nums1[i] + nums2[j+1],i,j+1});
            }
        }
        return ans;
    }
};



/*
====================
BRUTE FORCE APPROACH
====================

    static bool compare(const vector<int> &a,const vector<int> &b){
        return a[0] + a[1] < b[0] + b[1];
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                ans.push_back({nums1[i],nums2[j]});
            }
        }
        sort(ans.begin(),ans.end(),compare);
        vector<vector<int>> answer;
        int i=0;
        while(i < k && i < ans.size()){
            answer.push_back(ans[i]);
            i++;
        }
        return answer;
    }


*/