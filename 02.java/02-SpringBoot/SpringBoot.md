- - 





# SpringBoot

>介绍

- 为什么要使用 Spring Boot？
  - 因为Spring和SpringMVC 需要使用大量的配置文件以及配置各种对象，把使用的对象放入到spring容器中才能使用对象；
  - 集成其他框架时需要了解该框架的配置规则；
  - 而SpringBoot 就相当于不需要配置文件的Spring+SpringMVC，拥有很多常用框架的**起步依赖**。

# 1. JavaConfig

>介绍

- JavaConfig: 使用java类作为xml配置文件的替代， 是配置spring容器的纯java的方式；
- 在config类中可以创建java对象，把对象放入spring容器中；
- 常用注解
  - @Configuration ： 放在一个类的上面，表示这个类是作为配置文件使用的；
  - @Bean：声明对象，把对象注入到容器中。

```java
/**
 * Configuration:表示当前类是作为配置文件使用的，用来配置容器
 *       		 位置：在类的上面
 *
 * SpringConfig.java 就相当于beans.xml
 */
@Configuration
public class SpringConfig {

    /**
     * 创建方法，方法的返回值是对象。 在方法的上面加入@Bean
     * 方法的返回值对象就注入到容器中。
     *
     * @Bean: 把对象注入到spring容器中。 作用相当于<bean>
     *
     *     位置：方法的上面
     *
     *     说明：@Bean,不指定对象的名称，默认是方法名是 id
     *
     */
    @Bean
    public Student createStudent(){
        Student s1  = new Student();
        s1.setName("张三");
        s1.setAge(26);
        s1.setSex("男");
        return s1;
    }


    /***
     * 指定对象在容器中的名称（指定<bean>的id属性）
     * @Bean的name属性，指定对象的名称（id）
     */
    @Bean(name = "lisiStudent")
    public Student makeStudent(){
        Student s2  = new Student();
        s2.setName("李四");
        s2.setAge(22);
        s2.setSex("男");
        return s2;
    }
}

```

# 2. Spring Boot

## 2.1 介绍

- SpringBoot是Spring中的一个成员， 可以简化Spring，SpringMVC的使用， 核心是IOC容器；


- Embed Tomcat, Jetty or Undertow directly (no need to deploy WAR files)

  内嵌的tomcat， jetty ， Undertow ；

- Provide opinionated 'starter' dependencies to simplify your build configuration

  提供了starter起步依赖，简化应用的配置；

  - 比如使用MyBatis框架 ， 在Spring项目中，需要配置MyBatis的对象 SqlSessionFactory 、Dao的代理对象；


  - 在SpringBoot项目中，在pom.xml里面，加入一个 mybatis-spring-boot-starter依赖；

- Automatically configure Spring and 3rd party libraries whenever possible

  - 自动配置即尽可能去配置spring和第三方库

  - SpringBoot把spring中的第三方库中的对象都创建好，放到容器中， 开发人员可以直接使用）

- Provide production-ready features such as metrics, health checks, and externalized configuration

   提供了健康检查， 统计，外部化配置

- Absolutely no code generation and no requirement for XML configuration

  不用生成代码， 无需xml配置

## 2.2 创建项目

- https://start.spring.io
- https://start.springboot.io
- 直接创建maven项目引入springboot依赖即可

## 2.3 配置文件

