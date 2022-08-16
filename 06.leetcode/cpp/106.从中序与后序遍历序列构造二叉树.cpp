/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.14%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    134.4K
 * Total Submissions: 186.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *toTree(vector<int> &in, int il, int ir, vector<int> &post, int pl, int pr) {
        if (il > ir || pl > pr)
            return nullptr;
        TreeNode *node = new TreeNode(post[pr]);
        int pos;
        for(int i = il; i <= ir; ++i) {
            if(in[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = toTree(in, il, pos - 1, post, pl, pl - il + pos - 1);
        node->right = toTree(in, pos + 1, ir, post, pr - ir + pos, pr - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return toTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end

