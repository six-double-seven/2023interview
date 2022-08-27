# [剑指 Offer II 027. 回文链表](https://leetcode.cn/problems/aMhZSa/)

### 1. 题目

给定一个链表的 **头节点** `head` **，**请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。



### 2. 题解

- 将数据存入list，使用双指针判断是否为回文链表；
- **注意**：该题中使用的是lis的get方法进行随机访问，因此应该优先选择ArrayList，而不是LinkedList(会造成时间超出限制)。



### 3. 代码

- 代码如下。

```java
class Solution {
    public boolean isPalindrome(ListNode head) {

        List<Integer> list = new ArrayList<>();
        while (head != null){
            list.add(head.val);
            head = head.next;
        }
        
        int left = 0, right = list.size() - 1;
        while (left < right){
            if (!list.get(left).equals(list.get(right)))
                return false;
            left++;
            right--;
        }

        return true;
    }
}
```