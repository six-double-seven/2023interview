# [剑指 Offer II 013. 二维子矩阵的和](https://leetcode.cn/problems/O4NDxx/)

### 1. 题目

- 给定一个二维矩阵 matrix，以下类型的多个请求：

  计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。实现 NumMatrix 类：

  NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
  int sumRegion(int row1, int col1, int row2, int col2) 返回左上角 (row1, col1) 、右下角 (row2, col2) 的子矩阵的元素总和。



### 2. 题解

#### 2.1 一维前缀和

- 初始化矩阵时，每个位置存放的是**当前位置左侧**前缀和，即一维前缀和，如下图所示，红色数字为数组中真正存储的元素；

- 假如求矩阵   3， 5   的和，则只需要【9-1】 +【 37 - 10】= 35 即可。

  ​                     11，16

![image-20220822203341415](C:\Users\28897\AppData\Roaming\Typora\typora-user-images\image-20220822203341415.png)



### 3. 代码

- 代码如下。

```java
class NumMatrix {
    int[][] array;

    public NumMatrix(int[][] matrix) {

        for (int i = 0; i < matrix.length; i++){
            int sum = 0;
            //注意是 matrix[0].length 而不是 matrix.length
            for (int j = 0; j < matrix[0].length; j++){
                sum += matrix[i][j];
                matrix[i][j] = sum;
            }
        }
        array = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++){
            // col1为0时，代表其前缀和为0，减0忽略即可
            if (col1 == 0)
                sum += array[row][col2];
            else
                sum += array[row][col2] - array[row][col1 - 1];
        }
        return sum;
    }
}

```



- 暴力解法代码如下。

```java
class NumMatrix {
    int[][] array;

    public NumMatrix(int[][] matrix) {
        array = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++){
            for (int j = col1; j <= col2; j++){
                sum += array[i][j];
            }
        }
        return sum;
    }
}
```

