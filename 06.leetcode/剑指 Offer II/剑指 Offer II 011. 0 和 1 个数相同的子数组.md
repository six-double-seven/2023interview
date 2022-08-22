# [剑指 Offer II 011. 0 和 1 个数相同的子数组](https://leetcode.cn/problems/A1NYOS/)

### 1. 题目

- 给定一个二进制数组 `nums` , 找到含有相同数量的 `0` 和 `1` 的最长连续子数组，并返回该子数组的长度。




### 2. 题解

- 暴力左右指针循环超时；
- 将数组中的0换成-1，转换为前缀和为0的问题。



### 3. 代码

- 代码如下。

```java
public int findMaxLength(int[] nums) {

    int max = Integer.MIN_VALUE;
    for (int i = 0; i < nums.length; i++){
        if (nums[i] == 0)
            nums[i] = -1;
    }
    int preSum = 0;
    Map<Integer, Integer> map = new HashMap<>();
    map.put(0, -1);
    for (int i = 0; i < nums.length; i++){
        preSum += nums[i];
        if (map.containsKey(preSum)){
            max = Math.max(max, i - map.get(preSum));
        }else{
            map.put(preSum, i);
        }
    }
    return max == Integer.MIN_VALUE ? 0 : max;
}
```

