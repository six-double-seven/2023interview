# [剑指 Offer II 003. 前 n 个数字二进制中 1 的个数](https://leetcode.cn/problems/w3tCBm/)

### 1. 题目

- 给定一个非负整数 `n` ，请计算 `0` 到 `n` 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。



### 2. 题解

- 使用**[Brian Kernighan算法](https://blog.csdn.net/Andy123321aa/article/details/108182267?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-108182267-blog-122039781.t5_layer_targeting_sa_randoms&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-108182267-blog-122039781.t5_layer_targeting_sa_randoms&utm_relevant_index=2)**计算每个数字num中 1 的个数；
- Brian Kernighan 算法的原理
  - 对于任意整数 x，令 x=x & (x−1)，直至 x = 0；
  - 不断执行 x=x & (x−1)语句会使得二进制数字 x 的所有 1 变为 0；
  - Brian Kernighan 算法可以用于清除二进制数中**最右**侧的1，假如数字 x 最右侧1的下标为 i ，则 x - 1 下标为 i 的位置必然为0，因此二者做与运算结果为0，因此Brian Kernighan 算法执行的次数即为数字 x 中 1 的个数。



### 3. 代码

```java
class Solution {
    public int[] countBits(int n) {
        int [] res = new int[n + 1];
        for (int i = 0; i <= n; i++)
            res[i] = numberOfOne(i);
        return res;
    }
    int numberOfOne(int num){
        int ones = 0;
        while (num > 0) {
            num &= (num - 1);
            ones++;
        }
        return ones;
    }
}
```

