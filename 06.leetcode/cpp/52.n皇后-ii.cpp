/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.26%)
 * Likes:    360
 * Dislikes: 0
 * Total Accepted:    91.9K
 * Total Submissions: 111.7K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool judge(vector<string> &str, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (str[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (str[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < str.size(); --i, ++j) {
            if (str[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void dfs(vector<string> &str, int row, int &res)
    {
        if (row == str.size()) {
            ++res;
            return;
        } else {
            for (int i = 0; i < str.size(); ++i) {
                if (judge(str, row, i)) {
                    str[row][i] = 'Q';
                    dfs(str, row + 1, res);
                    str[row][i] = '.';
                }
            }
        }
    }
    int totalNQueens(int n) {
        if (n == 1)
            return 1;
        if (n == 2 || n == 3)
            return 0;
        int res = 0;
        vector<string> str(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            str[0][i] = 'Q';
            dfs(str, 1, res);
            str[0][i] = '.';
        }
        return res;
    }
};
// @lc code=end

