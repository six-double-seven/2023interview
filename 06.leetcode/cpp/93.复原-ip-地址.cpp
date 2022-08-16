/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    880
 * Dislikes: 0
 * Total Accepted:    214.9K
 * Total Submissions: 383.8K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> res;

public:
    bool judge(string& str, int start, int end) {
        if(start > end) return false;
        if(start != end && str[start] == '0')
            return false;
        int sum = 0;
        for(int i = start; i <= end; i++) {
            sum = sum * 10 + str[i] - '0';
            if(sum > 255)
                return false;
        }
        return true;
    }
    void Divide(string & str,int start,int num) {
        if(num == 3) {
            if (judge(str, start, str.size() - 1)) {
                res.push_back(str);
            }
        }
        for(int i = start; i < str.size(); ++i) {
            if (judge(str, start, i)) {
            str.insert(str.begin() + i + 1, '.');
            Divide(str, i + 2, num + 1);
            str.erase(str.begin() + i + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() <= 12)
            Divide(s, 0, 0);
        return res;
    }
};
// @lc code=end

