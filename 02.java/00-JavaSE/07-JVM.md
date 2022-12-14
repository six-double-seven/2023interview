## 1.java项目运行

1..java通过编译生成二进制的.class文件；

2.如果JVM想要执行.class文件，需要将其装进类**加载器**中，它就像搬运工s一样将所有的.class文件搬进JVM中；

3.**方法区**是用于存放类似于**元数据信息**方面的数据，比如类信息(类加载器将.class文件搬过来就放这)、常量、静态变量、编译后的代码等；

4.**堆** 主要存放存储的数据，比如对象实例、数组，它和方法区都属于 **线程共享区域** ，是线程不安全的；

5.**栈 ** 是我们的代码运行空间，编写的每一个方法都会放在栈里面运行。

6.**程序计数器** 类似于指针，指向下一行我们需要执行的代码

**总结**

- .java文件通过编译生成.class文件，.class文件通过类加载器加载到JVM中；
- 虚拟机分为5大块：方法区和堆都属于线程共享区域，栈、本地方法栈、计数器是独享区域

## 2.类加载器

### 2.1 工作流程

1.加载

将class文件加载到内存中，将静态数据结构转化为方法区中运行时的数据结构；

2.链接

验证：确保加载的类符合JVM规范和安全；

准备：为static变量在方法区中分配内存空间，设置变量的初始值；

**注：**准备阶段只设置类中的静态变量，不包括**堆内存中的实例变量**，实例变量是对象初始化时赋值的；

3.初始化

比如static a = 3 由默认初始化的0变成显式初始化的3

4.卸载

GC将无用的对象在内存中卸载

### 2.2 加载顺序

1. BootStrap ClassLoader：rt.jar
2. Extension ClassLoader: 加载扩展的jar包
3. App ClassLoader：指定的classpath下面的jar包
4. Custom ClassLoader：自定义的类加载器

### 2.3 双亲委派机制

- 当一个类收到加载请求时，不会自己尝试加载，而是委派给父类完成，只有父类加载器反馈自己无法完成该请求，子类加载器才会自行尝试；
- 好处是加载位于rt.jar包的类时，不管是哪个类加载器加载，最终都会委托到启动类加载器加载，这样保证使用不同的类加载器得到相同的结果，双亲委派机制起到了隔离的作用。

### 2.4 Tomcat打破双亲委派

-  通常一个tomcat要加载多个应用程序，假如使用的都是spring框架, 既有spring4的项目也有spring5的项目。因为spring4 和 spring5中有很多类的类名是一样的, 但是实现方式不一样，如果都是交给父类加载器进行加载，那么只能加载一份，也就是说spring4和spring5的项目不能共存。而实际上，tomcat可以加载各种各样类型的war包，相互之间没有影响，是因为Tomcat打破了双亲委派机制。
- tomcat中的`jsp类加载器`和`WebappClassLoader`两个类加载器，是java项目在打war包的时候，tomcat自动生成的类加载器。而这个类加载器打破了双亲委派机制，即Webbapp的类加载器不需要再让上级去加载, 他自己就可以加载对应war包里的class文件。

## 3.运行时数据区

### 3.1 方法区

方法区存放类的**元数据信息**、**常量**、**静态变量**

### 3.2 堆

- 堆主要存放存储的数据，比如对象实例、数组，
- JVM内存分为堆内存和非堆内存，堆内存划分为年轻代和老年代，非堆内存成为永久代。

### 3.3 程序计数器

程序计数器其实就是指针，指向我们程序中下一句需要执行的指令

### 3.4 本地方法栈

使用`nativte`修饰的方法是本地方法，此类方法 存放在本地方法栈的区域

### 3.5 虚拟机栈

1.生命周期

- 栈不存在垃圾回收，只要程序结束，栈的空间自然释放
- 8种基本类型的变量+对象的引用变量+实例方法都是在栈里面分配内存

2.虚拟机栈的执行

- 栈中的数据都是以栈帧的格式存在
- 栈帧数据在jvm中叫栈帧，其实就是方法，执行a方法将栈帧A1压栈，运行结束之后弹栈

3.虚拟机栈存在的异常

- StackOverflowError  超过栈的最大深度
- OutOfMemoryError  超内存

## 4.GC

### 4.1 如何判断一个对象不再使用

1.引用计数器

- 给对象添加一个引用计数器，每次引用该对象+1，引用失效就-1，计数器等于0标识不再使用；

2.可达性分析

- 是一种类似二叉树的实现，将一系列的GCRoots作为起始存活的对象集，从该节点向下搜索，所走过的路径成为引用链，把能够被该集合引用的对象加入到集合中，当某一个对象没有任何引用则说明不可用；

- GC会收集那些不是GC roots，且没有被GC roots引用的对象；

### 4.2 垃圾回收的算法

1. 标记清除算法
2. 复制算法
3. 标记整理算法
4. 分代收集算法
   - 在新生代中，每次垃圾收集都有大批对象死去，使用复制算法
   - 老年代中对象存活率高，使用标记清理或者标记整理回收。

# 5. JVM

>综述

- 包括三块内存空间，分别是栈内存、堆内存、方法区内存
- 堆内存和方法区内存只有1个，1个线程1个栈内存
- 方法调用的时候，该方法所需要的内存空间在栈内存中分配，称为**压栈**；方法结束之后，该方法所属的内存空间释放，称为**弹栈**
- 方法的代码片段以及整个类的代码片段都存储在方法区内存中，在类加载的时候这些代码片段会载入
- 在程序执行过程中，使用new运算符创建java对象，存储在堆内存中，对象内部有实例变量，实例变量存储在堆内存中
- **变量的分类**
  - 局部变量【方法体内声明】
  - 成员变量【方法体外声明】
    - 实例变量
    - 静态变量
- 栈内存中存储的**局部变量**，堆内存中存储**实例变量**，方法区内存中存储 **静态变量**
- 三块内存中变化最频繁的是**栈内存**、最先有数据的是**方法区内存**、垃圾回收器主要针对的是**堆内存**
- 堆和方法区是线程共享的，虚拟机栈、本地方法栈、程序计数器是线程私有的

![image-20220410110903304](http://six-double-seven.oss-cn-beijing.aliyuncs.com/img/image-20220410193426194.png)

# 6.JMM

>概念

- JMM是JAVA内存模型(JAVA Memory Model)，目的是为了屏蔽各种硬件和操作系统之间的内存访问差异，从而让JAVA程序在各种平台对内存的访问一致
- 在jdk1.2之前，Java 的内存模型实现总是从**主存**（即共享内存）读取变量，不需要特别注意
- 而在此之后线程可以把变量保存**本地内存**（比如机器的寄存器）中，而不是直接在主存中进行读写。这就可能造成一个线程在主存中修改了一个变量的值，而另外一个线程还继续使用它在寄存器中的变量值的拷贝，造成**数据的不一致**，因此需要将变量声明为volatile，那么对该变量的操作必须先从主存中读取到自己的工作内存中然后再进行操作，最后需要回写到主存。

## 6.1 主存&&本地内存

- **主内存** ：所有线程创建的实例对象都存放在主内存中，不管该实例对象是成员变量还是方法中的本地变量
- **本地内存** ：每个线程都有一个私有的本地内存来存储共享变量的副本，并且，每个线程只能访问自己的本地内存，无法访问其他线程的本地内存。本地内存是 JMM 抽象出来的一个概念，**存储了主内存中的共享变量副本**。

- 主存和内存交互的八种操作
  - lock、unlock、read、load、use、assign、store、write















