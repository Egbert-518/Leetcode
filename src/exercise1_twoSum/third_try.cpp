/*
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�


ʾ�� 1��
    ���룺nums = [2,7,11,15], target = 9
    �����[0,1]
    ���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 1��
    ���룺nums = [3,2,4], target = 6
    �����[1,2]

ʾ�� 1��
    ���룺nums = [3,3], target = 6
    �����[0,1]

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
ֻ�����һ����Ч��

���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;   // ֵ, �±�
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return { iter->second, i };
            }
            map[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    // Solution solution;

    return 0;
}

/*
* ����ʱ��8ms, ����78.39% c++�û�
* �����ڴ�13.86M, ����13.27% c++�û�
*/
