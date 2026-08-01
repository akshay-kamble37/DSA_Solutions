class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> ans;
        vector<int> nums;
        for(int i=0;i<ast.size();i++){
            if(ast[i] >=  0 ) ans.push(ast[i]);
            else{
                while(! ans.empty() && ans.top() > 0 && ans.top() < abs(ast[i])){
                    ans.pop();
                }
                if(! ans.empty() && ans.top() == abs(ast[i])){
                    ans.pop();
                }else if(ans.empty() || ans.top() < 0 ){
                    ans.push(ast[i]);
                }
            }
        }
        while(! ans.empty()){
            nums.push_back(ans.top());
            ans.pop();
        }
        reverse(nums.begin(),nums.end());

        return nums;
    }
};