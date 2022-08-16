/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.21%)
 * Likes:    622
 * Dislikes: 0
 * Total Accepted:    224.8K
 * Total Submissions: 392.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        deque<TreeNode *> deq;
        deq.push_back(root);
        int depth = 0;
        while(!deq.empty()) {
            int length = deq.size();
            vector<int> temp;
            while(length--) {
                if(depth%2) {
                    TreeNode *node = deq.back();
                    deq.pop_back();
                    temp.push_back(node->val);
                    if(node->right) {
                        deq.push_front(node->right);
                    }
                    if (node->left) {
                        deq.push_front(node->left);
                }
                } else {
                    TreeNode *node = deq.front();
                    deq.pop_front();
                    temp.push_back(node->val);
                    if(node->left) {
                        deq.push_back(node->left);
                    }
                    if(node->right) {
                        deq.push_back(node->right);
                    }
                } 
            }
            ++depth;
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

