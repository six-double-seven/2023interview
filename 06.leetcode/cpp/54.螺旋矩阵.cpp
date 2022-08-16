/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (48.53%)
 * Likes:    1057
 * Dislikes: 0
 * Total Accepted:    249.4K
 * Total Submissions: 513K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
 * -100 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        while (left <= right && up <= down) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            ++up;
            if(up > down)
                break;
            for (int i = up; i <= down; ++i) {
                res.push_back(matrix[i][right]);
            }
            --right;
            if(left > right)
                break;
            for (int i = right; i >= left; --i){
                res.push_back(matrix[down][i]);
            }
            --down;
            if(up > down)
                break;
            for (int i = down; i >= up; --i) {
                res.push_back(matrix[i][left]);
            }
            ++left;
            if(left > right)
                break;
        }
        return res;
    }
};
// @lc code=end

