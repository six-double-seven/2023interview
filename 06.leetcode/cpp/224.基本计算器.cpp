/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.83%)
 * Likes:    750
 * Dislikes: 0
 * Total Accepted:    86.7K
 * Total Submissions: 207.1K
 * Testcase Example:  '"1 + 1"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 
 * 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1 + 1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
 * '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
 * 输入中不存在两个连续的操作符
 * 每个数字和运行的计算将适合于一个有符号的 32位 整数
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        long res = 0;
        long val = 0;
        int flag = 1;
        stk.push(flag);
        for(auto& ch:s) {
            if (ch >= '0' && ch <= '9') {
                val = val * 10 + ch - '0';
                continue;
            }
            res += flag * val;
            val = 0;
            if (ch == '+')
                flag = stk.top();
            else if (ch == '-')
                flag = -stk.top();
            else if (ch == '(')
                stk.push(flag);
            else if (ch == ')')
                stk.pop();
        }
        res += val * flag;
        return res;
    }
};
// @lc code=end

