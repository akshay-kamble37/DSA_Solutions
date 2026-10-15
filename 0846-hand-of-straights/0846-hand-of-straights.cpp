class Solution {

struct Compare {
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.first > b.first ;
    }
};

public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        unordered_map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]] += 1;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        while( ! pq.empty()){
            int group = 0;
            queue<pair<int,int>> que;
            while(! pq.empty() && group < groupSize){
                int first_value = pq.top().first ;
                int second_value = pq.top().second ; 
                second_value--;
                if(second_value != 0){
                    que.push({first_value,second_value});
                }
                pq.pop();

                if(group + 1 < groupSize) {
                    if(pq.empty() || pq.top().first != first_value + 1) {
                        return false;
                    }
                }

                group++;
            }

            if(group < groupSize) return false;

            while(! que.empty()){
                pq.push(que.front());
                que.pop();
            }
        }
        return true;

    }
};