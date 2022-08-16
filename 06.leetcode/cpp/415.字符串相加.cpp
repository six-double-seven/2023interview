/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.69%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    195.5K
 * Total Submissions: 357.5K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int flag = 0;
        string res = "";
        while (m >= 0 || n >= 0 || flag) {
            int x = (m >= 0 ? num1[m] - '0' : 0);
            int y = (n >= 0 ? num2[n] - '0' : 0);
            int sum = x + y + flag;
            char ch = sum % 10 + '0';
            flag = sum / 10;
            res += ch;
            --m;
            --n;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

