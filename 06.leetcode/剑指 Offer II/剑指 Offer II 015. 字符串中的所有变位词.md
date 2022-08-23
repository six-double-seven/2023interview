# [剑指 Offer II 015. 字符串中的所有变位词](https://leetcode.cn/problems/VabMRr/)

### 1. 题目

- 给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

  变位词 指字母相同，但排列不同的字符串。




### 2. 题解

- 见 [剑指 Offer II 014. 字符串中的变位词](https://leetcode.cn/problems/MPnaiL/)

### 3. 代码

- 代码如下。

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> list = new ArrayList<>();
        // s长度小于p, 返回空
        if (s.length() < p.length())
            return list;
        
        int[] sCount = new int[26];
        int[] pCount = new int[26];
        for (int i = 0; i < p.length(); i++){
            sCount[s.charAt(i) - 'a']++;
            pCount[p.charAt(i) - 'a']++;
        }
        if (Arrays.equals(sCount, pCount))
            list.add(0);
        for (int left = 1; left <= s.length() - p.length(); left++){
            sCount[s.charAt(left - 1) - 'a']--;
            sCount[s.charAt(left + p.length() - 1) - 'a']++;
            if (Arrays.equals(sCount, pCount))
                list.add(left);
        }
        return list;
    }
}
```

