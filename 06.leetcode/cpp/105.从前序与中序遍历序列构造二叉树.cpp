/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.44%)
 * Likes:    1248
 * Dislikes: 0
 * Total Accepted:    251.3K
 * Total Submissions: 356.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * inorder.length == preorder.length
 * -3000 
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
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
    TreeNode * buildFunc(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend) {
        if(prestart > preend || instart > inend) {
            return nullptr;
        }
        int root = preorder[prestart];
        int index = 0;
        for (int i = instart; i <= inend; ++i) {
            if(inorder[i] == root) {
                index = i;
                break;
            }
        }
        TreeNode *node = new TreeNode(root);
        node->left = buildFunc(preorder, prestart + 1, prestart + index - instart, inorder, instart, index - 1);
        node->right = buildFunc(preorder, preend - inend + index + 1, preend, inorder, index + 1, inend);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildFunc(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

