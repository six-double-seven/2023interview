# [剑指 Offer II 009. 乘积小于 K 的子数组](https://leetcode.cn/problems/ZVAVXX/)

### 1. 题目

- 给定一个正整数数组 `nums`和整数 `k` ，请找出该数组内乘积小于 `k` 的连续的子数组的个数。




### 2. 题解

- 左指针 left 和 右指针 right 用来维护子数组的左右边界；
- 假设满足条件的滑动窗口为[left, right]，则其子数组个数为right - left + 1；比如滑动窗口内的数据为 1，2，3 则其子数组为 `3`，`2、3`，`1、2、3`，个数为right - left - 1；



### 3. 代码

- 右指针移动代码如下。

```java
public int numSubarrayProductLessThanK(int[] nums, int k) {

    int product = 1, sum = 0, left = 0;
    for (int right = 0; right < nums.length; right++){
        product *= nums[right];
        // 要用while循环，而不是if && left <= right 
        while (left <= right && product >= k){
            product /= nums[left];
            left++;
        }
        //计算的是以nums[right]为尾的子数组的个数
        sum += right - left + 1;
    }
    return sum;
}
```

- 左指针移动代码如下。

```java
public int numSubarrayProductLessThanK(int[] nums, int k) {

    int product = 1, sum = 0, right = nums.length - 1;
    for (int left = nums.length - 1; left >= 0; left--){
        product *= nums[left];
        // 要用while循环，而不是if && left <= right 
        while (left <= right && product >= k){
            product /= nums[right];
            right--;
        }
        sum += right - left + 1;
    }

    return sum;
}
```

- 双重循环移动代码如下，效率较低。

```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {

        int product = 1, sum = 0;
        for (int left = 0; left < nums.length; left++){
            product = nums[left];
            if (product < k)
                sum++;
            else
                continue;
            for (int right = left + 1; right < nums.length; right++){
                product *= nums[right];
                if (product < k)
                    sum++;
                else
                    break;
            }
        }
        return sum;
    }
}
```

