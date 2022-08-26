# [剑指 Offer II 024. 反转链表](https://leetcode.cn/problems/UHnkqh/)

### 1. 题目

- 给定单链表的头节点 `head` ，请反转链表，并返回反转后的链表的头节点。



### 2. 题解 - 迭代

- 遍历链表，改变next指针的方向；

- 以 a -> b -> c 为例，在某个场景下，pre = a，cur = b，next = c；

  ​	a. 将next指针保存， ListNode next = cur.next;

  ​	b. 改变next指针，使next指针指向pre节点，实现转向；

  ​	c. 向右移动pre和cur指针；

  循环上述步骤即可。




### 3. 代码

- 迭代的代码如下。

```java
class Solution {
    public ListNode reverseList(ListNode head) {
       
        ListNode pre = null;
        ListNode cur = head;
        
        while (cur != null){
            //保存next指针
            ListNode next = cur.next;
            
            //改变指针方向
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}
```

