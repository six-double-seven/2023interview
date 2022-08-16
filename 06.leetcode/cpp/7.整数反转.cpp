/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x)
        {
            if(res>INT_MAX/10 || res<INT_MIN/10) return 0;
            int tmp = x % 10;
            x /= 10;
            res = res*10 + tmp;
        }
        return res;
    }
};
// @lc code=end

