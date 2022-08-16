/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (61.46%)
 * Likes:    765
 * Dislikes: 0
 * Total Accepted:    149.6K
 * Total Submissions: 243.2K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 
 * 返回 你可以获得的最大乘积 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return (n - 1);
        int a = n / 3;
        int b = n % 3;
        if (b == 0)
            return pow(3, a);
        else if (b == 1)
            return pow(3, a - 1) * 4;
        else
            return pow(3, a) * 2;
        }
};
// @lc code=end

