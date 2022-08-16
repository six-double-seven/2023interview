/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 *
 * https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (52.50%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    50.7K
 * Total Submissions: 96.6K
 * Testcase Example:  '5\n7'
 *
 * 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right
 * 端点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：left = 5, right = 7
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：left = 0, right = 0
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：left = 1, right = 2147483647
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = right--;
        while (left <= right)
        {
            res &= right--;
        }
        return res;
    }
};
// @lc code=end

