/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (76.85%)
 * Likes:    636
 * Dislikes: 0
 * Total Accepted:    174.8K
 * Total Submissions: 227.4K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int index = 1;
        int up = 0;
        int right = n - 1;
        int down = n - 1;
        int left = 0;
        int i, j;
        while (index <= n * n) {
            i = up;
            j = left;
            for (; j <= right; ++j) {
                res[i][j] = index++;
            }
            ++up;
            i = up;
            j = right;
            for (; i <= down; ++i) {
                res[i][j] = index++;
            }
            --right;
            i = down;
            j = right;
            for (; j >= left; --j) {
                res[i][j] = index++;
            }
            --down;
            i = down;
            j = left;
            for (; i >= up; --i) {
                res[i][j] = index++;
            }
            ++left;
        }
            return res;
    }
};
// @lc code=end