- 配置文件名称： application
- 扩展名包括  properties(k=v) ;  yml (<font color=#FF0033>k: v</font>)   <font color=#FF0033>k 冒号+空格 v</font>

- 例1：application.properties设置 端口和上下文


```xml
#设置端口号
server.port=8082
#设置访问应用上下文路径， contextpath
server.servlet.context-path=/myboot
```

- 例2： application.yml


```yaml
server:
  port: 8083
  servlet:
    context-path: /myboot2
```

## 2.4 多环境配置

- 开发环境  application-dev.properties(  application-dev.yml )

- 测试环境  application-test.properties
- 生产环境  application-pre.properties

## 2.5 容器Context

- ConfigurableApplicationContext是ApplicationContext的子接口；

```java
public interface ConfigurableApplicationContext extends ApplicationContext
```

- 调用SpringApplication.run(Application.class, args); 语句获得ConfigurableApplicationContext对象；

```java
public static ConfigurableApplicationContext run(Class<?> primarySource, String... args) {
        return run(new Class[]{primarySource}, args);
}
```

- 获得的ConfigurableApplicationContext对象即为容器，可在该容器中获得某个对象。

## 2.6 ComnandLineRunner & ApplcationRunner

- 均存在run()方法，执行时间在容器对象创建好后**自动执行run()**方法；
- 可以自动完成在容器对象创建好的一些操作

```java
@FunctionalInterface
public interface CommandLineRunner {
    void run(String... args) throws Exception;
}

@FunctionalInterface
public interface ApplicationRunner {
    void run(ApplicationArguments args) throws Exception;
}

```

# 3. 注解

## 3.1 创建对象

- @Controller  **控制层对象**，放在类的上面，创建控制器对象，注入到容器中；
- @RestController **控制层对象** ，@Controller + @ResponseBody，控制器方法的返回值都是数据；

- @Service **业务层对象**，放在业务层的实现类上面，创建service对象，注入到容器；
- @Repository  **持久层对象**，放在dao层的实现类上面，创建dao对象，放入到容器；
- @Component   **普通对象(和分层无关)**，放在类的上面，**创建**此类的对象，放入到容器中。 

## 3.2 引用类型注入

- @Value  简单类型的赋值

  - 在属性的上面使用

  ```java
  @Value("李四") 
  private String name
  ```

  - 获取配置文件者的数据

  ```java
  @Value("${server.port}")
  private Integer port
  ```

- @Autowired   引用类型赋值自动注入的

  - Spring框架提供；

  - 支持byName, byType，默认是byType；
  - 放在属性的上面，也可以放在构造方法的上面。

- @Qualifer   引用类型赋值，使用byName方式。   

  - Spring框架提供。

- @Resource   引用类型的自动注入
  - 来自jdk中的定义， javax.annotation；
  - 支持byName, byType；
  - 默认是byName, 如果byName失败， 再使用byType注入；
  - 在属性上面使用。

## 3.3 springboot注解

### 3.3.1 @SpringBootApplication

>介绍

- 是一个复合注解，由下面三个组成

  - @SpringBootConfiguration
  - @EnableAutoConfiguration
  - @ComponentScan
- 作用

  - 将启动类当作配置文件处理(@SpringBootConfiguration)
  - 借助@Import的帮助，将所有符合自动配置条件的bean定义加载到IoC容器(@EnableAutoConfiguration)
  - 扫描并加载符合条件的组件，创建对象，装配到ioc容器中(@ComponentScan)

### 3.3.2 @SpringBootConfiguration

- 底层是@Configuration

```java
@Configuration
public @interface SpringBootConfiguration {
    @AliasFor(
        annotation = Configuration.class
    )
    boolean proxyBeanMethods() default true;
}
```

### 3.3.3 @EnableAutoConfiguration

- 启用自动配置， 把java对象配置好，注入到spring容器中。例如可以把mybatis的对象创建好，放入到容器中

### 3.3.4 @ComponentScan

- @ComponentScan 扫描器，找到注解，根据注解的功能创建对象，给属性赋值等等；
- 该注解**默认扫描**的包是@ComponentScan所在的类所在的包和子包。

## 3.4 MyBatis注解

- @Mapper  放在类的上面 ， 让MyBatis找到接口， 创建他的代理对象；
- @MapperScan   放在主类的上面 ， 指定扫描的包， 把这个包中的所有接口都创建代理对象，对象注入到容器中；
- @Param  放在dao接口的方法的形参前面， 作为命名参数使用的。

## 3.5 Dubbo注解

- @DubboService: 在提供者端使用的，暴露服务的， 放在接口的实现类上面
- @DubboReference:  在消费者端使用的， 引用远程服务， 放在属性上面使用。
- @EnableDubbo : 放在主类上面， 表示当前引用启用Dubbo功能。

## 3.6 @ConfigurationProperties

- @ConfigurationProperties: 把配置文件的数据映射为java对象；

- SchoolInfo.java中的name、website、address分别映射至配置文件中的

  school.name、school.website、school.address

- SchoolInfo.java如下

```java
@Component
@ConfigurationProperties(prefix = "school")
public class SchoolInfo {

    private String name;

    private String website;

    private String address;
}

```

- application.properties


```properties
#自定义key=value
school.name=动力节点
school.website=www.bjpowernode.com
school.address=北京的大兴区
```

## 3.7 其他

- @Configuration
  - 放在类的上面，表示这是个配置类，相当于xml配置文件

- @Bean
  - 放在方法的上面， 把方法的返回值对象，注入到spring容器中
- @Transcational
  - 处理事务的， 放在service实现类的public方法上面， 表示此方法有事务
- @ComponentScan
  - 扫描器 ，指定包名，扫描注解的
- @ResponseBody
  - 放在方法的上面，表示方法的返回值是数据， 不是视图
- @RequestBody 
  - 把请求体中的数据，读取出来， 转为java对象使用。

- @ControllerAdvice(和@ExceptionHandler连用)

  - 控制器增强；

  - 放在类的上面， 表示此类提供了方法，可以对controller增强功能。

- @ExceptionHandler(和@ControllerAdvice连用)

  - 处理异常，放在方法的上面；

- @ImportResource
  - 加载其他的xml配置文件， 把文件中的对象注入到spring容器中；

```java
@Configuration
@ImportResource(value ={ "classpath:applicationContext.xml","classpath:beans.xml"})
public class SpringConfig {
}
===============================等价于==================================
<import resources="其他配置文件"/>
```

- @PropertySource
  - 读取properties属性配置文件;
  - 使用 @Value(value="${key}")获取。

```java
@Configuration
@ImportResource(value ={ "classpath:applicationContext.xml","classpath:beans.xml"})
@PropertySource(value = "classpath:config.properties")
@ComponentScan(basePackages = "com.bjpowernode.vo")
public class SpringConfig {
}
```

# 4. Web组件

- 拦截器， Servlet ，Filter


## 4.1 拦截器

>介绍

- 拦截器是SpringMVC中一种对象，能拦截对Controller的请求；
- 拦截器框架中有系统的拦截器， 还可以自定义拦截器， 实现对请求预先处理。

>实现自定义拦截器

- 创建类实现SpringMVC框架的HandlerInterceptor接口


```java
public interface HandlerInterceptor {
 default boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
     return true;
 }

 default void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, @Nullable ModelAndView modelAndView) throws Exception {
 }

 default void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, @Nullable Exception ex) throws Exception {
 }
}
```

- 需在SpringMVC的配置文件中，声明拦截器


```xml
<mvc:interceptors>
	<mvc:interceptor>
    	<mvc:path="url" />
        <bean class="拦截器类全限定名称"/>
    </mvc:interceptor>
</mvc:interceptors>
```

- SpringBoot中注册拦截器：


```java

@Configuration
public class MyAppConfig implements WebMvcConfigurer {

    //添加拦截器对象， 注入到容器中
    @Override
    public void addInterceptors(InterceptorRegistry registry) {

        //创建拦截器对象
        HandlerInterceptor interceptor = new LoginInterceptor();

        //指定拦截的请求uri地址
        String path []= {"/user/**"};
        //指定不拦截的地址
        String excludePath  [] = {"/user/login"};
        registry.addInterceptor(interceptor)
                .addPathPatterns(path)
                .excludePathPatterns(excludePath);

    }
}
```

## 4.2  Servlet

>Servlet使用步骤

- 创建Servlet类。 创建类继承HttpServlet；
- 注册Servlet ，让框架能找到Servlet；

>测试

- 创建自定义Servlet


```java
//创建Servlet类
public class MyServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req,resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       //使用HttpServletResponse输出数据，应答结果
        resp.setContentType("text/html;charset=utf-8");
        PrintWriter out  = resp.getWriter();
        out.println("===执行的是Servlet==");
        out.flush();
        out.close();

    }
}
```

- 注册Servlet

```java
@Configuration
public class WebApplictionConfig {

    //定义方法， 注册Servlet对象
    @Bean
    public ServletRegistrationBean servletRegistrationBean(){

        //public ServletRegistrationBean(T servlet, String... urlMappings)
        //第一个参数是 Servlet对象， 第二个是url地址

        //ServletRegistrationBean bean =
                //new ServletRegistrationBean( new MyServlet(),"/myservlet");


        ServletRegistrationBean bean = new ServletRegistrationBean();
        bean.setServlet( new MyServlet());
        bean.addUrlMappings("/login","/test"); // <url-pattern>


        return bean;
    }
}
```

## 4.3 过滤器Filter

>介绍

- Filter是Servlet规范中的过滤器，可以处理请求， 对请求的参数， 属性进行调整，常常在过滤器中处理字符编码；
- 创建自定义过滤器类
- 注册Filter过滤器对象

>测试

- 自定义过滤器

```java
// 自定义过滤器
public class MyFilter implements Filter {
    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("执行了MyFilter，doFilter ");
        filterChain.doFilter(servletRequest,servletResponse);
    }
}
```

- 注册Filter


```java
@Configuration
public class WebApplicationConfig {

    @Bean
    public FilterRegistrationBean filterRegistrationBean(){
        FilterRegistrationBean bean  = new FilterRegistrationBean();
        bean.setFilter( new MyFilter());
        bean.addUrlPatterns("/user/*");
        return bean;
    }
}
```

## 4.4 字符集过滤器

>介绍

- CharacterEncodingFilter : 解决post请求中乱码的问题

>使用方式一

- 配置字符集过滤器


```java
@Configuration
public class WebSystemConfig {

    //注册Servlet
    @Bean
    public ServletRegistrationBean servletRegistrationBean(){
        MyServlet myServlet = new MyServlet();
        ServletRegistrationBean reg = new ServletRegistrationBean(myServlet,"/myservlet");
        return reg;
    }


    //注册Filter
    @Bean
    public FilterRegistrationBean filterRegistrationBean(){
        FilterRegistrationBean reg = new FilterRegistrationBean();

        //使用框架中的过滤器类
        CharacterEncodingFilter filter  = new CharacterEncodingFilter();
        //指定使用的编码方式
        filter.setEncoding("utf-8");
        //指定request ， response都使用encoding的值
        filter.setForceEncoding(true);

        reg.setFilter(filter);
        //指定 过滤的url地址
        reg.addUrlPatterns("/*");

        return reg;
    }
}
```

- 修改application.properties文件， 让自定义的过滤器起作用

```properties
#SpringBoot中默认已经配置了CharacterEncodingFilter。 编码默认ISO-8859-1
#设置enabled=false 作用是关闭系统中配置好的过滤器， 使用自定义的CharacterEncodingFilter
server.servlet.encoding.enabled=false
```

> 使用方式二

- 修改application.properties文件


```properties
server.port=9001
server.servlet.context-path=/myboot

#让系统的CharacterEncdoingFilter生效
server.servlet.encoding.enabled=true
#指定使用的编码方式
server.servlet.encoding.charset=utf-8
#强制request，response都使用charset属性的值
server.servlet.encoding.force=true
```

# 5. MyBatis

## 5.1 引入依赖

- mybatis起步依赖 ： 完成mybatis对象自动配置， 对象放在容器中；
- 在pom.xml 指定  将src/main/java目录中的**xml文件**包含到classpath中；

<font color=F0033>以下代码是将java目录的下任意子目录的所有.xml文件输出到target的classpath中</font>

```xml
<build>
    <!--加入 resource 插件-->
    <resources>
        <resource>
            <directory>src/main/java</directory>
            <includes>
                <include>**/*.xml</include>
            </includes>
        </resource>
    </resources>
</build>
```

## 5.2 标识dao

> @Mapper

- @Mapper：放在dao接口的上面， 每个接口都需要使用这个注解。


```java
/**
 * @Mapper：告诉MyBatis这是dao接口，创建此接口的代理对象。
 *     位置：在类的上面
 */
@Mapper
public interface StudentDao {

    Student selectById(@Param("stuId") Integer id);
}
```

>@MapperScan

```java
/**
 * @MapperScan: 找到Dao接口和Mapper文件
 *     basePackages：Dao接口所在的包名
 */
@SpringBootApplication
@MapperScan(basePackages = {"com.bjpowernode.dao","com.bjpowernode.mapper"})
public class Application {
}
```

> Mapper文件和Dao接口分开管理

- Mapper文件放在resources目录下；


- 在resources目录中创建子目录，例如mapper；
- 将XxxMapper文件放到 mapper目录中；
- 在application.properties文件中，指定mapper文件的目录

```properties
#指定mapper文件的位置
mybatis.mapper-locations=classpath:mapper/*.xml
#指定mybatis的日志
mybatis.configuration.log-impl=org.apache.ibatis.logging.stdout.StdOutImpl
```

- 在pom.xml中指定 把resources目录中的文件 ， 编译到目标目录中

```xml
<!--resources插件-->
<resources>
   <resource>
      <directory>src/main/resources</directory>
      <includes>
         <include>**/*.*</include>
      </includes>
   </resource>
</resources>
```

## 5.3 流程

1. 创建实体类Student

2. 创建Dao接口 StudentDao , 创建一个查询学生的方法 

3. 创建Dao接口对应的Mapper文件， xml文件， 写sql语句

4. 创建Service层对象， 创建StudentService接口和他的实现类。 去dao对象的方法。完成数据库的操作

5. 创建Controller对象，访问Service。

6. application.properties文件  配置数据库的连接信息。


## 5.4 事务

>介绍

- 管理事务的对象： 事务管理器（接口， 接口有很多的实现类）


​      例如：使用Jdbc或mybatis访问数据库，使用的事务管理器：DataSourceTransactionManager

- 声明式事务：在**xml**配置文件或者使用**注解**说明事务控制的内容


​      控制事务： 隔离级别，传播行为， 超时时间

- 事务处理方式：
  - Spring框架中的@Transactional
  - aspectj框架可以在xml配置文件中，声明事务控制的内容

>SpringBoot中使用事务

- 在**业务方法**的上面加入@Transactional ,  加入注解后，**方法有事务功能**了。
- 明确的在 主启动类的上面 ，加入**@EnableTransactionManager**

>测试

- 事务的提交
- 事务的回滚

```java
/**
 * @Transactional: 表示方法的有事务支持
 *       默认：使用库的隔离级别， REQUIRED 传播行为； 超时时间  -1
 *       抛出运行时异常，回滚事务
 */
@Transactional
@Override
public int addStudent(Student student) {
    System.out.println("业务方法addStudent");
    int rows  =  studentDao.insert(student);
    System.out.println("执行sql语句");

    //抛出一个运行时异常， 目的是回滚事务
    //int m   = 10 / 0 ;

    return rows;
}
```

# 6. RESTful

## 6.1 介绍

- REST(英文： Representational State Transfer , 中文： 表现层状态转移)
- REST：是一种接口的架构风格和设计的理念，不是标准，更简洁，更有层次

## 6.2 注解

- @PathVariable :  从url中获取数据
- @GetMapping:    支持的get请求方式，  等同于 @RequestMapping( method=RequestMethod.GET)
- @PostMapping:  支持post请求方式 ，等同于 @RequestMapping( method=RequestMethod.POST)
- @PutMapping:  支持put请求方式，  等同于 @RequestMapping( method=RequestMethod.PUT)
- @DeleteMapping: 支持delete请求方式，  等同于 @RequestMapping( method=RequestMethod.DELETE)
- @RestController
  - 复合注解， 是@Controller + @ResponseBody组合；
  - 在类的上面使用@RestController ， 表示当前类者的所有方法都加入了 @ResponseBody

### 6.3 put、delete

- 过滤器org.springframework.web.filter.HiddenHttpMethodFilter，把请求中的post请求转为 put 、delete；
- 实现步骤
  - application.properties(yml) : 开启使用 HiddenHttpMethodFilter 过滤器；
  - 在请求页面中，包含 _method参数， 值为 put或delete，以post方式发送该请求；

```html
<form action="student/test" method="post">
    <input type="hidden" name="_method" value="delete">
    <input type="submit" value="测试put">
</form>
```

# 7. Redis

## 7.1 介绍

- 工作原理
  - 先去redis中查找数据，若有则直接返回；
  - 若没有则去db中查询，查询到的值返回用户并写入redis；
- Redis是一个NoSQL数据库，  常用作缓存使用
- Redis的数据类型： string  ,  hash  ,set  ,zset , list
- Redis是一个中间件： 是一个独立的服务器。
- java中客户端： Jedis ，  lettuce ， Redisson
- Spring,SpringBoot中 **RedisTemplate(tringRedisTemplate)**处理和redis的交互  

## 7.2  依赖

- RedisTemplate 使用  lettuce 客户端库
- 在程序中使用RedisTemplate类的方法操作redis数据， 实际就是调用的lettuce 客户端的中的方法

```xml
<!--redis起步依赖： 直接在项目中使用RedisTemplate(StringRedisTemplate)-->
<dependency>
   <groupId>org.springframework.boot</groupId>
   <artifactId>spring-boot-starter-data-redis</artifactId>
</dependency>
```

## 7.3 StringRedisTemplate & RedisTemplate

>介绍

- StringRedisTemplate ： 把k，v 都是作为String处理， 使用的是String的序列化 ， 可读性好
- RedisTemplate ： 把k，v 经过了序列化存到redis。 k，v 是序列化的内容， 不能直接识别.

​                                		 默认使用的jdk序列化， 可以修改为前提的序列化

>为什么需要序列化

序列化最终的目的是为了对象可以跨平台存储，和进行网络传输。而我们进行跨平台存储和网络传输的方式就是IO，而我们的IO支持的数据格式就是字节数组。我们必须在把对象转成字节数组的时候就制定一种规则（序列化），那么我们从IO流里面读出数据的时候再以这种规则把对象还原回来（反序列化）。

> 什么情况下需要序列化

通过上面我想你已经知道了凡是需要进行“跨平台存储”和”网络传输”的数据，都需要进行序列化。

本质上存储和网络传输 都需要经过 把一个对象状态保存成一种跨平台识别的字节格式，然后其他的平台才可以通过字节信息解析还原对象信息。

> 序列化的方式

- 序列化只是一种拆装组装对象的规则，常见的序列化方式有：
  - JDK、JSON、XML、Thrift、Protofbuff、Hessian、Kryo（不支持跨语言)

