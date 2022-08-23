# [剑指 Offer II 020. 回文子字符串的个数](https://leetcode.cn/problems/a7VOhD/)

### 1. 题目

- 给定一个字符串 `s` ，请计算这个字符串中有多少个回文子字符串。

  具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
  
- `s` 由小写英文字母组成。


### 2. 题解

- 采用此前的 isPalindrome() 函数判断字符串是否为回文字符串，字串通过双重循环进行选择。




### 3. 代码

- 代码如下。

```java
class Solution {
    public int countSubstrings(String s) {

        int sum = 0;
        for (int left = 0; left < s.length(); left++){
            for (int right = left + 1; right < s.length() + 1; right++){
                String substring = s.substring(left, right);
                if (isPalindrome(substring))
                    sum++;
            }
        }

        return sum;
    }

    public boolean isPalindrome(String s) {

        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}
```