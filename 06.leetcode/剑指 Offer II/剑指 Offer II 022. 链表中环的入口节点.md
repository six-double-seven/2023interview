# [剑指 Offer II 022. 链表中环的入口节点](https://leetcode.cn/problems/c32eOV/)



### 1. 题目

- 给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。

  为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

  说明：不允许修改给定的链表。




### 2. 题解

- 遍历链表，将节点ListNode存入Set中。





### 3. 代码

- 代码如下。

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        Set<ListNode> set = new HashSet<>();
        while (head != null){

            if (set.contains(head))
                return head;
            set.add(head);
            head = head.next;
        }
        return null;
    }
}
```

