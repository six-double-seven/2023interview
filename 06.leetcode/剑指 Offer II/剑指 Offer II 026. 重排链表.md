# [剑指 Offer II 026. 重排链表](https://leetcode.cn/problems/LGjMqU/)

### 1. 题目

给定一个单链表 L 的头节点 head ，单链表 L 表示为： L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要**实际的进行节点交换**。



### 2. 题解

- 存入list，利用双指针由两侧向中间收缩，重新组成新的链表。



### 3. 代码

- 代码如下。

```java
class Solution {
    public void reorderList(ListNode head) {

        List<ListNode> list = new LinkedList<>();
        ListNode node = head;
        while (node != null){
            list.add(node);
            node = node.next;
        }
        int i = 0, j = list.size() - 1;
        while (i < j){
            list.get(i).next = list.get(j);
            i++;
            list.get(j).next = list.get(i);
            j--;
        }
        list.get(i).next = null;
    }


}
```

### 4. 其他

初始时解决策略如下：

- 拆分为两个链表 l1 l2 ，采用头插法翻转 l2，合并 l1 和 l2；
- 由于在拆分的时候创建了新的节点，不符合题意。

```java
class Solution {
    public void reorderList(ListNode head) {

        ListNode headNode = new ListNode();
        ListNode l1 = headNode;
        ListNode l2 = null;

        boolean odd = true;
        while (head != null){
            if (odd){
                l1.next = new ListNode(head.val);
                l1 = l1.next;
                odd = false;
            }else {
                ListNode listNode = new ListNode(head.val);
                listNode.next = l2;
                l2 = listNode;
                odd = true;
            }
            head = head.next;
        }
        mergeTwoLists(headNode, l2);
    }

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        ListNode headNode = new ListNode();
        ListNode cur = headNode;
        boolean odd = true;
        while (list1 != null && list2 != null){
            if (odd){
                cur.next = list1;
                list1 = list1.next;
                odd = false;

            }else {
                cur.next = list2;
                list2 = list2.next;
                odd = true;
            }
            cur = cur.next;
        }
        return headNode.next;
    }

}
```