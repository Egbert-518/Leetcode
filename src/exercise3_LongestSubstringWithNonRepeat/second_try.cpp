/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。


示例1:
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例2:
    输入: s = "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例3:
    输入: s = "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
        请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成
*/


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        
        unordered_map<char, int> map;
        int max_length = 1;
        int front = 0;
        map[s[front]] = 1;

        for (int back = 1; back < s.length(); back++)
        {
            if (map[s[back]] == 0) {
                map[s[back]] = 1;
                if (back - front + 1 > max_length) {
                    max_length = back - front + 1;
                }
            }
            else {
                bool tag = false;
                for (; front < back; front++)
                {
                    if (tag) {
                        break;
                    }
                    if (s[front] == s[back]) {
                        tag = true;
                    }
                    map[s[front]]--;
                }
                map[s[back]] = 1;
            }
        }

        return max_length;
    }
};


int main()
{   
    Solution solution;
    int result = solution.lengthOfLongestSubstring("pwwkew");
    std::cout << result << std::endl;
    return 0;
} 

/*
* 执行时间12ms, 击败75.17%c++用户
* 内存消耗10.99M, 击败59.56%c++用户
*/