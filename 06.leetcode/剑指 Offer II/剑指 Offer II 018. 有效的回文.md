# [剑指 Offer II 018. 有效的回文](https://leetcode.cn/problems/XltzEq/)

### 1. 题目

- 给定一个字符串 `s` ，验证 `s` 是否是 **回文串** ，只考虑字母和数字字符，可以忽略字母的大小写。

  本题中，将空字符串定义为有效的 **回文串** 。



### 2. 题解

#### 解法1

- 使用**正则**过滤字母和数字，对字符串转小写并进行**反转**，观察是否相等判断是否为回文串。

#### 解法2

- reverse() 和 正则 复杂度较高，考虑使用 双指针 + Character.isLetterOrDigit(c) 进行优化。



### 3. 代码

- 解法 1 代码如下。

```java
class Solution {
    public boolean isPalindrome(String s) {

        StringBuilder sb = new StringBuilder();
        String regex = "^[a-zA-Z0-9]$";
        for (int i = 0; i < s.length(); i++){
            String substring = s.substring(i, i + 1);
            if (substring.matches(regex))
                sb.append(substring);
        }
        String start = sb.toString().toLowerCase();
        String end = sb.reverse().toString().toLowerCase();
        return start.equals(end);
    }
}
```

- 解法 2 代码如下。

```java
class Solution {
    public boolean isPalindrome(String s) {

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)){
                sb.append(Character.toLowerCase(c));
            }
        }

        System.out.println(sb.toString());
        int left = 0, right = sb.length() - 1;
        while (left <= right){
            if (sb.charAt(left) != sb.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}
```



### 4. 反馈

- 正则表达式使用，复杂度较高谨慎使用；

```java
String regex = "^[a-zA-Z0-9]$";
s.matches(regex);// 返回值boolean
```

- Character类的常用方法

```java
Character.isLetterOrDigit(c);
Character.toLowerCase(c);
```

