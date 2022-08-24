# [剑指 Offer II 023. 两个链表的第一个重合节点](https://leetcode.cn/problems/3u1WK4/)

### 1. 题目

- 给定两个单链表的头节点 `headA` 和 `headB` ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。



### 2. 题解

- 用指针`p1`和`p2`分别遍历两个链表；

- 若`p1`走到链表A的尾部，则在链表B的头部重新开始遍历，`p2`同理；

- 返回结果分两种情况：

   - 如果二者相交，`p1`走了a+c+b,`p2`走了b+c+a  则二者一定会在`c1`点相遇；

   ![在这里插入图片描述](https://img-blog.csdnimg.cn/eb83cd9027284eac8e57392296a99795.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAc2l4IGRvdWJsZSBzZXZlbkA=,size_14,color_FFFFFF,t_70,g_se,x_16)

   - 如果二者不相交，`p1`走a+b，`p2`走b+a，二者最终均为null ，跳出循环，返回nul 。

   ![在这里插入图片描述](https://img-blog.csdnimg.cn/fdcde1b57b6b437485b2a6e899f71ff1.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAc2l4IGRvdWJsZSBzZXZlbkA=,size_7,color_FFFFFF,t_70,g_se,x_16)




### 3. 代码

- 代码如下。

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode headACopy = headA;
        ListNode headBCopy = headB;
        while (headA != null || headB != null){

            if (headA == headB)
                return headA;
            headA = headA == null ? headBCopy : headA.next;
            headB = headB == null ? headACopy : headB.next;
        }
        return null;
    }
}
```

### 4. 反馈

- 2021年9月26日，做该题时代码如下，[blog传送门](https://blog.csdn.net/qq_52641681/article/details/120487918?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166134878316781683912687%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166134878316781683912687&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-120487918-null-null.nonecase&utm_term=%E8%B5%B7%E5%A7%8B%E8%8A%82%E7%82%B9&spm=1018.2226.3001.4450)。

```java
public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {

    if (headA==null||headB==null){
        return null;
    }
    ListNode p1 = headA;
    ListNode p2 = headB;
    while (p1!=p2){
        if (p1!=null){
            p1=p1.next;//p1不为空，则继续前进
        }else {
            p1=headB; //走到链表的尾部，开始走p2的路
        }
        if (p2!=null){
            p2=p2.next;
        }else {
            p2=headA;
        }
    }
    return p1;
}
```

- 去年comment

  之所以相遇，是因为你走了 ta 走过的路，而 ta 也刚好走了你走过的路。



- 今年comment

  我吹过你吹过的风，这算不算相拥。

  我踏过你走过的路，这算不算相逢。