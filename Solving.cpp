#include <bits/stdc++.h> 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int dx[4] = {0, -1, 0, 1};
	int dy[4] = {1, 0, -1, 0};

	// N, M 입력
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// 캠퍼스 정보 입력, 도연이 위치 기록
	vector<string> board(n);
	pair<int, int> doYeon;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		if (board[i].find("I") != -1) {
			doYeon = {i, board[i].find("I") };
		}
	}

	int friendCnt = 0;
	queue<pair<int, int>> q;
	
	q.push(doYeon);
	visited[doYeon.first][doYeon.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || board[nx][ny] == 'X') continue;
			
			if (board[nx][ny] == 'P') friendCnt++;
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	if (friendCnt) cout << friendCnt;
	else cout << "TT";


	return 0;
}