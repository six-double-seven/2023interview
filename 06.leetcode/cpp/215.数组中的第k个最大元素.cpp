/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.69%)
 * Likes:    1615
 * Dislikes: 0
 * Total Accepted:    598.1K
 * Total Submissions: 924.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int qsort(vector<int>& nums, int begin,int end,int pos) {
    if (begin == end) return nums[end];
    else {
        int i = begin;
        int j = end;
        int value = nums[i];
        while(i < j)
        {
            while(i < j && nums[j] < value)
                --j;
            if(i < j)
                nums[i++] = nums[j];
            while(i < j && nums[i] >= value) {
                ++i;
            }
            if( i < j)
                nums[j--] = nums[i];
        }
        nums[i] = value;
        // 后续
        if(i > pos) {
            return qsort(nums, begin, i - 1, pos);
        } else if (i < pos) {
            return qsort(nums, i + 1, end, pos);
        } else{
            return nums[i];
        }
    }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qsort(nums, 0, nums.size() - 1, k - 1);
    }
};
// @lc code=end

