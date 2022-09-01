# [剑指 Offer II 033. 变位词组](https://leetcode.cn/problems/sfvd7V/)

### 1. 题目

给定一个字符串数组 `strs` ，将 **变位词** 组合在一起。 可以按任意顺序返回结果列表。

**注意：**若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。



### 2. 题解

- 互为变位词的字符串排序后相同，将排序后的字符串作为map的key值，其value值为所有的字符串；
- 将 Map 的 values 存入 list 中 返回。



### 3. 代码

- 代码如下。

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            List<String> list = map.getOrDefault(key, new ArrayList<String>());
            list.add(s);
            map.put(key, list);
        }
        return new ArrayList<>(map.values());
    }
}
```