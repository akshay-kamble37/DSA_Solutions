class Solution {
public:
    long long maxScore(vector<int>& card, int k) {
        int total = 0;
        int n = card.size();
        for(int i=0;i<n;i++){
            total+=card[i];
        }
        int window = n-k;
        int maximum = 0;
        int count = 0;
        for(int i=0;i<window;i++){
            count += card[i];
        }
        maximum = max(maximum,total-count);

        int left = 0;
        for(int i=window;i<n;i++){
            count += card[i];
            count -= card[left];
            maximum = max(maximum,total-count);
            left++;

        }

        return maximum;
    }
};






// =========INTER-NEL TESTCASES FAIL===========

// int total = 0;
//         int n = card.size();
//         for(int i=0;i<n;i++){
//             total+=card[i];
//         }
//         int window = n-k;
//         int maximum = 0;
//         int count = 0;
//         for(int i=0;i<window;i++){
//             count += card[i];
//         }
//         maximum = max(maximum,total-count);

//         count = 0;
//         for(int i=n-1;i>=n-window;i--){
//             count += card[i];
//         }
//         maximum = max(maximum,total-count);

//         return maximum;