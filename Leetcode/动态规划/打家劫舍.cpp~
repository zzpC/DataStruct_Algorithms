#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
	int rob(vector<int>& nums){
		if(nums.empty()){
			return 0;
		}
		int preprev,prev,maxi;
		preprev=0;
		maxi=prev=nums[0];
		for(int i=1;i<nums.size();i++){
			maxi=max(preprev+nums[i],maxi);
			preprev=prev;
			prev=maxi;

		}
		return maxi;
	}

};
int main(){
	vector<int>vec0={};
	vector<int>vec1={1};
	vector<int>vec2={1,3,4};
	vector<int>vec3={2,300,3};
	vector<int>vec4={5,6};
	vector<int>vec5={3,388};
	vector<int>vec6={1000,1,2,200};
	vector<int>vec7={8,7,9};
	Solution s;
	cout << s.rob(vec0) << endl;
	cout << s.rob(vec1) << endl;
	cout << s.rob(vec2) << endl;
	cout << s.rob(vec3) << endl;
	cout << s.rob(vec4) << endl;
	cout << s.rob(vec5) << endl;
	cout << s.rob(vec6) << endl;
	cout << s.rob(vec7) << endl;
	return 0;
}