- java的序列化： 把java对象转为byte[], 二进制数据
- json序列化：json序列化功能将对象转换为 JSON 格式或从 JSON 格式转换对象

> 设置key或者value的序列化方式

```java
// 使用RedisTemplate ，在存取值之前，设置序列化
// 设置 key 使用String的序列化
redisTemplate.setKeySerializer( new StringRedisSerializer());

// 设置 value 的序列化
redisTemplate.setValueSerializer( new StringRedisSerializer());

redisTemplate.opsForValue().set(k,v);
```

# 8. SpringBoot集成Dubbo

 https://github.com/apache/dubbo-spring-boot-project/blob/master/README_CN.md

## 8.1  公共项目

- 独立的maven项目： 定义了接口和数据类


```java
public class Student implements Serializable {
    private static final long serialVersionUID = 1901229007746699151L;

    private Integer id;
    private String name;
    private Integer age;
}

public interface StudentService {

    Student queryStudent(Integer id);
}

```

## 8.2  提供者 provider

- pom.xml


```xml
<dependencies>

   <!--加入公共项目的gav-->
   <dependency>
      <groupId>com.bjpowernode</groupId>
      <artifactId>022-interface-api</artifactId>
      <version>1.0.0</version>
   </dependency>

   <!--dubbo依赖-->
   <dependency>
      <groupId>org.apache.dubbo</groupId>
      <artifactId>dubbo-spring-boot-starter</artifactId>
      <version>2.7.8</version>
   </dependency>


   <!--zookeeper依赖-->
   <dependency>
      <groupId>org.apache.dubbo</groupId>
      <artifactId>dubbo-dependencies-zookeeper</artifactId>
      <version>2.7.8</version>
      <type>pom</type>
      <exclusions>
         <!-- 排除log4j依赖 -->
         <exclusion>
            <artifactId>slf4j-log4j12</artifactId>
            <groupId>org.slf4j</groupId>
         </exclusion>
      </exclusions>
   </dependency>
</dependencies>
```

