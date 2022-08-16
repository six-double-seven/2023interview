/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode.cn/problems/base-7/description/
 *
 * algorithms
 * Easy (52.13%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 141.4K
 * Testcase Example:  '100'
 *
 * 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num = 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: num = -7
 * 输出: "-10"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^7 <= num <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        int flag = num > 0 ? 1 : -1;
        if (num == 0) {
            return "0";
        }
        num = abs(num);
        string res = "";
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        if(flag == -1) {
            res = "-" + res;
        }
        return res;
    }
};
// @lc code=end

