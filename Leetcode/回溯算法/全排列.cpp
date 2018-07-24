#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void permuteCore(vector<vector<int>>& res,vector<int>& nums, int k, int m) {
		if (k == m) {
			res.push_back(nums);
		}
		else {
			for (int i = k; i <= m; i++) {
				swap(nums[i], nums[k]);
				permuteCore(res,nums, k + 1, m);
				swap(nums[i], nums[k]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permuteCore(res,nums, 0, nums.size() - 1);
		return res;
	}
};

int main() {
	Solution s;
	vector<int> vec = { 1,2,3 };
	vector<vector<int>> temp = s.permute(vec);
	for (vector<int>& v : temp) {
		for (int& i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
