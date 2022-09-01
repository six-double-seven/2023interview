# [剑指 Offer II 032. 有效的变位词](https://leetcode.cn/problems/dKk3P7/)

### 1. 题目

给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）

注意：若 s 和 t 中每个字符出现的 **次数都相同** 且 **字符顺序不完全相同** ，则称 s 和 t 互为变位词（字母异位词）



### 2. 题解

**方法一、排序**

(1) 变位词 等价于 s 和 t 不相等，但排序后相等；

(2) 主要逻辑

- 如果 s 和 t 长度不相等 (违背条件 1 - 各字符次数都相同) 或者 s 和 t 相等 (违背条件2 - 字符顺序不完全相同)，则返回false；
- 对两个字符串进行排序，如果相等返回true，反之为false。



**方法二、将 变位词 的 两个条件 抽象为 timesEqual() 和 orderEquals()**

(1) timesEqual

- 判断各个字母出现的次数是否相同；
- 遍历字符串，将字母及出现的次数存入map中；
- 遍历26个字母，观察两个map中的返回值是否相同。

(2) orderEquals

- 指针 i 在 字符串 s1 上 滑动，指针 j 在 字符串 s2 上 滑动；
- 如果遇到 i 和 i + 1 位置上的元素相等，则不断执行i++，直到不相等为止。



### 3. 代码

- 排序 代码如下。

```java
class Solution {
    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length() || s.equals(t))
            return false;
        char[] str1 = s.toCharArray();
        char[] str2 = t.toCharArray();

        Arrays.sort(str1);
        Arrays.sort(str2);

        return Arrays.equals(str1, str2);

    }

}
```

- 方法二的代码如下。

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Integer, Integer> sMap = eleTimes(s);
        Map<Integer, Integer> tMap = eleTimes(t);
        boolean timesEqual = timesEqual(sMap, tMap);
        boolean orderEqual = orderEquals(s, t);

        return timesEqual & !orderEqual;
    }

    Map<Integer, Integer> eleTimes (String s){

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            map.put(s.charAt(i) - 'a', map.getOrDefault(s.charAt(i) - 'a', 0) + 1);
        }
        return map;
    }

    boolean timesEqual(Map<Integer, Integer> map1, Map<Integer, Integer> map2){

        for (int i = 0; i < 26 ; i++){

            if (!map1.getOrDefault(i, 0).equals(map2.getOrDefault(i, 0)))
                return false;
        }

        return true;
    }

    boolean orderEquals(String s1, String s2){
        int i = 0, j = 0;
        while (i < s1.length() && j < s2.length()){

            if (s1.charAt(i) != s2.charAt(j))
                return false;
            while (i < s1.length() - 1 && s1.charAt(i) == s1.charAt(i + 1)){

                i++;
            }
            while (j < s2.length() - 1 && s2.charAt(j) == s2.charAt(j + 1)){

                j++;
            }
            i++;
            j++;
        }
        return true;
    }
}
```