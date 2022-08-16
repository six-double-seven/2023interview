/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.93%)
 * Likes:    1128
 * Dislikes: 0
 * Total Accepted:    290.1K
 * Total Submissions: 420.4K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i
 * 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        if(n == 1)
            return {0};
        // 栈存储今天之后温度最高的一天
        stk.push(n - 1);
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0;--i) {
            // 找到此后比今天温度高的一天
            while (stk.size() && temperatures[i] >= temperatures[stk.top()]) {  
                stk.pop();
            }
            if (stk.size())
                res[i] = stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

