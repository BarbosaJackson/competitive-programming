#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		double max = -1;
		int pos;
		for(int i = 0; i < n; i++) {
			double d, c;
			cin >> d >> c;
			double res = c * log(d);
			if(max <= res) {
				max = res;
				pos = i;
			}
		}
		cout << pos << endl;
	}
	return 0;
}