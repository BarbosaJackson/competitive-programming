#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, a, b;
	char op;
	cin >> x >> a >> op >> b;
	cout << ((op == '+' ? a + b : a * b) > x ? "OVERFLOW" : "OK") << endl;
	return 0;
}