- 实现接口

```java
/**
 * 使用dubbo中的注解暴露服务
 * @Component 可以不用加
 */
@DubboService(interfaceClass = StudentService.class,version = "1.0",timeout = 5000)
public class StudentServiceImpl implements StudentService {
    @Override
    public Student queryStudent(Integer id) {
        Student student  = new Student();
        if( 1001 == id){
            student.setId(1001);
            student.setName("------1001-张三");
            student.setAge(20);
        } else if(1002  == id){
            student.setId(1002);
            student.setName("#######1002-李四");
            student.setAge(22);
        }

        return student;
    }
}
```

- application.properties


```properties
#配置服务名称 dubbo:application name="名称"
spring.application.name=studentservice-provider

#配置扫描的包， 扫描的@DubboService
dubbo.scan.base-packages=com.bjpowernode.service

#配置dubbo协议
#dubbo.protocol.name=dubbo
#dubbo.protocol.port=20881

#注册中心
dubbo.registry.address=zookeeper://localhost:2181
```

- 启动类  添加@EnableDubbo


```java
@SpringBootApplication
@EnableDubbo
public class ProviderApplication {

   public static void main(String[] args) {
      SpringApplication.run(ProviderApplication.class, args);
   }
}
```

## 8.3 消费者 consumer

- pom.xml   【同提供者 provider】

