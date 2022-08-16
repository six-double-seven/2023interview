/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    2006
 * Dislikes: 0
 * Total Accepted:    505.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return -1;
        if (n == 1)
            return (nums[0] == target) ? 0 : -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            // 上升
            if(nums[mid] == target) {
                return mid;
            }
            // 中值在上升段
            if(nums[mid] >= nums[0]) {
                // 目标值在中值右侧
                if(nums[mid] < target) {
                    left = mid + 1;
                // 目标值在中值左侧
                } else if (nums[0] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                // 中值在目标值左侧，目标值在右区间
                if(nums[mid] < target && target <= nums[n -1]) {
                    left = mid + 1;
                } else if(nums[mid] > target) {
                    right = mid - 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

