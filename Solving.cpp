#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> stickers(2, vector<int>(n, 0));
		vector<vector<int>> loss(2, vector<int>(n, 0));
		vector<vector<bool>> picked(2, vector<bool>(n, false));


		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> stickers[i][j];
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

					loss[i][j] += stickers[nx][ny];
				}
			}
		}
		
		
		

	}

	return 0;
}
