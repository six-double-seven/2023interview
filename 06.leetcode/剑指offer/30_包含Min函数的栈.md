## [剑指 Offer 30. 包含min函数的栈](https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/)

### 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

###  思路

新增一个栈，每次插入时比较最小值插进去。弹出的时候，跟着一起弹出。

### 代码

```c++
class MinStack {
public:
    stack<int> stk;
    stack<int> Minstk;
    /** initialize your data structure here. */
    MinStack() {
        Minstk.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        Minstk.push(Minstk.top() < x ? Minstk.top(): x);
    }
    
    void pop() {
        stk.pop();
        Minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return Minstk.top();
    }
};
```