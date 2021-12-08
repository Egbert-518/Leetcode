#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> hash_map;   // ����hash��, ����Ч�ʸ���
		std::vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = hash_map.find(target - nums.at(i));   // ��hash���в�����û�е�ǰ��Ԫ��ֵ��Ӧ��target - itemֵ, ����, ������Ԫ�غ��ҵ�Ԫ�ص��±귵��
			if (it != hash_map.end())
			{
				result.emplace_back(i);
				result.emplace_back(it->second);
				return result;
			}
			hash_map[nums[i]] = i;
		}
		return result;
	}
};
