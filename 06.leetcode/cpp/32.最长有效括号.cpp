/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (36.31%)
 * Likes:    1787
 * Dislikes: 0
 * Total Accepted:    257.5K
 * Total Submissions: 708.8K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>dp(n,0);
        int res = 0;
        for(int i = 1;i<n;i++)
        {
            if(s[i] ==')')
            {
                if(s[i - 1]=='(') 
                {
                    dp[i] = 2;
                    if(i > 2) dp[i] += dp[i - 2];
                }
                else if(dp[i - 1] > 0)
                {
                    int tmp = i - dp[i - 1]- 1;
                    if(tmp >= 0 && s[tmp] =='(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if(tmp - 1 >= 0)
                        {
                            dp[i] += dp[tmp -1];
                        }
                    }
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};

// @lc code=end

