/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    1126
 * Dislikes: 0
 * Total Accepted:    151.6K
 * Total Submissions: 339.5K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum;
        int sum = 0;
        int res = 0;
        presum[sum]++;
        for(auto & num:nums) {
            sum += num;
            res += presum[sum - k];
            presum[sum]++;
        }
        return res;
    }
};
// @lc code=end

