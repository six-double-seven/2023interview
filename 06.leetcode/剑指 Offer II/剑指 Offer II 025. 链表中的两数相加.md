# [剑指 Offer II 025. 链表中的两数相加](https://leetcode.cn/problems/lMSNwu/)

### 1. 题目

- 给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

  可以假设除了数字 0 之外，这两个数字都不会以零开头。




### 2. 题解

**反转 + 头插法**

- 将 链表 l1和 l2 反转；
- 从右向左逐步计算新链表的val值，并创建链表节点；
- 由于需要从右向左计算，则链表的连接采用 头插法。


### 3. 代码

- 代码如下。

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        while (l1 != null) {
            stack1.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            stack2.push(l2.val);
            l2 = l2.next;
        }

        int carry = 0;
        ListNode ans = null;
        while (!stack1.isEmpty() || !stack2.isEmpty() || carry != 0){

            int a = stack1.isEmpty() ? 0 : stack1.pop();
            int b = stack2.isEmpty() ? 0 : stack2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;

            ListNode curNode = new ListNode(cur);
            curNode.next = ans;
            ans = curNode;
        }
        return ans;
    }
}
```

