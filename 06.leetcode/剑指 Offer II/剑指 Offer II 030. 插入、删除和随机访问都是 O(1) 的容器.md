# [剑指 Offer II 030. 插入、删除和随机访问都是 O(1) 的容器](https://leetcode.cn/problems/FortPu/)

### 1. 题目

设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

- insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false
- remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false
- getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回



### 2. 题解

- 采用 List + Map 实现随机存储，其中map的键值对中存储的是<val，下标>；
- insert() 同时向 List 和 Map 中存储元素；
- remove() 函数，由于 list 删除元素后，其他元素的下标会发生变化，因此将链表的 last 元素覆盖需要删除的元素
  - 使用last元素覆盖需要移除的index元素；
  - 更新map中last值的value值；
  - 删除 list 和 map 中的元素。



### 3. 代码

- List + Map 代码如下。

```java
class RandomizedSet {

    Map<Integer, Integer> map;
    List<Integer> list;
    
    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }

    public boolean insert(int val) {
        if (map.containsKey(val))
            return false;
        map.put(val, list.size());
        list.add(val);
        return true;
    }

    public boolean remove(int val) {
        if (map.containsKey(val)){
            int index = map.get(val);
            int last = list.get(list.size() - 1);
           
            // 使用last元素覆盖需要移除的index元素
            list.set(index, last);
           
            // 更新map中last值的value值
            map.put(last, index);
            
            // 删除 list 和 map 中的元素
            list.remove(list.size() - 1);
            map.remove(val);
            return true;
        }
        return false;
    }

    public int getRandom() {

        int random = new Random().nextInt(map.size());
        return list.get(random);
    }
}
```

- 只使用Map代码如下。

```java
class RandomizedSet {

    Map<Integer, Integer> map;
    
    public RandomizedSet() {
        map = new HashMap<>();
    }

    public boolean insert(int val) {
        if (map.containsKey(val))
            return false;
        map.put(val, val);
        return true;
    }

    public boolean remove(int val) {
        if (map.containsKey(val)){
            map.remove(val);
            return true;
        }
        return false;
    }

    public int getRandom() {

        int random = new Random().nextInt(map.size());
        int cur = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()){
            if (cur == random)
                return entry.getKey();
            cur++;
        }
        return 0;
    }
}
```