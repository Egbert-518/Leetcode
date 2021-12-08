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
                    // ����ظ�, ����ظ�����һ���ַ���ʼ�͵�ǰ�ַ�����µ�vector
                    max_num = non_repeatQueue.size() > max_num ? non_repeatQueue.size() : max_num;
                    non_repeatQueue.erase(non_repeatQueue.begin(), non_repeatQueue.begin() + i + 1);   // erase()�ܹ��Ѵ�[begin, end)�Ĳ���ȥ��, ���Һ���Ԫ���±�仯, +1����Ϊ)
                    break;
                }
            }
            non_repeatQueue.emplace_back(ch);
        }
        max_num = non_repeatQueue.size() > max_num ? non_repeatQueue.size() : max_num;  // ���ȫ����ͬ, �򲻻��if, ��ʱ����Ҫ��max_num��һ��ֵ
        return max_num;
    }
};
