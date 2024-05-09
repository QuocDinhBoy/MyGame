#include <bits/stdc++.h>
using namespace std;
void printMatrix(const int &m,const int &n) {
	int matrix[m][n];
	int top = 0;
	int bottom = m - 1;
	int left = 0;
	int right = n - 1;
	int huong = 0;
	int a = 1;
	while (top <= bottom && left <= right) {
		if (huong == 0) {
			for (int i = left;i <= right;i++) {
				matrix[top][i] = a++;
			}
			top++;
		} else if (huong == 1) {
			for (int i = top;i <= bottom;i++) {
				matrix[i][right] = a++;
			}
			right--;
		} else if (huong == 2) {
			for (int i = right;i >= left;i--) {
			matrix[bottom][i] = a++;
			}
			bottom--;
		} else if (huong == 3) {
			for (int i = bottom;i >= top;i--) {
				matrix[i][left] = a++;
			}
			left++;
		}
		huong = (huong + 1) % 4;
 	}
 	for (int i = 0;i < m;i++) {
 		for (int j = 0;j < n;j++) {
 			cout << matrix[i][j] << " ";
		 }
		 cout << endl;
	 }
}
int main () {
	int m,n;
	cin >> m >> n;
	printMatrix(m,n);
}
