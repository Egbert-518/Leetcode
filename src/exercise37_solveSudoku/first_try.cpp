/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1：
    输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]


board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
题目数据 保证 输入数独仅有一个解
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        is_finised = false;
        vector<bool> is_used(9, false);
        backtracking(board, 0, is_used);
    }

    void backtracking(vector<vector<char>>& board, int index, vector<bool> is_used) {
        // index存储当前该处理的节点位置, 左上角为0, 行优先, 右下角80, is_used是一个长度为9的向量, 当进入新的一行时会更新, 对当前行还能填写的数字先进行一次总的判断, 省去行的每次遍历
        if (index == 81) {
            // 9x9填满返回
            is_finised = true;
            return;
        }

        int row = index / 9;    // 行
        int col = index % 9;    // 列

        if (col == 0) {
            // 表示新的一行的开始, 要更新is_used数组
            for (int i = 0; i < 9; i++)
            {
                is_used[i] = false;
            }
            for (int i = 0; i < 9; i++)
            {
                if (board[row][i] != '.') {
                    is_used[board[row][i] - '1'] = true;
                }
            }
        }

        // 开始回溯放入数字
        if (board[row][col] != '.') {
            // 如果这个位置已经有数字了
            backtracking(board, index + 1, is_used);
        }
        else {
            // 这个位置没有数字
            for (int i = 0; i < 9; i++)
            {
                if (is_used[i]) {
                    // is_used中存储了该行还能存放的数字, 如果已经被使用, 则跳过
                    continue;
                }
                else {
                    if (isValid(board, row, col, i + 1)) {    // 数字为1-9所以需要+1
                        is_used[i] = true;
                        board[row][col] = i + 1 + '0';
                        backtracking(board, index + 1, is_used);
                        if (is_finised) {    // 结束了直接return, 否则结果不会被保存下来
                            return;
                        }
                        else {
                            board[row][col] = '.';
                            is_used[i] = false;
                        }
                    }
                }
            }
        }
    }

    bool isValid(vector<vector<char>>& board, int row, int col, int value) {
        // 检查在row行col列处值为value是否有效, 因为行通过is_used检查过了, 只需要检查列和九宫格
        for (int i = 0; i < 9; i++) {
            if (board[i][col] - '0' == value) {
                return false;
            }
        }

        // 九宫格左上角点获取
        row = row / 3 * 3;
        col = col / 3 * 3;
        for (int i = row; i < row + 3; i++)
        {
            for (int j = col; j < col + 3; j++)
            {
                if (board[i][j] - '0' == value) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool is_finised;
};


int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'} ,{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}
    };
    solution.solveSudoku(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
* 运行时间42ms, 击败11.42％ c++用户
* 消耗内存15.23M, 击败6.81% c++用户
*/
