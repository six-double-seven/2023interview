# [剑指 Offer II 021. 删除链表的倒数第 n 个结点](https://leetcode.cn/problems/SLwz0R/)

### 1. 题目

- 给定一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。



### 2. 题解

- 滑动窗口，维持一个大小为n的窗口，将窗口向右移动，当窗口右边界right到达末尾，此时左边界正好位于**待删除元素的左侧**，此时执行 left.next = left.next.next，即可实现删除指定节点；

- 如果链表为{1, 2, 3, 4, 5}

  - 初始化时 left = 1，right = 3；
  - 第一次移动后 left = 2，right = 4；
  - 第二次移动后 left = 3，right = 5；
  - 此时left左边界正好位于待删除元素4的左侧，指针删除即可。

- 注意点

  - 待删除的元素正好为head节点，如{1，2} n = 2，此时需要特殊处理

    `if (right == null)  return head.next;`




### 3. 代码

- 代码如下。

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        if (head.next == null)
            return null;

        ListNode left = head, right = head;
        for (int i = 0; i < n ; i++){
            right = right.next;
        }
        if (right == null)
            return head.next;
        while (right.next != null){

            left = left.next;
            right = right.next;
        }
        left.next = left.next.next;
        return head;

    }
}
```

