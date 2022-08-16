/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (66.66%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    146.8K
 * Total Submissions: 219.8K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: rowIndex = 0
 * 输出: [1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: rowIndex = 1
 * 输出: [1,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> tmp;
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == i || j == 0)
                {
                    tmp.push_back(1);
                }
                else
                {
                    tmp.push_back(result[j - 1] + result[j]);
                }
            }
            result.assign(tmp.begin(), tmp.end());
            tmp.clear();
        }
        return result;
    }
};
// @lc code=end

