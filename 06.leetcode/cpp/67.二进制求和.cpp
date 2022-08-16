/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.90%)
 * Likes:    810
 * Dislikes: 0
 * Total Accepted:    245.4K
 * Total Submissions: 455.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int temp = 0;
        int i = a.size();
        int j = b.size();
        while (i || j || temp) {
            if (i) {
                temp += a[--i] - '0';
            }
            if (j) {
                temp += b[--j] - '0';
            }
            res += char(temp % 2 + '0');
            temp /= 2;
        }
        string str;
        for (int i = res.size(); i > 0;) {
            str += res[--i];
        }
        return str;

    }
};
// @lc code=end

