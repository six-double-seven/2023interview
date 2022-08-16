/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.51%)
 * Likes:    1945
 * Dislikes: 0
 * Total Accepted:    586K
 * Total Submissions: 746.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
    unordered_set<int> set;

public:
    void dfs(vector<int>&nums) {
        if(nums.size() == set.size()) {
                res.push_back(temp);
            }
        for(int i = 0; i < nums.size(); ++i) {
            if(set.count(nums[i]) == 0) {
                set.insert(nums[i]);
                temp.push_back(nums[i]);
                dfs(nums);
                set.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
};
// @lc code=end

