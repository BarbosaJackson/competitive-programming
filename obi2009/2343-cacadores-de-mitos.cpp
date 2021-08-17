#include <bits/stdc++.h>
using namespace std;

int main() {
	map<pair<int, int>, int> rain;
	bool can = false;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pair<int, int> ii = {x, y};
		if(!rain[ii]) rain[ii] = 0;
		rain[ii]++;
		if(rain[ii] > 1) {
			can = true;
		}
	}	
	cout << (can ? 1 : 0) << endl;
	return 0;
}