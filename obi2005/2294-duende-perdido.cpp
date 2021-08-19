#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second

int dg[10][10];
int cost[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int min_cont;

bool is_invalid(int x, int y, int lx, int ly) {
	return x < 0 || x >= lx || y < 0 || y >= ly || dg[x][y] == 2;
}

void go(int x, int y, int lx, int ly, int cont) {
	if(is_invalid(x, y, lx, ly)) {
		return;
	}
	if(dg[x][y] == 0) {
		min_cont = min(min_cont, cont);
		return;
	}
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		int aux = dg[x][y];
		dg[x][y] = 2;
		go(xx, yy, lx, ly, cont + 1);
		dg[x][y] = aux;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	while(cin >> n >> m) {
		int x, y;
		min_cont = 1e6;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> dg[i][j];
				cost[i][j] = -1;
				if(dg[i][j] == 3) {
					x = i;
					y = j;
				}
			}
		}
		// go(x, y, n, m, 0);
		queue<pair<int, int>> pq;
		pq.push({x, y});
		cost[x][y] = 0;
		while(!pq.empty()) {
			ii cur = pq.front();
			// cout << " ( " << cur.fi << " " << cur.se << " | " << dg[cur.fi][cur.se] << ") ";
			if(dg[cur.fi][cur.se] == 0) {
				min_cont = min(min_cont, cost[cur.fi][cur.se]);
			}
			pq.pop();			
			for(int k = 0; k < 4; k++) {
				int xx = cur.fi + dx[k];
				int yy = cur.se + dy[k];
				if(!is_invalid(xx, yy, n, m) && cost[xx][yy] == -1){
					cost[xx][yy] = cost[cur.fi][cur.se] + 1;
					pq.push({xx, yy});
				}
			}
		}
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < m; j++) {
		// 		cout << cost[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << min_cont << endl;
	}
	return 0;
}