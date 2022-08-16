/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode.cn/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.57%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    123.1K
 * Total Submissions: 221.4K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 * 
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 
 * 
 * 示例 1: 
 * 
 * 
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:s = "a"
 * 输入:1
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入:s = "bb"
 * 输入: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 2000
 * s 只能由小写和/或大写英文字母组成
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> umap;
        int res = 0;
        for(auto & ch:s) {
            ++umap[ch];
            if (umap[ch] % 2 == 0) {
                res += umap[ch];
                umap[ch] = 0;
            }
        }
        for(auto & temp:umap) {
            if (temp.second == 1){
                ++res;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

