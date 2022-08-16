/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.40%)
 * Likes:    2625
 * Dislikes: 0
 * Total Accepted:    500.5K
 * Total Submissions: 646.3K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(vector<string> &res, string str, int left, int right, int sum) {
        if (left + right == sum) {
            res.push_back(str);
            return;
        }
        if (left < sum / 2) {
            str.push_back('(');
            dfs(res, str, left + 1, right, sum);
            str.pop_back();
        }
        if (right < left) {
            str.push_back(')');
            dfs(res, str, left, right + 1, sum);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        dfs(res, str, 0, 0, 2 * n);
        return res;
    }
};
// @lc code=end

