 /*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (46.22%)
 * Likes:    1271
 * Dislikes: 0
 * Total Accepted:    303K
 * Total Submissions: 655.4K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for ( int j = 0; j < board[0].size(); ++j) {
                if(judge(board,word,i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool judge(vector<vector<char>>& board,string word,int x,int y,int index) {
        if(word.size() == index) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        if(board[x][y] != word[index]) {
            return false;
        }
        char ch = board[x][y];
        board[x][y] = '0';
        bool temp = judge(board, word, x - 1, y, index + 1) || judge(board, word, x + 1, y, index + 1) || judge(board, word, x, y - 1, index + 1) || judge(board, word, x, y + 1, index + 1);
        board[x][y] = ch;
        return temp;
    }
};
// @lc code=end

