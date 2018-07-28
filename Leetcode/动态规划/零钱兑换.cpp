#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int res = 0;
		sort(coins.begin(), coins.end());

		res = coinCore(coins, amount);

		return res;
	}

	int coinCore(vector<int>& coins, int last) {
		if (last == 0) {
			return 0;
		}
		else if (last<0) {
			return INT_MIN;
		}

		int lastV = INT_MIN;
		for (int i = coins.size() - 1; i >= 0; i--) {
			int currV = coinCore(coins, last - coins[i]) + 1;
			if (lastV<0 || (currV >= 0 && currV<lastV)) {
				lastV = currV;
			}
		}

		return  lastV>0 ? lastV : -1;

	}
};
int main(int argc, char* argv[])
{
	vector<int> vec = {2,5};
	Solution s;
	cout << s.coinChange(vec, 3) << endl;
	system("pause");
	return 0;
}
