

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        /*思想是令两个指针分别指向s的头和尾, 交换它们的值, 这样只需要额外的o(1)空间即可*/
        int left = 0, right = s.size() - 1;
        while (left <= right)    // 左右指针相同是有意义的, 这样是指向同一个值
        {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

