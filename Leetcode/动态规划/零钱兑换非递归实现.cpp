
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int res = 0;
		sort(coins.begin(), coins.end());

		res = coinCore(coins, 0, coins.size() - 1, amount);
		



		return res;
	}

	int coinCore(vector<int>& coins, int ahead,int behind, int amount) {
		if (ahead == behind ) {
			if (coins[ahead] == amount) {
				return 1;
			}else{
				return INT_MIN;
			}
		}
		else if (ahead > behind) {
			return INT_MIN;
		}
		int temp = 0;
		if (coins[ahead] + coins[behind] < amount) {
			temp= coinCore(coins, ahead + 1, behind,amount-coins[ahead])+1;
		}
		else if (coins[ahead] + coins[behind] == amount) {
			temp = 2;
		}
		else
		{
			temp = coinCore(coins, ahead, behind-1, amount-coins[behind]);
		}

		int temp2 = coinCore(coins, ahead, behind - 1, amount);
		if (temp > 0 && temp2 > 0) {
			return temp > temp2 ? temp2 : temp;
		
		}
		else {
			if (temp < 0 && temp2 < 0) {
				return -1;
			}
			else {
				if (temp > 0) {
					return temp;
				}
				else {
					return temp2;
				}
			}
		}
		return temp;
 
	}
};
int main(int argc, char* argv[])
{
	vector<int> vec = { 1,2,5 };
	Solution s;
	cout << s.coinChange(vec, 11) << endl;
	system("pause");
	return 0;
}

