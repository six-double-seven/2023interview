/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (49.00%)
 * Likes:    1195
 * Dislikes: 0
 * Total Accepted:    220.9K
 * Total Submissions: 450.6K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 target 。
 * 
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 
 * 
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 
 * 
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], target = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 0 
 * -1000 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        if (abs(target) > sum) {
            return 0;
        }
        vector<int> pre(2 * sum + 1);
        vector<int> cur(2 * sum + 1);
        // 从[-sum,0) + 0 + (0,sum]共2sum+1个元素
        // +sum移位到基准0
        ++pre[sum + nums[0]];
        ++pre[sum - nums[0]];
        cur = pre;
        for (int i = 1; i < n; ++i) {
            for (int j = sum; j >= -sum; --j) {
                int left = (j - nums[i]) >= -sum ? pre[j - nums[i] + sum] : 0;
                int right = (j + nums[i]) <= sum ? pre[j + nums[i] + sum] : 0;
                cur[j + sum] = left + right;
            }
            pre = cur;
        }
        return cur[sum + target];
    }
};
// @lc code=end

