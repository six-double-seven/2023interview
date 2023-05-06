/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 *
 * https://leetcode.cn/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (43.83%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    36.4K
 * Total Submissions: 83.2K
 * Testcase Example:  '[197,130,1]'
 *
 * 给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。
 * 
 * UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
 * 
 * 
 * 对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
 * 对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10
 * 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
 * 
 * 
 * 这是 UTF-8 编码的工作方式：
 * 
 * 
 * ⁠     Number of Bytes  |        UTF-8 octet sequence
 * ⁠                      |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠           1          | 0xxxxxxx
 * ⁠           2          | 110xxxxx 10xxxxxx
 * ⁠           3          | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠           4          | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 
 * 
 * x 表示二进制形式的一位，可以是 0 或 1。
 * 
 * 注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：data = [197,130,1]
 * 输出：true
 * 解释：数据表示字节序列:11000101 10000010 00000001。
 * 这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：data = [235,140,4]
 * 输出：false
 * 解释：数据表示 8 位的序列: 11101011 10001100 00000100.
 * 前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
 * 下一个字节是开头为 10 的延续字节，这是正确的。
 * 但第二个延续字节不以 10 开头，所以是不符合规则的。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= data.length <= 2 * 10^4
 * 0 <= data[i] <= 255
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // 前4位中1的个数
        int index = 0;
        int n = data.size();
        while(index  < n) {
            if((data[index] & 0x80) == 0) {
                ++index;
                // 第一位是0
            } else if ((data[index] & 0xe0) == 0xc0 && index + 1 < n && ((data[index + 1] & 0xc0) == 0x80)) {
                index += 2;
                // 110
            } else if ((data[index] & 0xf0)== 0xe0 && index + 2 < n
                    && ((data[index + 1] & 0xc0) == 0x80) && ((data[index + 2] & 0xc0) == 0x80)) {
                index += 3;
            } else if ((data[index] & 0xf8) == 0xf0 && index + 3 < n
            && ((data[index + 1] & 0xc0) == 0x80) && ((data[index + 2] & 0xc0) == 0x80) && ((data[index + 3] & 0xc0) == 0x80)) {
                index += 4;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

