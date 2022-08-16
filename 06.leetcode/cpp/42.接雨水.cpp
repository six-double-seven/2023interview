/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (60.14%)
 * Likes:    3292
 * Dislikes: 0
 * Total Accepted:    439.8K
 * Total Submissions: 729.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2)
            return 0;
        int res = 0;
        vector<int> LeftMax(n, 0);
        vector<int> RightMax(n, 0);
        for (int i = 1; i < n; ++i) {
            LeftMax[i] = max(height[i - 1], LeftMax[i - 1]);
        }
        for (int i = n - 2; i > 0; --i) {
            RightMax[i] = max(height[i + 1], RightMax[i + 1]);
        }
        for (int i = 1; i < n - 1; ++i) {
            int temp = min(LeftMax[i], RightMax[i]) - height[i];
            res += (temp < 0) ? 0 : temp;
        }
        return res;
    }
};
// @lc code=end

