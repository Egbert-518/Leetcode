/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

示例1:
    输入：s = "egg", t = "add"
    输出：true

示例 2：
    输入：s = "foo", t = "bar"
    输出：false

示例 3：
    输入：s = "paper", t = "title"
    输出：true

1 <= s.length <= 5 * 10^4
t.length == s.length
s 和 t 由任意有效的 ASCII 字符组成
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*因为s和t事任意可能的ASCII字符, 并不是简单的小写字母, 所以空间应该为128*/
        int map_t[128] = { 0 };
        int map_s[128] = { 0 };
        for (int i = 0; i < s.length(); i++)
        {
            if (map_t[t[i]] != 0 && map_t[t[i]] != s[i]) {
                return false;
            }
            if (map_t[t[i]] == 0) {
                map_t[t[i]] = s[i];
            }
            if (map_s[s[i]] != 0 && map_s[s[i]] != t[i]) {
                return false;
            }
            if (map_s[s[i]] == 0) {
                map_s[s[i]] = t[i];
            }
        }
        return true;
    }
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间3ms, 击败96.56% c++用户
* 消耗内存8.08M, 击败40.91% c++用户
*/
