// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if(nums.size()<3){
			return res;
		}
		sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++){
			for(int j=i+1;j<nums.size();j++){
				for(int k=j+1;k<nums.size();k++){
					if(k==i || k==j){
						continue;
					}

					bool flag=false;
					while(nums[i]==nums[k] && nums[j]==nums[k]){
						if(nums[i]==0){
							flag=true;
						}
						if(nums[i]==nums[k] && nums[j]==nums[k]){
							if(k+1<nums.size()){
								++i;
								++j;
								++k;
							}
						}
						
					}
					if(flag){
						vector<int> tempvec={0,0,0};
						res.push_back(tempvec);
					}

					vector<int> tempvec;
					int temp=nums[i]+nums[j];
					if(nums[k]+temp==0){
						if(!res.empty()){
							vector<int> back=res.back();
							if(!back.empty() && nums[i]==back[0] && nums[j]==back[1] && nums[k]==back[2]){
								continue;
							}
						}
						tempvec.push_back(nums[i]);
						tempvec.push_back(nums[j]);
						tempvec.push_back(nums[k]);
						res.push_back(tempvec);
					}else if(nums[k]+temp>0){
						break;
					}
				}
			}
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<int> vec={-1, 0, 1, 2, -1, -4};
	vector<vector<int>> test={{-1, 0, 1, 2, -1, -4},{-2},{-1,-3,-2},{12,5,9},{2,3,-4,-5},{0,0,0,0},{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6}};
	for(vector<int>& v:test){
		cout << "开始测试一组数据: " << endl;
		vector<vector<int>> res=s.threeSum(v);
		if(res.empty()){
			cout << "本次测试结果为空集" << endl << endl;
			continue;
		}
		for(vector<int> v : res){
			cout << "测试开始:" ;
			for(int& i: v){
				cout << i << " ";
			}
			cout << "测试结束" << "######"; 
		}
		cout << "本组数据测试完毕" << endl << endl;
	}
	return 0;
}
