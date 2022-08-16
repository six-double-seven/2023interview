/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (60.44%)
 * Likes:    575
 * Dislikes: 0
 * Total Accepted:    134.2K
 * Total Submissions: 222.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row, col;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.emplace_back(i);
                    col.emplace_back(j);
                }
            }
        }
        for(int i = 0;i<row.size();i++)
        {
            int x = 0,y = 0;
            while(y<matrix[0].size()) matrix[row[i]][y++] = 0;
            while(x<matrix.size()) matrix[x++][col[i]] = 0;
        }
    }
};
// @lc code=end

