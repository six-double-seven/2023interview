/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 *
 * https://leetcode-cn.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (81.24%)
 * Likes:    524
 * Dislikes: 0
 * Total Accepted:    172.5K
 * Total Submissions: 212.3K
 * Testcase Example:  '1\n4'
 *
 * 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
 * 
 * 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 1, y = 4
 * 输出：2
 * 解释：
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 上面的箭头指出了对应二进制位不同的位置。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 3, y = 1
 * 输出：1
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
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int minus = x ^ y;
        // cout << minus << endl;
        int res = 0;
        while (minus) {
            res += minus % 2;
            minus /= 2;
            // cout << res << "+++" << minus << endl;
        }
        return res;
    }
};
// @lc code=end

