#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> cont;
	int n, k;	
	cin >> n >> k;
	cont.assign(k + 1, 0);
	int min_k = 1e6;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cont[x]++;
	}
	for(int i = 1; i <= k; i++) min_k = min(min_k, cont[i]);
	cout << min_k << endl;
	return 0;
}