- 创建Controller 或者 Service

```java
@RestController
public class DubboController {

    /**
     * 引用远程服务， 把创建好的代理对象，注入给studentService
     */
    //@DubboReference(interfaceClass = StudentService.class,version = "1.0")

    /**
     * 没有使用interfaceClass，默认的就是 引用类型的 数据类型
      */
    @DubboReference(version = "1.0")
    private StudentService studentService;

    @GetMapping("/query")
    public String queryStudent(Integer id){
        Student student   = studentService.queryStudent(id);
        return "调用远程接口，获取对象："+student;
    }
}
```

- application.properties


```properties
#指定服务名称
spring.application.name=consumer-application
#指定注册中心
dubbo.registry.address=zookeeper://localhost:2181
```

# 9.Thymeleaf 模板引擎

>介绍

- 是使用java开发的模板技术， 在服务器端运行。 把处理后的数据发送给浏览器；
- 模板是作视图层工作的，用于显示数据的；
- Thymeleaf是基于Html语言，Thymleaf语法是应用在html标签中；
- SpringBoot框架集成Thymealeaf,  使用Thymeleaf代替jsp。
- Thymeleaf 的官方网站：http://www.thymeleaf.org
- Thymeleaf 官方手册：https://www.thymeleaf.org/doc/tutorials/3.0/usingthymeleaf.html

