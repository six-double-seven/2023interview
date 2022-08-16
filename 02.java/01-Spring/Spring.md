# Spring

# 1.[spring/springmvc/springboot](https://blog.51cto.com/u_14622073/2536453)

- spring包含springmvc，springboot是spring的扩展，spring是其核心
- Spring为简化我们的开发工作，封装了一系列的开箱即用的组件功能模块，包括：Spring JDBC 、Spring MVC 、Spring Security；
- SpringMVC是属于SpringWeb里面的一个功能模块；
- Spring Boot是Spring框架的扩展，它消除了设置Spring应用程序所需的XML配置。

- spring框架是 Spring Framework

# 2. IOC&&AOP

>IOC (Inverse of Control:控制反转)

- IOC控制反转是一种设计思想，控制指的是对象创建和管理的权力，反转是指将控制权交给外部环境(spring框架、Ioc容器)。即 将原本在程序中手动创建对象的控制权交由spring框架管理；
- 将对象之间的相互依赖关系交给Ioc容器管理，并由Ioc容器完成对象的注入。当我们需要创建一个对象时，只需要使用注解注入即可，而不用关心对象是怎么创建的；
- 之前在学校有一门课程是使用servlet+jsp完成web开发，当时各种service的创建就是手动new的，这个代码我现在是一点都不敢动，紧接着课设的时候使用springboot搭建的后台，切实的感受到了Ioc的震撼；
- 另外之前使用过微软的xamarin.Forms，里面有一个simpleIOC容器，和spring的Ioc是相同的思想，需要在ViewModelLocator的类中将对象注入，使用的时候在容器中取出。

>AOP(Aspect-Oriented Programming:面向切面编程)

- 所谓面向切面编程，就是将那些与业务无关、却被业务模块共同调用的逻辑或责任(事务处理、日志管理)封装起来，避免代码冗余；
- 不改变原来代码的情况下，实现对原有功能的增强，是AOP的核心；
- AOP是基于动态代理的
  - 要代理的对象实现了某个接口，使用**JDK Proxy**创建代理对象
  - 没有实现接口的对象， 使用**Cglib** 生成一个被代理对象的子类来作为代理

# 3.spring的循环依赖

>**循环依赖**

在**依赖注入**过程中，一个Java类A中存在一个属性是类B的一个对象，那么我们就说类A的对象依赖类B，而在Spring中是依靠的IOC来实现对象的注入，也就是说创建对象的过程是IOC容器来实现的，并不需要自己在使用的时候通过new关键字来创建对象。那么当类A中依赖类B的对象，而类B中又依赖类C的对象，最后类C中又依赖类A的对象的时候，这种情况最终的依赖关系会形成一个环，这就是循环依赖。

![img](https://pics6.baidu.com/feed/43a7d933c895d143ac933f48bd05ac0558af07f4.png?token=b973634407a6311bdf5e4652e64f32de)

> **循环依赖的类型**

根据注入的时机可以分为两种：

- **构造器循环依赖** 依赖的对象是通过**构造方法**传入的，在实例化bean的时候发生。

  构造器循环依赖，本质上是**无解**的，实例化A的时候调用A的构造器，发现依赖了B，又去实例化B，然后调用B的构造器，发现又依赖于C，然后调用C的构造器去实例化，结果发起C的构造器里依赖了A，这就是个死循环无解。Spring是不支持构造器循环依赖的，当发现存在构造器循环依赖时，会直接抛出BeanCurrentlyInCreationException 异常；

- **赋值属性循环依赖** 依赖的对象是通过**setter**方法传入，对象已经实例化，在属性赋值和依赖注入的时候发生。Spring通过对还在创建过程中的单例bean，**进行缓存并提前暴露该单例**，使得其他实例可以提前引用到该单例bean。

  **Spring只支持bean在单例模式下的循环依赖**，其他模式下的循环依赖Spring也是会抛出BeanCurrentlyInCreationException 异常的。

# 4. 设计模式

> 设计模式中的开闭原则 – 对扩展开放，对修改关闭

## 4.1 DI(Dependecy Inject,依赖注入)

- IoC(Inversion of Control,控制反转)是一种解耦的设计思想
- DI(Dependecy Inject,依赖注入)是实现控制反转的一种设计模式，依赖注入就是将实例变量传入到一个对象中去

## 4.2 **工厂设计模式**

- `BeanFactory` ：延迟注入(使用到某个 bean 的时候才会注入),相比于`ApplicationContext` 来说会占用更少的内存，程序启动速度更快。
- `ApplicationContext` ：容器启动的时候，不管你用没用到，一次性创建所有 bean 。

## 4.3 **单例设计模式**

**3.1 好处**：

- 对于频繁使用的对象，可以省略创建对象所花费的时间；

- 由于 new 操作的次数减少，因而对系统内存的使用频率也会降低。

**3.2 Spring 实现单例的方式：**

```java
xml : <bean id="userService" class="top.snailclimb.UserService" scope="singleton"/>
注解：@Scope(value = "singleton")
```

## 4.4 代理设计模式

- AOP(Aspect-Oriented Programming:面向切面编程)能够将那些与业务无关，却被业务模块所共同调用的逻辑或责任（例如事务处理、日志管理、权限控制等）封装起来便于系统的重复代码**，**降低模块间的耦合度，并有利于未来的可拓展性和可维护性。
- Spring AOP 就是基于动态代理的，如果要代理的对象，实现了某个接口，那么Spring AOP会使用**JDK Proxy**，去创建代理对象，而对于没有实现接口的对象，就无法使用 JDK Proxy 去进行代理了，这时候Spring AOP会使用**Cglib** ，这时候Spring AOP会使用 **Cglib** 生成一个被代理对象的子类来作为代理

## 4.5 模板方法

模板方法是一种行为设计模式，它定义一个操作中算法的骨架，而将一些步骤延迟到子类中，模板模式使得子类可以在不改变算法结构的情况下重新定义该算法的某些特定步骤的实现。

## 4.6 观察者模式

观察者模式表示的对象和对象之间的依赖关系，当一个对象发生变化，其所依赖的对象也应该发生变化，spring的事件驱动模型是观察者模式的典型应用，可以解耦我们的代码。比如用户添加商品之后，列表索引需要更新，可以利用观察者模式解决。

**spring的事件驱动模型三个角色**

- 事件角色   ApplicationEvent
- 事件监听者角色  ApplicationListener
- 事件发布者角色  ApplicationEventPublisher

## 4.7 适配器模式

适配器模式(Adapter Pattern) 将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作，其别名为包装器(Wrapper)。
