/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (34.87%)
 * Likes:    4634
 * Dislikes: 0
 * Total Accepted:    912.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if (n >= 3)
        {
            for (int i = 0; i < n - 1;++i) {
                if (i == 0 || nums[i] != nums[i - 1]) {
                    int right = n - 1;
                    for (int left = i + 1; left < n; ++left) {
                        if( left > i + 1 && nums[left] == nums[left - 1])
                            continue;
                        while(left < right && (nums[left] + nums [i] + nums[right] > 0)) {
                            --right;
                        }
                        if(left == right) {
                            break;
                        }
                        if (nums[left] + nums[i] + nums[right] == 0) {
                            res.push_back({nums[i], nums[left], nums[right]});
                        }
                        
                        
                    }
                }
            }
            return res;
        }
        return res;
    }
};
// @lc code=end
