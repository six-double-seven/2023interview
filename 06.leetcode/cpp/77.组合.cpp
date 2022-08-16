/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.06%)
 * Likes:    974
 * Dislikes: 0
 * Total Accepted:    346.2K
 * Total Submissions: 449.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k) {
        if (k <= 0 || n <= 0)
            return res;
        vector<int> temp;
        dfs(n, k, 1, temp);
        return res;
    }
    void dfs(int n, int k, int index, vector<int> &temp) {
        if (k == temp.size()) {
            res.push_back(temp);
            return;
        }
        
        for (int i = index; i <= n; ++i) {
            temp.push_back(i);
            dfs(n, k, i + 1, temp);
            temp.pop_back();
        }
    }
};
// @lc code=end

