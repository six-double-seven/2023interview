/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 *
 * https://leetcode.cn/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (72.09%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 63.6K
 * Testcase Example:  '["Solution","getRandom","getRandom","getRandom","getRandom","getRandom"]\n' +
  '[[[1,2,3]],[],[],[],[],[]]'
 *
 * 给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。
 * 
 * 实现 Solution 类：
 * 
 * 
 * Solution(ListNode head) 使用整数数组初始化对象。
 * int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["Solution", "getRandom", "getRandom", "getRandom", "getRandom",
 * "getRandom"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * 输出
 * [null, 1, 3, 2, 2, 3]
 * 
 * 解释
 * Solution solution = new Solution([1, 2, 3]);
 * solution.getRandom(); // 返回 1
 * solution.getRandom(); // 返回 3
 * solution.getRandom(); // 返回 2
 * solution.getRandom(); // 返回 2
 * solution.getRandom(); // 返回 3
 * // getRandom() 方法应随机返回 1、2、3中的一个，每个元素被返回的概率相等。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中的节点数在范围 [1, 10^4] 内
 * -10^4 <= Node.val <= 10^4
 * 至多调用 getRandom 方法 10^4 次
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果链表非常大且长度未知，该怎么处理？
 * 你能否在不使用额外空间的情况下解决此问题？
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
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int, ListNode *> mmap;
    int num;

public:
    Solution(ListNode* head) {
        int index = 0;
        while(head) {
            mmap[index++] = head;
            head = head->next;
        }
        num = index;
    }
    
    int getRandom() {
        // srand(time(NULL));
        int random = rand() % num;
        return mmap[random]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

