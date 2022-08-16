/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (78.88%)
 * Likes:    959
 * Dislikes: 0
 * Total Accepted:    275.6K
 * Total Submissions: 349.3K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给你两棵二叉树： root1 和 root2 。
 * 
 * 
 * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为
 * null 的节点将直接作为新二叉树的节点。
 * 
 * 返回合并后的二叉树。
 * 
 * 注意: 合并过程必须从两个树的根节点开始。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
 * 输出：[3,4,5,5,4,null,7]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root1 = [1], root2 = [1,2]
 * 输出：[2,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两棵树中的节点数目在范围 [0, 2000] 内
 * -10^4 <= Node.val <= 10^4
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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
// @lc code=end

