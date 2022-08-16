/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 *
 * https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (74.85%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 36.3K
 * Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
 *
 * 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root1 = [2,1,4], root2 = [1,0,3]
 * 输出：[0,1,1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root1 = [1,null,8], root2 = [8,1]
 * 输出：[1,1,8,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每棵树的节点数在 [0, 5000] 范围内
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> temp;

public:
    void Low2High(TreeNode *root) {
        if(root == nullptr)
            return;
        Low2High(root->left);
        temp.push_back(root->val);
        Low2High(root->right);
    }
    void High2Low(TreeNode* root) {
        if(root == nullptr)
            return;
        High2Low(root->right);
        temp.push_back(root->val);
        High2Low(root->left);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        Low2High(root1);
        High2Low(root2);
        vector<int> res;
        int i = 0;
        int j = temp.size() - 1;
        while (i <= j) {
            if (temp[i] < temp[j]) {
                res.push_back(temp[i++]);
            } else {
                res.push_back(temp[j--]);
            }
        }
        return res;
    }
};
// @lc code=end

