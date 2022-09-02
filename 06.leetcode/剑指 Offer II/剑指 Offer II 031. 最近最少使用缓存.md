# [剑指 Offer II 031. 最近最少使用缓存](https://leetcode.cn/problems/OrIXps/)

### 1. 题目

运用所掌握的数据结构，设计和实现一个  LRU (Least Recently Used，最近最少使用) 缓存机制 。

实现 LRUCache 类：

- LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
- int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
- void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。



### 2. 题解

(1) 重写 LinkedHashMap 的 **removeEldestEntry()** 方法

- removeEldestEntry：当size 大于 capacity 时，返回true；
- put() 函数对 removeEldestEntry() 的依赖关系  put() -->  putVal() --> afterNodeInsertion() --> removeEldestEntry()；

(2) HashMap<key，node> + 双向链表

- 双向链表的节点 class 属性包括 key、value、pre、next；

- 主要逻辑

  a. LRUCache()  对 HashMap 和 双向链表 进行初始化；

  b. get(int key) 函数

  - 如果map不存在，则返回-1；
  - 如果存在key，则返回map.get(key).value，将key值对应的节点移动至双向链表的头部；

  c. put(int key，int value) 函数

  - 如果存在key，则覆盖当前节点的value值，将对应的节点移动至双向链表的头部；
  - 如果不存在key，则创建新的节点，存入 双向链表的头部 和 HashMap 中；判断节点数量**是否超出容量**，如果超出则删除双向链表的尾部节点，并删除map中对应的项。



### 3. 代码

- 重写 removeEldestEntry 代码如下。

```java
class LRUCache extends  LinkedHashMap<Integer, Integer> {
    private int capacity;

    public LRUCache(int capacity) {
        super(capacity, 0.75F, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return super.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity;
    }
}
```

-  HashMap + 双向链表 代码如下。

```java
class LRUCache {

    int capacity;
    HashMap<Integer, Node> cache;
    Node head, tail;

    public LRUCache(int capacity) {

        this.capacity = capacity;
        cache = new HashMap<>();

        //初始化双向链表
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.pre = head;
    }

    public int get(int key) {

        if (cache.containsKey(key)){

            Node keyNode = cache.get(key);
            // 删除 node
            removeNode(keyNode);
            // 添加 至头部
            addToHead(keyNode);
            return keyNode.value;
        }
        else
            return -1;
    }

    public void put(int key, int value) {

        if (cache.containsKey(key)){

            cache.get(key).value = value;
            Node keyNode = cache.get(key);
            // 删除 keyNode
            removeNode(keyNode);
            // 添加 至头部
            addToHead(keyNode);

            cache.put(key, keyNode);
        }else {
            Node node = new Node(key, value);
            addToHead(node);
            cache.put(key, node);
            if (cache.size() > capacity){
                cache.remove(tail.pre.key);
                removeNode(tail.pre);
            }
        }

    }

    public void removeNode(Node node){
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }

    public void addToHead(Node node){

        node.next = head.next;
        head.next.pre = node;
        head.next = node;
        node.pre = head;
    }

    class Node {
        int key;
        int value;
        Node pre;
        Node next;

        public Node() {
        }

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

}
```