/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

示例 1：
    输入：s = "25525511135"
    输出：["255.255.11.135","255.255.111.35"]

示例 2：
    输入：s = "0000"
    输出：["0.0.0.0"]

示例 3：
    输入：s = "101023"
    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

1 <= s.length <= 20
s 仅由数字组成
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        /*这也是一个分割问题, 在同一集合内考虑用startIndex, 这样能有效避免substr传参, 注意到每次分割需要判断是否有效, 终止条件是path的size为4且startIndex应等于s的size*/
        path.clear();
        results.clear();
        backtracking(s, 0);
        return results;
    }

    void backtracking(string& s, int startIndex) {
        // 终止条件
        if (path.size() == 4) {
            // 当封装的字符已经为有效IP位数时
            if (startIndex == s.size()) {
                string str = path[0];
                for (int i = 1; i < 4; i++) {
                    str = str + ".";
                    str = str + path[i];
                }
                results.emplace_back(str);
                return;
            }
            else {
                return;
            }
        }

        for (int i = startIndex; i < s.length(); i++)
        {
            string before_str = s.substr(startIndex, i - startIndex + 1);   // 起始位置, 长度
            if (before_str.length() > 1 && before_str[0] == '0') {
                // 前导0的去除
                continue;
            }

            int before_num = atoi(before_str.c_str());
            if (before_num >= 0 && before_num <= 255) {
                path.emplace_back(before_str);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

private:
    vector<string> path;
    vector<string> results;
};


int main()
{
    Solution solution;
    string s = "101023";
    vector<string> results = solution.restoreIpAddresses(s);
    for (string result : results)
    {
        std::cout << result << std::endl;
    }
    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存10.05M, 击败9.90% c++用户
*/
