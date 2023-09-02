/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

1 <= n <= 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<string> total_str;

        if (n == 0) {
            string str_num_0 = "";
            total_str.emplace_back(str_num_0);
            return total_str;
        }

        // 考虑使用递归, 每一层为上i层与n-i-1层的组合, "(" + p + ")" + q
        while (n != 1) {
            for (int i = 0; i <= n - 1; i++) {
                std::vector<string> strings_p = this->generateParenthesis(i);
                std::vector<string> strings_q = this->generateParenthesis(n - i - 1);

                for (auto str_p : strings_p) {
                    for (auto str_q : strings_q) {
                        string str = "(" + str_p + ")" + str_q;
                        total_str.emplace_back(str);
                    }
                }
            }

            return total_str;
        }

        string str_num_1 = "()";  // 到第一层, 返回
        total_str.emplace_back(str_num_1);
        return total_str; 
    }
    
};


int main() {
    Solution solution;
    std::vector<std::string> parenthesis = solution.generateParenthesis(3);
    for (int i = 0; i < parenthesis.size(); i++) {
        std::cout << parenthesis[i] << std::endl;
    }
    return 0;
}


/*
* 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
* 内存消耗：10.92MB, 在所有 C++ 提交中击败了70.94%的用户
*/