## 9.1 表达式

1. 标准变量表达式 

   语法：  ${key} 

   作用： 获取key对于的文本数据，  key 是request作用域中的key ， 使用request.setAttribute(), model.addAttribute()

   在页面中的 html标签中， 使用 th:text="${key}" 

```html
<div style="margin-left: 400px">
    <h3>标准变量表达式:  ${key}</h3>
    <p th:text="${site}">key不存在</p>
    <br/>
    <p>获取SysUser对象 属性值</p>
    <p th:text="${myuser.id}">id</p>
    <p th:text="${myuser.name}">姓名</p>
    <p th:text="${myuser.sex}">姓名：m男</p>
    <p th:text="${myuser.age}">年龄</p>
    <p th:text="${myuser.getName()}">获取姓名使用getXXX</p>
</div>
```

2. 选择变量表达式（ 星号变量表达式）

   语法：  *{key}

   作用： 获取这个key对应的数据，   *{key}需要和th:object 这个属性一起使用。

   目的是简单获取对象的属性值。

   ```html
   <p>使用 *{} 获取SysUser的属性值</p>
   <div th:object="${myuser}">
       <p th:text="*{id}"></p>
       <p th:text="*{name}"></p>
       <p th:text="*{sex}"></p>
       <p th:text="*{age}"></p>
   
   </div>
   <p>使用*{}完成的表示 对象的属性值</p>
   <p th:text="*{myuser.name}" ></p>
   ```

3. 链接表达式

   语法： @{url}

   作用： 表示链接， 可以

   ```html
    <script src="..."> , <link href="..."> <a href=".."> ,<form action="..."> <img src="...">
   ```


## 9.2  Thymeleaf属性

- 属性是放在html元素中的，就是html元素的属性，加入了th前缀。  属性的作用不变。
- 加入上th， 属性的值由模板引擎处理了， 在属性可以使用变量表达式。

```xml
<form action="/loginServlet" method="post"></form>

<form th:action="/loginServlet" th:method="${methodAttr}"></form>
```

## 9.3 each

- each循环， 可以循环List，Array
- 在一个html标签中，使用th:each
- 集合循环成员,循环的状态变量:两个名称都是自定义的。 “循环的状态变量”这个名称可以不定义，默认是"集合循环成员Stat"

```xml
<div th:each="集合循环成员,循环的状态变量:${key}">
    <p th:text="${集合循环成员}" ></p>
</div>
```

- each循环Map
- 在一个html标签中，使用th:each
- 集合循环成员,循环的状态变量:两个名称都是自定义的。 “循环的状态变量”这个名称可以不定义，默认是"集合循环成员Stat"

```html
<div th:each="集合循环成员,循环的状态变量:${key}">
    <p th:text="${集合循环成员.key}" ></p>
    <p th:text="${集合循环成员.value}" ></p>
</div>
key:map集合中的key
value：map集合key对应的value值
```

## 9.4 th:if

- "th:if"  : 判断语句， 当条件为true， 显示html标签体内， 反之不显示 没有else语句


```xml
<div th:if=" 10 > 0 "> 显示文本内容 </div>
```

-  th:unless  和 th:if相反的行为


```xml
<div th:unless=" 10 < 0 "> 当条件为false显示标签体内容 </div>
```

- if


