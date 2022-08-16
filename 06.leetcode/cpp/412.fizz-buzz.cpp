/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (67.43%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    86.8K
 * Total Submissions: 125.2K
 * Testcase Example:  '3'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 * 
 * 示例：
 * 
 * n = 15,
 * 
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n;i++)
        {
            string tmp;
            if (i % 3 == 0)
                tmp += "Fizz";
            if (i % 5 == 0)
                tmp += "Buzz";
            if(tmp.size() == 0)
                tmp += to_string(i);
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

