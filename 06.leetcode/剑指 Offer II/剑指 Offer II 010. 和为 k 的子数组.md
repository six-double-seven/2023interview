# [剑指 Offer II 010. 和为 k 的子数组](https://leetcode.cn/problems/QTMn0o/)

### 1. 题目

- 给定一个整数数组和一个整数 `k` **，**请找到该数组中和为 `k` 的**连续子数组**的个数。



### 2. 题解

> 前缀和 + 左右指针

#### 2.1 前缀和

- 将前缀和及出现的次数存入map中，map应该初始化为{0 : 1}，因为第一个元素的前缀和为0；
- 每两个前缀和之差代表一个连续子数组的和，在将前缀preSum和存入map中的过程中
  - 需要判断`preSum - k`是否在map中存在，如果存在则获取出现的次数对res进行累加；
  - 如果preSum首次出现则直接put，如果非首次则需要更新value值。
- 例如：nums = [1,2,3], k = 3  前缀和 preSum 分别为 0，1，3，6
  - 当preSum 为 0 时，判断`preSum - k = -3`在map中不存在，res = 0， map.put(0)；
  - 当preSum 为 1 时，判断`preSum - k = -2`在map中不存在，res = 0， map.put(1)；
  - 当preSum 为 3 时，判断`preSum - k = 0 `在map中存在，res = 1， map.put(3)； == > 子数组：[1，2]
  - 当preSum 为 6 时，判断`preSum - k = 3 `在map中存在，res = 2， map.put(6)； == > 子数组：[3]

#### 2.2 左右指针

- 看[评论区](https://leetcode.cn/problems/QTMn0o/solution/ti-mu-you-wu-you-tu-wei-zheng-2021-08-08-2ctg/)说此前给题目给定的是**正整数数组**而非**整数数组**，对于正整数数组的情况可以使用左右指针，因此进行尝试；
- 当sum == k 时，右移right指针 or 左移left指针 均可；
- 对于数组中存在**负数**测试不通过的情况说明
  - 负数的累加可能会造成sum < k 恒成立，则在第一个while循环就会结束程序，并未起到窗口滑动的效果；
  - 例如：nums = [-1,-1,1], k = 0 则会一直在 while (right < nums.length && sum < k) 循环直至结束。



### 3. 代码

- 前缀和代码如下。

```java
class Solution {
    public int subarraySum(int[] nums, int k) {

        int res = 0, preSum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int num : nums){
            preSum += num;
            res += map.getOrDefault(preSum - k, 0);
            map.put(preSum, map.getOrDefault(preSum, 0) + 1);
        }
        return res;
    }
}
```

- 左右指针代码如下。

```java
public int subarraySum(int[] nums, int k) {

    if (nums.length == 1 && nums[0] != k)
        return 0;
    int left = 0, right = 0, sum = 0, res = 0;
    while (right < nums.length){
        while (right < nums.length && sum < k){
            sum += nums[right++];//累加和小于k值
            if (sum == k)
                res++;
        }

        while (left < right && sum >= k){
            sum -= nums[left++]; //累加和大于k值
            if (sum == k)
                res++;
        }
    }
    return res;
}
```