```xml
<div style="margin-left: 400px">
        <h3> if 使用</h3>
        <p th:if="${sex=='m'}">性别是男</p>
        <p th:if="${isLogin}">已经登录系统</p>
        <p th:if="${age > 20}">年龄大于20</p>
        <!--""空字符是true-->
        <p th:if="${name}">name是“”</p>
        <!--null是false-->
        <p th:if="${isOld}"> isOld是null</p>
 </div>

```

- unless


```html
 <div style="margin-left: 400px">
        <h3>unless: 判断条件为false，显示标签体内容</h3>
        <p th:unless="${sex=='f'}">性别是男的</p>
        <p th:unless="${isLogin}">登录系统</p>
        <p th:unless="${isOld}"> isOld是null </p>
 </div>
```

## 9.5  th:switch

- th:switch 和 java中的swith一样的


```html
<div th:switch="要比对的值">
    <p th:case="值1">
        结果1
    </p>
    <p th:case="值2">
        结果2
    </p>
    <p th:case="*">
        默认结果
    </p>
    以上的case只有一个语句执行
</div>
```

## 9.6 th:inline

- 内联text：  在html标签外，获取表达式的值


```xml
<p>显示姓名是：[[${key}]]</p>

<div style="margin-left: 400px">
    <h3>内联 text, 使用内联表达式显示变量的值</h3>
    <div th:inline="text">
        <p>我是[[${name}]]，年龄是[[${age}]]</p>
        我是<span th:text="${name}"></span>,年龄是<span th:text="${age}"></span>
    </div>

    <div>
        <p>使用内联text</p>
        <p>我是[[${name}]],性别是[[${sex}]]</p>
    </div>
</div>
```

- 内联javascript

```html
<script type="text/javascript" th:inline="javascript">
    var myname = [[${name}]];
    var myage = [[${age}]];

    //alert("获取的模板中数据 "+ myname + ","+myage)

    function fun(){
        alert("单击事件，获取数据 "+ myname + ","+ [[${sex}]])
    }
</script>
```

## 9.7  字面量

- 例如


```html
 <div style="margin-left: 400px">
       <h3>文本字面量: 使用单引号括起来的字符串</h3>
       <p th:text="'我是'+${name}+',我所在的城市'+${city}">数据显示</p>

       <h3>数字字面量</h3>
        <p th:if="${20>5}"> 20大于 5</p>

        <h3>boolean字面量</h3>
        <p th:if="${isLogin == true}">用户已经登录系统</p>

        <h3>null字面量</h3>
        <p th:if="${myuser != null}">有myuser数据</p>
    </div>
```

## 9.8  字符串连接

连接字符串有两种语法

- 单引号括起来字符串 ，使用 + 连接其他的 字符串或者表达式

```html
<p th:text="'我是'+${name}+',我所在的城市'+${city}">数据显示</p>
```

- 使用双竖线， |字符串和表达式|


```html
<p th:text="|我是${name},我所在城市${city|">
    显示数据
</p>
```

- 


```html
<div style="margin-left: 400px">
    <h3>字符串连接方式1：使用单引号括起来的字符串</h3>
    <p th:text="'我是'+${name}+',我所在的城市'+${city}">数据显示</p>
    <br/>
    <br/>
    <h3>字符串连接方式2：|字符串和表达式|</h3>
    <p th:text="|我是${name},所在城市${city},其他人${myuser.name}|"></p>
</div>
```

## 9.9 运算符

- 算术运算： + , - - , * , / , %
- 关系比较 : > , < , >= , <= ( gt , lt , ge , le )
- 相等判断： == , != ( eq , ne )
- 三元运算符：
   表达式  ？ true的结果 : false的结果

```xml
<div style="margin-left: 400px">
        <h3>使用运算符</h3>
        <p th:text="${age > 10}">年龄大于 10 </p>
        <p th:text="${ 20 + 30 }">显示运算结果</p>
        <p th:if="${myuser == null}">myuser是null</p>
        <p th:if="${myuser eq null}">myuser是null</p>
        <p th:if="${myuser ne null}">myuser不是null</p>

        <p th:text="${isLogin == true ? '用户已经登录' : '用户需要登录'}"></p>
        <p th:text="${isLogin == true ? ( age > 10 ? '用户是大于10的' : '用户年龄比较小') : '用户需要登录'}"></p>

    </div>
```

## 9.10 内置对象

