/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (58.37%)
 * Likes:    892
 * Dislikes: 0
 * Total Accepted:    123.6K
 * Total Submissions: 211.8K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 1;
        set<long> temp;
        temp.insert(1);
        long res = 1;
        while (i++ < n) {
            temp.insert(i * res);
            temp.insert(i * res);
            temp.insert(i * res);
            temp.erase(temp.begin());
            res = *temp.begin();
        }
        return res;
    }
};
// @lc code=end

