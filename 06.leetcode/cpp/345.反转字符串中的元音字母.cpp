/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (53.90%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    108.9K
 * Total Submissions: 201.9K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        set<char> temp = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && temp.find(s[right]) == temp.end()) {
                --right;
            }
            while(left < right && temp.find(s[left]) == temp.end()) {
                ++left;
            }
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
// @lc code=end

