# [剑指 Offer II 002. 二进制加法](https://leetcode.cn/problems/JFETK5/)

### 1. 题目

- 给定两个 01 字符串 `a` 和 `b` ，请计算它们的和，并以二进制字符串的形式输出。



### 2. 题解

- 暴力转十进制显然会超时，因此考虑右侧位对齐，左侧缺少位置用0补齐，从右向左依次计算，最终结果记得反转字符串；
- 变量使用
  - 进位用carray；
  - aIndex 、bIndex分别是ab的下标值，aValue、bValue分别为对应下标的值；
  - aValue 、 bValue 及 前一个位置的进位carray 三者之和sum，对2取余记作最后结果，sum / 2 记作进位carry；

### 3. 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        while (aIndex >= 0 || bIndex >= 0){
            int aValue = aIndex < 0 ? 0 : a.charAt(aIndex) - '0';
            int bValue = bIndex < 0 ? 0 : b.charAt(bIndex) - '0';
            int sum = aValue + bValue + carry;
            sb.append(sum % 2);
            carry = sum / 2;

            aIndex--;
            bIndex--;
        }
        if (carry > 0)
            sb.append(carry);
        return sb.reverse().toString();
    }
}
```