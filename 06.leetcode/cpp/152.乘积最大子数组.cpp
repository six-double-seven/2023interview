/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (42.11%)
 * Likes:    1318
 * Dislikes: 0
 * Total Accepted:    186.4K
 * Total Submissions: 442.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int now_max = 1;
        int now_min = 1;
        for (auto &num : nums)
        {
            if (num < 0)
            {
                swap(now_max, now_min);
            }
            now_max = max(now_max * num, num);
            now_min = min(now_min * num, num);
            res = max(res, now_max);
        }
        return res;
    }
};
// @lc code=end

