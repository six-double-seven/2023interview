# [剑指 Offer II 004. 只出现一次的数字 ](https://leetcode.cn/problems/WGki4K/)

### 1. 题目

- 给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。



### 2. 题解

- 整数的范围是0-32位，对nums中的整数依次做右移运算，计算每一位的结果然后重新组装；
- 注意点：重新组装时如果余数不为0 (则为 1)，需要将 1 左移 i 位放置在合适位置。

![剑指 Offer II 004](images\剑指 Offer II 004.png)

### 3. 代码

- 依次确定每一个二进制位

```java
class Solution {
    public int singleNumber(int[] nums) {

        int res = 0;
        for (int i = 0; i < 32; i++){
            int sum = 0;
            for (int num : nums){
                sum += (num >> i) & 1;
            }
            if (sum % 3 != 0)
                res |= 1 << i;
        }
        return res;
    }
}
```

- 哈希表

```java
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);
        for (Map.Entry<Integer, Integer> entry : map.entrySet()){
            int key = entry.getKey(), value = entry.getValue();
            if (value == 1)
                return key;
        }
        return 0;
    }
}
```