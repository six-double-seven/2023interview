/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (52.49%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    80.3K
 * Total Submissions: 153K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：24
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-1,-2,-3]
 * 输出：-6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 
 * -1000 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int tmp1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int tmp2 = nums[0] * nums[1] * nums[n - 1];
        return max(tmp1, tmp2);
    }
};
// @lc code=end

