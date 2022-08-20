# [剑指 Offer II 005. 单词长度的最大乘积](https://leetcode.cn/problems/aseY1I/)

### 1. 题目

- 给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] **不包含相同字符**时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。



### 2. 题解

- 将每个字符串word用int类型的变量`convertValue`表示；
- 转换的原则，比如word = “abd”
  - 对于字母a，则将1 << 0；对于字母b，则将1 << 1；对于字母d，则将1 << 3；
  - 将上述左移的结果累计取或运算，得到1011，即字符串“abd”可用1011代替；
  - 转换的原则是低26位用来表示某个字母是否出现，如果出现，则对应的数位为1，

![剑指 Offer II 004](images\剑指 Offer II 005.png)

- 假设两个字符串 words[i] 和 words[j] 对应的 convertValue 分别为 i 和 j，则 i & j 相与如果为0则说明**二者不包含相同字符**。



### 3. 代码

- 代码如下。

```java
class Solution {
    public int maxProduct(String[] words) {

        int[] masks = new int[words.length];
        int index = 0, res = 0;
        for (String word : words){
            int convertValue = 0;
            for (int i = 0; i < word.length(); i++){
                int position = word.charAt(i) - 'a';
                convertValue |= (1 << position);
            }
            masks[index] = convertValue;
            index++;
        }

        for (int i = 0; i < masks.length; i++){
            for (int j = i; j < masks.length; j++){
                if ((masks[i] & masks[j]) == 0)
                    res = Math.max(res, words[i].length() * words[j].length());
            }
        }
        return res;
    }
}
```

























