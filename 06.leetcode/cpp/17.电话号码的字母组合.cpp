/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.77%)
 * Likes:    1893
 * Dislikes: 0
 * Total Accepted:    481.5K
 * Total Submissions: 833.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    vector<string> temp = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

public:
    void dfs(string digits, int index, string str) {
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }
        int pos = digits[index] - '1';
        for (int i = 0; i < temp[pos].size(); ++i) {
            dfs(digits, index + 1, str + temp[pos][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        dfs(digits, 0, "");
        return res;
    }
};
// @lc code=end

