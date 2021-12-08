#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i == j)
					continue;
				else {
					if (nums.at(i) + nums.at(j) == target) {
						result.emplace_back(i);
						result.emplace_back(j);
						return result;
					}
				}
			}
		}
		return result;
	}
};
