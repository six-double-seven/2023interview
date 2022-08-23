# 02-小而美的API

>主要用于记录不常见但很好用的API



## 一、java

#### 1. Character.isLetterOrDigit()

- 判断字符是字母or数字，代替正则；

  ```java
  if (Character.isLetterOrDigit(c)){
      sb.append(Character.toLowerCase(c));
  }
  ```

  

#### 2.  String removeCharAt(String s, int pos)

- 移除字符串s位置为pos的字母

  ```java
  String removeCharAt(String s, int pos) {
      return s.substring(0, pos) + s.substring(pos + 1);
  }
  ```

  



## 二、js

