/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.86%)
 * Likes:    1036
 * Dislikes: 0
 * Total Accepted:    155.2K
 * Total Submissions: 210.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<string>> res;

public:
    bool judge(vector<string> &str, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if(str[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0;--i, --j) {
            if (str[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < str.size(); --i, ++j) {
            if(str[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void dfs(vector<string> &str, int row)
    {
        if(row == str.size()) {
            res.push_back(str);
        } else {
            for (int i = 0; i < str.size(); ++i) {
                if (judge(str, row, i)) {
                    str[row][i] = 'Q';
                    dfs(str, row + 1);
                    str[row][i] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1)
            return {{"Q"}};
        else if (n < 4)
            return res;
        vector<string> temp(n, string(n, '.'));
        for(int i = 0; i <n; ++i) {
            temp[0][i] = 'Q';
            dfs(temp, 1);
            temp[0][i] = '.';
        }
        return res;
    }
};
// @lc code=end