// RotateRectangle.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#pragma once
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();

		for (int i = 0; i<N / 2; i++) {
			for (int j = 0 + i; j < N - 1 - i; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[N - j - 1][i];
				matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
				matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
				matrix[j][N - i - 1] = temp;
			}
		}
	}

};

// TODO: 在此处引用程序需要的其他标头。
