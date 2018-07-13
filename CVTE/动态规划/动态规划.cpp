#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int minPrice(vector<vector<int>> prices) {
		if (prices.empty()) {
			return 0;
		}
		

		int a0, a1, m0, m1;
		a0 = INT_MAX;
		a1 = INT_MAX;
		m0 = m1 = -1;
		for (int i = 0; i < prices[0].size(); i++) {
			if (prices[0][i] < a0) {
				if (a0 != a1) {
					a1 = a0;
					m1 = m0;
				}
				a0 = prices[0][i];
				m0 = i;
			}
			else if (prices[0][i] < a1) {
				a1 = prices[0][i];
				m1 = i;
			}
		}

		if (prices.size() >= 2) {
			int b0, b1, n0, n1;
			b0 = INT_MAX;
			b1 = INT_MAX;
			n0 = n1 = -1;
			for (int i = 1; i < prices.size(); i++) {
				b0 = INT_MAX;
				b1 = INT_MAX;
				n0 = n1 = -1;
				for (int j = 0; j < prices[0].size(); j++) {
					if (prices[i][j] < b0) {
						if (b0 != b1) {
							b1 = b0;
							n1 = n0;
						}
						b0 = prices[i][j];
						n0 = j;
					}else if (prices[i][j] < b1) {
						b1= prices[i][j];
						n1 = j;
					}
				}
				if (m0 != n0) {
					int temp = a1 + b1;
					a0 = a0 + b0;
					a1 = temp;
					m0 = n0;
					m1 = n1;
					
				}
				else {
					if (a0 + b1 < a1 + b0) {
						int temp = a1 + b0;
						a0 = a0 + b1;
						m0 = n1;
						m1 = n0;
						a1 = temp;

					}
					else {
						int temp = a0+b1;
						a0 = a1 + b0;
						m0 = n0;
						m1 = n1;
						a1 = temp;
					}
				}
			}
		}
		return a0;
	};

};

int main()
{
	Solution s;	
	vector<vector<int>> vec0;
	vector<vector<int>> vec1 = { {1,2,3},{4,5,6},{100,3,800},{1000,1,1000} };
	vector<vector<int>> vec2 = { { 10,1,9 },{ 9,12,3 } };
	vector<vector<int>> vec3 = { { 10,1,9 } };
	vector<vector<int>> vec4 = { { 10,1,9 },{ 9,2,3 },{5,6,6} };

	cout << s.minPrice(vec0) << endl;
	cout << s.minPrice(vec1) << endl;
	cout << s.minPrice(vec2) << endl;
	cout << s.minPrice(vec3) << endl;
	cout << s.minPrice(vec4) << endl;

	system("pause");
	return 0;
}

