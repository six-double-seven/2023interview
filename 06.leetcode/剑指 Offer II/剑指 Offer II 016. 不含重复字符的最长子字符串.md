# [剑指 Offer II 016. 不含重复字符的最长子字符串](https://leetcode.cn/problems/wtcaE1/)

### 1. 题目

- 给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长连续子字符串** 的长度。




### 2. 题解 - 左右指针

注意点

- 假如set中不存在，则执行add 并且 right 右移；
- set中已存在，则首先将left所指向的元素在set中**移除**，然后执行left++。



### 3. 代码

- 代码如下。

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {

        if (s.length() < 1)
            return 0;

        int max = 1, left = 0, right = 1;
        char[] chars = s.toCharArray();
        Set<Character> set = new HashSet<>();
        set.add(chars[0]);
        while (left <= right && right < s.length()){
            if (set.add(chars[right])){
                right++;
            }else {
                set.remove(chars[left]);
                left++;
            }
            max = Math.max(max, right - left);

        }
        return max;
    }
}
```

