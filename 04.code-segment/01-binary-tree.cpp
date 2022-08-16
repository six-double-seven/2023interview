#include<bits/stdc++.h>
using namespace std;
// 数据结构定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){};
};
// 建树
TreeNode *CreateTree(vector<int> &nums, int index) {
    if (index >= nums.size() || nums[index] == 0) {
        return nullptr;
    }
    TreeNode *node = new TreeNode(nums[index]);
    node->left = CreateTree(nums, 2 * index + 1);
    node->right = CreateTree(nums, 2 * index + 2);
    return node;
}
// 释放
void DeleteTree(TreeNode * root) {
    if(root == nullptr) {
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
}
// 层序遍历
vector<int> printTree(TreeNode * root) {
    vector<int> temp;
    queue<TreeNode *> que;
    que.push(root);
    while(!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        temp.push_back(node->val);
        if(node->left) {
            que.push(node->left);
        }
        if(node->right) {
            que.push(node->right);
        }
    }
    return temp;
}
// 找节点
TreeNode * findTree(TreeNode * root, vector<int> target) {
    int index = 1;
    // 题目说 一定能找到 且唯一
    // 直接把新的树 替换其父节点的子节点  故返回父节点
    while(index <target.size() - 1) {
        if(root->left->val == target[index]) {
            root = root->left;
        } else {
            root = root->right;
        }
        ++index;
    }
    return root;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string str;
    getline(cin, str);
    vector<int> vec;
    // 题目给出节点的值为个位数
    for(auto &ch:str) {
        if(ch >= '0' && ch <= '9') {
            vec.push_back(ch - '0');
        }
    }
    TreeNode *root = CreateTree(vec, 0);
    str = "";
    vector<int> tmp;
    getline(cin, str);
    for(auto &ch:str) {
        if(ch >= '0' && ch <= '9') {
            tmp.push_back(ch - '0');
        }
    }
    TreeNode *in = findTree(root, tmp);

    vector<int> res;
    str = "";
    getline(cin, str);
        for(auto &ch:str) {
        if(ch >= '0' && ch <= '9') {
            res.push_back(ch - '0');
        }
    }
    TreeNode *node = CreateTree(res, 0);

    // 插入
    if(in->left->val == tmp.back()) {
        in->left = node;
    } else {
        in->right = node;
    }
    res.clear();
    res = printTree(root);
    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if(i != res.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
    DeleteTree(root);
    return 0;
}