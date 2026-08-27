class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        sort(intervals.begin(),intervals.end());
        int count = 0 ;
        vector<int> result = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(result.back() > intervals[i][0]){
                count++;
                if (intervals[i][1] < result[1]) {
                    result = intervals[i];
                }
            }else{
                result = intervals[i];
            }
        }
        return count;
    }
};