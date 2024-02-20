/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
    输入：n = 4
    输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
    输入：n = 1
    输出：[["Q"]]

1 <= n <= 9
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
    vector<vector<string>> solveNQueens(int n) {
        path.clear();
        results.clear();
        vector<bool> free_pos(n, true);
        backtracking(n, free_pos);
        return results;
    }

    void backtracking(int n, vector<bool>& free_pos) {
        // 首先每行放一个, 就通过层数来判断, 每列也只能放一个, 通过free_pos来判断, 此外在每层放置时, 要根据前面已经防止的来生成当前层可放置的位置
        if (path.size() == n) {
            vector<string> result;
            for (int i = 0; i < n; i++)
            {
                string str;
                for (int j = 0; j < n; j++)
                {
                    if (path[i] == j) {
                        str = str + "Q";
                    }
                    else {
                        str = str + ".";
                    }
                }
                result.emplace_back(str);
            }
            results.emplace_back(result);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (!free_pos[j]) {
                continue;
            }
            // 判断该pos是否在已填充元素的斜角上
            bool is_free = true;
            for (int i = 0; i < path.size(); i++)
            {
                // i表示已填皇后在第i行, path[i]表示已填皇后在第i行第path[i]列, path.size()表示现在要填的行数
                if (path[i] + path.size() - i == j || path[i] - path.size() + i == j) {
                    is_free = false;
                    break;
                }
            }
            if (is_free) {
                path.emplace_back(j);
                free_pos[j] = false;
                backtracking(n, free_pos);
                free_pos[j] = true;
                path.pop_back();
            }
        }
    }

private:
    vector<int> path;
    vector<vector<string>> results;
};


int main()
{
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(4);
    for (vector<string> result : results)
    {
        for (string str : result)
        {
            std::cout << str << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
* 运行时间13ms, 击败24.35％ c++用户
* 消耗内存11.41M, 击败15.59% c++用户
*/
