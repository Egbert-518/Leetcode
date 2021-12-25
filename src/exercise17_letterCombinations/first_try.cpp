/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。

*/

// 没看题解先运行了一遍标答, 似乎输出长度与输入长度相同, 即如果输入为"234", 不需要考虑"23"的组合, 此外"abcd"与"bacd"是不同的
// 本来以为至少要考虑子串, 以及重复的应该不考虑, 看来想复杂了
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> map_ = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        bool first_emplace = true; 

        for (int i = 0; i < digits.size(); i++) {
            string cur_s = map_.find(digits[i])->second;
            if (first_emplace) {
                first_emplace = false;
                for (auto s : cur_s) {
                    string ss(1, s);  // s是char型, 不能直接构造
                    results.emplace_back(ss);
                }
            }
            else {
                calculate(results, cur_s);
            }
        }
        return results;
    }

    void calculate(vector<string>& results, string cur_s) {
        vector<string> tmps = results;
        results.clear();
        results.reserve(results.size() * cur_s.size());   // 提前分配空间
        for (auto tmp : tmps) {
            for (auto s : cur_s) {
                results.emplace_back(tmp + s);
            }
        }
    }
};

int main() {
    Solution solution;
    string s = "23";
    vector<string> results = solution.letterCombinations(s);
    for (auto result : results) {
        cout << result << endl;
    }
    return 0;
}

/*
* 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
* 内存消耗：6.3MB, 在所有 C++ 提交中击败了79.95%的用户
* 通过测试用例：25 / 25
*/
