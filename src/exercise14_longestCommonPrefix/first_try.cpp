/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

*/

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


bool compare(string s1, string s2) {
    return s1.size() < s2.size();
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        sort(strs.begin(), strs.end(), compare);   // 自定义大小比较函数, 按长度从小到大排序, 公共前缀必不可能超过最短string的长度
        string curPrefix = CommonPrefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) {
            curPrefix = CommonPrefix(strs[i], curPrefix);
            if (curPrefix == "") {
                return curPrefix;
            }      
        }
        return curPrefix;
    }

    string CommonPrefix(string s1, string s2) {
        int size = min(s1.size(), s2.size());
        string s = "";
        for (int i = 0; i < size; i++) {
            if (s1[i] == s2[i]) {
                s = s + s1[i];
            }
            else {
                return s;
            }
        }
        return s;
    }
};

/*
* 执行用时：16 ms, 在所有 C++ 提交中击败了5.78%的用户
* 内存消耗：18.6MB, 在所有 C++ 提交中击败了5.01%的用户
* 通过测试用例：123 / 123
*/
