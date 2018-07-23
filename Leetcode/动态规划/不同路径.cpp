#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m,int n){
		//m+1行,n+1列
		vector<vector<int>> vec(m+1,vector<int>(n+1,0));
		vec[1][1]=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				//往下走
				vec[i][j]+=vec[i-1][j];
				//往右走
				vec[i][j]+=vec[i][j-1];
			}
		}
		return vec[m][n];
	}
};

int main(){
	Solution s;
	cout << s.uniquePaths(1,1) << endl
		<< s.uniquePaths(2,2) << endl
		<< s.uniquePaths(2,3) << endl
		<< s.uniquePaths(7,3) << endl
		<< s.uniquePaths(3,7) << endl;
	return 0;
}
