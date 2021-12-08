#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<char> non_repeatQueue;
        int max_num = 0;
        for (auto ch : s)
        {
            for (int i = 0; i < non_repeatQueue.size(); i++)
            {
                if (non_repeatQueue[i] == ch)
                {
                    // 如果重复, 则从重复的下一个字符开始和当前字符组成新的vector
                    max_num = non_repeatQueue.size() > max_num ? non_repeatQueue.size() : max_num;
                    non_repeatQueue.erase(non_repeatQueue.begin(), non_repeatQueue.begin() + i + 1);   // erase()能够把从[begin, end)的部分去除, 并且后续元素下标变化, +1是因为)
                    break;
                }
            }
            non_repeatQueue.emplace_back(ch);
        }
        max_num = non_repeatQueue.size() > max_num ? non_repeatQueue.size() : max_num;  // 如果全不相同, 则不会进if, 这时候还需要对max_num赋一次值
        return max_num;
    }
};
