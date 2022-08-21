# [剑指 Offer II 012. 左右两边子数组的和相等](https://leetcode.cn/problems/tvdfij/)

### 1. 题目

- 给你一个整数数组 nums ，请计算数组的 中心下标 。数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。




### 2. 题解

- 前缀和。



### 3. 代码

- 代码如下。

```java
public int pivotIndex(int[] nums) {

    int sum = 0, preSum = 0, flag = -1;
    for (int num : nums)
        sum += num;

    for (int i = 0; i < nums.length; i++){

        if (preSum == sum - nums[i] - preSum){
            flag = i;
            break;
        }
        preSum += nums[i];
    }
    return flag;

}
```

