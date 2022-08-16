/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (60.68%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    123.1K
 * Total Submissions: 202.7K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续 1 的个数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：[1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的数组只包含 0 和 1 。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size();i++)
        {
            tmp = nums[i] == 1 ? tmp + 1 : 0;
            res = max(tmp, res);
        }
        return res;
    }
};
// @lc code=end

