# 1.抽象类

## 1.1 概述

>定义

- 类和类之间具有共同特征，将这些共同特征提取出来，形成的是抽象类

- 抽象类属于引用数据类型

- ```java
  [修饰符列表] abstract class 类名{
  
  类体；   
  
  }
  ```

>抽象类无法实例化

- 抽象类无法实例化，**无法创建对象**。抽象类是类和类之间的共同特征，将这些具有共同特征的类再进一步抽象形成了抽象类，由于类本身是不存在的，所以抽象类无法创建对象。
- 抽象类虽然无法实例化，但是抽象类有**构造方法**，这个构造方法供子类使用
- 抽象类无法实例化，无法创建对象，所以抽象类是用来被子类**继承**的

>抽象类的父类和子类

- 抽象类和抽象类实际上可能还会有共同特征，还可以继续抽象

- 抽象类的子类可以是抽象类，也可以是非抽象类

>非抽象类继承抽象类

- 一个非抽象类继承抽象类，必须将抽象类中的抽象方法实现

## 1.2 抽象方法

>什么是抽象方法

- 抽象方法是没有实现的方法，没有方法体的方法

  `public abstract void test();`

- 特点1 没有方法体，以分号结尾

- 特点2 前面的修饰符列表中有abstract关键字

>特点

- 抽象类中不一定有抽象方法，但抽象方法必须出现在抽象类中
- 抽象类中可以有非抽象方法

>面试题：java中凡是没有方法体的方法都是抽象方法吗

- Object类中 public native int hashCode(); 该方法底层调用c++写的动态链接库程序，前面的修饰符列表中没有abstract，因此不是抽象方法。有一个native，表示调用JVM本地程序

# 2.接口

## 2.1 接口概述

- 接口是一种引用数据类型
- 接口是**完全抽象**的，或者说接口是特殊的抽象类
- [修饰符列表] interface 接口名{  }
- 接口支持多继承

>接口 = 常量 + 抽象方法

- 接口中只包含  **常量**+ **抽象方法**
- 接口中所有的元素都是**public**的
- 接口中抽象方法定义时 **public abstract** 修饰符可以忽略
- 接口中常量定义时**public static final** 可以忽略

>允许有默认的实现类

- 接口中有默认default的实现类

  ```java
  default int test(){
          return 11;
      }
  ```

## 2.2 接口的应用

- FoodMenu接口

```java
public interface FoodMenu {

    void food1();
    void food2();

}
```

- Cooker1.class

```java
public class Cooker1 implements FoodMenu{
    @Override
    public void food1() {
        System.out.println("中餐food1");
    }

    @Override
    public void food2() {
        System.out.println("中餐food2");

    }
}
```

- Cooker2.class

```java
public class Cooker2 implements FoodMenu{

    @Override
    public void food1() {
        System.out.println("西餐food1");
    }

    @Override
    public void food2() {
        System.out.println("西餐food2");
    }
}

```

- Customer.class

```java
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Customer {
    private FoodMenu foodMenu;
    public void order(){
        foodMenu.food1();
        foodMenu.food2();
    }

}
```

- Test.class

```java
public class Test {
    public static void main(String[] args) {
        Cooker1 cooker1 = new Cooker1();
        Customer customer = new Customer(cooker1);
        customer.order();
    }
}
```

# 3.抽象类和接口的区别

- 抽象类是半抽象的，接口是完全抽象的
- 抽象类有构造方法，接口中没有构造方法
- 接口和接口之间支持多继承，抽象类和抽象类之间只能单继承
- 一个类可以实现多个接口，一个抽象类只能继承一个类(单继承)
- 接口中只允许出现常量和抽象方法，一般是对**行为**的抽象

# 4.类和类的关系

- 继承关系  is a   A extends B
- 关联关系  has a   
  - A{ B b}  A中有B
- 实现关系 like a    类是实现接口