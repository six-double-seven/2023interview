# [剑指 Offer II 038. 每日温度](https://leetcode.cn/problems/iIQa4I/)

### 1. 题目

请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：

要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。



### 2. 题解

- 单调栈：存储数组下标，从栈底到栈顶下标对应的温度列表中的温度依次递减，如果最后下标在单调栈里，则说明尚未找到下一次温度更高的下标；
- 如果当前 temperature 大于栈顶元素下标index 所对应的温度，则执行pop，并更新res[index]的值；



### 3. 代码

- 单调栈代码如下。

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {

        int[] res = new int[temperatures.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < temperatures.length; i++) {

            int temperature = temperatures[i];
            while (!stack.isEmpty() && temperature > temperatures[stack.peek()]) {

                int pop = stack.pop();
                res[pop] = i - pop;
            }
            stack.push(i);
        }

        return res;
    }
}
```



- 暴力双重循环代码如下。

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {

        int[] res = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++){
            res[i] = 0;
            for (int j = i + 1; j < temperatures.length; j++){
                if (temperatures[j] > temperatures[i]){
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
}
```



