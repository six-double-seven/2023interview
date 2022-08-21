# [剑指 Offer II 008. 和大于等于 target 的最短子数组](https://leetcode.cn/problems/2VG8Kg/)

### 1. 题目

- 给定一个含有 n 个正整数的数组和一个正整数 target。找出该数组中满足其和 ≥ target 的长度最小的**连续子数组** [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。





### 2. 题解

- 双重循环。



### 3. 代码

- 代码如下。

```java
class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++){
            int number = 1;
            int sum = nums[i];
            if (sum >= target){
                res = Math.min(res, number);
                break;
            }
            for (int j = i + 1; j < nums.length; j++){
                number++;
                sum += nums[j];
                if (sum >= target){
                    res = Math.min(res, number);
                    break;
                }
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
```



