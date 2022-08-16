/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (56.61%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 47.7K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 * 
 * 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 * 
 * 编码的字符串应尽可能紧凑。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 * 
 * 
 * 示例 2：
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
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    int toVal(string& str) {
        int pos = str.find(',');
        int val = stoi(str.substr(0, pos));
        str = str.substr(pos + 1);
        return val;
    }
    TreeNode *toTreeNode(string &str) {
        if (str[0] == '#') {
            if (str.size() > 1) {
                str = str.substr(2);
            }
            return nullptr;
        }
        TreeNode *node = new TreeNode(toVal(str));
        node->left = toTreeNode(str);
        node->right = toTreeNode(str);
        return node;
    }
        // Decodes your encoded data to tree.
        TreeNode *deserialize(string data) {
            return toTreeNode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

