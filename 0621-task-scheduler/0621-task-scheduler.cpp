class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]] += 1;
        }
        priority_queue<int> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int total_time = 0;

        while(! pq.empty()){
            int count = 0;

            priority_queue<int> temp;
            while(count <= n && ! pq.empty()){
                int value = pq.top();
                pq.pop();

                value--;
                if(value > 0){
                    temp.push(value);
                }
                count++;
            }
            while(!temp.empty()) {
                pq.push(temp.top());
                temp.pop();
            }

            if(pq.empty()){
                total_time += count;
                break;
            }
            if( n - count >= 0){
                total_time += count + (n-count)+1;
            }else{
                total_time += count;
            }
        }
        return total_time;
    }
};










/*

unordered_map<char,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]] += 1;
        }
        int total_time = 0;
        while( ! mp.empty()){
            int count = 0;
            for(auto it = mp.begin(); it != mp.end(); ){
                it->second--;

                if(it->second == 0){
                    it = mp.erase(it);
                }
                else{
                    it++;
                }
                count++;
            }
            if(mp.empty()){
                total_time += count;
                break;
            }
            if( n - count >= 0){
                total_time += count + (n-count)+1;
            }else{
                total_time += count;
            }
        }
        return total_time;

*/