# [剑指 Offer II 007. 数组中和为 0 的三个数](https://leetcode.cn/problems/1fGaJU/)

### 1. 题目

- 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 **不重复** 的三元组。




### 2. 题解

- 该题的关键点在于如何保证**不重复**；
- 对于排好序的数组，遍历所有数组选择num[i]作为基准，在选取的时候需要判断如果和num[i - 1]相等则直接continue；
- 选取左指针为i + 1，右指针为 nums.length - 1，同时对于`左指针 l `的选取也需要判断是否重复，右指针不需要；
- 对于基准nums[i]，根据 lrSum和-nums[i] 移动指针位置，直至找出所有符合条件的选项即可。



### 3. 代码

- 代码如下。

```java
public List<List<Integer>> threeSum(int[] nums) {

    Arrays.sort(nums);
    List<List<Integer>> res = new ArrayList<>();
    for (int i = 0; i < nums.length - 1; i++){
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1, r = nums.length - 1;
        while (l < r){
            if (l > i + 1 && nums[l] == nums[l - 1]){
                l++;
                continue;
            }
            int lrSum = nums[l] + nums[r];
            if (lrSum == -nums[i]){
                List<Integer> list = new ArrayList<>();
                list.add(nums[i]);
                list.add(nums[l]);
                list.add(nums[r]);
                res.add(list);
                l++;
                r--;
            }
            else if (lrSum < -nums[i])
                l++;
            else
                r--;
        }
    }

    return res;
}
```

