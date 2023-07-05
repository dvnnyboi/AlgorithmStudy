#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//배열크기 입력받기
	cin >> n >> m;
	//미로 배열 크기 설정
	board.assign(n, vector<int>(m));
	//최단거리 배열 크기 설정 및 초기화
	dist.assign(n, vector<int>(m, 0));
	
	//미로 배열 입력받기
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			board[i][j] = num[j] - '0';
		}
	}

	//시작점, 끝점
	pair<int, int> start = {0, 0};
	pair<int, int> end = {n - 1, m - 1};

	//BFS
	queue<pair<int, int>> q;

	//시작점 설정
	dist[start.first][start.second] = 1;
	q.push(start);

	while (!q.empty()) {
		//queue에서 한 점을 꺼낸다 (현재칸)
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//상하좌우 확인 (후보칸)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 확인하려는 칸이 범위를 벗어났다면 넘어가기
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			//확인하려는 칸이 지나갈 수 없는칸이라면 넘어가기
			if (board[nx][ny] == 0) continue;

			//최소거리를 한번도 구해본적이 없는 칸이면 현재칸의 최소거리 + 1, queue에 저장
			if (dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx,ny});
			}
			else dist[nx][ny] = min(dist[x][y] + 1, dist[nx][ny]);	//최단거리 갱신
		}
	}

	cout << dist[end.first][end.second];
	
	
	return 0;
}

