/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if(map.count(target - nums[i]))
                return {i, map[target - nums[i]]};
            else
                map.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

