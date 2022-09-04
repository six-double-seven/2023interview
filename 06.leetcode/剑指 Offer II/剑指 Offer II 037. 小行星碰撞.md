# [剑指 Offer II 037. 小行星碰撞](https://leetcode.cn/problems/XagZNi/)

### 1. 题目

给定一个整数数组 asteroids，表示在同一行的小行星。

对于数组中的每一个元素，其绝对值表示小行星的大小，正负表示小行星的移动方向（正表示向右移动，负表示向左移动）。每一颗小行星以相同的速度移动。

找出碰撞后剩下的所有小行星。碰撞规则：

- 两个行星相互碰撞，较小的行星会爆炸；
- 如果两颗行星大小相同，则两颗行星都会爆炸；
- 两颗移动方向相同的行星，永远不会发生碰撞。



### 2. 题解

- 对于每个 asteroid 均赋予变量 alive，如果行星存在则存入stack；
- 只有左侧数字为正，右侧数字为负的才会发生碰撞，比如 10，-10 之类；
- 当满足 asteroid < 0 && !stack.isEmpty() && stack.peek() > 0 时，会发生碰撞，
  - 碰撞结果大于0，则右侧负数小行星消失，alive为false；
  - 碰撞结果小于0，则说明左侧正数小行星消失，需要执行pop行星删除，同时继续循环直至不发生碰撞；
  - 碰撞结果等于0，则说明二者同归于尽，同时执行alive=false 和 pop操作。



### 3. 代码

- 代码如下。

```java
class Solution {
    public int[] asteroidCollision(int[] asteroids) {

        Stack<Integer> stack = new Stack<>();
        for (int asteroid : asteroids) {

            boolean alive = true;
            while (asteroid < 0 && !stack.isEmpty() && stack.peek() > 0){

                asteroid = collision(asteroid, stack.peek());
                if (asteroid > 0)
                    alive = false;
                else if (asteroid < 0)
                    stack.pop();
                else {
                    alive = false;
                    stack.pop();
                }

            }
            if (alive)
                stack.push(asteroid);
        }

        int size = stack.size();
        int[] res = new int[size];
        for (int i = size - 1; i >= 0; i--) {
            res[i] = stack.pop();
        }

        return res;
    }

    int collision(int a, int b) {

        if (Math.abs(a) > Math.abs(b))
            return a;
        else if (Math.abs(a) < Math.abs(b))
            return b;
        else
            return 0;
    }

}
```