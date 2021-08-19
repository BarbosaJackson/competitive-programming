#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while(cin >> n) {
		int qnt, best_sum = 1e6, pos_sum = -1;
		for(int i = 0; i < n; i++) {
			vector<int> h;
			cin >> qnt;
			for(int k = 0;  k < qnt; k++) {
				int x;
				cin >> x;
				h.push_back(x);
			}
			int sum = 0;
			for(int k = 0; k < qnt - 1; k++){
				int s = h[k + 1] - h[k];
				sum += (s > 0 ? s : 0);
			}
			if(best_sum > sum) {
				best_sum = sum;
				pos_sum = i + 1;
			}
			sum = 0;
			for(int k = qnt - 1; k > 0; k--) {
				int s = h[k - 1] - h[k];
				sum += (s > 0 ? s : 0);
			}
			if(best_sum > sum) {
				best_sum = sum;
				pos_sum = i + 1;
			}
		}
		cout << pos_sum << endl;
	}	
	return 0;
}