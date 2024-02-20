/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
    输入：s = "aab"
    输出：[["a","a","b"],["aa","b"]]

示例 2：
    输入：s = "a"
    输出：[["a"]]

1 <= s.length <= 16
s 仅由小写英文字母组成
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        results.clear();
        path.clear();
        backtracking(s);
        return results;
    }

    void backtracking(string s) {
        /*切割问题也是可以用回溯来做的, 将s按照不同位置切割*/
        if (s.length() < 1) {
            // 终止条件
            results.emplace_back(path);
            return;
        }

        for (int i = 1; i <= s.length(); i++)
        {
            // 至少从将第一个字符切分出来
            string before_seg = s.substr(0, i);
            if (isReverse(before_seg)) {
                path.emplace_back(before_seg);
                string after_seg = s.substr(i, s.length() - i);
                backtracking(after_seg);
                path.pop_back();
            }
        }

    }

    bool isReverse(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string>> results;   // 放所有回文结果
    vector<string> path;   // 放回文结果
};


int main()
{
    Solution solution;
    string s = "aab";
    vector<vector<string>> results = solution.partition(s);
    for (vector<string> result : results)
    {
        for (string str : result)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
* 运行时间114ms, 击败70.80% c++用户
* 消耗内存77.29M, 击败45.83% c++用户
*/
