#define INT_MAX       2147483647 
#include <stdio.h>

//行row对应人数
//列col对应颜色编号
//price[行][列]对应价格
int minPrice(int * prices, int row, int col) {
	//A0是上次迭代相应价格的最大值,a0是二维数组的列坐标,
	//A1是上次迭代相应价格的第二大值,a1是二维数组的列坐标
	int A0, A1, a0, a1;
	A0 = INT_MAX;
	A1 = INT_MAX;
	a0 = a1 = -1;
	for (int i = 0; i < col; i++) {
		if (prices[i] < A0) {
			if (A0 != A1) {
				A1 = A0;
				a1 = a0;
			}
			A0 = prices[i];
			a0 = i;
		}
		else if (prices[i] < A1) {
			A1 = prices[i];
			a1 = i;
		}
	}
	//A0和B0是行相邻的衣服价格,颜色(也就是列)可能相邻也可能不相邻
	// 每次迭代把A0,A1改为上次的B0,B1
	// B0,B1的更新分为颜色相邻和颜色不相邻两种情况	
	 	if (row >= 2) {
		int B0, B1, b0, b1;
		B0 = INT_MAX;
		B1 = INT_MAX;
		b0 = b1 = -1;
		for (int i = 1; i < row; i++) {
			B0 = INT_MAX;
			B1 = INT_MAX;
			b0 = b1 = -1;
			for (int j = 0; j < col; j++) {
				if (prices[i*col + j] < B0) {
					if (B0 != B1) {
						B1 = B0;
						b1 = b0;
					}
					B0 = prices[i*col + j];
					b0 = j;
				}
				else if (prices[i*col + j] < B1) {
					B1 = prices[i*col + j];
					b1 = j;
				}
			}
			//相邻行的相邻颜色不同的情况
			if (a0 != b0) {
				int temp = A1 + B1;
				A0 = A0 + B0;
				A1 = temp;
				a0 = b0;
				a1 = b1;

			}
			//相邻行的相邻颜色相同的情况:又分2种情况
			else {
				if (A0 + B1 < A1 + B0) {
					int temp = A1 + B0;
					A0 = A0 + B1;
					a0 = b1;
					a1 = b0;
					A1 = temp;

				}
				else {
					int temp = A0 + B1;
					A0 = A1 + B0;
					a0 = b0;
					a1 = b1;
					A1 = temp;
				}
			}
		}
	}
	return A0;
};




int main()
{
	int  vec1[][3] = { { 1,2,3 },{ 4,5,6 },{ 100,3,800 },{ 1000,1,1000 } };
	int  vec2[2][3] = { { 10,1,9 },{ 9,12,3 } };
	int  vec3[][3] = { { 10,1,9 } };
	int  vec4[][3] = { { 10,1,9 },{ 9,2,3 },{ 5,6,6 } };

	printf("%d\n", minPrice((int *)vec1, 4, 3));
	printf("%d\n", minPrice((int *)vec2, 2, 3));
	printf("%d\n", minPrice((int *)vec3, 1, 3));
	printf("%d\n", minPrice((int *)vec4, 3, 3));


	system("pause");
	return 0;
}

