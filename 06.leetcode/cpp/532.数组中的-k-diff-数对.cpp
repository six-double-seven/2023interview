/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 *
 * https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (37.45%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    25.5K
 * Total Submissions: 68K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要在数组里找到 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。
 * 
 * 这里将 k-diff 数对定义为一个整数对 (nums[i], nums[j])，并满足下述全部条件：
 * 
 * 
 * 0 
 * |nums[i] - nums[j]| == k
 * 
 * 
 * 注意，|val| 表示 val 的绝对值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3, 1, 4, 1, 5], k = 2
 * 输出：2
 * 解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
 * 尽管数组中有两个1，但我们只应返回不同的数对的数量。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1, 2, 3, 4, 5], k = 1
 * 输出：4
 * 解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1, 3, 1, 5, 4], k = 0
 * 输出：1
 * 解释：数组中只有一个 0-diff 数对，(1, 1)。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1,2,4,4,3,3,0,9,2,3], k = 3
 * 输出：2
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [-1,-2,-3], k = 1
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^7 
 * 0 
 * 
 * 
 */
#include<vector>
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int num = 0;
        unordered_set<int> tmp;
        for (auto &num : nums)
        {
            if(tmp.find(num)==tmp.end())
                tmp.insert(num);
        }
        for (auto &num : nums)
        {
            if (tmp.find(abs(k - num)) != tmp.end())
                num++;
        }
        return num;
    }
};
// @lc code=end

