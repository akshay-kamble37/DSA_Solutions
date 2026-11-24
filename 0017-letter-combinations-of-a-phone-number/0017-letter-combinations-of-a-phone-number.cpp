class Solution {
public:
    void calculate(string nums,int i,string &temp,vector<string> &store,vector<string> &answer){
        if(i == nums.size()){
            answer.push_back(temp);
            return;
        }
        string here=store[i];
        for(int j=0;j<here.size();j++){
            temp.push_back(here[j]);
            calculate(nums,i+1,temp,store,answer);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string nums) {
        vector<string> store;
        string temp="";
        vector<string> answer;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == '2'){
                store.push_back("abc");
            }else if(nums[i] == '3'){
                store.push_back("def");
            }else if(nums[i] == '4'){
                store.push_back("ghi");
            }else if(nums[i] == '5'){
                store.push_back("jkl");
            }else if(nums[i] == '6'){
                store.push_back("mno");
            }else if(nums[i] == '7'){
                store.push_back("pqrs");
            }else if(nums[i] == '8'){
                store.push_back("tuv");
            }else {
                store.push_back("wxyz");
            }
        }
        calculate(nums,0,temp,store,answer);

        return answer;

    }
};