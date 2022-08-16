# Java解析多层嵌套的JSON

# 1. com.google.code.gson

## 1.1 引入依赖

```xml
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.8.0</version>
</dependency>
```

## 1.2 测试代码

- 创建JSON解析器    JsonParser parse = new JsonParser();
- 将String转成jsonObject  JsonParser .parse(json).getAsJsonObject();
- JsonObject.get("").getAsInt();
- JsonObject.get("").getAsString();
- JsonObject.get("").getAsJsonArray();

```java
public static void gsonTest(String json){

    //创建JSON解析器
    JsonParser parse = new JsonParser();

    //将String转成jsonObject
    JsonObject jsonObject = parse.parse(json).getAsJsonObject();

    //error
    int error = jsonObject.get("error").getAsInt();
    System.out.println("error: " + error);

    //status
    String status = jsonObject.get("status").getAsString();
    System.out.println("status: " + status);

    //results
    JsonArray results = jsonObject.get("results").getAsJsonArray();
    for (int i = 0; i < results.size(); i++){
        JsonObject jsonObject1 = results.get(i).getAsJsonObject();

        //currentCity
        String currentCity = jsonObject1.get("currentCity").getAsString();
        System.out.println("currentCity" + "-" + i + ": " + currentCity);

        //index
        JsonArray indexes = jsonObject1.get("index").getAsJsonArray();
        for (int j = 0; j < indexes.size(); j++){
            JsonObject jsonObject2 = indexes.get(j).getAsJsonObject();

            //title
            String title = jsonObject2.get("title").getAsString();
            System.out.println("title" + "-" + (j + 1) + ": " + title);

            //zs
            String zs = jsonObject2.get("zs").getAsString();
            System.out.println("zs" + "-" + (j + 1) + ": " + zs);

        }
    }
}
/*
error: 0
status: success
currentCity-0: bj
title-1: 穿衣
zs-1: 较冷
title-2: 紫外线强度
zs-2: 中等
*/
```

# 2. net.sf.json.JSONObject

## 2.1 引入依赖

- maven依赖如下

```xml
<dependency>
    <groupId>net.sf.json-lib</groupId>
    <artifactId>json-lib</artifactId>
    <version>2.4</version>
    <classifier>jdk15</classifier>// jdk8也适用
</dependency>
```

## 2.2 JSONArray

>List 转 JSONArray

```java
public static void main(String[] args) {
    ArrayList<Stu> list = new ArrayList<>();
    list.add(new Stu(2020,"张三"));
    list.add(new Stu(2021,"李四"));
    list.add(new Stu(2022,"王五"));
    JSONArray jSONArray = JSONArray.fromObject(list);
    System.out.println(list);
    System.out.println(jSONArray);

}
/*
[Stu(no=2020, name=张三), Stu(no=2021, name=李四), Stu(no=2022, name=王五)]      //list
[{"name":"张三","no":2020},{"name":"李四","no":2021},{"name":"王五","no":2022}]  //jSONArray
*/
```

## 2.3 测试代码

```java
public static void jSONObjectTest(String json){

    JSONObject jsonObject = JSONObject.fromObject(json);

    //error
    int error = jsonObject.getInt("error");
    System.out.println("error: " + error);

    //status
    String status = jsonObject.getString("status");
    System.out.println("status: " + status);

    //results
    JSONArray results = jsonObject.getJSONArray("results");
    for (int i = 0; i < results.size(); i++) {

        //currentCity
        String currentCity = results.getJSONObject(i).getString("currentCity");
        System.out.println("currentCity: " + currentCity);
        //index
        JSONArray indexes = results.getJSONObject(i).getJSONArray("index");
        for (int j = 0; j < indexes.size(); j++) {

            //title
            String title = indexes.getJSONObject(j).getString("title");
            System.out.println("title" + "-" + (j + 1) + ": " + title);

            //zs
            String zs = indexes.getJSONObject(j).getString("zs");
            System.out.println("zs" + "-" + (j + 1) + ": " + zs);
        }
    }
}
/*
error: 0
status: success 
currentCity: bj
title-1: 穿衣
zs-1: 较冷
title-2: 紫外线强度
zs-2: 中等
*/
```

# 3. 测试 json 

```java
String json = "{\n" +
    "    \"error\": 0,\n" +
    "    \"status\": \"success\",\n" +
    "    \"results\": [\n" +
    "        {\n" +
    "            \"currentCity\": \"bj\",\n" +
    "            \"index\": [\n" +
    "                {\n" +
    "                    \"title\": \"穿衣\",\n" +
    "                    \"zs\": \"较冷\",\n" +
    "                    \"tipt\": \"穿衣指数\",\n" +
    "                    \"des\": \"建议着厚外套加毛衣等服装。\"\n" +
    "                },\n" +
    "                {\n" +
    "                    \"title\": \"紫外线强度\",\n" +
    "                    \"zs\": \"中等\",\n" +
    "                    \"tipt\": \"紫外线强度指数\",\n" +
    "                    \"des\": \"属中等强度紫外线辐射天气。\"\n" +
    "                }\n" +
    "            ]\n" +
    "\n" +
    "        }\n" +
    "    ]\n" +
    "}\n";
```