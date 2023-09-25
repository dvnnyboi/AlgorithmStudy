#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;

	board.assign(n, vector<int>(m));
	dist.assign(n, vector<int>(m, 2e9));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) dist[i][j] = 0;
		}
	}

	//int biggest = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] != 0) continue;

			queue<pair<int, int>> q;
			q.push({i, j});

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 8; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (dist[nx][ny] <= dist[x][y] + 1) continue;

					dist[nx][ny] = dist[x][y] + 1;
					//biggest = max(biggest, dist[nx][ny]);
					q.push({nx, ny});
				}

			}

		}
	}
	
	//cout << max_element(dist.begin(), dist.end());

	return 0;
}

