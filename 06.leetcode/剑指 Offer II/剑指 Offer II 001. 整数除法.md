# [剑指 Offer II 001. 整数除法](https://leetcode.cn/problems/xoh6Oh/)

### 1. 题目

- 给定两个整数 `a` 和 `b` ，求它们的除法的商 `a/b` ，要求不得使用乘号 `'*'`、除号 `'/'` 以及求余符号 `'%'` 。



### 2. 题解

- 使用减法代替除法，比如10/3 = 3...1 可以换算为 10 - 3 = 7 ，7 - 3 = 4，4 - 3 = 1，此时1 < 3 循环结束即可；
- 需注意边界值，如果 a == Integer.MIN_VALUE && b == -1会造成越界，需要特殊处理返回Integer.MAX_VALUE。



### 3. 代码

```java
public int divide(int a, int b) {
    //对越界情况特殊处理
    if (a == Integer.MIN_VALUE && b == -1)
        return Integer.MAX_VALUE;
    int sign = (a > 0) ^ (b > 0) ? -1 : 1; //sign代表最终的返回值是正or负
    if (a > 0) a = -a;
    if (b > 0) b = -b;
    int res = 0;
    while (a <= b) {
        a -= b;
        res++;
    }
    return sign == 1 ? res : -res;
}
```