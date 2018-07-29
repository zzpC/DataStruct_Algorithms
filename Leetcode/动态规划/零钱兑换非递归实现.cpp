
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> arr(amount + 1, -1);
		arr[0] = 0;
		for (int& i : coins) {
			if (i <= amount) {
				arr[i] = 1;
			}
		}

		for (int i = 1; i <= amount; i++) {
			//int last = INT_MAX;
			if (arr[i] == 1) {
				continue;
			}
			for (int j = coins.size() - 1; j >= 0; j--) {
				// arr[i-coins[j]]>0 是为了筛选有效数据,不存在的组合值为-1
				if (coins[j] <= i && arr[i-coins[j]]>0) {
					int temp = arr[i - coins[j]] + 1;
					if (arr[i]==-1 || arr[i]>temp) {
						arr[i] = temp;
					}					
				}
			}
		}

		return arr[amount];
	}
};
int main(int argc, char* argv[])
{
	vector<int> vec = { 1,2,5 };
	Solution s;
	cout << s.coinChange(vec, 11) << endl;
	return 0;
}

