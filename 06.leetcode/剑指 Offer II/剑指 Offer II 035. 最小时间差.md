# [剑指 Offer II 035. 最小时间差](https://leetcode.cn/problems/569nqc/)

### 1. 题目

给定一个 24 小时制（小时:分钟 **"HH:MM"**）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。



### 2. 题解

- getMinutes() 函数，将 HH:MM 格式 转换为 分钟数，并存入list中；
- 对list进行排序，随后遍历寻找最小值，最小值分为两种情况：
  - 相邻的；
  - list 的 最后一个 和 第一个，比如 23:59 和 00:00 。



### 3. 代码

- 代码如下。

```java
class Solution {
    public int findMinDifference(List<String> timePoints) {

        List<Integer> list = new ArrayList<>();
        int min = Integer.MAX_VALUE;
        for (String time : timePoints){
            list.add(getMinutes(time));
        }
        Collections.sort(list);
        for (int i = 0; i < list.size() - 1; i++){
            min = Math.min(min, list.get(i + 1) - list.get(i));
        }
        min = Math.min(min, 24 * 60 - list.get(list.size() - 1) + list.get(0));

        return min;
    }

    public int getMinutes(String s){
        int h1 = s.charAt(0) - '0';
        int h2 = s.charAt(1) - '0';
        int m1 = s.charAt(3) - '0';
        int m2 = s.charAt(4) - '0';
        return (h1 * 10 + h2) * 60 + m1 * 10 + m2;
    }
}
```