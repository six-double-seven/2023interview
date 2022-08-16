package utils;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import okhttp3.Call;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import org.junit.Test;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.Base64;

public class GitUtils {

    /**
     * @param accessToken 用户授权码
     * @param owner 用户名
     * @param repo  仓库名称
     * @param path  文件路径【以反斜杠 / 开头】
     * @param ref   分支(默认是仓库的默认分支)
     * @return
     * @throws Exception
     */
    public static String readFile(String accessToken, String owner, String repo, String path, String ref) throws Exception {

        String gitUrl = "https://gitee.com/api/v5/repos/";
        StringBuffer url = new StringBuffer(gitUrl);
        url.append(owner)
                .append("/")
                .append(repo)
                .append("/contents")
                .append(path);
        if (accessToken != null)
            url.append("access_token=")
                    .append(accessToken);
        if (ref != null)
            url.append("&ref=")
                    .append(ref);
        Request request = new Request.Builder()
                .url(url.toString())
                .build();

        String resStr = null;
        try {
            OkHttpClient client = new OkHttpClient
                    .Builder()
                    .build();

            Call call = client.newCall(request);
            Response response = call.execute();
            resStr = response.body().string();

        } catch (IOException e) {
            e.printStackTrace();
        }
        //数据格式转换: Base64转String
        return convertData(resStr);
    }

    private static String convertData(String resStr) {

        JSONObject jsonObject = JSON.parseObject(resStr);
        byte[] content = null;
        try {
            //1. Base64转byte[]
            content = Base64.getDecoder().decode(jsonObject.getString("content"));
        } catch (Exception e) {
            System.out.println(">> response is " + resStr);
        }
        String contentStr = null;
        if (content != null) {
            try {
                //2. byte[]转String
                contentStr = new String(content, "UTF-8");
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
        }
        return contentStr;
    }
    @Test
    public void getWeiChen() throws Exception {
        String s = GitUtils.readFile(null, "six-double-seven", "blog", "/tools/GitUtil/微尘.md", null);
        System.out.println(s);
    }
}
