# [剑指 Offer II 006. 排序数组中两个数字之和](https://leetcode.cn/problems/kLl5u1/)

### 1. 题目

- 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。




### 2. 题解

- 遍历数组得到数字numbers[i]，将target - numbers[i] 和 下标 i 存入 map 中；
- 同时在遍历的过程中需要比对当前元素在map中是否存在，如果存在则返回二者的下标即可。



### 3. 代码

- 代码如下。

```java
public int[] twoSum(int[] numbers, int target) {

    Map<Integer, Integer> map = new HashMap<>();
    int[] res = new int[2];
    for (int i = 0; i < numbers.length; i++){
        if (map.containsKey(numbers[i])) {
            res[0] = map.get(numbers[i]);
            res[1] = i;
            return res;
        }else
            map.put(target - numbers[i], i);
    }
    return res;
}
```