- [文档地址](https://www.thymeleaf.org/doc/tutorials/3.0/usingthymeleaf.html#web-context-namespaces-for-requestsession-attributes-etc)
- #request 表示 HttpServletRequest、#session 表示 HttpSession对象；
- session 表示Map对象的， 是#session的简单表示方式， 用来获取session中指定的key的值

```java
#session.getAttribute("loginname") == session.loginname
```

- 测试如下

```html
<div style="margin-left: 350px">
    <h3>内置对象#request,#session，session的使用</h3>
    <p>获取作用域中的数据</p>
    <p th:text="${#request.getAttribute('requestData')}"></p>
    <p th:text="${#session.getAttribute('sessionData')}"></p>
    <p th:text="${session.loginname}"></p>

    <br/>
    <br/>
    <h3>使用内置对象的方法</h3>
    getRequestURL=<span th:text="${#request.getRequestURL()}"></span><br/>
    getRequestURI=<span th:text="${#request.getRequestURI()}"></span><br/>
    getQueryString=<span th:text="${#request.getQueryString()}"></span><br/>
    getContextPath=<span th:text="${#request.getContextPath()}"></span><br/>
    getServerName=<span th:text="${#request.getServerName()}"></span><br/>
    getServerPort=<span th:text="${#request.getServerPort()}"></span><br/>
</div>
```

##  9.11 内置工具类

- #dates: 处理日器的工具类
- #numbers:处理数字
- #lists: 处理list集合

```xml
<div style="margin-left: 350px">
    <h3>日期类对象 #dates</h3>
    <p th:text="${#dates.format(mydate )}"></p>
    <p th:text="${#dates.format(mydate,'yyyy-MM-dd')}"></p>
    <p th:text="${#dates.format(mydate,'yyyy-MM-dd HH:mm:ss')}"></p>
    <p th:text="${#dates.year(mydate)}"></p>
    <p th:text="${#dates.month(mydate)}"></p>
    <p th:text="${#dates.monthName(mydate)}"></p>
    <p th:text="${#dates.createNow()}"></p>
    <br/>

    <h3>内置工具类#numbers，操作数字的</h3>
    <p th:text="${#numbers.formatCurrency(mynum)}"></p>
    <p th:text="${#numbers.formatDecimal(mynum,5,2)}"></p>

    <br/>
    <h3>内置工具类#strings,操作字符串</h3>
    <p th:text="${#strings.toUpperCase(mystr)}"></p>
    <p th:text="${#strings.indexOf(mystr,'power')}"></p>
    <p th:text="${#strings.substring(mystr,2,5)}"></p>
    <p th:text="${#strings.substring(mystr,2)}"></p>
    <p th:text="${#strings.concat(mystr,'---java开发的黄埔军校---')}"></p>
    <p th:text="${#strings.length(mystr)}"></p>
    <p th:text="${#strings.length('hello')}"></p>
    <p th:unless="${#strings.isEmpty(mystr)}"> mystring 不是 空字符串  </p>

    <br/>
    <h3>内置工具类#lists,操作list集合</h3>
    <p th:text="${#lists.size(mylist)}"></p>
    <p th:if="${#lists.contains(mylist,'a')}">有成员a</p>
    <p th:if="!${#lists.isEmpty(mylist)}"> list 集合有多个成员</p>

    <br/>
    <h3>处理null</h3>
    <p th:text="${zoo?.dog?.name}"></p>

</div>
```

## 9.12 自定义模板

- 模板定义语法

  th:fragment="模板自定义名称"

```html
<div th:fragment="head">
    <p>
        动力节点-java开发
    </p>
    <p>
        www.bjpowernode.com
    </p>
</div>
```

- 引用模板语法：


```html
1) ~{templatename :: selector}
   templatename:  文件名称
   selector： 自定义模板名称
2）templatename :: selector
   templatename:  文件名称
   selector： 自定义模板名称
对于使用模板：有包含模板（th:include）， 插入模板(th:insert)
```

# 10.打包

## 10.1 打包war

- 创建了一个jsp应用
- 修改pom.xml

```xml
<!--打包类型-->
<packaging>war</packaging>
<build>
    <!--打包后的文件名称-->
    <finalName>myboot</finalName>
    <!--resources插件， 把jsp编译到指定的目录-->
    <resources>
        <resource>
            <directory>src/main/webapp</directory>
            <targetPath>META-INF/resources</targetPath>
            <includes>
                <include>**/*.*</include>
            </includes>
        </resource>

        <!--使用了mybatis ，而且mapper文件放在src/main/java目录-->
        <resource>
            <directory>src/main/java</directory>
            <includes>
                <include>**/*.xml</include>
            </includes>
        </resource>

        <!--把src/main/resources下面的所有文件，都包含到classes目录-->
        <resource>
            <directory>src/main/resources</directory>
            <includes>
                <include>**/*.*</include>
            </includes>
        </resource>
    </resources>
</build>
```

- 主启动类继承SpringBootServletInitializer


```java
/**
 * SpringBootServletInitializer: 继承这个类， 才能使用独立tomcat服务器
 */
@SpringBootApplication
public class JspApplication  extends SpringBootServletInitializer  {

   public static void main(String[] args) {
      SpringApplication.run(JspApplication.class, args);
   }

   @Override
   protected SpringApplicationBuilder configure(SpringApplicationBuilder builder) {
      return builder.sources(JspApplication.class);
   }
}
```

- 部署war

  - 把war放到tomcat等服务器的发布目录中；

  - tomcat为例， myboot.war放到tomcat/webapps目录。

## 10.2 打包为jar

- 修改pom.xml；

```xml
<build>
    <!--打包后的文件名称-->
    <finalName>myboot</finalName>
    <!--指定springboot-maven-plugin版本-->
    <plugins>
        <plugin>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-maven-plugin</artifactId>
            <!--打包jar， 有jsp文件时，必须指定maven-plugin插件的版本是 1.4.2.RELEASE-->
            <version>1.4.2.RELEASE</version>
        </plugin>
    </plugins>
</build>
```

- 在target目录中，生成jar 文件， 例子是myboot.jar；
- java  -jar  myboot.jar 即可运行该项目。

