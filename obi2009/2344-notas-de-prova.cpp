#include <bits/stdc++.h>
using namespace std;
int main() {
	int nota;
	while(cin >> nota) {
		char let = 'A';
		if(nota == 0) let = 'E';
		else if(nota <= 35) let = 'D';
		else if(nota <= 60) let = 'C';
		else if(nota <= 85) let = 'B';
		cout << let << endl;
	}	
	return 0;
}