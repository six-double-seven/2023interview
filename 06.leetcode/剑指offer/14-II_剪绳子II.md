## [剑指 Offer 14- II. 剪绳子 II](https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/)

### 题目描述

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 `k[0],k[1]...k[m - 1] `。请问 `k[0]*k[1]*...*k[m - 1]` 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

### 思路

[14-I_剪绳子](./14-I_剪绳子.md)基础上增加取模。

> 根据除以3余1、2在开始确定走向，然后循环 * 3

### 代码

```c++
class Solution {
public:
    int cuttingRope(int n) {
        int mod = 1000000007;
        long res = 1;
        if(n < 4) {
            return n - 1;
        }
        if( n%3 == 2) {
            res *= 2;
            n -= 2;
        }
        if(n%3 == 1) {
            res *= 4;
            n -= 4;
        }
        while(n) {
            res = res * 3 % mod;
            n -= 3;
        }
        return (int)res;
    }
};
```