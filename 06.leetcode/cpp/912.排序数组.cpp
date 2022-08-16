/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (55.62%)
 * Likes:    555
 * Dislikes: 0
 * Total Accepted:    355.9K
 * Total Submissions: 640.4K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void Qsort(vector<int> &nums, int left, int right) {
        if (left > right)
            return;
        int i = left;
        int j = right;
        int temp = rand() % (right - left + 1) + left;
        swap(nums[left], nums[temp]);
        while (i < j) {
            while (nums[j] >= nums[left] && j > i) {
                --j;
            }
            while (nums[i] <= nums[left] && j > i) {
                ++i;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[i]);
        Qsort(nums, left, i - 1);
        Qsort(nums, i + 1, right);
    }
        vector<int> sortArray(vector<int> &nums) {
        Qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

