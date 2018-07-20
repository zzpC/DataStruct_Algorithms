#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums){
		if(nums.size()<2){
			return true;
		}
		int target=0;
		for(int i=0;i<nums.size();i++){
			target=target-1>nums[i]?target-1:nums[i];
			if(target<=0){
				return (i == nums.size() - 1) ? true : false;
			}
		}
		return true;
	}
};

int main(){
	Solution s;
	vector<vector<int>> test={{2,3,1,1,4},
		{1},
		{2},
		{5,0},
		{4,1,3},
		{2,3,1,0,1,1,5},
		{2,2,0,0,1,1,5},
		{1,0,5}};

	for(vector<int>& v : test){
		cout << "¿ªÊ¼²âÊÔ:  ";
		cout << s.canJump(v) << endl << endl;
	}
	return 0;
}
