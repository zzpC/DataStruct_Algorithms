class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()){
		return 0;
	}
	int a=0;
	for(int i=1;i<=nums.size();i++){
		n+=i;
	}
	int b=0;
	for(int i=0;i<nums.size();i++){
		b+=nums[i];
	}
	return a-b;
    }
};
