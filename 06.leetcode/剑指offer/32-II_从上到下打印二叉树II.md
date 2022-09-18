## [剑指 Offer 32 - II. 从上到下打印二叉树 II](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

### 题目描述

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

### 思路

层序遍历基础上增加一个int型变量，记录每一层的节点个数。

### 代码

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {return {};}
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;
        vector<vector<int>> res;
        while(!que.empty()) {
            int n = que.size();
            while(n--) {
            TreeNode* node = que.front();
            que.pop();
            temp.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
```