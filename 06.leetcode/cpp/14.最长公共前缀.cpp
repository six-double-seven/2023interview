/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (40.94%)
 * Likes:    1803
 * Dislikes: 0
 * Total Accepted:    629.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if (strs.size() == 0)
            return "";
        // 判断两个极端
        string left = strs[0];
        string right = strs.back();
        string res = "";
        for (int i = 0; i < left.size() && i < right.size(); ++i) {
            if (left[i] == right[i]) {
                res += left[i];
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

