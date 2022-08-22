# [剑指 Offer II 014. 字符串中的变位词](https://leetcode.cn/problems/MPnaiL/)

### 1. 题目

- 给定两个字符串 `s1` 和 `s2`，写一个函数来判断 `s2` 是否包含 `s1` 的某个变位词。

  换句话说，第一个字符串的排列之一是第二个字符串的 **子串** 。



### 2. 题解

#### 解法1

- 滑动窗口的大小为字符串s1的长度，在字符串s2上自左向右移动该滑动窗口，判断当前窗口内的字符和字符串s1的关系；
- 具体的判断条件
  - 将当前窗口内的字符串排序，判断与s1排序后的结果是否相同，相同则直接返回true。
- 反馈：每次均需要对字串进行Sort操作，效率低。



#### 解法2

- 变位词可以理解为 两个字符串各个元素出现的次数相同，因此可以将字符串中各个元素出现的次数存储在数组中

- 字符串向数组中转存的原则

  - s = "abcb"  ==> a出现1次，b出现2次，c出现1次 ==>  [1,2,1,0,0......]

- 具体的流程

  - 对s1Count和s2Count进行初始化；

  - 此后对s2中的滑动窗口进行移动，假设右移后的左下标为left，右下标为left + s1.length() - 1，则执行

    ```java
    s2Count[s2.charAt(left - 1) - 'a']--; //去掉当前窗口左边界的前一个字母
    s2Count[s2.charAt(left + s1.length() - 1) - 'a']++;//增加当前窗口的右边界值
    ```

  - 执行Arrays.equals(s1Count, s2Count)判断当前窗口是否满足条件。



### 3. 代码

- 解法 1 代码如下。

```java
class Solution {
    public boolean checkInclusion(String s1, String s2){

        String  target = swap(s1.toCharArray());
        int left = 0;
        for (int right = s1.length(); right <= s2.length(); right++){
            String window = s2.substring(left, right);
            String windowSorted = swap(window.toCharArray());
            if (windowSorted.equals(target))
                return true;
            left++;
        }
        return false;
    }

    String swap(char[] chars){
        StringBuilder sb = new StringBuilder();
        Arrays.sort(chars);
        for (char c : chars){
            sb.append(String.valueOf(c));
        }
        return sb.toString();
    }
}
```

- 解法 2 代码如下。

```java
class Solution {
    public boolean checkInclusion(String s1, String s2){

        if (s1.length() > s2.length())
            return false;
        int[] s1Count = new int[26];
        int[] s2Count = new int[26];

        for (int i = 0; i < s1.length(); i++){
            s1Count[s1.charAt(i) - 'a']++;
            s2Count[s2.charAt(i) - 'a']++;
        }
        if (Arrays.equals(s1Count, s2Count))
            return true;

        for (int left = 1; left <= s2.length() - s1.length(); left++){

            s2Count[s2.charAt(left - 1) - 'a']--;
            s2Count[s2.charAt(left + s1.length() - 1) - 'a']++;
            if (Arrays.equals(s1Count, s2Count))
                return true;

        }
        return false;
    }


}
```

