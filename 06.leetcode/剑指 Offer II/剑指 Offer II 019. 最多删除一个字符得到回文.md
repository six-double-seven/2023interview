# [剑指 Offer II 019. 最多删除一个字符得到回文](https://leetcode.cn/problems/RQku0D/)

### 1. 题目

- 给定一个非空字符串 `s`，请判断如果 **最多** 从字符串中删除一个字符能否得到一个回文字符串。
- `s` 由**小写**英文字母组成




### 2. 题解

- boolean flag ==> 如果还未删除某个字符，则flag为true；如果已经删除某个字符，则flag为false；

- 左右指针移动的过程中，如果出现字符不相等，大致分为以下两种情况

  a. 第一次出现不相等

  - 尝试删除左指针指向的字母 或者 右指针指向的字母；
  - 并且将flag更新为false，表明当前已经删除过一个元素；

  b. 第二次出现不相等

  - 如果flag为false，则表明此前已经删除过字母，此轮执行不允许再次删除；
  - 即  如果再次**出现不相等 && flag为false** ，表明此轮已经没有机会再次删除字母，直接返回false即可。



### 3. 代码

- 代码如下。

```java
class Solution {
    public boolean validPalindrome(String s) {
        return check(s, 0, s.length()-1, true);
    }

    /**
     * @param s 字符串
     * @param i 左指针
     * @param j 右指针
     * @param flag 是否已经删除字母
     * @return
     */
    boolean check(String s,int i,int j,boolean flag){
        while (i < j){
            if(s.charAt(i) != s.charAt(j)){
                if(!flag){
                    // 已经删除某个字符，失败
                    return false;
                }
                // 左边去掉
                boolean b1 = check(s, i, j - 1, false);
                // 右边去掉
                boolean b2 = check(s, i+1, j , false);
                return b1||b2; // 有一种成功即可
            }
            i++;
            j--;
        }
        return true;
    }
}
```

