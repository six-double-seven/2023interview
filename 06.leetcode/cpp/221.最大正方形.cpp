/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (48.75%)
 * Likes:    1120
 * Dislikes: 0
 * Total Accepted:    189.5K
 * Total Submissions: 388.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            if (matrix[i][0] == '1')
                res = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            if (matrix[0][j] == '1')
                res = 1;
        }
        for (int i = 1; i < m; ++i)  {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return pow(res, 2);
    }
};
// @lc code=end

