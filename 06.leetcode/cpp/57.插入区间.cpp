/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode.cn/problems/insert-interval/description/
 *
 * algorithms
 * Medium (41.49%)
 * Likes:    579
 * Dislikes: 0
 * Total Accepted:    108.8K
 * Total Submissions: 262.1K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 示例 3：
 * 
 * 
 * 输入：intervals = [], newInterval = [5,7]
 * 输出：[[5,7]]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,3]
 * 输出：[[1,5]]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,7]
 * 输出：[[1,7]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * intervals[i].length == 2
 * 0 
 * intervals 根据 intervals[i][0] 按 升序 排列
 * newInterval.length == 2
 * 0 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = newInterval[0];
        int high = newInterval[1];
        bool flag = true;
        vector<vector<int>> res;
        for(auto& interval:intervals) {
            if (interval[0] > high) {
                if(flag) {
                    res.push_back({low, high});
                    flag = false;
                }
                res.push_back(interval);
            } else if (interval[1] < low) {
                res.push_back(interval);
            } else {
                low = min(low, interval[0]);
                high = max(high, interval[1]);
            }
        }
        if(flag) {
            res.push_back({low, high});
        }
        return res;
    }
};
// @lc code=end
