/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (69.44%)
 * Likes:    725
 * Dislikes: 0
 * Total Accepted:    203.4K
 * Total Submissions: 292.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
public:
    void dfs(vector<string> &str, string path, TreeNode *root) {
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            str.push_back(path);
            return;
        }
        if (root->left)
            dfs(str, path + "->", root->left);
        if (root->right)
            dfs(str, path + "->", root->right);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string path = "";
        if(root == nullptr)
            return res;
        dfs(res, path, root);
        return res;
    }
};
// @lc code=end

