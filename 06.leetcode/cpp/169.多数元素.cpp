/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.47%)
 * Likes:    1159
 * Dislikes: 0
 * Total Accepted:    392K
 * Total Submissions: 589.7K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3,2,3]
 * 输出：3
 * 
 * 示例 2：
 * 
 * 
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int sum = 1;
        for (int i = 1; i < nums.size(); ++i) {
            (nums[i] == val) ? ++sum : --sum;
            if (!sum) {
                val = nums[i];
                sum = 1;
            }
        }
        return val;
    }
};
// @lc code=end

