#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, d;
	while(cin >> n >> d) {
		vector<int> dist;
		string ans = "S";
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			dist.push_back(x);
		}
		for(int i = 1; i < n; ++i) {
			if(dist[i] - dist[i - 1] > d) ans = "N";
		}
		if(42195 - dist[n - 1] > d) ans = "N";
		cout << ans << endl;
	}
	return 0;
}