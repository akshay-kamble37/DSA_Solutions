// Problem: Two Sum
// Platform: LeetCode
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];

        if (mp.find(diff) != mp.end()) {
            return {mp[diff], i};
        }

        mp[nums[i]] = i;
    }
    return {};
}