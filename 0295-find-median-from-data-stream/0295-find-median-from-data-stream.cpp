class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()){
            left.push(num);
        }else{
            right.push(num);
        }

        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian(){
        if(left.size() > right.size()) return left.top();
        else if(right.size() > left.size()) return right.top();

        return ((double)left.top() + right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 /* BRUTE FORCE APPROACH 

 vector<int> vec;
    MedianFinder() {
    }
    
    void addNum(int num) {
        vec.push_back(num);
    }
    
    double findMedian() {
        if(vec.size() == 0) return 0; 

        sort(vec.begin(),vec.end());

        int n = vec.size();

        if(n % 2 != 0){
            return vec[n/2];
        }

        return ((double) vec[n/2] + vec[n/2-1])/2.0;
    }


*/