#include <bits/stdc++.h> 
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//�迭ũ�� �Է¹ޱ�
	cin >> n >> m;
	//�̷� �迭 ũ�� ����
	board.assign(n, vector<int>(m));
	//�ִܰŸ� �迭 ũ�� ���� �� �ʱ�ȭ
	dist.assign(n, vector<int>(m, 0));
	
	//�̷� �迭 �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < m; j++) {
			board[i][j] = num[j] - '0';
		}
	}

	//������, ����
	pair<int, int> start = {0, 0};
	pair<int, int> end = {n - 1, m - 1};

	//BFS
	queue<pair<int, int>> q;

	//������ ����
	dist[start.first][start.second] = 1;
	q.push(start);

	while (!q.empty()) {
		//queue���� �� ���� ������ (����ĭ)
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//�����¿� Ȯ�� (�ĺ�ĭ)
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// Ȯ���Ϸ��� ĭ�� ������ ����ٸ� �Ѿ��
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			//Ȯ���Ϸ��� ĭ�� ������ �� ����ĭ�̶�� �Ѿ��
			if (board[nx][ny] == 0) continue;

			//�ּҰŸ��� �ѹ��� ���غ����� ���� ĭ�̸� ����ĭ�� �ּҰŸ� + 1, queue�� ����
			if (dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx,ny});
			}
			else dist[nx][ny] = min(dist[x][y] + 1, dist[nx][ny]);	//�ִܰŸ� ����
		}
	}

	cout << dist[end.first][end.second];
	
	
	return 0;
}

