# [剑指 Offer II 028. 展平多级双向链表](https://leetcode.cn/problems/Qv1Da2/)

### 1. 题目

多级双向链表中，除了指向下一个节点(next)和前一个节点指针(prev)之外，还有子链表指针(child)，可能指向单独的双向链表。

这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。



### 2. 题解

- 深度优先遍历。



### 3. 代码

- 代码如下。

```java
class Solution {
    
    public Node flatten(Node head) {
        dfs(head);
        return head;
    }

    public Node dfs(Node node) {
        Node cur = node;
        // 记录链表的最后一个节点
        Node last = null;

        while (cur != null) {
            Node next = cur.next;
            //  如果有子节点，那么首先处理子节点
            if (cur.child != null) {
                Node childLast = dfs(cur.child);

                //  将 node 与 child 相连
                cur.next = cur.child;
                cur.child.prev = cur;

                //  如果 next 不为空，就将 last 与 next 相连
                if (next != null) {
                    childLast.next = next;
                    next.prev = childLast;
                }

                // 将 child 置为空
                cur.child = null;
                last = childLast;
            } else {
                last = cur;
            }
            cur = next;
        }
        return last;
    }
}
```

