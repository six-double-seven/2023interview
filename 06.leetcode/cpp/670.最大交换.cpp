/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 *
 * https://leetcode-cn.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (46.03%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 54.9K
 * Testcase Example:  '2736'
 *
 * 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: 2736
 * 输出: 7236
 * 解释: 交换数字2和数字7。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: 9973
 * 输出: 9973
 * 解释: 不需要交换。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数字的范围是 [0, 10^8]
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        unordered_map<char, int> unmap;
        for (int i = n - 1; i >= 0; --i) {
            if (unmap.count(str[i]) == 0)
                unmap[str[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (char ch = '9'; ch > str[i]; --ch) {
                if (unmap.count(ch) && unmap[ch] > i) {
                    swap(str[i], str[unmap[ch]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};
// @lc code=end

