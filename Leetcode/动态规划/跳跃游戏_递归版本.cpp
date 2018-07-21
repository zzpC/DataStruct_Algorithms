#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums){
		return funCore(nums,0,nums.size()-1);
	}
	bool funCore(vector<int>& nums,int no,int last){
		if(last<=0){
			return true;
		}
		bool flag=false;
		for(int i=1;i<=nums[no];i++){
			flag=flag||funCore(nums,no+i,last-i);
		}
		return flag;
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
		cout << "开始测试:  ";
		cout << s.canJump(v) << endl << endl;
	}
	return 0;
}
