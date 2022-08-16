/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.29%)
 * Likes:    1239
 * Dislikes: 0
 * Total Accepted:    282.4K
 * Total Submissions: 510.7K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
public:
    ListNode *reverse(ListNode *head, int k) {
        ListNode * pre = nullptr;
        ListNode *cur = head;
        while(k--) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = cur;

        return pre;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        ListNode *pre = nullptr;
        while(left-- && right--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = reverse(cur, right + 1);
        return dummy->next;
    }
};
// @lc code=end

