#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while(cin >> n >> m) {
		int mat[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
		int sum = 0, max_sum = 0;
		for(int i = 0; i < n; i++){
			sum = 0;
			for(int j = 0; j < m; j++) {
				sum += mat[i][j];
			}
			max_sum = max(max_sum, sum);
		}
		for(int j = 0; j < m; j++) {
			sum = 0;
			for(int i = 0; i < n; i++) {
				sum += mat[i][j];
			}
			max_sum = max(max_sum, sum);
		}
		cout << max_sum << endl;
	}
	return 0;
}