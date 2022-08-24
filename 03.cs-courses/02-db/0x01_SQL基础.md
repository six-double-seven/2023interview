### 前言
本文参考[SQL基础教程](https://github.com/datawhalechina/wonderful-sql/)编写，建立在曾学习过相关课程的基础上，进行回顾。如您未曾接触过SQL，阅读本文可能会有些吃力。
### 语法规范

1. MySQL本身不区分大小写，但强烈要求关键字大写，表名、列名用小写；
2. 创建表时，使用统一的、描述性强的字段命名规则保证字段名是独一无二且不是保留字的，不要使用连续的下划线，不用下划线结尾；最好以字母开头
3. 关键字右对齐，且不同层级的用空格或缩进控制，使其区分开。
4. 列名少的时候写在一行里无伤大雅；多的时候以及涉及到CASE WHEN 或者聚合计算的时候，建议分行写；个人习惯是逗号在列名前面，方便之后删除某些列，放列名后亦可；
5. 表别名和列别名尽量用有具体含义的词组，不要用`a b c`，不然以后review的时候会非常痛苦；
6. 运算符前后都加一个空格；
7. 当用到多个表时，请在所有列名前写上引用的表别名，不要嫌麻烦；
8. 每条命令用分号结尾；
9. 养成随手写注释的习惯，注释方法：
```sql
#单行注释
-- 单行注释
/*
多行注释
*/
```

### SQL语句分类

#### DDL

DDL（Data Definition Language，数据定义语言） 用来**创建或者删除**存储数据用的**数据库以及**数据库中的**表**等对象。（create、drop、alter）

#### DML

DML（Data Manipulation Language，数据操纵语言） 用来**查询或者变更表中的记录**。(select、insert、update、delete)

#### DCL

DCL（Data Control Language，数据控制语言） 用来**确认或者取消**对数据库中的**数据进行的变更**。除此之外，还可以对 RDBMS 的用户是否有权限操作数据库中的对象（数据库表等）进行设定。（commit、rollback、grant、revoke）

> Win 系统默认不区分表名及字段名的大小写<br>Linux / Mac 默认严格区分表名及字段名的大小写

### 基本语句

```mysql
# 创建数据库
CREATE DATABASE < 数据库名称 > ;
# 建表
CREATE TABLE < 表名 >
( < 列名 1> < 数据类型 > < 该列所需约束 > ,
  < 列名 2> < 数据类型 > < 该列所需约束 > ,
  < 该表的约束 1> , < 该表的约束 2>);
# 删除表
DROP TABLE < 表名 > ;
# 添加列
ALTER TABLE < 表名 > ADD COLUMN < 列的定义 >;
# 删除列
ALTER TABLE < 表名 > DROP COLUMN < 列名 >;
# 删除行
DELETE FROM product WHERE < 所满足的条件 >;
# 更新数据 值可以改为NULL
UPDATE <表名>
   SET <列名> = <表达式> [, <列名2>=<表达式2>]  
 WHERE <条件>  -- 可选，非常重要
 ORDER BY 子句  -- 可选
 LIMIT 子句; -- 可选
# 插入
INSERT INTO <表名> (列1, 列2, 列3) VALUES (值1, 值2, 值3);  


# 创建索引
-- 建表时
CREATE TABLE mytable(< 列名 1> < 数据类型 > < 该列所需约束 >,  
INDEX [indexName] (username(length))  );  
-- else
CREATE INDEX indexName ON table_name (column_name)

ALTER table tableName ADD INDEX indexName(columnName)

```

> 只有未设置`NOT NULL`且非主键的列才可以清空为NULL。

#### 列约束

- `PRIMARY KEY`  ---  主键
- `UNIQUE`  ---  值唯一（NULL值可重复）
- `DEFAULT`  ---  默认值（使用时不写、写`DEFAULT`均可以）
- `NOT NULL`  ---  非空
- `FOREIGN`  ---  外键
- `AUTO_INCREMENT`  ---  自动成长（成长为列的最大值+1）

### 索引

索引的作用  ---  提高查询速率

索引一般分为

1. 聚集索引  ---  在数据库中，所有行数都会按照主键索引排序。
2. 非聚集索引  ---  就是给普通字段加上索引。
3. 联合索引  ---  好几个字段组成的索引称为联合索引。

#### 分类

- 主键索引

建立在主键上的索引。一张数据表只能有一个主键索引，索引列值不允许有空值，通常在创建表时一起创建。

- 唯一索引

建立在UNIQUE字段上的索引。一张表可以有多个唯一索引，索引列值允许为空，列值中出现多个空值不会发生重复冲突。

- 普通索引

建立在普通字段上的索引。

- 前缀索引

对字符类型字段的前几个字符或对二进制类型字段的前几个bytes建立索引。通常建立在类型为`char、varchar、binary、varbinary`的列上。

可以大大减少索引占用的存储空间，也能提升索引的查询效率。

- 全文索引

全文索引技术就是将各种信息，文档中所有的文字序列都作为检索对象，找出包含检索词汇的信息或文档。

### 查找

> 找某一列

```sql
SELECT [DISTINCT] <列名> FROM <表名>;
```

- `*`查找全部
- 随意使用换行符，不影响语句执行。
- `DISTINCT`用来去重。
- `-- 单行注释` & `/* 多行注释*/`
- SELECT子句中可以使用常数或者表达式。

> 寻找某列满足某一条件的值所在行中的某些列

```sql
SELECT <列名>
  FROM <表名>
 WHERE <条件表达式>;
```

#### 运算符

| 含义 |   运算符   |
| :--: | :--------: |
|  +   |     加     |
|  -   |     减     |
|  *   |     乘     |
|  /   |     除     |
|  =   |    相等    |
|  <>  |    不等    |
|  >   |    大于    |
|  >=  |  大于等于  |
|  <   |    小于    |
|  <=  |  小于等于  |
| NOT  |     非     |
| AND  |     与     |
|  OR  |     或     |
|  ()  | 改变优先级 |

- `NULL`既不为真也不为假。值为`UNKNOWN`

#### 聚合函数

- COUNT  ---  行数
- SUM  ---  数据的和
- AVG  ---  数据均值
- MAX  ---  数据最大值
- MIN  ---  数据最小值

```sql
SELECT FUNC(<列名>) FROM <表名> ;
```

- `COUNT(*)`包含含有`NULL`的项；`COUNT(列名)`不包含NULL值。
- `MAX/MIN`适用于所有(字典序)，`AVG/SUM`只适用于数值。

#### 分组

`GROUP BY`按照某几列的值进行分组（有优先级）

```sql
   SELECT <列名1>, <列名2>, <列名3>,
     FROM <表名>
 GROUP BY <列名1>, <列名2>, <列名3>;
```

#### 条件

`HAVING`用于解决**WHERE无法与聚合函数一起使用**。这一问题

```sql
  SELECT <列名1>, <列名2>
    FROM <表名>
   WHERE <条件>
GROUP BY <列名1>, <列名2>
  HAVING <条件[常为聚合后的条件]>
```

#### 排序

`ORDER BY`将查询结果排序。默认为升序排列，降序排列为`DESC`。

```sql
  SELECT <列名1>, <列名2>
    FROM <表名>
   WHERE <条件>
GROUP BY <列名1>, <列名2>
  HAVING <条件[常为聚合后的条件]>
ORDER BY <排序基准列1>, <排序基准列2> [DESC]
```

- `MySQL`中认为`NULL`值比`非NULL`小。（排序时可能需要特殊处理）
  - 在排序时可以使用`IS NULL`运算符及`ISNULL()`函数来对NULL值做特殊处理

### 视图

视图是一个虚拟的表，不同于直接操作数据表，视图是依据 SELECT 语句来创建的，所有操作视图时会根据创建视图的 `SELECT` 语句生成一张虚拟表，然后在这张虚拟表上做 SQL 操作。

> 视图与表的区别是「是否保存了实际的数据」

视图**并不是**数据库**真实存储的数据表**，它可以看作是一个窗口，通过这个窗口我们可以看到数据库表中真实存在的数据。

#### 存在原因

- 可以将频繁使用的 SELECT 语句保存以提高效率。
- 可以使用户看到的数据更加清晰。
- 可以不对外公开数据表全部字段，增强数据的保密性。
- 可以降低数据的冗余。

```sql
-- 创建视图
CREATE VIEW <视图名称>(<列名1>,<列名2>) AS <SELECT语句>
# 可以基于多张表创建视图
```

- SELECT 语句中列的排列顺序和视图中列的排列顺序相同
- 视图名在数据库中需要是唯一的，不能与其他视图和表重名。

#### 更新视图

由于视图是一个虚拟表，对视图的操作就是对底层基础表的操作。

故，当视图存在以下结构时不能更新：

- 聚合函数。如，SUM()、MIN()、COUNT() 
- DISTINCT 关键字
- GROUP BY 子句。
- HAVING 子句。
- UNION 或 UNION ALL 运算符。
- FROM 子句中包含多个表。

```sql
UPDATE <视图名称>
   SET <列名> = <表达式>
 WHERE <条件>
```

#### 删除视图

```sql
DROP VIEW <视图名1>
```

### 子查询

一个查询语句嵌套在另一个查询语句内部。子查询结果作为外层查询的过滤条件，查询可以基于一个表或者多个表。

> 不建议嵌套多层子查询<br>虽然嵌套子查询可以查询出结果，但是随着子查询嵌套的层数的叠加，SQL语句不仅会难以理解而且执行效率也会很差，所以要尽量避免这样的使用。

#### 标量子查询

执行的SQL语句只能返回一个值，也就是要返回表中具体的**某一行的某一列**。

> 标量子查询不仅仅局限于 WHERE 子句中，通常任何可以使用单一值的位置都可以使用。

```sql
-- 查找价格高于平均值的商品
SELECT product_id, product_name, sale_price
  FROM product
 WHERE sale_price > (SELECT AVG(sale_price) FROM product) AS avg_price;
```

> 这里出现的`AS`用来起别名。创建别名是为了让列名称的可读性更强。

#### 关联子查询

关联子查询，在细分的组内进行比较时使用。

> 需要特别注意其与一般的SQL语句相比，执行顺序有所不同。

- 首先执行不带WHERE的主查询，获取到所关联的列，依次（一次传一行）传入子查询。
- 根据主查询传入的结果匹配子查询，将查询结果返回父查询
- 根据子查询返回值依次判断父查询的`WHERE`子句。

以下列代码为例

```sql
/********************
  已知 有一张表 score
   表中含有如下信息：
   student_id 学生学号
    course_id 课程号
 course_score 课程成绩
  所要查询的内容：
  成绩大于平均分的学生
  的学号、课程号、成绩
 ********************/ 
SELECT student_id,course_id,course_score
  FROM score AS s1
 WHERE course_score > ( SELECT AVG(course_score)
    		     FROM score AS s2
   			    WHERE s1.course_id = s2.course_id
			 GROUP BY course_id);
```

1. 首先执行主查询`SELECT student_id,course_id,course_score FROM score AS s1`提取出`student_id,course_id、course_score`三列所需要的信息
2. 执行`()`中的子查询语句，依次将`course_id`传入`s1.course_id= s2.course_id `并执行得到
   - 如第一步查询出课程编号为`10001  10002  10003  10004`
   - 依次将课程号传入相应位置 执行`SELECT AVG(course_score) FROM score AS s2 WHERE course_id = 10001 GROUP BY course_id`根据这门课的所有人成绩计算该门课的平均分
   - 依次将每门课的平均分`val`值返回给主查询。
3. 然后依次执行`SELECT student_id,course_id,course_score FROM score AS s1 WHERE course_score > val`。得到每门课成绩大于平均分的学生的信息。

> 其中 需要注意的是 看似是废话的`WHERE s1.course_id = s2.course_id`即为关联子查询的关键点。（关联条件）

### 函数

SQL内置了一些函数，极大提高了SQL语言的便利性。分类如下

* 算术函数
* 字符串函数
* 日期函数
* 转换函数
* 聚合函数

#### 算术函数

- ABS(val)  ---  绝对值。ABS(NULL) 返回NULL
- MOD(val, pow)  ---  取余。
- ROUND(val, n)  ---  四舍五入保留n位小数。

#### 字符串函数

- CONCAT(str1, str2)  ---  字符串拼接
- LENGTH(str)  ---  字符串长度
- LOWER(str)  ---  转换成小写
- UPPER(str)  ---  转换成大写
- REPLACE(str,ch1,ch2)  ---  将str中`ch1`全部替换为`ch2`
- SUBSTRING(str FROM pos FOR n)  ---  在str中pos位置开始提取长度为n的子串
- SUBSTRING_INDEX(str,ch,n)  ---  以ch为分隔符划分str，并获取第n个分隔符前的所有内容
- REPEAT(str,n)  ---  将字符串str重复n次

#### 日期函数

- CURRENT_DATE  ---  获取当前日期
- CURRENT_TIME  ---  获取当前时间
- CURRENT_TIMESTAMP  ---  获取当前日期和时间
- EXTRACT(日期元素 FROM 日期)  ---  从日期中截取信息
  - EXTRACT(YEAR   FROM CURRENT_TIMESTAMP) AS year 获取年份。
  - 日期元素有`YEAR  MONTH  DAY  HOUR  MINUTE  SECOND`

#### 转换函数

- CAST(val,type)  ---  将值转换成相应的类型
- COALESCE(val1,val2,....)  ---  获取所有参数中第一个非NULL值。

### 谓词

表示个体的性质和个体之间关系的符号。主要包括`LIKE、BETWEEN、IS NULL、IS NOT NULL、IN 、EXISTS`

#### LIKE

用于字符串的部分匹配

```sql
  SELECT <列名1>, <列名2>
    FROM <表名>
   WHERE <列名> LIKE <字符串>;
```

字符串支持正则表达式。

- `%`表示任意个数字符。例如，`%xxx%`表示含有`xxx`的所有字符串。
- `_`表示一个字符。例如`_xxx%`表示第2~4位为`xxx`的所有字符串。
- `[x]`表示列表中的一个字符。例如`[abcd]xxx`表示`axxx`或`bxxx`或`cxxx`或`dxxx`
- `[^x] 、 [!x]`表示不在列表中的字符。`[^abc]xxx`表示长度为4，首位不为`a  b  c`，后三位为`xxx`的字符串

#### BETWEEN

用于范围查询。

```sql
SELECT product_name, sale_price
  FROM product
  WHERE sale_price BETWEEN 100 AND 1000;
-- 查询价格在100~1000之间的商品
```

> `BETWEEN val1 AND val2 `包括左右临界值。

#### IS NULL/ IS NOT NULL

取空或非空（有些条件下不能使用`= <>`，比如取值为空的数据）

```sql
SELECT product_name, purchase_price
  FROM product
 WHERE purchase_price IS NULL;
```

#### IN/ NOT IN

多条件并集的查询。

```sql
SELECT product_name, purchase_price
  FROM product
 WHERE purchase_price IN (250,500,750);
 /**********************************
       purchase_price = 250
    OR purchase_price = 500
    OR purchase_price = 750;
***********************************/
```

> IN 还可以用在子查询中<br>比如某连锁商店有很多个分店，不同分店的商品不完全一样<br>我们查询某个分店的是否有某个商品时<br>子查询返回该分店的所有商品<br>主查询判断是否在这个范围内

#### EXIST/NOT EXIST

「判断是否存在满足某种条件的**记录**」。存在，返回`true`；不存在，返回`false`。

```sql
-- 选出某个分店在售商品(价格不为NULL)的单价
-- IN
SELECT product_name, sale_price
  FROM product
 WHERE product_id IN (SELECT product_id
  	                    FROM shopproduct
                       WHERE shop_id = 'XXX');
-- EXIST
SELECT product_name, sale_price
  FROM product AS p
 WHERE EXISTS (SELECT 1 -- 这里可以书写适当的常数
                 FROM shopproduct AS sp
                WHERE sp.shop_id = 'XXX'
                  AND sp.product_id = p.product_id);
```

> 由于 EXIST 只关心记录是否存在，返回哪些列都没有关系。

### CASE

条件分支。

```sql
CASE WHEN <求值表达式> THEN <表达式>
     WHEN <求值表达式> THEN <表达式>
     WHEN <求值表达式> THEN <表达式>
-- 均为假执行else
ELSE <表达式>
END  
-- 可以用于调用聚合函数时 一些特殊值的处理
CASE WHEN <列名> IS NOT NULL THEN <表达式>
ELSE <表达式> END
```

### 集合的运算

`表、视图、查询结果`都是记录的集合， 其中的元素为「表或者查询结果」中的每一行。

`UNION、INTERSECT、EXCEPT` 来将检索结果进行集合运算。

#### 并集

UNION，重复项会去重。

```sql
/******************
 楼下有两个商店
 shop1为A商店所卖商品
 shop2为B商店所卖商品
 求问能在楼下买到啥
******************/
SELECT product_id, product_name
  FROM shop1
 UNION
SELECT product_id, product_name
  FROM shop2;
```

`UNION ALL`取并集后不去重。

#### 交集 

INTERSECT，`MySQL`不支持。

```sql
-- 两个商店中均能买到的商品
-- INTERSECT
   SELECT product_id, product_name
     FROM shop1
INTERSECT
   SELECT product_id, product_name
     FROM shop2;
-- 手动模拟
    SELECT s1.product_id, s1.product_name
      FROM shop1 s1
INNER JOIN shop2 s2
        ON s1.product_id=s2.product_id
```

#### 差集

EXCEPT，`MySQL`不支持。

```sql
-- 只能在A商店中买的商品
SELECT *
  FROM shop1
 WHERE product_id NOT IN (SELECT product_id
                         	FROM shop2)
-- EXCEPT
SELECT *
  FROM shop1
EXCEPT
SELECT *
  FROM shop2
```

#### 对称差

两个集合`A  B`， 求仅在A及仅在B中的元素。

```sql
-- 只能在一个商店买
-- 另一个商店买不到
SELECT *
  FROM shop1
 WHERE product_id NOT IN (SELECT product_id
                         	FROM shop2)
 UNION
SELECT *
  FROM shop2
 WHERE product_id NOT IN (SELECT product_id
                         	FROM shop1)
-- 交集 - 并集
```

### JOIN

从多个表获取信息时，用于表的合并。

使用某种关联条件将其他表中的列添加过来, 进行「添加列」的集合运算。

关联条件  ---  两个表中的公共列信息（两个表建立关联的桥梁）

#### INNER JOIN

将两张表进行连结。其中不满足关联条件的行被丢弃。

```sql
FROM <表1> INNER JOIN <表2> ON <关联条件>
```

> 如果分组列和被聚合的列不在同一张表, 且二者都未被用于连结两张表, 则只能先连结, 再聚合。

##### NATURAL JOIN

`INNER JOIN`的特例，会按照两个表中都包含的列名来进行等值连结。

```sql
FROM <表1> NATURAL  JOIN <表2>
```

#### OUTER JOIN

将两张表进行连结。其中会保留部分不满足条件的行。提取不到的值填充为`NULL`值。

- LEFT OUTER JOIN  ---  左外连结。保留左表（表1）中匹配失败的值。
- RIGHT OUTER JOIN  ---  右外连结。保留右表（表2）中匹配失败的值。
- FULL OUTER JOIN  ---  全外连结。两个表中匹配失败的值均会保留。

```sql
FROM <表1>  LEFT OUTER JOIN <表2> ON <关联条件>
FROM <表1> RIGHT OUTER JOIN <表2> ON <关联条件>
FROM <表1>  FULL OUTER JOIN <表2> ON <关联条件>
```

#### 多表连结

语法中JOIN只涉及两个表，但实际使用会涉及多张表。

```sql
-- INNER JOIN
      FROM <表1> 
INNER JOIN <表2> ON <关联条件1>
INNER JOIN <表3> ON <关联条件2>
INNER JOIN <表4> ON <关联条件3>
-- OUTER JOIN 同理
```

#### 非等值连结

ON子句中的关联条件不局限于两表中相等。

#### 交叉连结

`CROSS JOIN`笛卡尔积。交叉连结不具备`ON`子句（可以理解为恒真）

对两张表中的全部记录进行交叉组合，因此结果中的记录数通常是两张表中行数的乘积。

### 窗口函数

`OnLine AnalyticalProcessing`OLAP函数。对数据库数据进行实时分析处理。

常规的SELECT语句都是对整张表进行查询，而窗口函数可以让我们有选择的去某一部分数据进行汇总、计算和排序。

```sql
<窗口函数> OVER ([PARTITION BY <列名>]
                     ORDER BY <排序用列名>)  
-- [PARTITION BY <列名>] 可以省略
```

- PARTITION BY  ---  指定窗口对象(分组基准)
- ORDER BY  ---  窗口内排序

#### 分类

窗口函数分为

- 通用函数  ---  `SUM  MAX  MIN`等
- 专用函数  ---  `RANK  DENSE_RANK`等

通用函数在聚合函数中就在使用。专用函数是专属的。

- RANK()  ---  排序，存在相同位次会跳相应的位次`1 1 3`
- DENSE_RANK()  ---  排序。存在相同位次不会跳相应的位次`1 1 2`
- ROW_NUMBER()  ---  排序。值唯一（顺延，不存在并列）

> 聚合函数在窗口函数应用时，是一个**累计**的聚合函数值。(AVG分母从1开始加)
