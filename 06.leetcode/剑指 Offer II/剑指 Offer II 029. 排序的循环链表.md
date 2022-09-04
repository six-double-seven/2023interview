# [剑指 Offer II 029. 排序的循环链表](https://leetcode.cn/problems/4ueAj6/)

### 1. 题目

给定循环**单调非递减**列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。



### 2. 题解

- insertPos 代表的是 插入位置的节点；
- 主要逻辑
  - 遍历链表，得到最大值max、最小值min、最大值节点insertPos；
  - 如果 insertVal 大于 max 或者 小于 min，均需要在**最大值节点**的后面插入节点；
  - 如果 insertVal 处于 min 和 max 之间，则遍历链表找到合适的位置(大于等于左节点，小于等于右节点)进行插入。



### 3. 代码

- 代码如下。

```java
class Solution {
    public Node insert(Node head, int insertVal) {

        if (head == null) {
            Node node = new Node(insertVal);
            node.next = node;
            return node;
        }

        Node headNode = head, insertPos = head; // 头节点headNode，insertPos插入节点位置
        int min = head.val, max = head.val; //链表中元素的最大值最小值
        head = head.next;

        //由于是循环链表，注意【循环结束的条件】
        while (head != headNode) {

            if (head.val >= max)
                insertPos = head;
            min = Math.min(min, head.val);
            max = Math.max(max, head.val);
            head = head.next;
        }

        Node node = new Node(insertVal);
        if (insertVal <= min || insertVal >= max) {
            node.next = insertPos.next;
            insertPos.next = node;

        } else {
            while (!(head.val <= insertVal && head.next.val >= insertVal)) {
                head = head.next;
            }
            node.next = head.next;
            head.next = node;
        }
        return headNode;
    }
}
```