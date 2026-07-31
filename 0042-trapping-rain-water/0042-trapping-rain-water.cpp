class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0 || n == 2) return 0;

        vector<int> ans(n,0);

        int maxi = 0 ;
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            ans[i] = maxi;
        }
        
        maxi = 0;
        int count = 0;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            ans[i] = min(maxi,ans[i]);
            if(ans[i] > height[i]) count+=ans[i] - height[i];
        }
        return count;
    }
};