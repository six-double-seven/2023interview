# [剑指 Offer II 034. 外星语言是否排序](https://leetcode.cn/problems/lwyVBB/)

### 1. 题目

某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。



### 2. 题解

- 循环遍历order，建立新字母表顺序与a-z的映射关系；
- 遍历words中每个单词，将外星语单词按照映射关系转换为a-z所熟知的单词；
- 通过 compareTo() 方法比较大小。



### 3. 代码

- 代码如下。

```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {

        Map<Character, Character> map = new HashMap<>();
        String temp = "";
        for (int i = 0; i < order.length(); i++){
            map.put(order.charAt(i), (char)('a' + i));
        }
        for (String word : words){

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < word.length(); i++){
                sb.append(map.get(word.charAt(i)));
            }
            if (!temp.equals("") && sb.toString().compareTo(temp) < 0)
                return false;
            temp = sb.toString();
        }

        return true;
    }
}
```