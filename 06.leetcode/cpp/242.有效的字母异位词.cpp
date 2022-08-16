/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.11%)
 * Likes:    533
 * Dislikes: 0
 * Total Accepted:    381.6K
 * Total Submissions: 586.1K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(auto& ch:s) {
            arr[ch - 'a']++;
        }
        for(auto& ch:t) {
            arr[ch - 'a']--;
        }
        for(auto& a:arr) {
            if (a != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

