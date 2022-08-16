/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (42.47%)
 * Likes:    1435
 * Dislikes: 0
 * Total Accepted:    214K
 * Total Submissions: 504K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n + 1, 0);
        for(auto& num:nums) {
            if(num <= n && num >= 0) {
                ++res[num];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if(!res[i]) {
                return i;
            }
        }
        return n + 1;
    }
};
// @lc code=end

