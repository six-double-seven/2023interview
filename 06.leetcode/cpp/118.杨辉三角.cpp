/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (73.02%)
 * Likes:    597
 * Dislikes: 0
 * Total Accepted:    218K
 * Total Submissions: 298.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
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
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> tmp;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == i || j == 0)
                {
                    tmp.push_back(1);
                }
                else
                {
                    tmp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};
// @lc code=end

