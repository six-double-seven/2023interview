/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (67.40%)
 * Likes:    762
 * Dislikes: 0
 * Total Accepted:    197.5K
 * Total Submissions: 292.7K
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid 。
 * 
 * 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid
 * 的四个边缘都被 0（代表水）包围着。
 * 
 * 岛屿的面积是岛上值为 1 的单元格的数目。
 * 
 * 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 输出：6
 * 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[0,0,0,0,0,0,0,0]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] 为 0 或 1
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int num;
    int res;

public:
    void dfs(vector<vector<int>> &grid, int i, int j){
        if (i == grid.size() || i < 0)
            return;
        if (j == grid[0].size() || j < 0)
            return;
        if (grid[i][j]) {
            grid[i][j] = 0;
            num++;
            dfs(grid, i - 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i + 1, j);
            dfs(grid, i, j + 1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                num = 0;
                dfs(grid, i, j);
                res = max(res, num);
            }
        }
        return res;
    }
};
// @lc code=end

