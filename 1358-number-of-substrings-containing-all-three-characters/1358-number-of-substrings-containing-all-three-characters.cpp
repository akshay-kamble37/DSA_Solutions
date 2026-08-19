class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int count =0;
        for(int i=0;i < s.size();i++){
            last[s[i] - 'a'] = i;

                if(last[0] != -1 && last[1] != -1 && last[2] != -1  ){
                    count += (1 + min(min(last[0],last[1]),last[2]));
                }
        }
        return count;
    }
};





// =============BRUTE FORCE============

// int count = 0 ;
//         int n = s.size();
//         for(int i=0;i<n;i++){
//             set<int> st;
//             bool track = false;
//             for(int j=i;j<n;j++){
//                 st.insert(s[j]);
//                 if(st.size() == 3){
//                     count += n - j ;
//                     track = true;
//                     break;
//                 }
//             }
//             if(track == false) return count;
//         }    
//         return count;