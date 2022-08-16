/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.29%)
 * Likes:    607
 * Dislikes: 0
 * Total Accepted:    96.3K
 * Total Submissions: 126.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> toVector(ListNode * head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }
    TreeNode *toTreeNode(vector<int> &nums, int left, int right) {
        if(left >right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = toTreeNode(nums, left, mid - 1);
        root->right = toTreeNode(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> temp = toVector(head);
        return toTreeNode(temp, 0, temp.size() - 1);
    }
};
// @lc code=end

