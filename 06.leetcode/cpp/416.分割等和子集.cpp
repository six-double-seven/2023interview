/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (51.50%)
 * Likes:    1283
 * Dislikes: 0
 * Total Accepted:    256.9K
 * Total Submissions: 498K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        if (sum % 2)
            return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int j = 0; j <= target; ++j) {
            dp[0][j] = (j >= nums[0]) ? nums[0] : 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = max(dp[i - 1][j], (j >= nums[i] ? dp[i - i][j - nums[i]] + nums[i] : 0));
            }
        }
        return (dp[n - 1][target] == target);
    }
};
// @lc code=end

