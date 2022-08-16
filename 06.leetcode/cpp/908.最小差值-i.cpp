/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 *
 * https://leetcode-cn.com/problems/smallest-range-i/description/
 *
 * algorithms
 * Easy (69.85%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1]\n0'
 *
 * 给你一个整数数组 nums，请你给数组中的每个元素 nums[i] 都加上一个任意数字 x （-k ），从而得到一个新数组 result 。
 * 
 * 返回数组 result 的最大值和最小值之间可能存在的最小差值。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1], k = 0
 * 输出：0
 * 解释：result = [1]
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,10], k = 2
 * 输出：6
 * 解释：result = [2,8]
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,3,6], k = 3
 * 输出：0
 * 解释：result = [3,3,3] or result = [4,4,4]
 * 
 * 
 * 
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
 * 
 * 
 */
#inlucde<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_element = INT_MIN;
        int min_element = INT_MAX;
        for (auto &num : nums)
        {
            max_element = max(max_element, num);
            min_element = min(min_element, num);
        }
        int tmp = max_element - min_element - 2 * k;
        return tmp < 0 ? 0 : tmp;
    }
};
// @lc code=end

