/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (73.89%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    217K
 * Total Submissions: 293.6K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> temp1;
            vector<int> res;
            unordered_set<int> temp2;
            for(auto& num:nums1) {
                if(temp1.find(num) == temp1.end()) {
                    temp1.insert(num);
                }
            }
            for(auto& num:nums2) {
                if(temp1.find(num) != temp1.end() && temp2.find(num) == temp2.end()) {
                    temp2.insert(num);
                    res.push_back(num);
                }
            }
            return res;
    }
};
// @lc code=end

